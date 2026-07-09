#include <Wire.h>
#include <MPU6050.h>
#include <PID_v1.h>
double sabet = 50;
double ezaf = 1.1;
double sb0 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf;
double sf0 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf;
double sb1 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf;
double sf1 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf;
double sb2 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf;
double sf2 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf*ezaf;
double sb3 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf;
double sf3 = sabet*ezaf*ezaf*ezaf*ezaf*ezaf;
double sb4 = sabet*ezaf*ezaf*ezaf*ezaf;
double sf4 = sabet*ezaf*ezaf*ezaf*ezaf;
double sb5 = sabet*ezaf*ezaf*ezaf;
double sf5 = sabet*ezaf*ezaf*ezaf;
double sb6 = sabet*ezaf*ezaf;
double sf6 = sabet*ezaf*ezaf;
double sb7 = sabet*ezaf;
double sf7 = sabet*ezaf;

double zavie=-3;

MPU6050 mpu;
const int IN1 = 11;
const int IN2 = 10;
const int IN3 = 9;
const int IN4 = 5;
// Define variables for PID computation
int enA = 5;
int enB = 3;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
        
  mpu.initialize();
  if (!mpu.testConnection()) {
    Serial.println("MPU6050 connection failed");
    while (1);
  }
}

void loop() {
  analogWrite(IN1, 30);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  analogWrite(IN4, 30);
  int16_t ax, ay, az;
  int16_t gx, gy, gz;

  mpu.getAcceleration(&ax, &ay, &az);
  mpu.getRotation(&gx, &gy, &gz);

  // Convert raw data to meaningful units
  float accelX = ax / 16384.0; // Convert raw accelerometer data to g-force
  float accelY = ay / 16384.0;
  float accelZ = az / 16384.0;
  
  float gyroX = gx / 131.0; // Convert raw gyroscope data to degrees per second
  float gyroY = gy / 131.0;
  float gyroZ = gz / 131.0;

  // Calculate pitch and roll angles using accelerometer data
  float pitch = atan2(-accelX, sqrt(accelY * accelY + accelZ * accelZ)) * 180 / PI;
   

  Compute PID output
 

  Serial.print(":\n");
  Serial.print(pitch);
 
 if (pitch >= 8+zavie) {
    // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb0);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb0);
    Serial.println("Rotating backward 7");

  
  }
   else if (pitch >= 6+zavie && pitch <8+zavie) {
    // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb1);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb1);
    Serial.println("Rotating backward 6");

  
  }
    else if (pitch >= 5+zavie && pitch <6+zavie) {
    // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb2);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb2);
    Serial.println("Rotating backward 5");

  
  }
   else if (pitch >= 4+zavie && pitch<5+zavie) {
    // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb3);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb3);
    Serial.println("Rotating backward 4");

  
  }
   else if (pitch >= 3+zavie && pitch<4+zavie) {
    // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb4);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb4);
    Serial.println("Rotating backward 3");

  
  }
  
    else if (pitch >= 2+zavie && pitch <3+zavie) {
    // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb5);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb5);
    Serial.println("Rotating backward 2");

  
  }
   else if (pitch >= 1+zavie && pitch<2+zavie) {
//     // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb6);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb6);
    Serial.println("Rotating backward 1");

  
  }

   else if (pitch >= 0+zavie && pitch<1+zavie) {
//     // Rotate wheels backward
    digitalWrite(IN1, LOW);
    analogWrite(IN2, sb7);
    digitalWrite(IN3, LOW);
    analogWrite(IN4, sb7);
    Serial.println("Rotating backward 0");

  
  }
      else if (pitch < 0+zavie && pitch >= -1+zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf7);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf7);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 0");
 
  }
      else if (pitch < -1+zavie && pitch >= -2+zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf6);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf6);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 1");
 
  }
      else if (pitch < -2+zavie && pitch >=-3+zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf5);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf5);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 2");
 
  }
      else if (pitch < -3+zavie && pitch >= -4+zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf4);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf4);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 3");
 
  }
      else if (pitch < -4+zavie && pitch >= -5+zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf3);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf3);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 4");
 
  }
      else if (pitch < -5+zavie && pitch >=-6+zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf2);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf2);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 5");
 
  }
  else if (pitch < -6+zavie && pitch >=-8+zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf1);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf1);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 6");
 
  }
  else if (pitch < -8 + zavie) {
//     // Rotate wheels forward
    analogWrite(IN1, sf0);
    digitalWrite(IN2, LOW);
    analogWrite(IN3, sf0);
    digitalWrite(IN4, LOW);
    Serial.println("Rotating forward 7");
 
  }

delay(1);
   
 else {
    // Stop the wheels
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    Serial.println("Wheels stopped");
   
  
  }
  delay(50);

}
  