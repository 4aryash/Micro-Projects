#include <WiFi.h>
#include <TFT_eSPI.h>
#include <ESPAsyncWebServer.h>
#include <AsyncTCP.h>

/////////////////////////////// EDIT THESE BEFORE RUNNING THE CODE ///////////////////////////////
const char* ssid = "insert-ssid-here";
const char* password = "insert-password-here";
/////////////////////////////////////////////////////////////////////////////////////////////////

TFT_eSPI tft = TFT_eSPI();
AsyncWebServer server(80);

// Button pins
const int buttonPin1 = 35; // S1
const int buttonPin2 = 0;  // S2

int totalNetworks = 0;
int currentPosition = 0;
int networksPerPage = 5;

void setup() {
  Serial.begin(115200);
  tft.init();
  tft.setRotation(1);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_GREEN, TFT_BLACK);
  tft.setTextSize(1.5);

  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);

  WiFi.begin(ssid, password);

  tft.println("Connecting to WiFi...\n");
  delay(5000);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  tft.println("Connected!\n\n");
  tft.println("IP address: ");
  tft.println(WiFi.localIP());

  server.on("/scan", HTTP_GET, [](AsyncWebServerRequest *request){
    String json = "[";
    int n = WiFi.scanNetworks();
    for (int i = 0; i < n; ++i) {
      if (i) json += ",";
      json += "{";
      json += "\"ssid\":\"" + WiFi.SSID(i) + "\"";
      json += ",\"rssi\":" + String(WiFi.RSSI(i));
      json += ",\"bssid\":\"" + WiFi.BSSIDstr(i) + "\"";
      json += "}";
    }
    json += "]";
    request->send(200, "application/json", json);
  });

  server.begin();
}

void loop() {
  // Check if buttons are pressed
  if (digitalRead(buttonPin1) == LOW) {
    currentPosition -= networksPerPage;
    if (currentPosition < 0) currentPosition = 0;
    displayNetworks();
    delay(200); // Debounce delay
  }
  
  if (digitalRead(buttonPin2) == LOW) {
    currentPosition += networksPerPage;
    if (currentPosition >= totalNetworks) currentPosition = totalNetworks - networksPerPage;
    displayNetworks();
    delay(200); // Debounce delay
  }
  
  // Update the network list every 30 seconds
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 30000) {
    lastUpdate = millis();
    updateNetworkList();
  }
}

void updateNetworkList() {
  totalNetworks = WiFi.scanNetworks();
  currentPosition = 0; // Reset position
  displayNetworks();
}

void displayNetworks() {
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(0, 0);
  tft.printf("Devices: %d\n\n", totalNetworks);

  for (int i = currentPosition; i < currentPosition + networksPerPage && i < totalNetworks; ++i) {
    tft.printf("SSID: %s\n", WiFi.SSID(i).c_str());
    tft.printf("RSSI: %d\n", WiFi.RSSI(i));
    tft.printf("BSSID: %s\n", WiFi.BSSIDstr(i).c_str());
    tft.println("");
  }
}
