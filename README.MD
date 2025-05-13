# Control de Motor con Encoder y Potenciómetro

## Descripción
Este código implementa el control de un motor utilizando un potenciómetro, un encoder para medición de velocidad y comunicación serial para control de dirección.

## Componentes Utilizados
- **Potenciómetro** (`pinPot` - A2) para ajustar la velocidad del motor.
- **Motor DC** con control de dirección mediante `pinIN1` y `pinIN2`.
- **PWM** (`pinENA` - 10) para variación de velocidad.
- **Encoder** (`encoderPinA` - 2, `encoderPinB` - 3) para medición de revoluciones.
- **Interfaz serial** para cambiar la dirección del motor.

## Funcionamiento
1. **Control de Velocidad**: Se lee el valor del potenciómetro y se ajusta la velocidad del motor utilizando PWM.
2. **Control de Dirección**: Se usa comunicación serial (`A`, `B`, `S`) para cambiar el sentido de giro del motor.
3. **Medición de Revoluciones**: Se usa un encoder para contar pulsos y calcular RPM (Revoluciones por minuto).
4. **Salida de Datos**: Se imprimen datos por serial para monitorear velocidad, pulsos y RPM.

## Comandos Disponibles
Los siguientes comandos pueden ser enviados a través del monitor serial:
- **'A'**: Mueve el motor en la dirección "A".
- **'B'**: Mueve el motor en la dirección "B".
- **'S'**: Detiene el motor.

## Instalación y Uso
1. **Conectar los componentes** según los pines especificados en el código.
2. **Subir el código** a un microcontrolador compatible (ej. Arduino).
3. **Abrir el monitor serial** y enviar comandos para cambiar la dirección del motor.

## Autores
Desarrollado por:
- **Jerson Oswaldo Sierra**
- **Juan David Sotelo**

