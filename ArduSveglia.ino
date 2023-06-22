/* ################### INCLUDES ############################ */

#include<Wire.h>                                        /*connessione I2C*/
#include<RTClib.h>
#include <LiquidCrystal_I2C.h>

/* ################### CONSTANT, VARIABLES ############################ */

LiquidCrystal_I2C lcd(0x27, 16, 2); 
RTC_DS3231 myRTC;                             /*definizione tipo struct RTC_DS3231*/

#define P1 2
#define P2 3
#define P3 4

#define TIME 0
#define TEMP 1
#define ALARM 2
#define DATE 3

#define ONOFF 7
#define RED  11
#define GREEN  10
#define BLUE 9
#define buzzer 6
#define LCD 5

uint8_t alarmHH = 0, alarmMM = 0;                                  /* CLOCK */
bool flagT = true, rtc, alarm = false, lcdon = true;               /* FLAGS */
bool P1_old_state = false, P2_old_state = false, P3_old_state = false;    /* LOOK FOR CHANGE IN STATE WITH POLLING*/
int8_t page = 0, select_param = 0, pressed, LED = LOW, press_time = 0 , timer_count_ISR = 0;
int8_t tempo = 85;                                                  /* melody */
DateTime data;

/* LCD BIGFONT 2.0*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
byte full1[8]{
  B00111,
  B01111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte halfdown[8]{
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B11111,
};

byte halfup[8]{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};

byte full2[8]{
  B11100,
  B11110,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
};

byte semi[8]{
  B11111,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
};

byte full3[8]{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B01111,
  B00111,
};

byte point[8]{
  B00000,
  B00000,
  B00000,
  B01100,
  B01100,
  B00000,
  B00000,
  B00000,
};

byte full4[8]{
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11110,
  B11100,
};

/* RGB COLOURS*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void black(){
  analogWrite(RED, 0);
  analogWrite(GREEN, 0);
  analogWrite(BLUE, 0);
}

void Sunrise(int8_t delta){
  /* BLUE */
  if(delta <= 15 && delta >= 14){
      analogWrite(BLUE, 255);
  }
  /* VIOLET*/
  if(delta < 14 && delta >= 12 ){
      analogWrite(RED, 255);
  }
  /* RED */
  if(delta < 12 && delta >= 10 ){
      analogWrite(BLUE, 0);
  }
  /* ORANGE */
  if(delta < 10 && delta >= 8 ){
      analogWrite(GREEN, 40);
  }
  /* YELLOW */
  if(delta < 8 && delta >= 5 ){
      analogWrite(GREEN, 70);
  }
  /* WHITE */
  if(delta < 5 && delta >= 0 ){
      analogWrite(BLUE, 255);
      analogWrite(RED, 255);
      analogWrite(GREEN, 255);
  }
  
}



/* MUSICAL NOTES, ALARM SONG*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

int melody[] = {

  // Jigglypuff's Song
  // Score available at https://musescore.com/user/28109683/scores/5044153
  
  NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
  NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
  NOTE_FS5,-4, NOTE_E5,8, NOTE_FS5,4,
  NOTE_D5,-2,
  NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
  NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
  NOTE_FS5,-1,
  NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
  NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
  
  NOTE_FS5,-4, NOTE_E5,8, NOTE_FS5,4,
  NOTE_D5,-2,
  NOTE_D5,-4, NOTE_A5,8, NOTE_FS5,8, NOTE_D5,8,
  NOTE_E5,-4, NOTE_FS5,8, NOTE_G5,4,
  NOTE_FS5,-1,
  
};

int notes = sizeof(melody) / sizeof(melody[0]) / 2;
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;

/* LCD SYMBOLS */
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void num0(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(0)); /*full*/
  lcd.write(byte(2)); /*halfup*/
  lcd.write(byte(3)); /*full*/
  lcd.setCursor(col,1);
  lcd.write(byte(5)); /*full*/
  lcd.write(byte(1)); /*halfdown*/
  lcd.write(byte(7)); /*full*/ 
}

void num1(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(B00100000);     /*blank, tutto spento*/
  lcd.setCursor(col,1);
  lcd.write(byte(1));
  lcd.write(255);
  lcd.write(byte(1)); 
}

void num2(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(4));
  lcd.write(byte(4));
  lcd.write(byte(3));    
  lcd.setCursor(col,1);
  lcd.write(byte(5));
  lcd.write(byte(1));
  lcd.write(byte(1)); 
}

void num3(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(4));
  lcd.write(byte(4));
  lcd.write(byte(3));    
  lcd.setCursor(col,1);
  lcd.write(byte(1));
  lcd.write(byte(1));
  lcd.write(byte(7)); 
}

void num4(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(5));
  lcd.write(byte(1));
  lcd.write(255);    
  lcd.setCursor(col,1);
  lcd.write(B00100000);
  lcd.write(B00100000);
  lcd.write(255); 
}

void num5(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(0));
  lcd.write(byte(4));
  lcd.write(byte(4));    
  lcd.setCursor(col,1);
  lcd.write(byte(1));
  lcd.write(byte(1));
  lcd.write(byte(7)); 
}

void num6(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(0));
  lcd.write(byte(4));
  lcd.write(byte(4));    
  lcd.setCursor(col,1);
  lcd.write(byte(5));
  lcd.write(byte(1));
  lcd.write(byte(7)); 
}

void num7(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(2));
  lcd.write(byte(2));
  lcd.write(byte(3));    
  lcd.setCursor(col,1);
  lcd.write(B00100000);
  lcd.write(B00100000);
  lcd.write(255); 
}

void num8(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(0));
  lcd.write(byte(4));
  lcd.write(byte(3));    
  lcd.setCursor(col,1);
  lcd.write(byte(5));
  lcd.write(byte(1));
  lcd.write(byte(7)); 
}

void num9(int8_t col){
  lcd.setCursor(col,0);
  lcd.write(byte(0));
  lcd.write(byte(4));
  lcd.write(byte(3));    
  lcd.setCursor(col,1);
  lcd.write(byte(1));
  lcd.write(byte(1));
  lcd.write(byte(7)); 
}

/* INTEGER TO CHAR ONTO LCD*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void select_paramect(uint8_t val, uint8_t x){
  switch(val){
    case 0:
      num0(x);
      break;
    case 1:
      num1(x);
      break;
    case 2:
      num2(x);
      break;
    case 3:
      num3(x);
      break;
    case 4:
      num4(x);
      break;
    case 5:
      num5(x);
      break;
    case 6:
      num6(x);
      break;
    case 7:
      num7(x);
      break;
    case 8:
      num8(x);
      break;
    case 9:
      num9(x);
    break;
  }
}

/* ################### PROGRAM CUSTOM FUNCTIONS ############################ */
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void stampaTemp(float num){
  
  uint8_t col=0, dec=0, unit=0, temp=0, decim=0;
  /*segno*/
  lcd.setCursor(col,0);
    
  /*trasformo in intero a 2/3 cifre così posso usare operatore resto%*/
  temp = num*10;

  decim = temp%10;
  temp = temp/10;
  unit = temp%10;
  temp = temp/10;
  dec = temp%10;
  
  /* decina */
  col=col+2;
  lcd.setCursor(col,0);
  select_paramect(dec,col);
  
  /* unità */
  col = col+4;
  lcd.setCursor(col,0);
  select_paramect(unit, col);

  /* dot */
  col = col+4;
  lcd.setCursor(col,1);
  lcd.write(byte(1));

  /* decimale */
  col=col+2;
  lcd.setCursor(col,0);
  select_paramect(decim, col);

  /* degree */
  col=col+3;
  lcd.setCursor(col,0);
  lcd.write(byte(6));
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void stampaTime(uint8_t ore, uint8_t minuti){
  
  uint8_t col=0, Hdec=0, Hunit=0, Mdec=0, Munit=0;
  /*segno*/
  lcd.setCursor(col,0);
    
  /*trasformo in intero a 2/3 cifre così posso usare operatore resto%*/
  Hunit = ore%10;
  Hdec = ore/10;
  Munit = minuti%10;
  Mdec = minuti/10;
  
  select_paramect(Hdec,col);
  
  col = col+4;
  lcd.setCursor(col,0);
  select_paramect(Hunit, col);

  col = col+3;
  lcd.setCursor(col,0);
  lcd.write(byte(6));
  lcd.setCursor(col,1);
  lcd.write(byte(6));

  col=col+1;
  lcd.setCursor(col,0);
  select_paramect(Mdec, col);

  col=col+4;
  lcd.setCursor(col,0);
  select_paramect(Munit, col);
}

void printDate(uint8_t num){ /* zero padding*/
  if(num >= 10)
    lcd.print(num);
  else{
    lcd.print("0");
    lcd.print(num);
  }
    
}

void stampaDate(uint8_t dd, uint8_t mm, uint16_t yyyy){
  lcd.clear();
  lcd.setCursor(3,0);
  printDate(dd);    lcd.print('/');   printDate(mm);    lcd.print('/');   lcd.print(yyyy);
  
  lcd.setCursor(4,1);

  switch(mm){
    case 1:   lcd.print("GENNAIO");     break;
    case 2:   lcd.print("FEBBRAIO");    break;
    case 3:   lcd.print("MARZO");       break;
    case 4:   lcd.print("APRILE");      break;
    case 5:   lcd.print("MAGGIO");      break;
    case 6:   lcd.print("GIUGNO");      break;
    case 7:   lcd.print("LUGLIO");      break;
    case 8:   lcd.print("AGOSTO");      break;
    case 9:   lcd.print("SETTEMBRE");   break;
    case 10:   lcd.print("OTTOBRE");    break;
    case 11:   lcd.print("NOVEMBRE");   break;
    case 12:   lcd.print("DICEMBRE");   break;
    default: break;
  }

  lcd.setCursor(15,1);
  lcd.print(select_param);
  
}

void AlarmOFF(){ 
     noTone(buzzer);
     alarm = false;
     digitalWrite(ONOFF, alarm);
}

/* time remaining between now() and fixed time */
int8_t time_remaining(uint8_t nowHH, uint8_t nowMM, uint8_t refHH, uint8_t refMM){
  if(refHH == nowHH && refMM >= nowMM)
    return refMM - nowMM;
  else if(refHH == (nowHH + 1) && refMM <= nowMM)
    return refMM - nowMM + 60;
  else
    return 100;
}

/* time passed between now() and fixed time, in seconds */
int8_t time_passed(uint8_t nowSec, uint8_t refSec){
  if(nowSec >= refSec)
    return nowSec - refSec;
  else if(nowSec < refSec)
    return nowSec - refSec + 60;
}

/*verifica che sia ora notturna*/
bool night(uint8_t ore){
  if((ore >= 23) || (ore < 7))
    return true;
  else 
    return false;
}

/* control lcd brightness according to day time */
void lcd_light(bool light){
  if(light)
    analogWrite(LCD, 255);
  else
    analogWrite(LCD, 30);
}

/*/* ################### SETUP, INITIALIZATION ############################ */
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setup() {
    
  /*PIN IN/OUT */
  pinMode(P1, INPUT);
  pinMode(P2, INPUT);
  pinMode(P3, INPUT);
  pinMode(LCD, OUTPUT);
  pinMode(ONOFF, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);

  /* INTERNAL TIMER1 INIT */
  cli(); // disable interrupts during setup
  // Configure Timer 1 interrupt
  // F_clock = 16e6 Hz, prescaler = 64, Fs = 100 Hz
  TCCR1A = 0;
  TCCR1B = 1<<WGM12 | 0<<CS12 | 1<<CS11 | 1<<CS10;
  TCNT1 = 0;          // reset Timer 1 counter
  // OCR1A = ((F_clock / prescaler) / Fs) - 1 = 2499
  OCR1A = 2499;       // Set sampling frequency Fs = 100 Hz
  TIMSK1 = 1<<OCIE1A; // Enable Timer 1 interrupt
 
  sei(); // re-enable interrupts

  /*RTC INIT*/
  /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
  
  if(!myRTC.begin()) /*restituisce TRUE FALSE se RTC connesso, serve per INIZIALIZZAZIONE MODULO*/
    rtc = false;

  myRTC.adjust(DateTime(2023, 6, 22, 17, 30, 0)); /*date solo da 2000 al 2100*/

  /*inizializza per la prima volta RTC se ha perso i dati*/  
  if(myRTC.lostPower()){ 
    myRTC.adjust(DateTime(2023, 6, 22, 16, 30, 0));
  }

  /*DateTime è un'altra variabile tipo di libreria, variabile data YYYY/MM/DD */
  analogWrite(LCD, 150);

  /*LCD INIT*/
  /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
  lcd.init();
  lcd.backlight();
  lcd.createChar(0,full1);
  lcd.createChar(1,halfdown);
  lcd.createChar(2,halfup);
  lcd.createChar(3,full2);
  lcd.createChar(4,semi);
  lcd.createChar(5,full3);
  lcd.createChar(6,point);
  lcd.createChar(7,full4);
  lcd.clear();

} 

/* ################### END SETUP ############################ */

// Timer 1 interrupt service routine (ISR)
// timer @100 Hz thus 1 sec is 100 interrupt events
ISR(TIMER1_COMPA_vect)
{
  timer_count_ISR += 1;
  if(timer_count_ISR == 100){
    timer_count_ISR = 0;
    flagT = true;         /* enable lcd update */
  }
}

/*MAIN*/
/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void loop() {

  uint8_t giorno, mese, ore, minuti, secondi; /*inizializzare le variabili nel loop è un problema!!! */
  uint8_t night_FSM;
  uint16_t anno;
  float temp;

  /* retrieve data from RTC module */
  data = myRTC.now();   /*restituisce data attuale trovata nell'rtc*/
  temp = myRTC.getTemperature();
  
  giorno = data.day();
  mese = data.month();
  anno = data.year();
  ore = data.hour();
  minuti = data.minute();
  secondi = data.second();

  /* compute time remaining to alarm*/
  int8_t delta = time_remaining(ore, minuti, alarmHH, alarmMM);

  /* assign value to lcd brightness */
  lcd_light(lcdon);

  /* introduco questo pezzo di programma per spegnere il display durante la notte, si accende solo con la pressione di P1 */
  if(night(ore)){
    if(ore != alarmHH || minuti != alarmMM){ /* if it's not alarm time */

      if(digitalRead(P1) == HIGH || digitalRead(P2) == HIGH || digitalRead(P3) == HIGH){  /* if button 1 is pressed than lcd on */
        lcdon = true;
        press_time = secondi;
        night_FSM = 1;
      } 
      
      if(night_FSM == 1){
        if(time_passed(secondi, press_time) > 5){
          night_FSM = 2;
        }
      }

      if(night_FSM == 2) {
        night_FSM = 0;
        lcdon = false;
        press_time = 0;
      }

    } else if(ore == alarmHH && minuti == alarmMM){   /* turn on always @ alarm */
      lcdon = true; 
    }
  }
  
  /* ACCESS TO THE MENU CONTROL IF DAY OR IF A BUTTON WAS PRESSED */  
  if(!night(ore) || lcdon){
    
    /*VISUALIZZAZIONE MENU' , polling per verificare se viene modificata la visualizzazione*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    
    /* CAMBIO PAGINA VISUALIZZATA */
    if(digitalRead(P1) == HIGH){
      delay(200);                 /*l'introduzione di un delay per vedere se il pulsante è rilasciato stabilizza il funzionamento della select_paramezione, 0.2 secondi per distinguere da Pressed a longPressed*/
      if(digitalRead(P1) == LOW){
        if(page == 3)
          page = 0;
        else
          page++;
      }
    }
      
    /* PAGE 0, VIEW HOURS */

    /*TIME SET , polling per verificare se viene modificata l'ora*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    if(page == TIME){
      if(digitalRead(P2) == HIGH){  /* P2, change hours*/
        delay(200);               
        if(digitalRead(P2) == LOW){ /*altrimenti, a causa della velocità di lettura del pin, per alcuni istanti troverebbe sempre pin HIGH e incrementa tante volte in pochi millisec*/
          if(ore == 23)
            ore = 0;
          else
            ore = ore + 1; /*adjust(datetime(..)) richiede parametri char */
          myRTC.adjust(DateTime(anno, mese, giorno, ore, minuti, secondi));
        }
      }

        /*polling per verificare se vengono modificati i minuti*/
      if(digitalRead(P3) == HIGH){  /* P3, CHANGE MINUTES */
        delay(200);                 /*l'introduzione di un delay per vedere se il pulsante è rilasciato stabilizza il funzionamento dell'incremento*/
        if(digitalRead(P3) == LOW){ /*altrimenti, a causa della velocità di lettura del pin, per alcuni istanti troverebbe sempre pin HIGH e incrementa tante volte in pochi millisec*/
          if(minuti == 59)
            minuti = 0;
          else
            minuti = minuti + 1; /*adjust(datetime(..)) richiede parametri char */
          myRTC.adjust(DateTime(anno, mese, giorno, ore, minuti, secondi));
        }
      }
    }

    /*PAGE 2, ALARM SET , imposto AlarmClock, Hour*/
    /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
    if(page == ALARM){
      if(digitalRead(P1) == HIGH && P1_old_state == false){ /*longPressed*/
        pressed = secondi;
        P1_old_state = true;
      }
      if(time_passed(secondi, pressed) > 2 && digitalRead(P1) == HIGH){
          alarm = !alarm;
          digitalWrite(ONOFF, alarm);
          P1_old_state = false;
      }
      if(digitalRead(P1) == LOW)
        P1_old_state = false;

      if(digitalRead(P2) == HIGH){
        delay(100);                 /*l'introduzione di un delay per vedere se il pulsante è rilasciato stabilizza il funzionamento dell'incremento*/
        if(digitalRead(P2) == LOW){ /*altrimenti, a causa della velocità di lettura del pin, per alcuni istanti troverebbe sempre pin HIGH e incrementa tante volte in pochi millisec*/
          if(alarmHH == 23)
            alarmHH = 0;
          else
            alarmHH = alarmHH + 1;
        }
      }

        /*imposto AlarmClock, Minutes*/
      if(digitalRead(P3) == HIGH){
        delay(200);                 /*l'introduzione di un delay per vedere se il pulsante è rilasciato stabilizza il funzionamento dell'incremento*/
        if(digitalRead(P3) == LOW){ /*altrimenti, a causa della velocità di lettura del pin, per alcuni istanti troverebbe sempre pin HIGH e incrementa tante volte in pochi millisec*/
          if(alarmMM == 59)
            alarmMM = 0;
          else
            alarmMM = alarmMM + 1;
        }
      }
    }

    /* PAGE 3, VIEW DATE*/
    /* select the parameter you want to change*/
    if(page == DATE){
      if(digitalRead(P2) == HIGH){
        delay(100);                 /*l'introduzione di un delay per vedere se il pulsante è rilasciato stabilizza il funzionamento dell'incremento*/
        if(digitalRead(P2) == LOW){ /*altrimenti, a causa della velocità di lettura del pin, per alcuni istanti troverebbe sempre pin HIGH e incrementa tante volte in pochi millisec*/
          if(select_param == 2)
            select_param = 0;
          else
            select_param = select_param + 1;
        }
      }

      if(digitalRead(P3) == HIGH){
        delay(100);                 /*l'introduzione di un delay per vedere se il pulsante è rilasciato stabilizza il funzionamento dell'incremento*/
        if(digitalRead(P3) == LOW){ /*altrimenti, a causa della velocità di lettura del pin, per alcuni istanti troverebbe sempre pin HIGH e incrementa tante volte in pochi millisec*/
          
          if(select_param == 0){
            if(giorno == 32)
              giorno = 0;
            else
              giorno = giorno + 1;
          }

          if(select_param == 1){
            if(mese == 12)
              mese = 0;
            else
              mese = mese + 1;
          }

          if(select_param == 2){
            anno = anno + 1;
          }
          
          myRTC.adjust(DateTime(anno, mese, giorno, ore, minuti, secondi));
        }
      }
    }
  }
    
  /*OK, vengo dalla Timer 1 ISR, stampo solo ogni secondo, senza delay che ferma arduino*/
  /*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
  if(flagT == true){

    flagT = false;

    lcd.clear();
        
    if(page == TIME){
      stampaTime(ore, minuti);
    }
    else if(page == TEMP){
      stampaTemp(temp);
    }
    else if(page == ALARM){
      stampaTime(alarmHH, alarmMM);
    }
    else if(page == DATE){
      stampaDate(giorno, mese, anno);
    }
  }

  if(delta <= 15 && delta > 0 && alarm == true){
    Sunrise(delta);/*no*/
  } else {
    black();
  }
      
  if(ore == alarmHH && minuti == alarmMM && alarm == true ){
    /*continua l'allarme finchè non preme P1 */
    int thisNote = 0;
    do{
      divider = melody[thisNote + 1];
      if(digitalRead(P1) == HIGH){ 
        AlarmOFF();
        goto STOPALARM;
      }
      if (divider > 0) {
        noteDuration = (wholenote) / divider;
      } 
      else if (divider < 0) {
        noteDuration = (wholenote) / abs(divider);
        noteDuration *= 1.1; 
      }
      tone(buzzer, melody[thisNote], noteDuration * 0.9);

      delay(noteDuration);
      noTone(buzzer);
      thisNote = thisNote + 2;
                
    }while( thisNote < notes * 2 && alarm);
    /*forse no interrupt, magari uso un polling durante la melodia che fa uscire immediatamente dal ciclo!! ora, la melodia non parte più sempre con la sveglia!!*/
  }
  STOPALARM:
  delay(1);
 


}
