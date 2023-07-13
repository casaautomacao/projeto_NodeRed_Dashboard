void roda_desligado()
{
  for (int i = 0; i < 4; i++)
  {
    digitalWrite(saidaOnBoard[i], 0);
    //   delay(35);
  }


  for (int i = 9; i < 16; i++)
  {
    gpio.digitalWrite(i, 0); // LED Off
    // delay(20);

  }


  for (int i = 9; i < 16; i++)
  {
    gpio2.digitalWrite(i, 0); // LED Off
    // delay(20);

  }

}
