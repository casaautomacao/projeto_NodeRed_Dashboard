
#include "RTClib.h"

RTC_PCF8563 rtc;




#include "SSD1306Wire.h"  // alias for `#include "SSD1306Wire.h"`
#include "images.h"
// Initialize the OLED display using Wire library
SSD1306Wire display(0x3c); // 21 sda  22 scl





#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);




#include "PCAL9535A.h"

int saidaOnBoard[4] = {13, 12, 15, 18};

PCAL9535A::PCAL9535A<TwoWire> gpio(Wire);
PCAL9535A::PCAL9535A<TwoWire> gpio2(Wire);


void Task2code( void * pvParameters ) {


  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  rtc.start();










  display.init();
  display.clear();


  display.flipScreenVertically();




  lcd.begin();

  gpio.begin(PCAL9535A::HardwareAddress::A000);  // 0x20 - Pins = 000



  for (int i = 9; i < 16; i++)
  {
    //   gpio.digitalWrite(i, 0);
    gpio.pinMode(i, OUTPUT);
    gpio.digitalWrite(i, 0);

  }

  gpio2.begin(PCAL9535A::HardwareAddress::A001);  // 0x21 - Pins = 001



  for (int i = 9; i < 16; i++)
  {
    //   gpio.digitalWrite(i, 0);
    gpio2.pinMode(i, OUTPUT);
    gpio2.digitalWrite(i, 0);

  }

  for (int i = 0; i < 4; i++)
  {
    pinMode(saidaOnBoard[i], OUTPUT);
  }



  int seta2 = 0;

  for (;;) {

    vTaskDelay(1);




    if (seta1 == 1)
    {

      roda_ligado();

      seta2 = 0;
    }

    else if (seta2 == 0)
    {
      seta2 = 1;
      roda_desligado();
    }



  }
}
