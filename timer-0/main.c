/*
  Proposta: PISCA_PISCA com o TIMER0
  PORTD.RD0 -> LED
  ***************************************
  CicloMaquina = Fosc/4 -> 8MHz/4 -> 2MHz -> Periodo = 1/2MHz -> 0.5us
  ***************************************
  Formula:
  TempoEstouro = Período_CicloMaquina * Prescaler * (Modo_8_16bits - CargaInicial)

  Portanta para 1 segundo, teremos:
  
  1.000.000us = 0.5us * 128 * (65536 - X)
  1.000.000 / (0.5us * 128) = 65536 - X
  15625 = 65536 - X
  X = 65536 - 15625 = 49911 (cargaInicial), portanto -> Hex -> C2F7
  *********
  TMR0L = 0XF7;
  TMR0H = 0XC2;
  ********

  ************************
  Dica: Cálculo do tempo máximo para Periodo_CicloMaquina = 0.5us:
  TempoMaximo = 0.5us * 256 * (65536 - 0) = 8.388.608us, ou seja, aprox: 8.4seg
  ************************
  
  //PROGRAMAÇÃO DO TIMER0
  T0CON = 0B00000110; //TIMER0 no modo TIMER, pres: 1:128, modo 16bits
  TMR0L = 0XF7;       //Tempo de estouro de 1 segundo.
  TMR0H = 0XC2;
  INTCON.TMR0IF = 0; //apaga o flag de sinalização de estouro do TIMER0
  
  (...)              //em algum momento...
  T0CON.TMR0ON = 1;  //liga o TIMER0

*/
void ConfigMCU()
{
#ifdef P18F45K22
 ANSELD = 0;
#else
 ADCON1 |= 0X0F;
#endif

 TRISD = 0;      //Define PORTD (Leds) como saída
 PORTD = 0;      //Leds OFF

}


void ConfigTIMER()
{
  //PROGRAMAÇÃO DO TIMER0
  T0CON = 0B00000110; //TIMER0 no modo TIMER, pres: 1:128, modo 16bits
  TMR0H = 0XC2;
  TMR0L = 0XF7;       //Tempo de estouro de 1 segundo.

  INTCON.TMR0IF = 0; //apaga o flag de sinalização de estouro do TIMER0

  //(...)              //em algum momento...
  T0CON.TMR0ON = 1;    //liga o TIMER0

}

void main() {

 ConfigMCU();
 ConfigTIMER();
 
 while(1)
  {
    if(INTCON.TMR0IF == 1)
     {
       PORTD.RD0 = ~LATD.RD0;  //inverte o estado lógico do LED
       
       //recarrega TIMER0 novamente para 1 segundo!
       TMR0H = 0XC2;
       TMR0L = 0XF7;           //Tempo de estouro de 1 segundo.

       INTCON.TMR0IF = 0;      //apaga o flag de sinalização de estouro do TIMER0

     }
     
  }

}