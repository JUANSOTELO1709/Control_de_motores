// Jerson Oswaldo Sierra & Juan David Sotelo

const int pinPot = A2;       // Potenciómetro
const int pinENA = 10;       // PWM para ENA
const int pinIN1 = 5;        // IN1
const int pinIN2 = 9;        // IN2
const int encoderPinA = 2;   // Señal A del encoder
const int encoderPinB = 3;   // Señal B del encoder

volatile int contadorPulsos = 0;    
char currentDirection = 'A';    // Iniciar en la posición 'A'
int encoder = 20;           
int tot = encoder * 48;
unsigned long tiempoAnterior = 0;

void setup() {
    pinMode(pinENA, OUTPUT);
    pinMode(pinIN1, OUTPUT);
    pinMode(pinIN2, OUTPUT);
    pinMode(encoderPinA, INPUT_PULLUP);
    pinMode(encoderPinB, INPUT_PULLUP);

    attachInterrupt(digitalPinToInterrupt(encoderPinA), encoderISR, RISING);

    Serial.begin(9600);
    Serial.println("Sistema listo. Usa 'A', 'B' o 'S' para controlar la dirección.");
}

void loop() {
    int potValue = analogRead(pinPot);
    int motorSpeed = map(potValue, 0, 1023, 0, 255);

    if (motorSpeed == 0 || currentDirection == 'S') {
        analogWrite(pinENA, 0);
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, LOW);
    } else {
        analogWrite(pinENA, motorSpeed);
        if (currentDirection == 'A') {
            digitalWrite(pinIN1, HIGH);
            digitalWrite(pinIN2, LOW);
        } else if (currentDirection == 'B') {
            digitalWrite(pinIN1, LOW);
            digitalWrite(pinIN2, HIGH);
        }
    }

    if (Serial.available() > 0) {
        char command = Serial.read();
        updateMotorDirection(command);
    }

    unsigned long tiempoActual = millis();
    if (tiempoActual - tiempoAnterior >= 1000) {
        noInterrupts();
        int pulsos = contadorPulsos;
        contadorPulsos = 0;
        interrupts();

        float rps = (float)pulsos / tot;
        float rpm = rps * 60.0;
        float velocidad = motorSpeed;

        Serial.print(velocidad + 10000);
        Serial.print("\t");
        Serial.print(pulsos + 10000);
        Serial.print("\t");
        Serial.print(rps + 10000);
        Serial.print("\t");
        Serial.println(rpm + 10000);

        tiempoAnterior = tiempoActual;
    }
}

void updateMotorDirection(char command) {
    if (command == 'A') {
        currentDirection = 'A';
    } else if (command == 'B') {
        currentDirection = 'B';
    } else if (command == 'S') {
        currentDirection = 'S';
    }
}

void encoderISR() {
    contadorPulsos++;
}