/*Change all the ? in the code and add code in ??? to Control 2 DC Motors.*/

#define IN1 26  // Replace the ? with the GPIO pin you selected to connect IN1
#define IN2 25   // Replace the ? with the GPIO pin you selected to connect IN2
#define AL  34 // Replace the ? with the GPIO pin you selected to connect encoder A of Motor L
#define BL  35 // Replace the ? with the GPIO pin you selected to connect encoder B of Motor L

#define IN3 14  // Replace the ? with the GPIO pin you selected to connect IN3
#define IN4 27   // Replace the ? with the GPIO pin you selected to connect IN4
#define AR 33 // Replace the ? with the GPIO pin you selected to connect encoder A of Motor R
#define BR 32 // Replace the ? with the GPIO pin you selected to connect encoder B of Motor R


int AL_data=0;
int BL_data=0;

int AR_data=0;
int BR_data=0;

String command;

void setup() {
  /*setup baud and pin mode */
  Serial.begin(115200); //Define baud

  pinMode(IN1, OUTPUT);  // Set IN1 as an output pin
  pinMode(IN2, OUTPUT);  // Set IN2 as an output pin
  pinMode(IN3, OUTPUT);  // Set IN1 as an output pin
  pinMode(IN4, OUTPUT);

  pinMode(AL, INPUT);  // Set A as an input pin
  pinMode(BL, INPUT);  // Set B as an input pin
  pinMode(AR, INPUT);  // Set A as an input pin
  pinMode(BR, INPUT); 
}

void loop() {
   
    if (Serial.available() > 0) {
        command = Serial.readStringUntil('\n'); // Read the incoming command
        command.trim(); // Remove any leading or trailing whitespace
    if (command == "F") 
    { 
      // Move forward 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH); 
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW); 
      } 
    else if (command == "B") 
    { // Move Backward 
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW); 
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH); 
      } 
    else if (command == "R") 
    { // Turn right 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH); 
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW); 
    } 
    else if (command == "L") { 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW); 
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW); 
   } 
  else if (command == "S") { 
    // Stop 
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW); 
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW); 
     } 
        }
    // Read values of A and B of both Motor L and R
    AL_data=digitalRead(AL);
    BL_data=digitalRead(BL);
    AR_data=digitalRead(AR);
    BR_data=digitalRead(BR);
    // Plot A and B of both Motor L and R in Serial Plotter
    Serial.print("AL:");
    Serial.print(AL_data);
    Serial.print(",");
    Serial.print("BL:");
    Serial.print(BL_data);
    Serial.print(",");
    Serial.print("AR:");
    Serial.print(AR_data);
    Serial.print(",");
    Serial.print("BR:");
    Serial.print(BR_data);
    Serial.println("\t"); 
    
}
