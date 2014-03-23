static int  PIEZO  = 12;
static long LENGTH = 300;    // 音を鳴らす時間の長さ

void setup() {
  pinMode(12, OUTPUT);       // 12番ピンを出力に設定
}

// 繰り返し実行される部分
void loop() {
   tone(12, 262);            // 音を鳴らす：ド
   delay(LENGTH);
   tone(12, 294);            // 音を鳴らす：レ
   delay(LENGTH);
   tone(12, 330);            // 音を鳴らす：ミ
   delay(LENGTH*3);
   tone(12, 294);            // 音を鳴らす：レ
   delay(LENGTH);
   tone(12, 262, LENGTH);    // 音を鳴らす：ド
   delay(500);

   tone(12, 262);            // 音を鳴らす：ド
   delay(LENGTH);
   tone(12, 294);            // 音を鳴らす：レ
   delay(LENGTH);
   tone(12, 330);            // 音を鳴らす：ミ
   delay(LENGTH);
   tone(12, 294);            // 音を鳴らす：レ
   delay(LENGTH);
   tone(12, 262);            // 音を鳴らす：ド
   delay(LENGTH);
   tone(12, 294, LENGTH*3);  // 音を鳴らす：レ

   delay(2000);              // 2秒待つ
}

