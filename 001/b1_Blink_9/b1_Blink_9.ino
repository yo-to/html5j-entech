// 最初に1回だけ処理される部分

const int LED = 9;            // 9番ピンにLEDをつないでいる

void setup() {
  pinMode(LED, OUTPUT);       // LEDに出力
}

// 繰り返し実行される部分
void loop() {
   digitalWrite(LED, HIGH);   // LEDを点ける
   delay(100);                // 1秒待つ
   digitalWrite(LED, LOW);    // LEDを消す
   delay(100);                // 1秒待つ
}

