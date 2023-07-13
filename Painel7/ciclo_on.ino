
String acum2 = "";

void roda_ligado()
{

  buscaHora();


  lcd.clear();

  lcd.backlight();
  String teste = "CRESCER " + acum2;
  lcd.print(teste);
  lcd.setCursor(0, 1);
  lcd.print("   PLC 32 I2C   ");


  for (int i = 0; i < 4; i++)
  {
    digitalWrite(saidaOnBoard[i], 1);
    delay(35);
  }


  for (int i = 9; i < 16; i++)
  {
    gpio.digitalWrite(i, 1); // LED Off
    delay(20);

  }


  for (int i = 9; i < 16; i++)
  {
    gpio2.digitalWrite(i, 1); // LED Off
    delay(20);

  }



  delay(500);



  for (int i = 0; i < 4; i++)
  {
    digitalWrite(saidaOnBoard[i], 0);
    delay(35);
  }


  for (int i = 9; i < 16; i++)
  {


    gpio.digitalWrite(i, 0); // LED Off
    delay(20);
  }




  for (int i = 9; i < 16; i++)
  {


    gpio2.digitalWrite(i, 0); // LED Off
    delay(20);
  }

  lcd.noBacklight();

  delay(200);




  for (int i = 0; i < 4; i++)
  {
    digitalWrite(saidaOnBoard[i], 1);
    // delay(20);
  }



  for (int i = 9; i < 16; i++)
  {
    gpio.digitalWrite(i, 1); // LED Off
    //  delay(20);

  }


  for (int i = 9; i < 16; i++)
  {
    gpio2.digitalWrite(i, 1); // LED Off
    //  delay(20);

  }



  delay(500);



  for (int i = 0; i < 4; i++)
  {
    digitalWrite(saidaOnBoard[i], 0);
    //   delay(20);
  }

  for (int i = 9; i < 16; i++)
  {


    gpio.digitalWrite(i, 0); // LED Off
    //   delay(20);
  }


  for (int i = 9; i < 16; i++)
  {


    gpio2.digitalWrite(i, 0); // LED Off
    //   delay(20);
  }


  delay(200);




}
