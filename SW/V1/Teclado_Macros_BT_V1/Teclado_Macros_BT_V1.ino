#include <BleKeyboard.h>

// Inicializamos el teclado Bluetooth con el nombre "Teclado Macros ESP32"
BleKeyboard bleKeyboard("Teclado Macros ESP32");

// Pines de los botones GPIO
const int buttonPins[] = {23, 22, 18, 16, 4, 25, 21, 19, 17, 33, 32, 26, 27, 14, 13};
const int numButtons = sizeof(buttonPins) / sizeof(buttonPins[0]);

void setup() {
  Serial.begin(115200);

  // Inicializar los pines de los botones
  for (int i = 0; i < numButtons; ++i) {
    pinMode(buttonPins[i], INPUT_PULLUP); // Configuramos los pines como entrada con resistencia interna
  }

  Serial.println("Iniciando Bluetooth...");
  bleKeyboard.begin(); // Iniciamos el teclado Bluetooth
}

void loop() {
  if (bleKeyboard.isConnected()) { // Verificamos si hay una conexión Bluetooth
    for (int i = 0; i < numButtons; ++i) {
      if (digitalRead(buttonPins[i]) == LOW) { // Si el botón está presionado (LOW significa presionado)
        switch (buttonPins[i]) {
          case 23:
          //Botón P1 
            // Ctrl + Alt + Shift + F2
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F2);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F2");
            break;
          case 22:
            //Botón P2 
            // Ctrl + Alt + Shift + F3
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F3);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F3");
            break;
          case 18:
          //Botón P3 
            // Ctrl + Alt + Shift + F4
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F4);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F4");
            break;
          case 16:
          //Botón P4
            // Ctrl + Alt + Shift + F5
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F5);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F5");
            break;
          case 4:
          //Botón P5 
            // Ctrl + Alt + Shift + F6
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F6);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F6");
            break;
          case 25:
          //Botón P6
            // Ctrl + Alt + Shift + F7
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F7);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F7");
            break;
          case 21:
          //Botón P7
            // Ctrl + Alt + Shift + F8
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F8);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F8");
            break;
          case 19:
          //Botón P8 
            // Ctrl + Alt + Shift + F9
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F9);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F9");
            break;
          case 17:
             //Botón P9 
            // Ctrl + Alt + Shift + F10
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F10);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F10");
            break;
          case 33:
            // Ctrl + Alt + Shift + F11
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press(KEY_LEFT_ALT);
            bleKeyboard.press(KEY_LEFT_SHIFT);
            bleKeyboard.press(KEY_F11);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Alt + Shift + F10");
            break;
          case 26:
            //Botón P11

            // Ctrl + C
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('c');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + C");
            break;
          case 32:
            //Botón P12

            // Ctrl + V
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('v');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + V");
            break;
          case 27:
            //Botón P13 

            // Ctrl + Z
            bleKeyboard.press(KEY_LEFT_CTRL);
            bleKeyboard.press('z');
            bleKeyboard.releaseAll();
            Serial.println("Enviando Ctrl + Z");
            break;
          case 14:
          //Botón P14 

            // Page Up
            bleKeyboard.press(KEY_PAGE_UP);
            bleKeyboard.releaseAll();
            Serial.println("Enviando Page Up");
            break;
          case 13:
          //Botón P15
            // Page Down
            bleKeyboard.press(KEY_PAGE_DOWN);
            bleKeyboard.releaseAll();
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
