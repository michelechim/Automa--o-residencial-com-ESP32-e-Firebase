#include <Arduino.h>

//Firebase Arduino Client Library for ESP8266 and ESP32@
#if defined(ESP32)
  #include <WiFi.h>
#elif defined(ESP8266)
  #include <ESP8266WiFi.h>
#endif
#include <Firebase_ESP_Client.h>

//Wi-fi
#define WIFI_SSID "Michele"
#define WIFI_PASSWORD "12041995chim"

//Firebase
#define API_KEY "AIzaSyBzixcxtHrjtprwHRzB_RVEv0fwR14gUMk"
#define DATABASE_URL "https://iot-tads-e0a53-default-rtdb.firebaseio.com" //a URL deve ser bem formada https://domínio/
//Variáveis globais para manipular o Firebase
FirebaseData fbdo; //Define Firebase Data object
FirebaseAuth auth; //Define Firebase Auth object
FirebaseConfig config; //Define Firebase Config object

//Led Azul embarcado na placa
#define LED_AZUL 2

//Inicializa o wifi
void wifiSetup(){
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();
}

//inicializa e authentica no Firebase
void firebaseSetup(){
  
  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  // Assign the user sign in credentials
  auth.user.email = "teste@teste.com";
  auth.user.password = "Teste123";

  // Initialize the library with the Firebase authentication and config
  Firebase.begin(&config, &auth);

  // Optional, set AP reconnection in setup()
  Firebase.reconnectWiFi(true);
}

void setup() {
  //inicializando o terminal
  Serial.begin(9600);
  //inicializa o Wifi e o Firebase
  Serial.println();
  Serial.println("Setup Wifi e Firebase");
  wifiSetup();
  firebaseSetup();
  pinMode(LED_AZUL,OUTPUT); //seta o pino 2 do led azul para output
}

//variávais globais para o loop
int count_int = 0;
int count_json = 0;

void loop() {
  delay(2000);
  if (Firebase.ready()){
    Serial.println("\nINICIANDO A CASA\n");

    //Lendo um Inteiro no RTDB
    Serial.println("Estado da /casa4/closet/lampada");
    //Lendo com get  
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/closet/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/cozinha/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/cozinha/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/estar/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/estar/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/estar/ar");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/estar/ar"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/garagem/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/garagem/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/jantar/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/jantar/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/jantar/ar");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/jantar/ar"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/quarto1/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/quarto1/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/quarto1/ar");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/quarto1/ar"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/quarto2/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/quarto2/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/quarto2/ar");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/quarto2/ar"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/servico/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/servico/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/suite/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/suite/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/suite/ar");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/suite/ar"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/varanda/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/varanda/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/wc/lampada");
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/wc/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("Estado da /casa4/wc2/lampada"); 
    Serial.printf("Get int... %s\n", Firebase.RTDB.getInt(&fbdo, F("/casa4/wc2/lampada"))
    ? String(fbdo.to<int>()).c_str() 
    : fbdo.errorReason().c_str());

    Serial.println("\nFIM DA CASA\n");
  
    //Liga ou desliga o Led Azul conforme o estado lido no Firebase
    fbdo.to<int>() == 0 
      ? digitalWrite(LED_AZUL,LOW) 
      : digitalWrite(LED_AZUL,HIGH);
  }
}