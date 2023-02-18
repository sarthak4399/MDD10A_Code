#define dir_1 4
#define pwm_1 5
#define dir_2 6
#define pwm_2 7
#define dir_3 8
#define pwm_3 9
#define dir_4 10
#define pwm_4 11
void setup() {
  // put your setup code here, to run once:
  pinMode(pwm_1, OUTPUT);
  pinMode(pwm_2, OUTPUT);
  pinMode(dir_1, OUTPUT);
  pinMode(dir_2, OUTPUT);
  pinMode(pwm_3, OUTPUT);
  pinMode(pwm_3, OUTPUT);
  pinMode(dir_4, OUTPUT);
  pinMode(dir_4, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
  FORWARD_1MIN();
  FORWARD_NEXT1MIN();
  int pwm_value;
  // for loop  automatic switching operation of voltage
  for (pwm_value = 0; pwm_value <= 255; pwm_value++) {
    digitalWrite(dir_1, HIGH);
    digitalWrite(dir_2, HIGH);
    digitalWrite(dir_3, HIGH);
    digitalWrite(dir_4, HIGH);
    analogWrite(pwm_1, pwm_value);
    analogWrite(pwm_2, pwm_value);
    analogWrite(pwm_3, pwm_value);
    analogWrite(pwm_4, pwm_value);
    Serial.println(pwm_value);
    delay(500);
  }
  for (pwm_value = 255; pwm_value >= 0; pwm_value--) {
    digitalWrite(dir_1, HIGH);
    digitalWrite(dir_2, HIGH);
    digitalWrite(dir_3, HIGH);
    digitalWrite(dir_4, HIGH);
    analogWrite(pwm_1, pwm_value);
    analogWrite(pwm_2, pwm_value);
    analogWrite(pwm_3, pwm_value);
    analogWrite(pwm_4, pwm_value);
    Serial.println(pwm_value);
    delay(500);
  }
}
// for one minute half pwm value 127.5
void FORWARD_1MIN() {
  digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);

  analogWrite(pwm_1, 127.5);
  analogWrite(pwm_2, 127.5);
  analogWrite(pwm_3, 127.5);
  analogWrite(pwm_4, 127.5);
  Serial.println("FIRst 1 min ");
  delay(60000);
}
// for  next one minute full pwm value 255
void FORWARD_NEXT1MIN() {
  digitalWrite(dir_1, HIGH);
  digitalWrite(dir_2, HIGH);
  digitalWrite(dir_3, HIGH);
  digitalWrite(dir_4, HIGH);
  analogWrite(pwm_1, 255);
  analogWrite(pwm_2, 255);
  analogWrite(pwm_3, 255);
  analogWrite(pwm_4, 255);
  Serial.println("NEXT 1 min ");
  delay(60000);
}
