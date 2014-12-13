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

void multPrint(int num, char *ch){
  for(i=num;i>0;i--){
    Serial.print(ch);
  }
}

