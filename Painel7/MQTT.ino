

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  int posicao;
  String trabalhoS = topic;

  if (trabalhoS.indexOf("rel") > -1)
  {
    if (trabalhoS.indexOf("rel0") > -1) posicao = 0;
    else if (trabalhoS.indexOf("rel1") > -1) posicao = 1;
    else if (trabalhoS.indexOf("rel2") > -1) posicao = 2;
    else if (trabalhoS.indexOf("rel3") > -1) posicao = 3;


    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {  //*****************************************************************************************
      digitalWrite(saidaOnBoard[posicao], LOW);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      digitalWrite(saidaOnBoard[posicao], HIGH);  // Turn the LED off by making the voltage HIGH
    }

  }

  if (trabalhoS.indexOf("pca") > -1)
  {
    if (trabalhoS.indexOf("pca9") > -1) posicao = 9;
    else if (trabalhoS.indexOf("pca10") > -1) posicao = 10;
    else if (trabalhoS.indexOf("pca11") > -1) posicao = 11;
    else if (trabalhoS.indexOf("pca12") > -1) posicao = 12;
    else if (trabalhoS.indexOf("pca13") > -1) posicao = 13;
    else if (trabalhoS.indexOf("pca14") > -1) posicao = 14;
    else if (trabalhoS.indexOf("pca15") > -1) posicao = 15;

    // Switch on the LED if an 1 was received as first character
    if ((char)payload[0] == '0') {  //*****************************************************************************************
      gpio.digitalWrite(posicao, LOW);   // Turn the LED on (Note that LOW is the voltage level
      // but actually the LED is on; this is because
      // it is active low on the ESP-01)
    } else {
      gpio.digitalWrite(posicao, HIGH);  // Turn the LED off by making the voltage HIGH
    }

  }
}





int setaMqtt = 0;

void reconnect() {
  // Loop until we're reconnected
  if (!client.connected() and setaMqtt == 0) {
    setaMqtt = 1;
    Serial.println("Attempting MQTT connection...");
    // Create a random client ID
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("topico/analogico1/", 0);
      // ... and resubscribe
      client.subscribe("topico/rel0/");  //**************************************************************************************************************
      client.subscribe("topico/rel1/");
      client.subscribe("topico/rel2/");
      client.subscribe("topico/rel3/");
      client.subscribe("topico/pca9/");
      client.subscribe("topico/pca10/");
      client.subscribe("topico/pca11/");
      client.subscribe("topico/pca12/");
      client.subscribe("topico/pca13/");
      client.subscribe("topico/pca14/");
      client.subscribe("topico/pca15/");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      //  delay(5000);
    }
  }

  if (temp1.Saida(setaMqtt))
  {
    setaMqtt = 0;
  }


}
