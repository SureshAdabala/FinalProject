#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

#define in 7   // Use valid digital pins
#define out 8  // Use valid digital pins
#define relay 2
#define led 3

int count = 0; // Declare and initialize the count variable

void setup() {
    lcd.begin(16, 2);
    lcd.print("Visitor Counter");
    delay(2000);
    pinMode(in, INPUT);
    pinMode(out, INPUT);
    pinMode(relay, OUTPUT);
    pinMode(led,OUTPUT);
    lcd.clear();
    lcd.print("Person In Room:");
    lcd.setCursor(0, 1);
    lcd.print(count);
}

void loop() {
    if (digitalRead(in)) {
        IN();
        delay(200); // Debounce delay
    }
    if (digitalRead(out)) {
        OUT();
        delay(200); // Debounce delay
    }

    if (count <= 0) {
        lcd.clear();
        digitalWrite(relay, LOW);
        lcd.print("Nobody In Room");
        lcd.setCursor(0, 1);
        lcd.print("Light Is Off");
        digitalWrite(led, LOW);
        delay(200);
    }
}

void IN() {
    if (count < 10) {
        count++;
        lcd.clear();
        lcd.print("Person In Room:");
        digitalWrite(led, HIGH);
        lcd.setCursor(0, 1);
        lcd.print(count);
        delay(1000);
    }
}

void OUT() {
    if (count > 0) {
        count--;
        lcd.clear();
        lcd.print("Person In Room:");
        lcd.setCursor(0, 1);
        digitalWrite(led, HIGH);
        lcd.print(count);
        delay(1000);
    }
}