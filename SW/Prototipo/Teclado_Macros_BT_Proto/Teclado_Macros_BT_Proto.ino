#include <BleKeyboard.h>

BleKeyboard bleKeyboard("Teclado Macros ESP32");

const int buttonPins[] = {4, 16, 17, 18, 22, 23, 25, 33, 32}; // Pines de los botones
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

void setup() {
  Serial.begin(115200);

  // Inicializar los pines de los botones
  for (int i = 0; i < numButtons; ++i) {
    pinMode(buttonPins[i], INPUT_PULLUP);
  }

  Serial.println("Iniciando Bluetooth...");
  bleKeyboard.begin();
}

void loop() {
  if (bleKeyboard.isConnected()) {
    for (int i = 0; i < numButtons; ++i) {
      if (digitalRead(buttonPins[i]) == LOW) {
        switch (buttonPins[i]) {
          case 4:
            // Ctrl + Alt + Shift + F2
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F2);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F2");
            break;
          case 16:
            // Ctrl + Alt + Shift + F3
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F3);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F3");
            break;
          case 17:
            // Ctrl + Alt + Shift + F4
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F4);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F4");
            break;
          case 18:
            // Ctrl + Alt + Shift + F5
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F5);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F5");
            break;
          case 22:
            // Ctrl + Shift + F6
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F6);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Shift + F6");
            break;
          case 23:
            // Ctrl + Shift + F7
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Shift + F7");
            break;
          case 25:
            // PrintScreen o Win + Shift + S
            //bleKeyboard.press(KEY_PRTSC);

            bleKeyboard.press(KEY_LEFT_GUI);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press('S');

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
