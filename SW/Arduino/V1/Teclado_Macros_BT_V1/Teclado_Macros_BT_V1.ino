#include <BleKeyboard.h>

/*Ejemplos de funciones:

            // Botón PX: CTR + C
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('c');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + C");


            // Botón PX: C Ctrl + Alt + Shift + F6
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F6);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F6");
            

            // Botón PX: Page Down
            bleKeyboard.press(KEY_PAGE_DOWN);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Page Down");

            bleKeyboard.press(KEY_HOME);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press('s');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Shift + WIN + S");

*/

// Inicializamos el teclado Bluetooth con el nombre "Teclado Macros ESP32"
BleKeyboard bleKeyboard("ESP32 Macros");

// Pines de los botones GPIO
const int buttonPins[] = { 23, 22, 18, 16, 4, 25, 21, 19, 17, 33, 32, 26, 27, 14, 13 };
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);  // Número total de botones
const int ledPin = 2;                                               // Pin del LED (D2)

void setup() {
  Serial.begin(115200);  // Iniciar la comunicación serial para depuración

  // Configurar los pines de los botones como entrada con resistencia pull-up
  for (int i = 0; i < numButtons; ++i) {
    pinMode(buttonPins[i], INPUT_PULLUP);  // Los pines se configuran como entradas con resistencia interna
  }

  // Configurar el pin del LED como salida
  pinMode(ledPin, OUTPUT);

  Serial.println("Iniciando Bluetooth...");
  bleKeyboard.begin();  // Inicializamos el teclado Bluetooth
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

        // Ejecutar acción dependiendo del botón presionado
        switch (buttonPins[i]) {
          case 23:
            // Botón P1: Ctrl + C
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('c');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + C");
            break;
          case 22:
            // Botón P2: F7
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando F7");
            break;
          case 18:
            // Botón P3: Ctrl + Alt + Shift + F8
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F8);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F8");
            break;
          case 16:
            // Botón P4: Ctrl + Alt + Shift + F9
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F9);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F9");
            break;
          case 4:
            // Botón P5: Ctrl + Alt + Shift + F11
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F11);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F11");
            break;
          case 25:
            // Botón P6: Ctrl + V
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('v');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + V");
            break;
          case 21:
            // Botón P7: Alt + F7
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Alt + F7");
            break;
          case 19:
            // Botón P8: Ctrl + Alt + Shift + F5
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F5);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F5");
            break;
          case 17:
            // Botón P9: Ctrl + Alt + Shift + F6
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F6);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F6");
            break;
          case 33:
            // Botón P10: Ctrl + Alt + Shift + F7
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F7");
            break;
          case 32:
            // Botón P11: Ctrl + C
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('z');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Z");
            break;
          case 26:
            // Botón P12: Ctrl + F7
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + F7");
            break;
          case 27:
            // Botón P13: Reserva
            bleKeyboard.println("KeyWord");
            Serial.println("Enviando KeyWord");  
            break;
          case 14:
            // Botón P14: Shift + WIN + S
            bleKeyboard.press(KEY_RIGHT_GUI);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press('s');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Shift + WIN + S");
            break;
          case 13:
            // Botón P15: WIN + K
            bleKeyboard.press(KEY_RIGHT_GUI);
            bleKeyboard.press('k');
            bleKeyboard.releaseAll();
            Serial.println("Enviando WIN + K");
            break;
          default:
            // Si el botón no está mapeado
            Serial.println("Botón no mapeado");
            break;
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
