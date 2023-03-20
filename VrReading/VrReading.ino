#include <ESP8266WiFi.h>

const char* ssid = "ChinGuy";
const char* password = "rayed18340";
const int Vr = A0;
int RW = 0;
WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  
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

  RW = analogRead(Vr);
  Serial.println(RW);
  delay(1000);
  
  Client.println("HTTP/1.1 200 OK");
  Client.println("Connect-Type: text/html");
  Client.println("");
  Client.println("<!DOCTYPE HTML>");
  Client.println("<html>");
  Client.println("<head><meta charset=utf-8></meta>");
  Client.println("<meta http-equiv=\"Refresh\"content=20></meta>");

  Client.println("<title> 20115117 </title>");
  Client.println("</head>");

  Client.println("<body>");
  Client.println("<br>");
  Client.println("<img src=\"https://drive.google.com/uc?export=view&id=1A_NNg0k2vYxugT8BypAny8px19iEXbFG\" width=250, height=250>");
  Client.println("<br>");
  Client.println("目前可變電阻數值：");
  Client.println(RW);
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
