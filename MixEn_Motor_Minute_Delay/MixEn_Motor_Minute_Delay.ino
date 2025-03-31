#define SECOND 1000UL
#define MINUTE (SECOND * 60UL)

int IN1 = 2;
int IN2 = 3;
int LED = 13;

void motor_turn_cw(int minute){
  Serial.println("Motor Turn CW");
  digitalWrite(LED, HIGH);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(MINUTE * minute);   
}

void motor_turn_ccw(int minute){
  Serial.println("Motor Turn CCW");
  digitalWrite(LED, HIGH);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(MINUTE * minute);   
}

void motor_stop(int minute){
  Serial.println("Motor Stop"); 
  digitalWrite(LED, LOW);  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  delay(MINUTE * minute);
}

void setup() {           
  Serial.begin(115200);     
  pinMode(LED, OUTPUT); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void loop() {
  motor_turn_cw(15); 
  motor_stop(5); 
  motor_turn_ccw(15);  
  motor_stop(5);    
}
