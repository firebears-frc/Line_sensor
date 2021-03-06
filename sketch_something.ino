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


//------------------------------------------------------------------------------------
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

  for (int L = 0; L < 59; L++) {
    Serial.print(PixelArray[L]);
    Serial.print(" L ");
  }

  for (int M = 59; M < 69; M++) {
    Serial.print(PixelArray[M]);
    Serial.print(" M ");
  }

  for (int R = 69; R < 128; R++) {
    Serial.print(PixelArray[R]);
    Serial.print(" R ");
  }
  Serial.print('\n');
}
//-----------------------------------------------------------------------------------
