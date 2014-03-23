// 最初に1回だけ処理される部分

const int LED = 9;        // 9番ピンにLEDをつないでいる

void setup() {
  pinMode(LED, OUTPUT);   // LEDに出力
}

// 繰り返し実行される部分
void loop() {
   analogWrite(LED, 10);  // 出力を最大に（値は 0〜255）
}

