#include <string.h>
#define CTRL_MODE 1
#define STAT_MODE 2
#define PROG_MODE 3

int i = 0;
byte mode = 1;
//byte buf[300] = {};
String input_buf = "";

void setup() {
  Serial.begin(9600);
}

void program() {
  multPrint(40,"*");
  Serial.println();
  
  Serial.print("**");
  multPrint(36," ");
  Serial.print("**");
  Serial.println();
  
  Serial.print("**");
  multPrint(36," ");
  Serial.print("**");
  Serial.println();
  
  Serial.print("**");
  multPrint(7," ");
  Serial.print("8CH Servos Controller");
  multPrint(8," ");
  Serial.print("**");
  Serial.println();
  
  Serial.print("**");
  multPrint(12," ");
  Serial.print("Program Mode");
  multPrint(12," ");
  Serial.print("**");
  Serial.println();
  
  Serial.print("**");
  multPrint(36," ");
  Serial.print("**");
  Serial.println();
  
  Serial.print("**");
  multPrint(36," ");
  Serial.print("**");
  Serial.println();
  
  multPrint(40,"*");
  Serial.println();
  Serial.print("Program>");
  
  while(mode == PROG_MODE){
    if(Serial.available()){
      char tmp = Serial.read();
      Serial.write(tmp);
      if(13 == tmp){
        Serial.write(0x0A);
        input_buf.trim();
        if(input_buf == "program"){
          Serial.println("Is now in program mode!");
          input_buf == "";
        }
        Serial.print("Program>");
        if(input_buf == "control"){
          input_buf == "";
          mode = CTRL_MODE;
          break;
        }
        
      }else{
        input_buf += tmp;
      }
      
    }
  }
}

void control(){
  Serial.println("COMMAND CONTROL MODE");
  while(mode == CTRL_MODE){
    if(Serial.available()){
      char tmp = Serial.read();
      Serial.write(tmp);
      if(13 == tmp){
        Serial.write(0x0A);
        input_buf.trim();
        if(input_buf == "program"){
          input_buf == "";
          mode = PROG_MODE;
          break;
        }
        
        if(input_buf == "control"){
          Serial.println("Is now in control mode!");
          input_buf == "";
        }
        
      }else{
        input_buf += tmp;
      }
      
    }
  }
}

void runstatic(){
  while(mode == STAT_MODE){
    
  }
}

void switchMode(){
  Serial.write(0x0A);
  Serial.write(0x0D);
  switch(mode){
    case CTRL_MODE:
      control();
      break;
    case PROG_MODE:
      program();
      break;
    case STAT_MODE:
      runstatic();
      break;
    default:
      control();
      break;
  }
}

void loop() {
  switchMode();
}

void multPrint(int num, char *ch){
  for(i=num;i>0;i--){
    Serial.print(ch);
  }
}

