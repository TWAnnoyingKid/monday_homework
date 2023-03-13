#include <ESP8266WiFi.h>

const char* ssid = "ChinGuy";
const char* password = "rayed18340";
int ledpin=14;
int led2pin=16;
int led3pin=12;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  
  pinMode(ledpin, OUTPUT);    digitalWrite(ledpin, LOW);
  pinMode(led2pin, OUTPUT);   digitalWrite(led2pin, LOW);
  pinMode(led3pin, OUTPUT);   digitalWrite(led3pin, LOW);

  Serial.println();
  Serial.print("Connecting To ");
  Serial.print(ssid);
  WiFi.begin(ssid,password);
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
    digitalWrite(ledpin, HIGH);
    Serial.println("LED1 ON");
  }
  if (request.indexOf("/LED1=OFF") != -1){
    digitalWrite(ledpin, LOW);
    Serial.println("LED1 OFF");
  }
  if (request.indexOf("/LED1=Three") != -1){
    digitalWrite(ledpin, HIGH);
    Serial.println("LED1 ON");
    delay(500);
    digitalWrite(ledpin, LOW);
    Serial.println("LED1 OFF");
    delay(500);
    digitalWrite(ledpin, HIGH);
    Serial.println("LED1 ON");
    delay(500);
    digitalWrite(ledpin, LOW);
    Serial.println("LED1 OFF");
    delay(500);
    digitalWrite(ledpin, HIGH);
    Serial.println("LED1 ON");
    delay(500);
    digitalWrite(ledpin, LOW);
    Serial.println("LED1 OFF");
    delay(500);
  }
  if (request.indexOf("/LED2=ON") != -1){
    digitalWrite(led2pin, HIGH);
    Serial.println("LED2 ON");
  }
  if (request.indexOf("/LED2=OFF") != -1){
    digitalWrite(led2pin, LOW);
    Serial.println("LED2 OFF");
  }
  if (request.indexOf("/LED2=Three") != -1){
    digitalWrite(led2pin, HIGH);
    Serial.println("LED2 ON");
    delay(500);
    digitalWrite(led2pin, LOW);
    Serial.println("LED2 OFF");
    delay(500);
    digitalWrite(led2pin, HIGH);
    Serial.println("LED2 ON");
    delay(500);
    digitalWrite(led2pin, LOW);
    Serial.println("LED2 OFF");
    delay(500);
    digitalWrite(led2pin, HIGH);
    Serial.println("LED2 ON");
    delay(500);
    digitalWrite(led2pin, LOW);
    Serial.println("LED2 OFF");
    delay(500);
  }
  if (request.indexOf("/LED3=ON") != -1){
    digitalWrite(led3pin, HIGH);
    Serial.println("LED3 ON");
  }
  if (request.indexOf("/LED3=OFF") != -1){
    digitalWrite(led3pin, LOW);
    Serial.println("LED3 OFF");
  }
  if (request.indexOf("/LED3=Three") != -1){
    digitalWrite(led3pin, HIGH);
    Serial.println("LED3 ON");
    delay(500);
    digitalWrite(led3pin, LOW);
    Serial.println("LED3 OFF");
    delay(500);
    digitalWrite(led3pin, HIGH);
    Serial.println("LED3 ON");
    delay(500);
    digitalWrite(led3pin, LOW);
    Serial.println("LED3 OFF");
    delay(500);
    digitalWrite(led3pin, HIGH);
    Serial.println("LED3 ON");
    delay(500);
    digitalWrite(led3pin, LOW);
    Serial.println("LED3 OFF");
    delay(500);
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
  }
  else if(request.indexOf("/LED1=OFF") != -1){
    Client.print("LED1 OFF");
  }
  else if(request.indexOf("/LED1=Three") != -1){
    Client.print("LED1 3");
  }
  else if(request.indexOf("/LED2=ON") != -1){
    Client.print("LED2 ON");
  }
  else if(request.indexOf("/LED2=OFF") != -1){
    Client.print("LED2 OFF");
  }
  else if(request.indexOf("/LED2=Three") != -1){
    Client.print("LED2 3");
  }
  else if(request.indexOf("/LED3=ON") != -1){
    Client.print("LED3 ON");
  }
  else if(request.indexOf("/LED3=OFF") != -1){
    Client.print("LED3 OFF");
  }
  else if(request.indexOf("/LED3=Three") != -1){
    Client.print("LED3 3");
  }
  else{
    Client.print("");
  }

  Client.println("<!DOCTYPE html><html>");
  Client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
  Client.println("<link rel=\"icon\" href=\"data:,\">");
  
  Client.println("<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}");
  Client.println(".button { background-color: #195B6A; border: none; color: white; padding: 16px 40px;");
  Client.println("text-decoration: none; font-size: 30px; margin: 2px; cursor: pointer;}");
  Client.println(".button2 {background-color: #77878A;}</style></head>");

  Client.println("<a href=\"/LED1=ON\"><button>LED1 ON</button></a>");
  Client.println("<a href=\"/LED1=OFF\"><button>LED1 OFF</button></a>");
  Client.println("<a href=\"/LED1=Three\"><button>LED1 3</button></a><br />");
  Client.println("<br>");
  Client.println("<a href=\"/LED2=ON\"><button>LED2 ON</button></a>");
  Client.println("<a href=\"/LED2=OFF\"><button>LED2 OFF</button></a>");
  Client.println("<a href=\"/LED2=Three\"><button>LED2 3</button></a><br />");
  Client.println("<br>");
  Client.println("<a href=\"/LED3=ON\"><button>LED3 ON</button></a>");
  Client.println("<a href=\"/LED3=OFF\"><button>LED3 OFF</button></a>");
  Client.println("<a href=\"/LED3=Three\"><button>LED3 3</button></a><br />");
  Client.println("<br>");
  Client.println("<img src=\"https://www.stu.edu.tw/images/stulogo2.png\" width=250, height=200>");
  Client.println("<br>");
  Client.println("<電通三甲>");
  Client.println("<br>");
  Client.println("<20115117>");
  Client.println("<br>");
  Client.println("<白簡銘>");
  Client.println("<br>");
  Client.println("</html>");
  
  delay(1);
  Serial.print("Client disconnected");
  Serial.print(" ");
}
