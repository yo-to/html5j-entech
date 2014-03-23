const int LED = 13;
int val = 0;                 // センサからの値を格納する変数

void setup() {
  pinMode(LED, OUTPUT);      // LEDに出力
  // アナログの入力は自動設定されるので、記載しない
}

void loop() {
   val = analogRead(0);      // センサの値を読み込む
   
   digitalWrite(LED, HIGH);  // LEDをつける
   delay(val);               // センサの入力値が大きいほど遅延が大きくなる
   
   digitalWrite(LED, LOW);   // LEDを消す
   delay(val);
}

