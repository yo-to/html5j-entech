// 最初に1回だけ処理される部分
void setup() {
  pinMode(13, OUTPUT);     // 13番ピンを出力に設定
}

// 繰り返し実行される部分
void loop() {
  digitalWrite(13, HIGH);  // LEDを点ける
  delay(100);              // 0.1秒待つ
  digitalWrite(13, LOW);   // LEDを消す
  delay(100);              // 0.1秒待つ
}

