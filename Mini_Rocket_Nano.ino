
#include <MPU6050_tockn.h>
#include <Wire.h>
int top = 3;
int bottom = 11;
int left = 9;
int right = 10;
int lightVal = 255;
int calibratingLight = 6;
float offsetX = -5;
float offsetY = -5;
float offsetZ = 5;

MPU6050 mpu6050(Wire);

void setup() {
  digitalWrite(calibratingLight,HIGH);
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
  digitalWrite(calibratingLight,LOW);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());

  
  if(mpu6050.getAngleX()>abs(offsetX)){
    analogWrite(top,lightVal);
    }
  else{
    analogWrite(top,0);
    }
  
  if(mpu6050.getAngleY()>abs(offsetY)){
    analogWrite(left,lightVal);
    }
  else{
    analogWrite(left,0);
    }
  
  if(mpu6050.getAngleX()<-abs(offsetX)){
    analogWrite(bottom,lightVal);
    }
  else{
    analogWrite(bottom,0);
    }
  
  if(mpu6050.getAngleY()<-abs(offsetY)){
    analogWrite(right,lightVal);
    }
  else{
    analogWrite(right,0);
    }
 

}
