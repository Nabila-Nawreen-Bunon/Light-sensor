// C++ code
//
int lP = A0; // Pin for the light sensor
int LEDP = 9; // Pin for the LED
float light;

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 baud
  pinMode(lP, INPUT); // Set light sensor pin as input
  pinMode(LEDP, OUTPUT); // Set LED pin as output
}

void loop() {
  int light_value = analogRead(lP); // Read the analog value from the light sensor
  light = light_value * (5.0 / 1023.0); // Convert the analog value to voltage (assuming a 5V reference)
  Serial.println(light); // Print the light intensity to the serial monitor
  delay(1000); // Wait for 1 second

  if (light > 0.5&&light<1.0) { // Threshold value for the light sensor
    analogWrite(LEDP, 50); // Turn on the LED
  } else if(light>1.0&&light<2.3) {
    analogWrite(LEDP, 100); // Turn off the LED
  }else if(light>2.3){
    analogWrite(LEDP,255);
  }
}