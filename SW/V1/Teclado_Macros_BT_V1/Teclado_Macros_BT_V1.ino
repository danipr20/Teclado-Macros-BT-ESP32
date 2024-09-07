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
            // Ctrl + Alt + F1
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_F1);
            bleKeyboard.releaseAll(); // Asegúrate de liberar todas las teclas y modificadores
            Serial.println("Enviando Ctrl + Alt + F1");
            break;
          case 16:
            // Ctrl + Alt + F2
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_F2);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + F2");
            break;
          case 17:
            // Ctrl + Alt + F3
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_F3);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + F3");
            break;
          case 18:
            // Ctrl + Alt + F4
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_F4);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + F4");
            break;
          case 22:
            // Ctrl + C
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('C');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + C");
            break;
          case 23:
            // Ctrl + V
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('V');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + V");
            break;
          case 25:
            // Ctrl + Z
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('Z');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Z");
            break;
          case 33:
            // Page Down
            bleKeyboard.write(KEY_PAGE_DOWN);
            Serial.println("Enviando Page Down");
            break;
          case 32:
            // Page Up
            bleKeyboard.write(KEY_PAGE_UP);
            Serial.println("Enviando Page Up");
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
