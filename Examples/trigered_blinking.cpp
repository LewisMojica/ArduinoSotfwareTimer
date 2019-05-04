#include <Arduino.h>
#include <Button.h>
#include <Timer.h>
#define led 13


Button but1(14,20,Button::PULLUP);
Timer timer(500);


void setup() {
  Serial.begin(19200);
  pinMode(13, OUTPUT);
}

void loop() {
  if(but1.falling()){
    Serial.println("falling");
    if(timer.isRunning()){
      timer.end();
      Serial.println("timer end");
    }
    else{
     timer.initOn();
     Serial.println("timer init");
    }
  }
  if(timer.read()){
    Serial.println("true read");
    digitalWrite(led,!digitalRead(led));
  }
  // delay(50);
}