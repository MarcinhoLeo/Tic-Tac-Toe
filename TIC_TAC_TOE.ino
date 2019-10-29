#include <LCD5110_Graph.h>

#define left 3 //кнопка вправо
#define right 5 //кпопка влево
#define G 8 //кпопка при надавливании на стик
#define DELAY 300
LCD5110 lcd(9,10,11,12,13);

int next =0;
int previous =0;
int play =0;
int place = 0;
int turn = 0;
int tn = 0;

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


extern uint8_t us_int[];

void setup() {
  pinMode(right,INPUT);
  pinMode(left,INPUT);
  pinMode(G,INPUT);
  place = 1; // начальнаое положение
  turn = 1; // первый ход ( 1 для Х, 2 для О)
  lcd.InitLCD();
  delay(1000);
  lcd.update();
}

/*
void loop() {
  next = digitalRead(right);
  previous = digitalRead(left);
  play = digitalRead(G);
  plc(); // проверяю свободно ли место, если занято то перемещаю на след
  win(); // пользуюсь если есть победитель
if(previous == HIGH){
   if(place != 1){
     lcd.print(" ",x,y); // показывает на каком месте я нахожусь
    place= place-1;
    prv(); // перемещение на пред место
    delay(300); 
   }else{
    lcd.print(" ",x,y);
    place=9;
    prv();
    delay(300);
   }
    }
  
if(next == HIGH){
   if(place != 9){
    place= place+1;
    nxt(); // пермещение на след место
    delay(300);
   }else{
    lcd.print(" ",x,y);
    place=1;
    nxt();
    delay(300);
   }
}
if(play == HIGH){
  if(turn ==1){
    tn=1;
    lcd.print("X",x,y);
  }
  if(turn ==2){
    tn=2;
    lcd.print("O",x,y);
  }
  take();
  lcd.update();
  delay(500);
  turn++;
  if(turn==3){
    turn=1;
  }
}
}
*/

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


/*
void plc(){
 if(place == 1){
   if(t1 >=1 ){
    place++;  
     }else{
    x=22 ;
    y=4 ;
    lcd.print("_",x,y);
    lcd.update(); 
    }
  }
  if(place == 2){
    if(t2 >=1){
    place++; 
    }else{
    x=38 ;
    y=4 ;
    lcd.print("_",x,y);
    lcd.update();
    }
  }
  if(place == 3){
    if(t3 >=1){
    place++; 
    }else{
    x=54 ;
    y=4 ;
    lcd.print("_",x,y);
    lcd.update();
    }
  }
  if(place == 4){
    if(t4 >=1){
    place++; 
    }else{
    x=22 ;
    y=20 ;
    lcd.print("_",x,y);
    lcd.update();
    }
  }
  if(place == 5){
    if(t5 >=1){
    place++; 
    }else{
    x=38 ;
    y=20 ;
    lcd.print("_",x,y);
    lcd.update();
    }
  }
  if(place == 6){
    if(t6 >=1){
    place++; 
    }else{
    x=54 ;
    y=20 ;
    lcd.print("_",x,y);
    lcd.update();
    }
  }
  if(place == 7){
    if(t7 >=1){
    place++; 
    }else{
    x=22 ;
    y=36 ;
    lcd.print("_",x,y);
    lcd.update();
    }
  }
  if(place == 8){
    if(t8 >=1){
    place++; 
    }else{
    x=38 ;
    y=36 ;
    lcd.print("_",x,y);
    lcd.update();
    }
  }
  if(place == 9){
    if(t9 >=1){
    place=1; 
   }else{
    x=54 ;
    y=36 ;
    lcd.print("_",x,y);
    lcd.update();
   }
  }
  
}
*/

//функция перемещ на след место
void nxt (){
  if(place ==1 && t1 >=1){
    place++;
  }
  if(place ==2 && t2 >=1){
    place++;
  }
  if(place ==3 && t3 >=1){
    place++;
  }
  if(place ==4 && t4 >=1){
    place++;
  }
  if(place ==5 && t5 >=1){
    place++;
  }
  if(place ==6 && t6 >=1){
    place++;
  }
  if(place ==7 && t7 >=1){
    place++;
  }
  if(place ==8 && t8 >=1){
    place++;
  }
  if(place ==9 && t9 >=1){
    place=1;
  }

}

//функция перемещ на пред место
void prv (){
  if(place ==9 && t9 >=1){
    place--;
  }
  if(place ==8 && t8 >=1){
    place--;
  }
  if(place ==7 && t7 >=1){
    place--;
  }
  if(place ==6 && t6 >=1){
    place--;
  }
  if(place ==5 && t5 >=1){
    place--;
  }
  if(place ==4 && t4 >=1){
    place--;
  }
  if(place ==3 && t3 >=1){
    place--;
  }
  if(place ==2 && t2 >=1){
    place--;
  }
  if(place ==1 && t1 >=1){
    place=9;
  }
  if(place ==9 && t9 >=1){
    place--;
  }
  if(place ==8 && t8 >=1){
    place--;
  }
  if(place ==7 && t7 >=1){
    place--;
  }
  if(place ==6 && t6 >=1){
    place--;
  }
  if(place ==5 && t5 >=1){
    place--;
  }
  if(place ==4 && t4 >=1){
    place--;
  }
  if(place ==3 && t3 >=1){
    place--;
  }
  if(place ==2 && t2 >=1){
    place--;
  }
  if(place ==1 && t1 >=1){
    place=9;
  }
}

//выявление победителя
void win (){
  if(t1==1 && t2==1 && t3==1 || t4==1 && t5==1 && t6==1 || t7==1 && t8==1 && t9==1 || t1==1 && t5==1 && t9==1 || t3==1 && t5==1 && t7==1 || t1==1 && t4==1 && t7==1 || t2==1 && t5==1 && t8==1 || t3==1 && t6==1 && t9==1){
    delay(1000);
    t1 =0;
    t2 =0;
    t3 =0;
    t4 =0;
    t5 =0;
    t6 =0;
    t7 =0;
    t8 =0;
    t9 =0;
    
    lcd.drawBitmap(0,0,us_int,84,48);
    place =1;
  }
  if(t1==2 && t2==2 && t3==2 || t4==2 && t5==2 && t6==2 || t7==2 && t8==2 && t9==2 || t1==2 && t5==2 && t9==2 || t3==2 && t5==2 && t7==2 || t1==2 && t4==2 && t7==2 || t2==2 && t5==2 && t8==2 || t3==2 && t6==2 && t9==2){
    delay(1000);
    t1 =0;
    t2 =0;
    t3 =0;
    t4 =0;
    t5 =0;
    t6 =0;
    t7 =0;
    t8 =0;
    t9 =0;
    
    lcd.drawBitmap(0,0,us_int,84,48);
    place =1;
  }
  if(t1>=1 && t2>=1 && t3>=1 && t4>=1 && t5>=1 && t6>=1 && t7>=1 && t8>=1 && t9>=1){
    delay(1000);
    t1 =0;
    t2 =0;
    t3 =0;
    t4 =0;
    t5 =0;
    t6 =0;
    t7 =0;
    t8 =0;
    t9 =0;
    
    lcd.drawBitmap(0,0,us_int,84,48);
    place =1;
  }
}