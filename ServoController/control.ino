void control(){
  Serial.println("COMMAND CONTROL MODE");
  while(mode == CTRL_MODE){
    if(Serial.available()){
      char tmp = Serial.read();
      Serial.write(tmp);
      if(13 == tmp){
        Serial.write(0x0A);
        input_buf.trim();
        if(input_buf == ""){
          break;
        }
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
