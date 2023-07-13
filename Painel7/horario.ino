void buscaHora()
{
  DateTime now = rtc.now();
  String acum = "";
  acum2 = "";

  acum += String(now.day(), DEC);
  acum += String('/');
  acum += String(now.month(), DEC);
  acum += String('/');
  acum += String(now.year() - 2000, DEC);
  acum += String("  ");

  acum2 += String(now.hour(), DEC);
  acum2 += String(':');
  acum2 += String(now.minute(), DEC);
  acum2 += String(':');
  acum2 += String(now.second(), DEC);
  acum += acum2;

  Serial.println(acum);



  display.clear();


  display.drawXbm(0 , 16, WiFi_Logo_width2, WiFi_Logo_height2, WiFi_Logo_bits2); //16



  display.setFont(ArialMT_Plain_16);
  display.drawString(2, 0 , acum);
  display.display();

}
