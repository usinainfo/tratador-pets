#include <RTClib.h>               // Inclui a Biblioteca

// Define os pinos de utilização do Driver L298.
const int motorB1  = 5;       // Pino 5 no B1 do L293.
const int motorB2  = 6;       // Pino 3 no B2 do L293.

RTC_DS1307 rtc;       // Inicia variáveis do RTC

int Hor;              // Define variável Hora
int Min;              // Define variável Minuto
int Sec;              // Define variável Segundo
int Data;             // Define variável Data

void setup()  {
  rtc.begin();        // Inicia o módulo RTC

  pinMode(motorB1, OUTPUT);   // Pino 5 é um pino de saída de sinal
  pinMode(motorB2, OUTPUT);   // Pino 6 é um pino de saída de sinal

  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));     // Ajuste Automático da hora e data
  //rtc.adjust(DateTime(2020, 04, 16, 10, 00, 00));   // Ajuste Manual (Ano, Mês, Dia, Hora, Min, Seg)
}

void loop()   {
  Hor = rtc.now().hour();       // Verifica a Hora
  Min = rtc.now().minute();     // Verifica os Minutos
  Sec = rtc.now().second();     // Verifica os Segundos
  Data = rtc.now().day();       // Verifica o Dia

  // Verifica o horário e se o mesmo for igual à 12:00:00
  if ( Hor == 12 &&  Min == 00 && Sec == 00) {
    analogWrite(motorB1, 255);
    analogWrite(motorB2, 0);
    delay(3000);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 255);
    delay(2000);
    analogWrite(motorB1, 255);
    analogWrite(motorB2, 0);
    delay(3000);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
  }

  // Verifica o horário e se o mesmo for igual à 18:00:00
  if ( Hor == 18 &&  Min == 00 && Sec == 00) {
    analogWrite(motorB1, 255);
    analogWrite(motorB2, 0);
    delay(3000);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 255);
    delay(2000);
    analogWrite(motorB1, 255);
    analogWrite(motorB2, 0);
    delay(3000);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
  }

  delay(1000);                      // Aguarda 1 segundo e reinicia
}
