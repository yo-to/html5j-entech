// 最初に1回だけ処理される部分

const int LED = 9;          // 9番ピンにLEDをつないでいる
int i = 0;

void setup() {
  pinMode(LED, OUTPUT);     // LEDに出力
}

// 繰り返し実行される部分
void loop() {
  for(i=0; i<255; i++) {
    analogWrite(LED, i);    // 出力を徐々に大きくしていく
    delay(10);              // 変化が目に見えるように遅延を加える
  }
  for(i=255; i>0; i--) {
    analogWrite(LED, i);    // 出力を徐々に小さくしていく
    delay(10);
  }
}

