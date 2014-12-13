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

void loop() {
  switchMode();
}
