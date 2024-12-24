#include <BleKeyboard.h>

// Inicializamos el teclado Bluetooth con el nombre "Teclado Macros ESP32"
BleKeyboard bleKeyboard("ESP32 Macros");

// Pines de los botones GPIO
const int buttonPins[] = { 23, 22, 18, 16, 4, 25, 21, 19, 17, 33, 32, 26, 27, 14, 13 };
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]); // Número total de botones
const int ledPin = 2;                                              // Pin del LED (D2)

// Pines de cambio de modo
const int modeSwitchPin1 = 13; // GPIO 13 (P15)
const int modeSwitchPin2 = 14; // GPIO 14 (P14)

// Variables globales
unsigned long modeSwitchStart = 0; // Tiempo de inicio para el cambio de modo
bool isMode2 = false;              // Modo actual: false para teclado, true para BT Serial

void setup() {
  Serial.begin(115200); // Iniciar la comunicación serial para depuración

  // Configurar los pines de los botones como entrada con resistencia pull-up
  for (int i = 0; i < numButtons; ++i) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  // Configurar los pines del cambio de modo como entrada
  pinMode(modeSwitchPin1, INPUT_PULLUP);
  pinMode(modeSwitchPin2, INPUT_PULLUP);

  // Configurar el pin del LED como salida
  pinMode(ledPin, OUTPUT);

  Serial.println("Iniciando Bluetooth...");
  bleKeyboard.begin(); // Inicializamos el teclado Bluetooth
}

void loop() {
  // Detectar si ambos pines de cambio de modo están presionados durante 5 segundos
  if (digitalRead(modeSwitchPin1) == LOW && digitalRead(modeSwitchPin2) == LOW) {
    if (modeSwitchStart == 0) {
      modeSwitchStart = millis(); // Iniciar el contador
    } else if (millis() - modeSwitchStart >= 5000) {
      isMode2 = !isMode2; // Cambiar de modo
      Serial.printf("Cambiando al modo %s\n", isMode2 ? "BT Serial" : "Teclado");
      digitalWrite(ledPin, isMode2 ? HIGH : LOW); // Encender el LED en modo BT Serial
      delay(500); // Pequeño retraso para evitar rebotes
    }
  } else {
    modeSwitchStart = 0; // Reiniciar el contador si los pines no están presionados
  }

  // Modo Teclado
  if (!isMode2 && bleKeyboard.isConnected()) {
    for (int i = 0; i < numButtons; ++i) {
      if (digitalRead(buttonPins[i]) == LOW) {
        digitalWrite(ledPin, HIGH); // Encender LED
        delay(50);
        digitalWrite(ledPin, LOW); // Apagar LED

        switch (buttonPins[i]) {
          case 23:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('c');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + C");
            break;
          case 22:
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando F7");
            break;
          case 18:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F8);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F8");
            break;
          case 16:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F9);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F9");
            break;
          case 4:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F11);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F11");
            break;
          case 25:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('v');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + V");
            break;
          case 21:
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Alt + F7");
            break;
          case 19:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F5);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F5");
            break;
          case 17:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F6);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F6");
            break;
          case 33:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F7");
            break;
          case 32:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('z');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Z");
            break;
          case 26:
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + F7");
            break;
          case 27:
            bleKeyboard.println("KeyWord");
            Serial.println("Enviando KeyWord");
            break;
          case 14:
            bleKeyboard.press(KEY_RIGHT_GUI);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press('s');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Shift + WIN + S");
            break;
          case 13:
            bleKeyboard.press(KEY_RIGHT_GUI);
            bleKeyboard.press('k');
            bleKeyboard.releaseAll();
            Serial.println("Enviando WIN + K");
            break;
          default:
            Serial.println("Botón no mapeado");
            break;
        }

        delay(100); // Antirrebote
        while (digitalRead(buttonPins[i]) == LOW)
          ;
      }
    }
  }

  // Modo BT Serial
  if (isMode2) {
    for (int i = 0; i < numButtons; ++i) {
      if (digitalRead(buttonPins[i]) == LOW) {
        digitalWrite(ledPin, HIGH); // Encender LED
        delay(50);
        digitalWrite(ledPin, LOW); // Apagar LED

        // Enviar identificador único del botón pulsado
        Serial.printf("Botón P%d pulsado\n", i + 1);
        String message = String("P") + String(i + 1);
        bleKeyboard.print(message);

        delay(100); // Antirrebote
        while (digitalRead(buttonPins[i]) == LOW)
          ;
      }
    }
  }

  delay(10); // Pequeño retraso para reducir el uso de CPU
}
