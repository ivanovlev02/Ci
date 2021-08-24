byte PIN_ENA = 9;
byte PIN_IN1 = 7;
byte PIN_IN2 = 6;
byte PIN_IN3 = 5;
byte PIN_IN4 = 4;
byte PIN_ENB = 3;

#define ir_1 A0
#define ir_2 A1
#define ir_3 A2
#define ir_4 A3
#define micro A5
#define sampleWindow 10

#define buzzer 32
#define but_1 33
#define but_2 34
#define rele 35
#define L_clean 36
#define R_clean 37

byte min_skor = 0;

unsigned long previousMillis = 0;

const long interval = 10000;
int proc = 0;
int n = 0, k = 0;
int arr[] = {22, 23, 24, 25, 26, 27, 28, 29, 30, 31};

void ROB_LEV(byte max_skor_lev, byte max_skor_prav)
{
  // right motor forvard
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  analogWrite(PIN_ENA, max_skor_lev);
  // left motor back
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
  analogWrite(PIN_ENB, max_skor_prav);
}
void ROB_PRAV(byte max_skor_lev, byte max_skor_prav)
{
  // left motor forvard
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENB, max_skor_prav);
  // right motor back
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  analogWrite(PIN_ENA, max_skor_lev);
}
void ROB_VPERED(byte max_skor_lev, byte max_skor_prav)
{
  // right motor back
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, HIGH);
  analogWrite(PIN_ENA, max_skor_lev);
  // left motor back
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, HIGH);
  analogWrite(PIN_ENB, max_skor_prav);
}
void ROB_NAZAD(byte max_skor_lev, byte max_skor_prav)
{
  // right motor forvard
  digitalWrite(PIN_IN1, HIGH);
  digitalWrite(PIN_IN2, LOW);
  analogWrite(PIN_ENA, max_skor_lev);
  // left motor forvard
  digitalWrite(PIN_IN3, HIGH);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENB, max_skor_prav);
}

void ROB_STOP()
{
  // right motor stop
  digitalWrite(PIN_IN1, LOW);
  digitalWrite(PIN_IN2, LOW);
  analogWrite(PIN_ENA, min_skor);
  // left motor stop
  digitalWrite(PIN_IN3, LOW);
  digitalWrite(PIN_IN4, LOW);
  analogWrite(PIN_ENB, min_skor);
}

void setup() {
  Serial.begin(115200);

  pinMode(PIN_ENA, OUTPUT);
  pinMode(PIN_IN1, OUTPUT);
  pinMode(PIN_IN2, OUTPUT);
  pinMode(PIN_IN3, OUTPUT);
  pinMode(PIN_IN4, OUTPUT);
  pinMode(PIN_ENB, OUTPUT);

  pinMode(ir_1, INPUT);
  pinMode(ir_2, INPUT);
  pinMode(ir_3, INPUT);
  pinMode(ir_4, INPUT);

  for (int i = 0; i <= 9; i++) {
    pinMode(arr[i], OUTPUT);
  }
  pinMode(micro, INPUT);
  pinMode(but_1, INPUT_PULLUP);
  pinMode(but_2, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(rele, OUTPUT);
  pinMode(L_clean, OUTPUT);
  pinMode(R_clean, OUTPUT);

  digitalWrite(rele, LOW);
}

void loop() {
  Serial.print(analogRead(A5));
  Serial.print("   ");
  proc = map(analogRead(A5), 220, 565, 0, 10);
  Serial.print("   ");
  Serial.println(proc);
  for (int i = 0; i < proc; i++) {
    digitalWrite(arr[i], HIGH);
  }
  delay(50);
  for (int j = proc; j >= 0; j--) {
    digitalWrite(arr[j], LOW);
  }
  if (digitalRead(but_1) == 0) {
    tone (buzzer, 600);
    delay(100);
    n++;
    if (n > 4) n = 0;
  }
  noTone(buzzer);
  switch (n) {
    case 1:
      ROB_VPERED(200, 200);
      digitalWrite(L_clean, 255);
      digitalWrite(R_clean, 255);
      if (digitalRead(ir_1) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_LEV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if (digitalRead(ir_2) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_NAZAD(100, 100);
        delay(200);
        ROB_LEV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if (digitalRead(ir_3) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_NAZAD(100, 100);
        delay(200);
        ROB_PRAV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if (digitalRead(ir_4) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_PRAV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if ((millis() - previousMillis >= interval) && (digitalRead(ir_1) == HIGH || digitalRead(ir_2) == HIGH || digitalRead(ir_3) == HIGH || digitalRead(ir_4) == HIGH)) {
        previousMillis = millis();
        ROB_NAZAD(100, 100);
        delay(800);
        ROB_PRAV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      break;
    case 2:
      ROB_STOP();
      digitalWrite(L_clean, 0);
      digitalWrite(R_clean, 0);
      break;
    case 3:
      ROB_STOP();
      digitalWrite(L_clean, 0);
      digitalWrite(R_clean, 0);
      break;
  }
  if (digitalRead(but_2) == 0) {
    tone (buzzer, 900);
    delay(100);
    k++;
    if (k > 4) k = 0;
  }
  switch (k) {
    case 1:
      digitalWrite(rele, HIGH);
      delay(1000);
      ROB_VPERED(200, 200);
      digitalWrite(L_clean, 255);
      digitalWrite(R_clean, 255);
      if (digitalRead(ir_1) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_LEV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if (digitalRead(ir_2) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_NAZAD(100, 100);
        delay(200);
        ROB_LEV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if (digitalRead(ir_3) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_NAZAD(100, 100);
        delay(200);
        ROB_PRAV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if (digitalRead(ir_4) == LOW) {
        ROB_STOP();
        delay(200);
        ROB_PRAV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      if ((millis() - previousMillis >= interval) && (digitalRead(ir_1) == HIGH || digitalRead(ir_2) == HIGH || digitalRead(ir_3) == HIGH || digitalRead(ir_4) == HIGH)) {
        previousMillis = millis();
        ROB_NAZAD(100, 100);
        delay(800);
        ROB_PRAV(100, 100);
        delay(random(200, 1100)); //TURN
      }
      break;
    case 2:
      ROB_STOP();
      digitalWrite(L_clean, 0);
      digitalWrite(R_clean, 0);
      break;
    case 3:
      ROB_STOP();
      digitalWrite(L_clean, 0);
      digitalWrite(R_clean, 0);
      break;
  }
}
