int steeringPin = 2; // Replace with the actual pin number for steering
int triggerPin = 3; // Replace with the actual pin number for trigger

float lastSteeringValue = 0.5; // Initialize with neutral value
float lastTriggerValue = 0.5; // Initialize with neutral value

void setup() {
  pinMode(steeringPin, INPUT);
  pinMode(triggerPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  int steeringPulse = pulseIn(steeringPin, HIGH);
  int triggerPulse = pulseIn(triggerPin, HIGH);

  // Update and map steering value if valid
  if(steeringPulse >= 900 && steeringPulse <= 2100) {
    lastSteeringValue = map(steeringPulse, 1000, 2000, 0, 1000) / 1000.0;
    lastSteeringValue = constrain(lastSteeringValue, 0, 1);
  }

  // Update and map trigger value if valid
  if(triggerPulse >= 900 && triggerPulse <= 2100) {
    lastTriggerValue = map(triggerPulse, 1000, 2000, 0, 1000) / 1000.0;
    lastTriggerValue = constrain(lastTriggerValue, 0, 1);
  }

  // Print values to serial
  Serial.print("Steering: ");
  Serial.print(lastSteeringValue);
  Serial.print("\tTrigger: ");
  Serial.println(lastTriggerValue);

  delay(20); // Adjust delay as needed
}
