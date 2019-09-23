//-----------------------------------------------------------------------------------
int PixelArray[128] ;            // Pixel array.
int CLK = 21;                    // Set pin as CLK I2C on arduino.
int SI  = 20;                    // Set pin as S the I2C on arduino.
int i   =  0;
int sensorValue = 0;             // Photoreceptor pixel exposure min value is set to 0.
int lightExposure = 2;           // Sets the LED pin, pin 2 on arduino.
int lightLeft = 3;               // Sets the left-light pinNumber.
int lightRight = 4;              // Sets the right-light pinNumber.


//-----------------------------------------------------------------------------------
void setup() {

  pinMode(lightLeft, OUTPUT);    // Sets the output of the PIN.
  pinMode(lightRight, OUTPUT);   // Sets the output of the PIN.
  pinMode(lightExposure, OUTPUT);// Sets the output of the PIN.
  pinMode(CLK, OUTPUT);          // Sets the output of the PIN.
  pinMode(SI, OUTPUT);           // Sets the output of the PIN.

  Serial.begin(9600);            // Starts.
  digitalWrite(SI, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(SI, LOW);
  digitalWrite(CLK, LOW);
  digitalWrite(lightExposure, HIGH);

  for (i = 0; i < 128; i ++) {

    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);

  }
}


//-----------------------------------------------------------------------------------
void loop() {

  sensorValue = analogRead(A1);
  digitalWrite(SI, HIGH);
  digitalWrite(CLK, HIGH);
  digitalWrite(SI, LOW);
  digitalWrite(CLK, LOW);

  for (i = 0; i < 128; i ++) {
    delayMicroseconds(sensorValue);
    PixelArray[i] = analogRead(A0);
    digitalWrite(CLK, HIGH);
    digitalWrite(CLK, LOW);
  }

  int Left[59] = {0, 59};
  int Right[128] = {69, 128};
  int Middle[69] = {59, 69};
  int D = 132;

  if (Left[59] = PixelArray[i] ) {
    for (int L = 0; L < 59; L++ ) {
      Left[L] +  Left[L] / 2;
      Left[L] = analogRead(A2);
    }
  }
  if (analogRead(A2) > D ) {
    Serial.print(analogRead(A2));
    Serial.print(" ");
  } else {
    Serial.print(0);
  }

  if (Middle[69] = PixelArray[i] ) {
    for (int M = 59; M < 69; M++ ) {
      Middle[M] +  Middle[M] / 2;
      Middle[M] = analogRead(A3);
    }
  }
  if (analogRead(A3) > D ) {
    Serial.print(analogRead(A3));
    Serial.print(" ");
  } else {
    Serial.print(0);
  }

  if (Right[128] = PixelArray[i] ) {
    for (int R = 69; R < 128; R++ ) {
      Right[R] +  Right[R] / 2;
      Right[R] = analogRead(A4);
    }
  }
  if (analogRead(A4) > D ) {
    Serial.print(analogRead(A4));
    Serial.print(" ");
  } else {
    Serial.print(0);
  }
  Serial.println("  ");
}
//----------------21------------------------------------------------------------------
