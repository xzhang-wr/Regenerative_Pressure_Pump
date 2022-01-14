#define FLOWMETER 13

void init_FLOWMETER();
int get_flow();

void init_FLOWMETER(){
  pinMode(FLOWMETER, INPUT_PULLUP);
}


int get_flow(){
  int start_time = millis();
  int flow_count = 0;
  bool last_state = false;
  while(millis()-start_time<2000){
    if(digitalRead(FLOWMETER)!=last_state){
      last_state = !last_state;
      if(last_state){
        flow_count++;
      }
    }
  }
  return flow_count;
}

void setup() {
  Serial.begin(9600);
  init_HX710();
  init_FLOWMETER();
  pinMode(25, OUTPUT);

}

void loop() {
  //digitalWrite(25, HIGH);   // turn the LED on (HIGH is the voltage level) 
  //unsigned int p = get_pressure();
  //int f = get_flow();
  Serial.println(digitalRead(FLOWMETER));
  //digitalWrite(25, LOW);    // turn the LED off by making the voltage LOW
  //delay(500);
}
