#include <WiFi.h>
#include <WebServer.h>

/*Put your SSID & Password*/
const char* ssid = "wifi_name";  // Enter SSID here
const char* password = "password";  //Enter Password here

WebServer server(80);             
 
void setup() {
  Serial.begin(115200);
  delay(100);
  Serial.println("Connecting to ");
  Serial.println(ssid);


  // Initialize WiFi connection
  /* Add code here */
Wifi.begin(ssid,password);
  // Check for WiFi connection status in a while loop
  // Once connected, print the IP address to Serial Monitor
  /* Add code here */
  while (WIFI.status() !=WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
Serial.println("");
Serial.println("WiFi connected..!");
Serial.print ("Got IP: ");
Serial.println(WiFi.localIP());

  // Intialize the server code to call its respective functions.
  server.on("/", handle_OnConnect);
  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}

// Serve the HTML file once connection between client and server is established.
// In send() function, parameter 1 refers to the HTTP response code.
// 200 response code means the request is a success.
void handle_OnConnect() {
  server.send(200, "text/html", SendHTML()); 
}

// 404 response code means failure to find requested source or missing resource.
void handle_NotFound(){
  server.send(404, "text/plain", "Not found");
}

// Use this web page code as a template
String SendHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP32 Hello World</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>Hello World !!</h1>\n";
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
