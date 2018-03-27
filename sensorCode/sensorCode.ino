#define SENSORPINX A2 // x axis
#define SENSORPINY A3 // y axis
#define RESETBUTTON 2 // y axis
 //TODO: define other sensor inputs

unsigned long targetTime=0;
const unsigned long interval=100; //TODO: How fast should we read
String x = "";
String y = "";
void setup(){
// TODO: begin the serial connection with a baudrate of 115200
//  Serial.begin(9600);
  Serial.begin(115200);
}


void loop(){
	if(millis()>=targetTime){
		targetTime= millis()+interval;
    x = String(analogRead(SENSORPINX), DEC);
    y = String(analogRead(SENSORPINY), DEC);
    Serial.println(String(x + "," + y));
	}
	// TODO: Detect if you want to reset the screen(shake the etch-a-sketch)
  // TODO: write the reset message(see server.js) to the serial port
  if (digitalRead(RESETBUTTON)) {
    Serial.println("rst");
  }

}
