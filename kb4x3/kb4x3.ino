

/*
3:1	2:2	6:3	12:4
4:q	5:w	7:e	11:r
10:z	8:g	9:tab	x(absent:a,space)
*/
char kmap[14] = "  21qw3eg\tzr4"; //0-12.plus \0 
char kon [14] = "             "; // when a key is pressed do not yield more than once until released


void setup() {
  //delay(6000); //  Give the keyboard driver time to boot
  int i=2;
  for (;i<=12;i++){
  	pinMode(i, INPUT_PULLUP);
  }
  Serial.begin(9600);
}

void loop() {
  int i=2;
  for (;i<=12;i++){
//  	pinMode(i, INPUT_PULLUP);
//  	delay(1);
	  int v = digitalRead(i);
	  delay(1);
	  if (v==0){
	  	 if (kon[i]!=1) { 
	  	 	kon[i]=1;
	  	 	Serial.print(kmap[i]);
	  	 }
	  	 //sendSCByte(convertAsciiToScanCode(kmap[i]));
	  }else{
	  	kon[i]=0;
	  }
  }
  delay(1);
}



// // meaningful names for constants used in this sketch
// const byte SC_SPACE = 0x2c;            const byte MOD_SHIFT = 0xf1;
// const byte SC_ENTER = 0x28;            const byte MOD_ALT = 0xf2;
// const byte SC_BCKSPC = 0x2a;           const byte MOD_CTRL = 0xf0;
// const byte SC_TAB = 0x2b;              const byte SC_PERIOD = 0x37;
// const byte SC_ESCAPE = 0x29;           const byte SC_COMMA = 0x36;
// const byte SC_ESC = 0x29;              const byte SC_SEMI_AND_COLON = 0x33;
// const byte SC_RIGHT_ARROW = 0xef;      const byte SC_SLASH_AND_QUESTION = 0x38;
// const byte SC_LEFT_ARROW = 0x50;       const byte SC_VOL_UP = 0x80; //not working
// const byte SC_DOWN_ARROW = 0x51;       const byte SC_VOL_DOWN = 0x81; //not working
// const byte SC_UP_ARROW = 0x52;         const byte SC_MUTE = 0x7f; //not working
// const byte SC_F1 = 0x3a;
// const byte SC_F2 = 0x3b;
// const byte SC_F3 = 0x3c;
// const byte SC_F4 = 0x3d;
// const byte SC_F5 = 0x3e;
// const byte SC_F6 = 0x3f;
// const byte SC_F7 = 0x40;
// const byte SC_F8 = 0x41;
// const byte SC_F9 = 0x42;
// const byte SC_F10 = 0x43;
// const byte SC_F11 = 0x44;
// const byte SC_F12 = 0x45;
// 
// void sendSCByte(byte byteToSend)
// {
//  // This function sends single scancode bytes.
//  // If using this function to send MOD bytes,
//  // keep in mind the above notes.
//  Serial.print(byteToSend);
//  delay(20);
// }
// 
// byte convertAsciiToScanCode(byte asciiByte)  // self explanatory name
// {
//  
//  if(asciiByte >= 0x61 && asciiByte <= 0x7a) // lower case letters
//    return(asciiByte - 0x5d);
//  else if(asciiByte >= 0x41 && asciiByte <= 0x5a) // upper case letters
//  {
//    sendSCByte(MOD_SHIFT);
//    return(asciiByte - 0x3d);
//  }
//  else if(asciiByte >= 0x31 && asciiByte <= 0x39) // numbers 1 to 9
//    return(asciiByte - 0x13);  // this actually sends the numbers across the top of the keyboard
//  else if(asciiByte == 0x30)  // number 0
//    return(0x27);
//  else if(asciiByte == 0x20)  // space (duh)
//    return(SC_SPACE);
//  else if(asciiByte == 0x2e)  // is a comment really necesary for this one?
//    return(SC_PERIOD);
//  else if(asciiByte == 0x0a || asciiByte == 0x0d)  // line feed/new line and carriage return
//    return(SC_ENTER);
//  else if(asciiByte == 0x2c)
//    return(SC_COMMA);
//  else if(asciiByte == 0x3b)
//    return(SC_SEMI_AND_COLON);
//  else if(asciiByte == 0x3a)
//  {
//    sendSCByte(MOD_SHIFT);
//    return(SC_SEMI_AND_COLON);
//  }
//  return(0x67);
// }

