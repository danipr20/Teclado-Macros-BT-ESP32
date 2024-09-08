#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Teclado Macros ESP32");

const int buttonPins[] = {4, 16, 17, 18, 22, 23, 25, 33, 32}; // Pines de los botones
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);
const int ledPin = 2; // Pin del LED (D2)

void setup() {
  Serial.begin(115200);

  // Inicializar los pines de los botones
  for (int i = 0; i < numButtons; ++i) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  pinMode(ledPin, OUTPUT); // Inicializar el pin del LED como salida

  Serial.println("Iniciando Bluetooth...");
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    for (int i = 0; i < numButtons; ++i) {
      if (digitalRead(buttonPins[i]) == LOW) {
        
        // Parpadeo rápido del LED
        digitalWrite(ledPin, HIGH); // Encender LED
        delay(50); // Esperar 50 ms
        digitalWrite(ledPin, LOW); // Apagar LED

        switch (buttonPins[i]) {
          case 4:
            // Ctrl + F7
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + F7");
            break;
          case 16:
            // Shift + F7
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Shift + F7");
            break;
          case 17:
            // Ctrl + Alt + Shift + F2
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F2);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F2");
            break;
          case 18:
            // Ctrl + Alt + Shift + F3
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F3);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F3");
            break;
          case 22:
            // Ctrl + C
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('c');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + C");
            break;
          case 23:
            // Ctrl + V
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('v');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + V");
            break;
          case 25:
            // PrintScreen o Win + Shift + S
            bleKeyboard.press(KEY_LEFT_GUI);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press('s');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Win + Shift + S");
            break;
          case 33:
            // Page Up
            bleKeyboard.write(KEY_PAGE_UP);
            Serial.println("Enviando Page Up");
            break;
          case 32:
            // Page Down
            bleKeyboard.write(KEY_PAGE_DOWN);
            Serial.println("Enviando Page Down");
            break;
          default:
            Serial.println("Botón no mapeado");
            break;
        }

        delay(100);  // Antirrebote
        while (digitalRead(buttonPins[i]) == LOW);  // Esperar hasta que se suelte el botón
      }
    }
  }

  delay(10);  // Pequeño retraso para reducir el uso de CPU
}
