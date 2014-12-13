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
        if(input_buf == ""){
          break;
        }
        Serial.print("Program>");
        if(input_buf == "program"){
          Serial.println("Is now in program mode!");
          input_buf == "";
        }
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
