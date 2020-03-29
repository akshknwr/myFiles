// including the library to interact with DHT22 sensor
#include <Adafruit_DHT.h>




#define DHTPIN A4    //  pin we're connected in Argon


#define DHTTYPE DHT22	// type of DHT sensor



int led = D7; // declarig pin value for led




DHT dht(DHTPIN, DHTTYPE); 

void setup() {
 pinMode(led, OUTPUT);
 dht.begin(); //initialising dht sensor
    
 
}

void loop() {
    

	
     digitalWrite(led, HIGH);  //turning led on
	// Read temperature as Celsius
	float t = dht.getTempCelcius();
	sendData(t); // sending data to Particle
  digitalWrite(led, LOW);    // Turn OFF the LED
  delay(30000);               // Wait for 30 seconds
    
}
void sendData(float t){
    	String tempstring= String(t); //converting float to string to avoid data conversion error
	  Particle.publish("temp", tempstring, PRIVATE);
    
}

