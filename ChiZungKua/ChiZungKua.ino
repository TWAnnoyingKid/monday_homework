#include <ESP8266WiFi.h>

const char* ssid = "ChinGuy";
const char* password = "rayed18340";
const int Vr = A0;
int RW = 0;
const int led1 = D1;
const int led2 = D2;
const int led3 = D3;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  pinMode(led1, OUTPUT); digitalWrite(led1,LOW);
  pinMode(led2, OUTPUT); digitalWrite(led2,LOW);
  pinMode(led3, OUTPUT); digitalWrite(led3,LOW);
  pinMode(Vr,INPUT);

  Serial.println();
  Serial.print("Connecting To ");
  Serial.print(ssid);
  WiFi.begin("ChinGuy","rayed18340");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop(){
  RW = analogRead(Vr);
  if(RW >= 300){
    for(int i = 0; i <3 ; i++){
      digitalWrite(led1, !digitalRead(led1));
      digitalWrite(led2, !digitalRead(led2));
      digitalWrite(led3, !digitalRead(led3));
      delay(500);
    }
  }
  Serial.println(RW);
  delay(100);
  
  WiFiClient Client = server.available();   
  if(!Client){
    return;
  }

  Serial.println("new Client");
  while(!Client.available()){
    delay(1);
  }

  String request = Client.readStringUntil('\r');
  Serial.println(request);
  Client.flush();

  if (request.indexOf("/LED1=ON") != -1){
    digitalWrite(led1, HIGH);
    Serial.println("LED1 ON");
  }
  if (request.indexOf("/LED1=OFF") != -1){
    digitalWrite(led1, LOW);
    Serial.println("LED1 OFF");
  }
  if (request.indexOf("/LED2=ON") != -1){
    digitalWrite(led2, HIGH);
    Serial.println("LED2 ON");
  }
  if (request.indexOf("/LED2=OFF") != -1){
    digitalWrite(led2, LOW);
    Serial.println("LED2 OFF");
  }
  if (request.indexOf("/LED3=ON") != -1){
    digitalWrite(led3, HIGH);
    Serial.println("LED3 ON");
  }
  if (request.indexOf("/LED3=OFF") != -1){
    digitalWrite(led3, LOW);
    Serial.println("LED3 OFF");
  }

  
  
  Client.println("HTTP/1.1 200 OK");
  Client.println("Connect-Type: text/html");
  Client.println("");
  Client.println("<!DOCTYPE HTML>");
  Client.println("<html>");
  Client.println("<meta charset=utf-8>");

  Client.println("Led pin is now: ");
  if(request.indexOf("/LED1=ON") != -1){
    Client.print("LED1 ON");
    Client.println("<br>");
  }
  else if(request.indexOf("/LED1=OFF") != -1){
    Client.print("LED1 OFF");
    Client.println("<br>");
  }
  else if(request.indexOf("/LED2=ON") != -1){
    Client.print("LED2 ON");
    Client.println("<br>");
  }
  else if(request.indexOf("/LED2=OFF") != -1){
    Client.print("LED2 OFF");
    Client.println("<br>");
  }
  else if(request.indexOf("/LED3=ON") != -1){
    Client.print("LED3 ON");
    Client.println("<br>");
  }
  else if(request.indexOf("/LED3=OFF") != -1){
    Client.print("LED3 OFF");
    Client.println("<br>");
  }
  else{
    Client.println("<br>");
  }

  Client.println("<!DOCTYPE html><html>");
  Client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  Client.println("<link rel=\"icon\" href=\"data:,\">");
  
  Client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  Client.println(".button { background-color: #195B6A; border: none; color: white; padding: 32px 80px;");
  Client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
  Client.println(".button2 {background-color: #77878A;}</style></head>");

  Client.println("<a href=\"/LED1=ON\"><button>LED1 ON</button></a>");
  Client.println("<a href=\"/LED1=OFF\"><button>LED1 OFF</button></a>");
  Client.println("<br>");
  Client.println("<a href=\"/LED2=ON\"><button>LED2 ON</button></a>");
  Client.println("<a href=\"/LED2=OFF\"><button>LED2 OFF</button></a>");
  Client.println("<br>");
  Client.println("<a href=\"/LED3=ON\"><button>LED3 ON</button></a>");
  Client.println("<a href=\"/LED3=OFF\"><button>LED3 OFF</button></a>");
  Client.println("<br>");
  Client.println("<body>");
  Client.println("<br>");
  Client.println("<img src=\"https://drive.google.com/uc?export=view&id=1A_NNg0k2vYxugT8BypAny8px19iEXbFG\" width=250, height=250>");
  Client.println("<br>");
  Client.println("<br>");
  Client.println("<電通三甲>");
  Client.println("<br>");
  Client.println("<20115117>");
  Client.println("<br>");
  Client.println("<白簡銘>");
  Client.println("<br>");
  Client.println("</body");
  Client.println("</html>");
  
  delay(1);
  Serial.print("Client disconnected");
  Serial.print(" ");
}
