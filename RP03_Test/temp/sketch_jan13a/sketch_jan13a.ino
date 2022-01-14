#define PIN 2

int count = 0;//变量count声明为volatile类型

void setup() {



attachInterrupt(digitalPinToInterrupt(PIN), blinkA, HIGH);//当引脚电平由高电平变为低电平时触发中断服务程序
pinMode(PIN, INPUT);

Serial.begin(9600);

}

void loop() {

Serial.print("累计脉冲=");

Serial.println(count);

delay(100);

}

void blinkA()

{

count++;

}
