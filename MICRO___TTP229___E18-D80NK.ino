
#define SCL_PIN 2
#define SDO_PIN 3
#define ir_sensor 8 
#include <Keyboard.h>
byte Key;
int trigger = 0; //sensor toggle





void setup() {
pinMode(SCL_PIN, OUTPUT);
pinMode(SDO_PIN, INPUT);
pinMode(ir_sensor, INPUT);
}

void loop() {
  
  int val = digitalRead(ir_sensor);
  Key = Read_Keypad();
  if ( (val==1) && (trigger==1) ){
    // jika x detect sensor
      //Keyboard.press(KEY_LEFT_CTRL);
     // Keyboard.press(KEY_LEFT_ALT);
     // Keyboard.press('p');
     Keyboard.write((char) 0x60);  // 0x20 ialah '`'
      
      delay(100);
      Keyboard.releaseAll();
      trigger = 0 ;
                                                                                               
    }   
  if ( (val==0) && (trigger==0) ){
    // jika detect sensor 
    Keyboard.write((char) 0x20);  // 0x20 ialah 'space bar'
    delay(100);
    Keyboard.releaseAll();
    trigger = 1 ;
    
    }
    
  if (Key)
    if (Key==1){
      Keyboard.write('1');
      delay(500);
      }

    if (Key==2){
      Keyboard.write('2');
      delay(500);
      }

    if (Key==3){
      Keyboard.write('3');
      delay(500);
      }

    if (Key==4){
      Keyboard.write('4');
      delay(500);
      }

    if (Key==5){
      Keyboard.write('5');
      delay(500);
      }

    if (Key==6){
      Keyboard.write('6');
      delay(500);
      }

    if (Key==7){
      Keyboard.write('7');
      delay(500);
      }

    if (Key==8){
      Keyboard.write('8');
      delay(500);
      }
      
  delay(100);

}

byte Read_Keypad(void){
byte Count;
byte Key_State = 0;
/* Pulse the clock pin 16 times (one for each key of the keypad)
and read the state of the data pin on each pulse */
for(Count = 1; Count <= 8; Count++)
{
digitalWrite(SCL_PIN, LOW);
/* If the data pin is low (active low mode) then store the
current key number */
if (!digitalRead(SDO_PIN))
Key_State = Count;
digitalWrite(SCL_PIN, HIGH);
}
return Key_State;
}


