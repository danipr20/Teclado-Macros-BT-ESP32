#include <BleKeyboard.h>

// Inicializamos el teclado Bluetooth
BleKeyboard bleKeyboard("ESP32 Macros");

// Pines de los botones GPIO
const int buttonPins[] = { 23, 22, 18, 16, 4, 25, 21, 19, 17, 33, 32, 26, 27, 14, 13 };
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);  // Número de botones
const int ledPin = 2;  // Pin del LED

// Número máximo de perfiles que podemos manejar
const int numProfiles = 5;

// Matriz de perfiles, cada uno contiene las combinaciones de teclas de los botones
int profiles[numProfiles][numButtons][4] = {
  // Perfil 1: cada botón tiene una combinación de teclas (ejemplo)
  {
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F2},  // Botón P1
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F3},  // Botón P2
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F4},  // Botón P3
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F5},  // Botón P4
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F6},  // Botón P5
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F7},  // Botón P6
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F8},  // Botón P7
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F9},  // Botón P8
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F10}, // Botón P9
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_LEFT_SHIFT, KEY_F11}, // Botón P10
    {KEY_LEFT_CTRL, 'c', 0, 0},                             // Botón P11 (Ctrl + C)
    {KEY_LEFT_CTRL, 'v', 0, 0},                             // Botón P12 (Ctrl + V)
    {KEY_LEFT_CTRL, 'z', 0, 0},                             // Botón P13 (Ctrl + Z)
    {0, 0, 0, 0},                                           // Botón P14 (Cambio de perfil)
    {0, 0, 0, 0}                                            // Botón P15 (Cambio de perfil)
  },
  // Perfil 2
  {
    {KEY_LEFT_CTRL, KEY_F7, 0, 0},            // Botón P1
    {KEY_LEFT_SHIFT, KEY_F7, 0, 0},           // Botón P2
    {KEY_F7, 0, 0, 0},                        // Botón P3
    {KEY_LEFT_CTRL, 'c', 0, 0},               // Botón P4
    {KEY_LEFT_CTRL, 'v', 0, 0},               // Botón P5
    {KEY_LEFT_CTRL, KEY_LEFT_ALT, KEY_F7, 0}, // Botón P6
    // Resto de botones...
  },
  // Agregar más perfiles aquí...
};

// Variables para controlar el perfil actual
int currentProfile = 0;  // Comienza con el perfil 1 (índice 0)

void setup() {
  Serial.begin(115200);

  // Configurar los pines de los botones como entrada con resistencia pull-up
  for (int i = 0; i < numButtons; ++i) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Configurar el pin del LED como salida
  pinMode(ledPin, OUTPUT);

  Serial.println("Iniciando Bluetooth...");
  bleKeyboard.begin();  // Inicializamos el teclado Bluetooth
}

// Función para ejecutar una combinación de teclas
void executeKeyPress(int buttonIndex) {
  // Obtener la combinación de teclas actual para el botón en el perfil activo
  int* keys = profiles[currentProfile][buttonIndex];

  // Enviar teclas si no están vacías
  for (int i = 0; i < 4; ++i) {
    if (keys[i] != 0) {
      bleKeyboard.press(keys[i]);
    }
  }
  bleKeyboard.releaseAll();  // Liberar las teclas
}

void loop() {
  // Verificar si el teclado Bluetooth está conectado
  if (bleKeyboard.isConnected()) {
    // Recorrer todos los botones para detectar si alguno está presionado
    for (int i = 0; i < numButtons; ++i) {
      if (digitalRead(buttonPins[i]) == LOW) {  // Si el botón está presionado (LOW)
        
        // Parpadeo del LED para indicar que un botón fue presionado
        digitalWrite(ledPin, HIGH);  // Encender LED
        delay(50);                   // Esperar 50 ms
        digitalWrite(ledPin, LOW);   // Apagar LED

        // Cambiar perfil con los botones P14 y P15
        if (i == 13) {  // Botón P14: Cambiar al perfil anterior
          currentProfile = (currentProfile - 1 + numProfiles) % numProfiles;
          Serial.print("Cambiando al Perfil ");
          Serial.println(currentProfile + 1);  // Mostrar el perfil actual
          delay(200);
        } else if (i == 14) {  // Botón P15: Cambiar al siguiente perfil
          currentProfile = (currentProfile + 1) % numProfiles;
          Serial.print("Cambiando al Perfil ");
          Serial.println(currentProfile + 1);  // Mostrar el perfil actual
          delay(200);
        } else {
          // Ejecutar la acción correspondiente al botón en el perfil actual
          executeKeyPress(i);
        }

        // Espera antirrebote
        delay(100);
        while (digitalRead(buttonPins[i]) == LOW)
          ;  // Esperar hasta que el botón se suelte
      }
    }
  }

  delay(10);  // Pequeño retraso para reducir el uso de CPU
}
