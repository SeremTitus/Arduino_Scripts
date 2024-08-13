#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

void setup() {
  //lcd.init();
  lcd.clear();
  lcd.backlight();
  
  lcd.setCursor(2,0);
  lcd.print("Hello world!");
  
  lcd.setCursor(2,1);
  lcd.print("Embeded Systems");
}

void loop() {
    delay(1000);
    lcd.clear(); 
    const char* texts[] = {
          "Hello!",
          "How are you?",
          "What's up?",
          "Nice to meet you!",
          "Have a great day!",
          "Goodbye!"
      };
    int numTexts = sizeof(texts) / sizeof(texts[0]);
    int randomIndex = rand() % numTexts;
    lcd.setCursor(0,1);
    lcd.print(texts[randomIndex]);
}