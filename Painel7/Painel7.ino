#include <WiFi.h>
#include <HTTPClient.h>

#include <ETH.h>
#include <Crescer.h>

//DEFINIÇÃO DOS PINOS PARA COMUNICAR COM A SHIELD ETHERNET ETH_LAN8720
// Pino do sinal de habilitação para o oscilador de cristal externo (-1 para desabilitar para fonte APLL interna)

// Tipo de Ethernet PHY
#define ETH_TYPE ETH_PHY_LAN8720
// Endereço I2C de Ethernet PHY (0 ou 1 para LAN8720)
#define ETH_ADDR 0
#define ETH_PHY_ADDR 1
// Pino do sinal de relógio I2C para Ethernet PHY

Tempora temp1;

#define ETH_CLK_MODE ETH_CLOCK_GPIO0_IN
//#define ETH_CLK_MODE ETH_CLOCK_GPIO15_IN
static bool eth_connected = false;



int seta1 = 0;

  int status_1 = 0;
  int status_1_old = 0;


  #include <PubSubClient.h>

  const char* mqtt_server = "192.168.100.105";

  WiFiClient espClient;
  PubSubClient client(espClient);
  unsigned long lastMsg = 0;
  #define MSG_BUFFER_SIZE  (50)
  char msg[MSG_BUFFER_SIZE];
  int value = 0;







#include "Wire.h"



TaskHandle_t Task1;
TaskHandle_t Task2;

#include <ADS7828.h>                  // Include ADS7828.h for TI ADS7828 functions

ADS7828 adc(0x48);






void IRAM_ATTR resetButton()
{
    ESP.restart();
}


void IRAM_ATTR ligaCiclo()
{

    status_1 = 1 - digitalRead(39);


    if (status_1 != status_1_old)
    {
      if (status_1 == 1)
      {
        seta1 = 1 - seta1;
      }

      status_1_old = status_1;
    }

  
}




void setup() {

  pinMode(39, INPUT);
  pinMode(34, INPUT);

  
attachInterrupt(39, ligaCiclo, FALLING);
attachInterrupt(34, resetButton, FALLING);


  Serial.begin(115200);

  WiFi.onEvent(WiFiEvent); //Executa a função de comunicação da Shield


  ETH.begin( 1 , 17, 14, 4 , ETH_PHY_LAN8720);

  temp1.defiSP(30000);

  Wire.begin(16, 5);


  scanI2C();

  adc.init(INT);

  //vTaskDelay(100);


  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
    Task1code,   /* Task function. */
    "Task1",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task1,      /* Task handle to keep track of created task */
    1);          /* pin task to core 0 */
  // delay(500);

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
    Task2code,   /* Task function. */
    "Task2",     /* name of task. */
    10000,       /* Stack size of task */
    NULL,        /* parameter of the task */
    1,           /* priority of the task */
    &Task2,      /* Task handle to keep track of created task */
    0);          /* pin task to core 1 */




  client.setServer(mqtt_server, 1883);
   client.setCallback(callback);




}

void loop() {

}
