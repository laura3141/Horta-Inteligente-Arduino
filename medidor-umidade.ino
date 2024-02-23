#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd_1(0);

int umidade;
int c=1;
void setup()
{
    
    pinMode(A0,OUTPUT);
    pinMode(A1,INPUT);
    pinMode(13,OUTPUT);
    lcd_1.begin(16, 2);
}

void loop()
{
    
    digitalWrite(A0,HIGH);
    delay(1000);
    umidade=analogRead(A1);//le a umidade
    digitalWrite(A0,LOW);//evitar a corrosão
    

    if(umidade<200&&c==1){
        lcd_1.clear();
        digitalWrite(13,HIGH);
        lcd_1.print("SEDE :(");
        c=0;
    }
    else{
        if(umidade>200&&c==0){
        lcd_1.clear();
        digitalWrite(13,LOW);
        lcd_1.print("SEM SEDE s:)");
        c=1;
        }
        
    }
    delay(1000);
}