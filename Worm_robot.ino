#include <IRremote.hpp>
#include <Servo.h>

#define IR_PIN 4 // Pin para el receptor IR

Servo servoY; // Servo para movimiento frontal
Servo servoX; // Servo para movimiento lateral

enum State {
  MOVING_FORWARD,
  TURNING_RIGHT,
  TURNING_LEFT,
  STOPPED
};

State currentState = STOPPED;
unsigned long lastUpdateTime = 0;
const unsigned long interval = 250

; // Intervalo de tiempo para movimientos

void setup() {
  servoY.attach(5); // Pin para servo frontal
  servoX.attach(6); // Pin para movimiento lateral

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK); // Inicializar receptor IR
  Serial.begin(9600); // Inicializar comunicación serial
}

void loop() {
  if (IrReceiver.decode()) {
    uint32_t irValue = IrReceiver.decodedIRData.decodedRawData;
    Serial.print("IR Value: ");
    Serial.println(irValue, HEX); // Imprimir el valor recibido para depuración

    // Manejar el comando IR
    switch (irValue) {
      case 0xB946FF00: // Comando CH (mover adelante)
        currentState = MOVING_FORWARD;
        break;
      case 0xBF40FF00: // Comando Rev> (girar derecha)
        currentState = TURNING_RIGHT;
        break;
      case 0xBB44FF00: // Comando Rev< (girar izquierda)
        currentState = TURNING_LEFT;
        break;
      case 0xBC43FF00: // Comando Play (detener)
        currentState = STOPPED;
        break;
      default:
        Serial.println("Unknown command"); // Imprimir si se recibe un comando desconocido
        break;
    }

    IrReceiver.resume(); // Recibir el siguiente comando
  }

  unsigned long currentTime = millis();
  if (currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;

    // Ejecutar las funciones según el estado actual
    switch (currentState) {
      case MOVING_FORWARD:
        moverAdelante();
        break;
      case TURNING_RIGHT:
        girarDerecha();
        break;
      case TURNING_LEFT:
        girarIzquierda();
        break;
      case STOPPED:
        detener();
        break;
    }
  }
}

void moverAdelante() {
  static bool position = false;
  if (position) {
    servoY.write(15);
  } else {
    servoY.write(165);
  }
  position = !position;
  servoX.write(90); 
}

void girarDerecha() {
  static bool position = false;
  if (position) {
    servoY.write(90); // Jala derecha
    servoX.write(165);
  } else {
    servoY.write(15); // Jala arriba
    servoX.write(90);
  }
  position = !position;
}

void girarIzquierda() {
  static bool position = false;
  if (position) {
    servoY.write(90); // Jala derecha
    servoX.write(15);
  } else {
    servoY.write(15); // Jala arriba
    servoX.write(90);
  }
  position = !position;
}

void detener() {
  servoX.write(90); // Detener movimiento
  servoY.write(90); // Detener movimiento
}


/*
Codes:
CH-: 0xBA45FF00 /3125149440
CH: 0xB946FF00/3108437760
CH+: 0xB847FF00/3091726080
Rev< : 0xBB44FF00/3141861120
Rev>:0xBF40FF00/3208707840
Play: 0xBC43FF00/3158572800
Vol-:0xF807FF00/4161273600
Vol+:0xEA15FF00/3927310080
Eq: 0xF609FF00/4127850240
0: 0xE916FF00/3910598400
100+: 0xE619FF00/3860463360
200+: 0xF20DFF00/4061003520
1: 0xF30CFF00/4077715200
2: 0xE718FF00/3877175040
3: 0xA15EFF00/2707357440
4: 0xF708FF00/4144561920
5: 0xE31CFF00/3810328320
6: 0xA55AFF00/2774204160
7: 0xBD42FF00/3175284480
8: 0xAD52FF00/2907897600
9: 0xB54AFF00/3041591040

*/
