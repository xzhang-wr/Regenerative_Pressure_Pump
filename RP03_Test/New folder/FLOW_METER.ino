#define FLOWMETER 13
int flow = 0;

void init_FLOWMETER(){
  pinMode(FLOWMETER, INPUT);
  digitalWrite(FLOWMETER, HIGH);
}


int get_flow(){
  int start_time = millis();
  int flow_count = 0;
  bool last_state = false;
  while(millis()-start_time<100){
    if(digitalRead(FLOWMETER)!=last_state){
      last_state = ~last_state;
      if(last_state){
        flow_count++;
      }
    }
  }
  return flow_count;
}
