


void Task1code( void * pvParameters ) {





  for (;;) {

    vTaskDelay(1);





/*

    status_1 = 1 - digitalRead(39);


    if (status_1 != status_1_old)
    {
      if (status_1 == 1)
      {
        seta1 = 1 - seta1;
      }

      status_1_old = status_1;
    }

*/


/*
    int status_2 = 1 - digitalRead(34);


    if (status_2 == 1)
    {

      ESP.restart();
    }

*/













    if (!client.connected()) {
      reconnect();
    }


     if (client.connected()) client.loop();





    unsigned long now = millis();
    if (now - lastMsg > 500) {


      lastMsg = now;


      unsigned int read_value = 0;

      int imprimir;


      for (int x = 0; x < 8; x++) {                   // Loops from 0 to 7

        read_value = adc.read(x, SD);                 // Read value of ADC channel x (0 to 7) in Single-ended mode
        //  voltage = read_value * (vref / 4095.0);       // Calculate voltage output value according to the voltage reference and resolution
        if (x == 0) imprimir = read_value;
        // Serial.print("Channel ");                 // Prints...
        //  Serial.print(x);                          // Prints channel number
        //  Serial.print(": ");                       // Prints...
        //   Serial.print(read_value);                 // Prints value read from ADC   //    + x*30
        //   Serial.print(",");                       // Prints...
        //  Serial.print(voltage,0);                  // Prints value of DAC output voltage on channel 0 to serial monitor
        // Serial.println(" mV)");                   // Prints...
      }







      snprintf (msg, MSG_BUFFER_SIZE, "%ld", imprimir);
      Serial.print("Publish message: ");
      Serial.println(msg);
   
      
      
     if (client.connected())   client.publish("topico/analogico1/", msg);


    }







  }


}
