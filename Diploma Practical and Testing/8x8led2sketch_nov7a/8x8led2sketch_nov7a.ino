//update from SAnwandter

#define ROW_1 2
#define ROW_2 3
#define  ROW_3 4
#define ROW_4 5
#define ROW_5 6
#define ROW_6 7
#define ROW_7  8
#define ROW_8 9

#define COL_1 10
#define COL_2 11
#define COL_3  12
#define COL_4 13
#define COL_5 A0
#define COL_6 A1
#define COL_7  A2
#define COL_8 A3

const byte rows[] = {
    ROW_1, ROW_2, ROW_3,  ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};
const byte col[] = {
  COL_1,COL_2,  COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

// The display buffer
//  It's prefilled with a smiling face (1 = ON, 0 = OFF)
byte ALL[] = {B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111,B11111111};
byte  EX[] = {B00000000,B00010000,B00010000,B00010000,B00010000,B00000000,B00010000,B00000000};
byte  A[] = {B11111111,B11110111,B11101011,B11010111,B10101111,B11010111,B11101011,B11110111};
byte  B[] = {B11111111,B11111111,B11111011,B11010101,B10101011,B11010111,B11101011,B11110111};
byte  C[] = {B11111111,B11111111,B11111111,B11011101,B10101010,B11010101,B11101011,B11110111};
byte  D[] = {B11111111,B11111111,B11101111,B11010101,B11101010,B11110101,B11101011,B11110111};//
byte  E[] = {B11111111,B11110111,B11101011,B11110101,B11111010,B11110101,B11101011,B11110111};//
byte  F[] = {B11111111,B11110111,B11101011,B11110101,B11101010,B11010101,B11101111,B11111111};//
byte  G[] = {B11111111,B11110111,B11101011,B11010101,B10101010,B11011101,B11111111,B11111111};//
byte  H[] = {B11111111,B11110111,B11101011,B11010111,B10101011,B11010101,B11111011,B11111111};//


float  timeCount = 0;

void setup() 
{
    // Open serial port
    Serial.begin(9600);
    
    // Set all used pins to OUTPUT
    // This is very important! If  the pins are set to input
    // the display will be very dim.
    for (byte  i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A0, OUTPUT);
    pinMode(A1, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
}

void  loop() {
  // This could be rewritten to not use a delay, which would make it  appear brighter
delay(10);
timeCount += 1;

if(timeCount <  20) 
{
drawScreen(A);
}  
else if (timeCount <  40) 
{
drawScreen(B);
} 
else if (timeCount  <  60) 
{
drawScreen(C);
} 
else if (timeCount <  80) 
{
drawScreen(D);
}  
else if (timeCount <  100) 
{
drawScreen(E);
} 
else if (timeCount  <  120) 
{
drawScreen(F);
} 
else if (timeCount <  140) {
  drawScreen(G);
}  
else if (timeCount <  160) 
{
drawScreen(H);
} 
else if (timeCount  <  180) 
{
drawScreen(A);
} 
else {
// back to the start
timeCount  = 0;
}
}
 void  drawScreen(byte buffer2[])
 { 
   // Turn on each  row in series
    for (byte i = 0; i < 8; i++)        // count next row
     {
        digitalWrite(rows[i], HIGH);    //initiate whole row
        for (byte  a = 0; a < 8; a++)    // count next row
        {
          // if You set  (~buffer2[i] >> a) then You will have positive
          digitalWrite(col[a],  (buffer2[i] >> a) & 0x01); // initiate whole column
          
          delayMicroseconds(100);       // uncoment deley for diferent speed of display
          //delayMicroseconds(1000);
          //delay(10);
          //delay(100);
          
          digitalWrite(col[a],  1);      // reset whole column
        }
        digitalWrite(rows[i], LOW);     // reset whole row
        // otherwise last row will intersect with next  row
    }
}
