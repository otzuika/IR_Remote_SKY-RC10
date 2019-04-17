//Pentru telecomanda IR SKY-RC10
//https://www.emag.ro/telecomanda-cu-design-original-sky-rco-rc10/pd/DPHGP7BBM/
//Written by otzuika@gmail.com, public sector

#include <IRremote.h>

int RECV_PIN = 8; //the data pin of the VR1838B IR sensor
IRrecv irrecv(RECV_PIN);
decode_results results; //structure for decoding IR data
int loopc = 0; // a loop counter

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // start the receiver
  Serial.println("START"); //program start
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.print(loopc); //print loop counter
    Serial.print(" -> 0x"); //ca sa copiez mai usor valoarea hexa
    Serial.print(results.value, HEX); //print remote control value
    Serial.print(" "); //print white space
    loopc++;
    switch(results.value) {

     case 0x8E7110EF : Serial.println(" POWER"); loopc=0; break; //key POWER //and reset loop counter
     case 0xC0000C : Serial.println(" POWER"); loopc=0; break; //key POWER //and reset loop counter
     case 0xC00080 : Serial.println(" S_source"); break; //key S_source
     case 0xC00084 : Serial.println(" TV"); break; //key TV

     case 0xC000CC : Serial.println(" tv_guide"); break; //key tv_guide
     case 0xC0007D : Serial.println(" box_office"); break; //key box_office
     case 0xC0007E : Serial.println(" services"); break; //key services
     case 0xC000F5 : Serial.println(" interactive"); break; //key interactive

     case 0x8E71906F : Serial.println(" MUTE"); break; //key MUTE
     case 0xC000CB : Serial.println(" INFO"); break; //key INFO

     case 0x8E7140BF : Serial.println(" VOL+"); break; //key VOL+
     case 0x8E71C03F : Serial.println(" VOL-"); break; //key VOL-
     case 0xC00020 : Serial.println(" CH_UP"); break; //key CH_UP
     case 0xC00021 : Serial.println(" CH_DN"); break; //key CH_DN

     case 0xC00058 : Serial.println(" UP"); break; //key UP
     case 0xC00059 : Serial.println(" DOWN"); break; //key DOWN
     case 0xC0005B : Serial.println(" RIGHT"); break; //key RIGHT
     case 0xC0005A : Serial.println(" LEFT"); break; //key LEFT
     case 0xC0005C : Serial.println(" select_CENTER"); break; //key select_CENTER

     case 0xC0003C : Serial.println(" text"); break; //key text
     case 0xC00083 : Serial.println(" backup"); break; //key backup
     case 0xC00081 : Serial.println(" help"); break; //key help

     case 0xC0006D : Serial.println(" RED"); break; //key RED
     case 0xC0006E : Serial.println(" GREEN"); break; //key GREEN
     case 0xC0006F : Serial.println(" YELLOW"); break; //key YELLOW
     case 0xC00070 : Serial.println(" BLUE"); break; //key BLUE

     case 0xC00001 : Serial.println(" 1"); break; //key 1
     case 0xC00002 : Serial.println(" 2"); break; //key 2
     case 0xC00003 : Serial.println(" 3"); break; //key 3
     case 0xC00004 : Serial.println(" 4"); break; //key 4
     case 0xC00005 : Serial.println(" 5"); break; //key 5
     case 0xC00006 : Serial.println(" 6"); break; //key 6
     case 0xC00007 : Serial.println(" 7"); break; //key 7
     case 0xC00008 : Serial.println(" 8"); break; //key 8
     case 0xC00009 : Serial.println(" 9"); break; //key 9

     case 0xC00000 : Serial.println(" 0"); break; //key 0

    }
    irrecv.resume(); // Receive the next value
   }
}
