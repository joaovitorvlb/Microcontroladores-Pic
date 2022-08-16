void main(){  //rotina principal do programa
#ifdef P18F45K22
  ANSELD = 0;
  ANSELB = 0;
#else
  ADCON1 |= 0X0F;
#endif

/**************** fórmula matemática de temporização do timer2 ***************
  TEMPOMaximo = Periodo_CICLO DE MAQUINA * PRESCALER * POSTSCALE * (PR2 + 1)
  TEMPOMaximo = 0.5us * 16 * 16 * (255 + 1)
  TEMPOMAXIMO: 32.768us OU SEJA: ~33ms
******************************************************************************/
  T2CON = 0B01111111;  //define TIMER2 ON, prescaler 1:16, postscale 1:16
  PR2 =  255;          //contagem de 32ms
  PIR1.TMR2IF = 0;     //apaga flag do TIMER2

  //****************************************************************************
  TRISB.RB0 = 1;      //TECLA RB0 CONFIG COMO ENTRADA
  TRISB.RB1 = 1;      //TECLA RB1 CONFIG. COMO ENTRADA
  //****************************************************************************
  TRISD.RD0 = 0;      //PINO LED0  COMO SAIDA
  PORTD.RD0 = 0;      //LED RD0 APAGADO
  //****************************************************************************

while (1){

    if (PORTB.RB0 == 0) { // se a tecla rb0 for pressionada, então...
         T2CON.TMR2ON = 1;  //ligar timer2
       }

    if (PORTB.RB1 == 0){  // se a tecla rb0 for pressionada, então...
         T2CON.TMR2ON = 0; //desligar timer2
       }

    if (PIR1.TMR2IF == 1) {     //se ocorrer o estouro de contagem do TIMER2
         PORTD.RD0 = ~LATD.RD0; //inverto o estado lógico do led rb2
         PIR1.TMR2IF = 0;        //apago flag de sinalização de estouro do TIMER2
        }

   }
 }