#include <LCD5110_Graph.h>

#define pinX A0 //координата по Х
#define pinY A1 //координата по У
#define G 4 //кпопка при надавливании на стик
#define E 6//кнопка Е для начала новой игры 
#define DELAY 300

int place = 0;//номер ячейки
int last_place = 0;
int turn = 0;//знач Х либо О
int tn = 0;

int valBut = 0; //задаю переменную, для счетчика 
long previousMillis = 0; //задаю начальное значение для счетчика millis
long TimePush = 5; //необходимое время нажатия на кнопку

int x = 0;
int y = 0;
int t1 =0;
int t2 =0;
int t3 =0;
int t4 =0;
int t5 =0;
int t6 =0;
int t7 =0;
int t8 =0;
int t9 =0;

extern uint8_t wino[];//растровое изобр после победы О
extern uint8_t winx[];//расторое изобр после победы Х
extern uint8_t draw[];//растровое изобр при ничье
extern uint8_t us_int[];//растровое поле для игры
extern uint8_t draw_x[];//растровое изобр Х
extern uint8_t draw_xx[];//растровое изобр Х
extern uint8_t draw_o[];//растровое изобр О
extern uint8_t draw_oo[];//растровое изобр О
extern uint8_t draw_cursor[];//растровое изобр курсора
extern uint8_t empty[];

extern unsigned char SmallFont[]; //размер шрифта

LCD5110 lcd(9,10,11,12,13);

void setup() {
  //pinMode(7,OUTPUT);
  //digitalWrite(7,LOW);
  pinMode(pinX,INPUT);
  pinMode(pinY,INPUT);
  pinMode(G,INPUT);
  pinMode(E,INPUT);
  digitalWrite(G, HIGH);
  place = 5; //начальнаое положение посередине
  turn = 1; //первый ход ( 1 для Х, 2 для О)
  lcd.InitLCD();
  lcd.setFont(SmallFont);
  lcd.update();
  delay(100);
  lcd.drawBitmap(0,0,us_int,84,48);
  lcd.update();
}



void loop() {
  cursor();
 // plc();//проверяю свободно ли место, если занято то перемещаю на след
  win();//пользуюсь если есть победитель
  //попадаю на левую четверть
  
if ((analogRead(pinX) == 0) && (analogRead(pinY) >=0 )&& (analogRead(pinY) <= 700)){
    prv(); //перемещение на пред место по горизонтали
    delay(DELAY);
}

//попадаю на правую четверть
if ((analogRead(pinX) >= 680) && (analogRead(pinY) >=0 )&& (analogRead(pinY) <= 700)){
    nxt();//пермещение на след место по горизонтали 
    delay(DELAY);
}

//попадаю на верхнюю четверть
if ((analogRead(pinX) >= 80) && (analogRead(pinX) <= 700) && (analogRead(pinY) >=680)){
    prvv();//пермещение на пред место по вертикали
    delay(DELAY);
}

//попадаю на нижнюю четверть
if ((analogRead(pinX) >= 80) && (analogRead(pinX) <= 700) && (analogRead(pinY) == 0)){
    nxtv();//пермещение на след место по вертикали
   delay(DELAY);
}

//нажатие на кнопку для выбора Х либо 0
if((digitalRead(G) == LOW) && (plc() == false)){
  if(turn ==1){
    tn=1;
    lcd.drawBitmap(x,y-1,draw_x,5,5);
    lcd.drawBitmap(0,0,draw_oo,5,5);
    lcd.update();
  }
  else{
    tn=2;
    lcd.drawBitmap(x,y-1,draw_o,5,5);
    lcd.drawBitmap(0,0,draw_xx,5,5);
    lcd.update();
  }
  
  take();
  turn++;
  
  if(turn==3){
    turn = 1;
  }
}
}

//функция курсора
void cursor(){
  //lcd.drawBitmap(x-3,y-1,empty,3,5)
  x=((last_place-1) % 3)*28 + 5;
  y=((last_place-1) / 3)*16 + 7;
  lcd.drawBitmap(x-3,y-1,empty,3,5);
  x=((place-1) % 3)*28 + 5;
  y=((place-1) / 3)*16 + 7;
  lcd.drawBitmap(x-3,y-1,draw_cursor,3,5);
  lcd.update();
  last_place = place;
  x+=5;
  
}

//заполение ячеек значениями 1(для крестиков) или 2(для ноликов)
void take(){
  if(place == 1){
    t1=tn;
  }
  if(place == 2){
    t2=tn;
  }
    if(place == 3){
    t3=tn;
  }
    if(place == 4){
    t4=tn;
  }
    if(place == 5){
    t5=tn;
  }
    if(place == 6){
    t6=tn;
  }
    if(place == 7){
    t7=tn;
  }
    if(place == 8){
    t8=tn;
  }
    if(place == 9){
    t9=tn;
  }
}

//проверяю свободна ли ячейка
bool plc(){
 if(place == 1){
   if(t1 >=1 ){
    return (true);
    //place++;  
     }else{ 
     return (false);
     }
  }
  if(place == 2){
    if(t2 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
    }
  
  if(place == 3){
    if(t3 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
    }
  
  if(place == 4){
    if(t4 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
    }
  
  if(place == 5){
    if(t5 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
    }
  
  if(place == 6){
    if(t6 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
    }
  
  if(place == 7){
    if(t7 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
    }
  
  if(place == 8){
    if(t8 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
    }
  
  if(place == 9){
    if(t9 >=1){
    return (true);
    //place++;  
     }else{ 
      return (false);
     }
   }
  }
  


//функция перемещ на след место по горизонтали
void nxt (){
  switch(place){
  case 1:
  place++;
  break;
  case 2:
  place++;
  break;
  case 3:
  place = 1;
  break;
  case 4:
  place++;
  break;
  case 5:
  place++;
  break;
  case 6:
  place = 4;
  break;
  case 7:
  place++;
  break;
  case 8:
  place++;
  break;
  case 9:
  place = 6;
  break;
  }
  }

//функция перемещ на пред место по горизонтали
void prv (){
  switch(place){
  case 1:
  place = 3;
  break;
  case 2:
  place-=1;
  break;
  case 3:
  place-=1;
  break;
  case 4:
  place = 6;
  break;
  case 5:
  place -=1;
  break;
  case 6:
  place-=1;
  break;
  case 7:
  place = 9;
  break;
  case 8:
  place -=1;
  break;
  case 9:
  place-=1;
  break;
  }
}

//функция перемещ на пред место по вертикали
void prvv (){
  switch(place){
  case 1:
  place = 7;
  break;
  case 2:
  place = 8;
  break;
  case 3:
  place = 9;
  break;
  case 4:
  place-=3;
  break;
  case 5:
  place-=3;
  break;
  case 6:
  place-=3;
  break;
  case 7:
  place-=3;
  break;
  case 8:
  place-=3;
  break;
  case 9:
  place-=3;
  break;
  }
}

//функция перемещ на след место по вертикали
void nxtv (){
  switch(place){
  case 1:
  place+=3;
  break;
  case 2:
  place+=3;
  break;
  case 3:
  place+=3;
  break;
  case 4:
  place+=3;
  break;
  case 5:
  place+=3;
  break;
  case 6:
  place+=3;
  break;
  case 7:
  place = 1;
  break;
  case 8:
  place = 2;
  break;
  case 9:
  place = 3;
  break;
  }
}



//выявление победителя
void win (){
  if(t1==1 && t2==1 && t3==1 || t4==1 && t5==1 && t6==1 || t7==1 && t8==1 && t9==1 || t1==1 && t5==1 && t9==1 || t3==1 && t5==1 && t7==1 || t1==1 && t4==1 && t7==1 || t2==1 && t5==1 && t8==1 || t3==1 && t6==1 && t9==1){
    delay(500);
    lcd.clrScr();
    delay(100);
    lcd.drawBitmap(0,0,winx,84,48);
    lcd.update();
    delay(1000);
    lcd.clrScr();
    delay(1000);
    
    //проверка для начала новой игры
    while(digitalRead(E) == HIGH){
      lcd.print((char *) "  TO PLAY ",10,25);
      lcd.print((char *) " PRESS E ",16,15);
      lcd.update();
      if (digitalRead(E) == LOW){
      break;
    }
    }
    delay(500);
    lcd.drawBitmap(0,0,us_int,84,48);
    lcd.update();
    t1 =0;
    t2 =0;
    t3 =0;
    t4 =0;
    t5 =0;
    t6 =0;
    t7 =0;
    t8 =0;
    t9 =0;
    place = 5;
    turn = 1;
  }
  
  if(t1==2 && t2==2 && t3==2 || t4==2 && t5==2 && t6==2 || t7==2 && t8==2 && t9==2 || t1==2 && t5==2 && t9==2 || t3==2 && t5==2 && t7==2 || t1==2 && t4==2 && t7==2 || t2==2 && t5==2 && t8==2 || t3==2 && t6==2 && t9==2){
    delay(500);
    lcd.clrScr();
    delay(100);
    lcd.drawBitmap(0,0,wino,84,48);
    lcd.update();
    delay(1000);
    lcd.clrScr();
    delay(1000);

    //проверка для начала новой игры
    while(digitalRead(E) == HIGH){
      lcd.print((char *) " TO PLAY ",16,25);
      lcd.print((char *) "  PRESS E ",10,15);
      lcd.update();
      if (digitalRead(E) == LOW){
      break;
    }
    }
    delay(500);
    lcd.drawBitmap(0,0,us_int,84,48);
    lcd.update(); 
    t1 =0;
    t2 =0;
    t3 =0;
    t4 =0;
    t5 =0;
    t6 =0;
    t7 =0;
    t8 =0;
    t9 =0;
    place = 5;
    turn = 1;
  }
  
  if(t1>=1 && t2>=1 && t3>=1 && t4>=1 && t5>=1 && t6>=1 && t7>=1 && t8>=1 && t9>=1){
    delay(500);
    lcd.clrScr();
    delay(100);
    lcd.drawBitmap(0,0,draw,84,48);
    lcd.update();
    delay(1000);
    lcd.clrScr();
    delay(1000);

    //проверка для начала новой игры
    while(digitalRead(E) == HIGH){
      lcd.print((char *) " TO PLAY ",16,25);
      lcd.print((char *) "  PRESS E ",10,15);
      lcd.update();
      if (digitalRead(E) == LOW){
      break;
    }
    }
    delay(500);
    lcd.drawBitmap(0,0,us_int,84,48);
    lcd.update(); 
    t1 =0;
    t2 =0;
    t3 =0;
    t4 =0;
    t5 =0;
    t6 =0;
    t7 =0;
    t8 =0;
    t9 =0;
    place = 5;
    turn = 1;
  }
}
