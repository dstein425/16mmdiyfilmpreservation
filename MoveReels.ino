#define MOTOR_ONE_DIRECTION_PIN 4
#define MOTOR_ONE_STEP_PIN 5

#define MOTOR_TWO_DIRECTION_PIN 2
#define MOTOR_TWO_STEP_PIN 3

#define STEPS_PER_REVOLUTION 3200

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(MOTOR_ONE_DIRECTION_PIN, OUTPUT);
  pinMode(MOTOR_ONE_STEP_PIN, OUTPUT);
  pinMode(MOTOR_TWO_DIRECTION_PIN, OUTPUT);
  pinMode(MOTOR_TWO_STEP_PIN, OUTPUT);
}


void move_motor(int direction_pin, int step_pin, int steps_per_revolution){
  for(int i = 0; i < steps_per_revolution; i++){
        digitalWrite(direction_pin, HIGH);
        digitalWrite(step_pin, HIGH);
        delayMicroseconds(500);
        digitalWrite(step_pin, LOW);
        delayMicroseconds(500);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0){
    String data = Serial.readStringUntil('\n');
    if(data.toInt() == 1){
      move_motor(MOTOR_ONE_DIRECTION_PIN, MOTOR_ONE_STEP_PIN, STEPS_PER_REVOLUTION);
      Serial.println("Take up film");
    } else if(data.toInt() == 2){
      move_motor(MOTOR_TWO_DIRECTION_PIN, MOTOR_TWO_STEP_PIN, STEPS_PER_REVOLUTION);
      Serial.println("Take picture");
    }
  }
}
