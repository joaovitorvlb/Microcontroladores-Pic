//Programa de teste de comunica��o Serial (transmiss�o e recep��o)
//Definir opera��o em 9600bps
//Dica: Normalmente o PORTC do microcontrolador � a porta de comunica��o (UART, I2C, SPI, ...)

//Defini��es
#define FOSC (8000000L)
#define BAUD (115200L)

//Prot�tipos
void ConfigUART();
void ConfigMCU();

void ConfigUART()
{
   //Transmiss�o Serial
   TXSTA1.TXEN = 1;    //Habilita a transmiss�o Serial
   RCSTA1.CREN = 1;    //Habilita a Recep��o Serial
   RCSTA1.SPEN = 1;    //Habilita o perif�rico Serial (v�lido tanto para recep��o quanto para transmiss�o)

   //C�culo de BaudRate 115200 bps****************************************************
   //SPBRG1 = (((FOSC/BAUD)/4) - 1);  
   //se for modo 8 bits -> usa apenas o registrador SPBRG1
   //se for modo 16bits -> usa os dois registradores (SPBRGH1:SPBRG1)
   SPBRG1 = (((FOSC/BAUD)/4) - 1);
   SPBRGH1 = 0;
   BAUDCON1.BRG16  = 1;    //modo 16bits desativado
   TXSTA1.BRGH   = 1;      //modo 8 bits
   TXSTA1.SYNC   = 0;      //modo assincrono
   //***********************************************************************



   TRISC.RC6 = 0;   //Pino RX configurado como sa�da
   TRISC.RC7 = 1;   //Pino TX configurado como entrada

   RC1REG = 0;      //Apaga o buffer de recep��o
   TX1REG = 0;      //Apaga o buffer de transmiss�o

   PIR1.RC1IF = 0;  //Apaga flag de recep��o
   PIR1.TX1IF = 0;  //Apaga flag de transmiss�o

}


void ConfigMCU()
{
  #ifdef P18F45K22
   ANSELC = 0;   //Configura o PORTC como I/O digital, pois os pinos RX e TX est�o nessa porta
  #else

  #endif
}

void main() {
  ConfigMCU();
  ConfigUART();

  while(1)
   {
     if(PIR1.RC1IF == 1)       //Verdadeiro quando chegar algum byte no buffer serial
      {
        if(RCSTA1.OERR == 1)   //Caso ocorra overflow do buffer de recep��o da UART
          {
             RCSTA1.CREN = 0;  //devemos resetar, pois caso contr�rio nenhum outro byte
             RCSTA1.CREN = 1;  //que vier pela serial n�o ser� armazenado no buffer de recep��o
          }                    //Portando podemos resertar o perif�rico UART na recep��o
                               //para apagar esse bit de erro.

          TXREG = RCREG ;     //RCREG � o registrador que armazena o byte que chegou pela UART
          PIR1.RC1IF = 0;      //TXREG � o registrador de envio
      }

   }
}






