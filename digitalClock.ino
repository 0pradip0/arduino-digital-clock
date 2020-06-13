/*
  Digital clock watch with Arduino (ATmega 328) and 7 segment Display (MPX6 CA)

                             Sadraque Nunes 
                             sadaquenunesmartiniano@gmail.com
    7 SEGMENT DISPLAY        07/06/2020
           A
    ::::::::::::::::         PIN OUT (Display)
    ::            ::         
  F ::            :: B       IO0  -> SEGMENT A
    ::            ::         IO1  -> SEGMENT B
    ::     G      ::         IO2  -> SEGMENT C
    ::::::::::::::::         IO3  -> SEGMENT D
    ::            ::         IO4  -> SEGMENT E
  E ::            :: C       IO5  -> SEGMENT F
    ::            ::         IO6  -> SEGMENT G
    ::            ::         IO7  -> DISPLAY 1
    :::::::::::::::: ::      IO8  -> DISPLAY 2
           D         DP      IO9  -> DISPLAY 3
                             IO10 -> DISPLAY 4
                             IO11 -> DISPLAY 5
                             IO12 -> DISPLAY 6

                            
                             
         
*/




//timers
short int const PROGMEM DISPLAY_TIME = 1;
short int const PROGMEM TIME = 160;

//constants 
short int const PROGMEM PIN_A = 0;
short int const PROGMEM PIN_B = 1;
short int const PROGMEM PIN_C = 2;
short int const PROGMEM PIN_D = 3;
short int const PROGMEM PIN_E = 4;
short int const PROGMEM PIN_F = 5;
short int const PROGMEM PIN_G = 6;
short int const PROGMEM PIN_1 = 7;
short int const PROGMEM PIN_2 = 8;
short int const PROGMEM PIN_3 = 9;
short int const PROGMEM PIN_4 = 10;
short int const PROGMEM PIN_5 = 11;
short int const PROGMEM PIN_6 = 12;
short int const PROGMEM PIN_STATUS = 13;
short int const PROGMEM PIN_SET = 14;
short int const PROGMEM PIN_MORE = 15;
short int const PROGMEM PIN_LESS = 16;
short int const PROGMEM PIN_LED_AJUST = 17;
short int const PROGMEM PIN_LED_MIN = 18;
short int const PROGMEM PIN_LED_HOUR = 19;


//clock control
short int seconds = 0;
short int minutes = 0;
short int hours = 0;
boolean ajust = false;
short int ajustCount = 0;

//components control 
boolean sts = true; //status leds
short int set = false; //SET
short int more = false; //+
short int less = false; //-



//set the seconds 
void setSeconds(){

  seconds = seconds + 1;      
}

//set the minutes
void setMinutes(){

  minutes = minutes + 1;     
}

//set the hours
void setHours(){

  hours = hours + 1;      
}

//increments the minutes
void isMinute(){
 
  if(seconds == 60){
    setMinutes();
    seconds = 0;    
  }   
}

//increments the hours
void isHour(){
 
  if(minutes == 60){
    setHours();
    minutes = 0;    
  }   
}

//reset hour (23 to 00)
void resetHour(){

  if(hours == 24){

    hours = 0;
 }

}

//show leds status (the four flashing leds)
void showStatus(boolean state){
  
  if(state == true){
    
    digitalWrite(PIN_STATUS, HIGH);
    sts = false;  
    
  }
  else if(state == false){
  
    digitalWrite(PIN_STATUS, LOW);
    sts = true;  
     
    }
}
    
//shows the number on the diplay
void showNumber(int number, int disp){

  if(number == 0){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, LOW);//SEGMENT D
    digitalWrite(PIN_E, LOW);//SEGMENT E
    digitalWrite(PIN_F, LOW);//SEGMENT F
    digitalWrite(PIN_G, HIGH);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY
  }
  
  if(number == 1){

    digitalWrite(PIN_A, HIGH);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, HIGH);//SEGMENT D
    digitalWrite(PIN_E, HIGH);//SEGMENT E
    digitalWrite(PIN_F, HIGH);//SEGMENT F
    digitalWrite(PIN_G, HIGH);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY  
  }  
  
  if(number == 2){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, HIGH);//SEGMENT C
    digitalWrite(PIN_D, LOW);//SEGMENT D
    digitalWrite(PIN_E, LOW);//SEGMENT E
    digitalWrite(PIN_F, HIGH);//SEGMENT F
    digitalWrite(PIN_G, LOW);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY
  
  }
  
  if(number == 3){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, LOW);//SEGMENT D
    digitalWrite(PIN_E, HIGH);//SEGMENT E
    digitalWrite(PIN_F, HIGH);//SEGMENT F
    digitalWrite(PIN_G, LOW);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY  
  }
  
  if(number == 4){

    digitalWrite(PIN_A, HIGH);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, HIGH);//SEGMENT D
    digitalWrite(PIN_E, HIGH);//SEGMENT E
    digitalWrite(PIN_F, LOW);//SEGMENT F
    digitalWrite(PIN_G, LOW);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY  
  }
  
  if(number == 5){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, HIGH);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, LOW);//SEGMENT D
    digitalWrite(PIN_E, HIGH);//SEGMENT E
    digitalWrite(PIN_F, LOW);//SEGMENT F
    digitalWrite(PIN_G, LOW);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY
  }
  
  if(number == 6){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, HIGH);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, LOW);//SEGMENT D
    digitalWrite(PIN_E, LOW);//SEGMENT E
    digitalWrite(PIN_F, LOW);//SEGMENT F
    digitalWrite(PIN_G, LOW);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY  
  }
  
  if(number == 7){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, HIGH);//SEGMENT D
    digitalWrite(PIN_E, HIGH);//SEGMENT E
    digitalWrite(PIN_F, HIGH);//SEGMENT F
    digitalWrite(PIN_G, HIGH);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY   
  }
  
  if(number == 8){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, LOW);//SEGMENT D
    digitalWrite(PIN_E, LOW);//SEGMENT E
    digitalWrite(PIN_F, LOW);//SEGMENT F
    digitalWrite(PIN_G, LOW);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY   
  }
  
  if(number == 9){

    digitalWrite(PIN_A, LOW);//SEGMENT A
    digitalWrite(PIN_B, LOW);//SEGMENT B
    digitalWrite(PIN_C, LOW);//SEGMENT C
    digitalWrite(PIN_D, LOW);//SEGMENT D
    digitalWrite(PIN_E, HIGH);//SEGMENT E
    digitalWrite(PIN_F, LOW);//SEGMENT F
    digitalWrite(PIN_G, LOW);//SEGMENT G

    digitalWrite((6 + disp), HIGH);//DISPLAY
    delay(DISPLAY_TIME);
    digitalWrite((6 + disp), LOW);//DISPLAY  
  }
}

//shows the complete time on the display
void showClock(){

  showStatus(sts);
  
  for(int j = 0; j <= TIME; j++){
    
    showNumber((seconds % 10), 6);
    showNumber((seconds / 10), 5);

    showNumber((minutes % 10), 4);
    showNumber((minutes / 10), 3);

    showNumber((hours % 10), 2);
    showNumber((hours / 10), 1);
    
  }
  
}

//enable the manual clock config 
void buttonSet(){

  if(analogRead(PIN_SET) >= 200){

    ajustCount = ajustCount + 1;
    }
    
  if(ajustCount == 1){

    digitalWrite(PIN_LED_AJUST, HIGH);
    digitalWrite(PIN_LED_MIN, HIGH);
    ajust = true;
    }

  if(ajustCount == 2){

    digitalWrite(PIN_LED_MIN, LOW);
    digitalWrite(PIN_LED_HOUR, HIGH);
    ajust = true;
    }
              
  if(ajustCount == 3){

    digitalWrite(PIN_LED_AJUST, LOW);
    digitalWrite(PIN_LED_MIN, LOW);
    digitalWrite(PIN_LED_HOUR, LOW);
    ajustCount = 0;
    ajust = false;
    }
  }

//add one more
void buttonMore(){

  if(analogRead(PIN_MORE) >= 200){
  
    if(ajust == true and ajustCount == 1){

      setMinutes();
      isMinute();
      }
      
    if(ajust == true and ajustCount == 2){

      setHours();
      isHour();
      }      
  }
   
}  

//remove one more
void buttonLess(){

  if(analogRead(PIN_LESS) >= 200){
  
    if(ajust == true and ajustCount == 1){

      minutes = minutes - 1;
        if(minutes == -1){

          minutes = 59;
          }
        
      }
      
    if(ajust == true and ajustCount == 2){

      hours = hours - 1;
        if(hours == -1){

          hours = 23;
          }
          
      }      
  }
   
}  

  
void setup() {
  
  for(int i = 0; i<=13; i++){pinMode(i, OUTPUT);}
  
  pinMode(PIN_SET, INPUT);
  pinMode(PIN_MORE, INPUT);
  pinMode(PIN_LESS, INPUT);
  
  pinMode(PIN_LED_AJUST, OUTPUT);
  pinMode(PIN_LED_MIN, OUTPUT);
  pinMode(PIN_LED_HOUR, OUTPUT);
}

void loop() {
  
  buttonSet();

  buttonLess();

  buttonMore();
  
  setSeconds();
  
  isMinute();
  
  isHour();

  resetHour();
   
  showClock();
  
}
