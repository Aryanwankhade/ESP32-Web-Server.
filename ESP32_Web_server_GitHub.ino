#include <WiFi.h>

const char* ssid = "Enter Your WIFI NAME";
const char* password = "Enter your WIFI PASSWORD";

WiFiServer server(80);

const int gpio26 = 26;
const int gpio27 = 27;

void setup() {
  Serial.begin(115200);
  pinMode(gpio26, OUTPUT);
  pinMode(gpio27, OUTPUT);
  digitalWrite(gpio26, LOW);
  digitalWrite(gpio27, LOW);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    if (request.indexOf("/ON26") != -1) digitalWrite(gpio26, HIGH);
    if (request.indexOf("/OFF26") != -1) digitalWrite(gpio26, LOW);
    if (request.indexOf("/ON27") != -1) digitalWrite(gpio27, HIGH);
    if (request.indexOf("/OFF27") != -1) digitalWrite(gpio27, LOW);

    bool state26 = digitalRead(gpio26);
    bool state27 = digitalRead(gpio27);

    client.println("HTTP/1.1 200 OK");
    client.println("Content-type:text/html");
    client.println();

    // Begin HTML
    client.println("<!DOCTYPE html><html>");
    client.println("<head>");
    client.println("<link href=\"https://fonts.googleapis.com/css2?family=Aclonica&family=Alfa+Slab+One&family=Atma&family=Tiro+Devanagari+Sanskrit&display=swap\" rel=\"stylesheet\">");
    client.println("<style>");
    client.println("html { font-family: Arial; text-align: center; margin: 10px; }");
    client.print("body { transition: background-color 0.5s ease; ");
    if (state26 || state27) client.println("background-color: #f5fff5; }");
    else client.println("background-color: white; }");

    client.println("h1 { font-family: 'Courier New', monospace; font-size: 32px; }");
    client.println("<link href='https://fonts.googleapis.com/css?family=Aboreto' rel='stylesheet'>");
    client.println("h2 { font-family: 'Brush Script MT', cursive; font-size: 32px; }");
    client.println(".gpio26 { font-family: 'Atma', cursive; font-size: 24px; margin: 10px 0; }");
    client.println(".gpio27 { font-family: 'Atma', cursive; font-size: 24px; margin: 10px 0; }");

    client.println(".button { font-family: 'Aclonica', sans-serif; border: none; color: white; padding: 16px 40px;");
    client.println("text-decoration: none; font-size: 30px; margin: 10px; cursor: pointer; border-radius: 25px;");
    client.println("transition: all 0.3s ease-in-out; }");

    client.println(".on { background-color: #4CAF50; }");
    client.println(".off { background-color: #ff0000; }");

    client.println(".active { box-shadow: 0 0 20px rgba(0,255,0,0.7); filter: brightness(1.1); }");
    client.println("</style>");
    client.println("</head><body>");

    client.println("<h1>ESP32 Web Server</h1>");
     client.println("<h2>Created By : Aryan Wankhade. </h2>");

    client.println("<div class='gpio26'>GPIO 26 - State " + String(state26 ? "ON" : "OFF") + "</div>");
    client.print("<button class='button on");
    if (state26) client.print(" active");
    client.println("' onclick=\"location.href='/ON26'\">ON</button>");

    client.print("<button class='button off");
    if (!state26) client.print(" active");
    client.println("' onclick=\"location.href='/OFF26'\">OFF</button>");

    client.println("<div class='gpio27'>GPIO 27 - State " + String(state27 ? "ON" : "OFF") + "</div>");
    client.print("<button class='button on");
    if (state27) client.print(" active");
    client.println("' onclick=\"location.href='/ON27'\">ON</button>");

    client.print("<button class='button off");
    if (!state27) client.print(" active");
    client.println("' onclick=\"location.href='/OFF27'\">OFF</button>");

    client.println("</body></html>");
    client.stop();
  }
}
