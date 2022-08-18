//Programa de teste de comunicação Serial (transmissão e recepção)
//Definir operação em 9600bps
//Dica: Normalmente o PORTC do microcontrolador é a porta de comunicação (UART, I2C, SPI, ...)

//Definições
#define FOSC (8000000L)
#define BAUD (115200L)

//Protótipos
void ConfigUART();
void ConfigMCU();

void ConfigUART()
{
   //Transmissão Serial
   TXSTA1.TXEN = 1;    //Habilita a transmissão Serial
   RCSTA1.CREN = 1;    //Habilita a Recepção Serial
   RCSTA1.SPEN = 1;    //Habilita o periférico Serial (válido tanto para recepção quanto para transmissão)

   //Cáculo de BaudRate 115200 bps****************************************************
   //SPBRG1 = (((FOSC/BAUD)/4) - 1);  
   //se for modo 8 bits -> usa apenas o registrador SPBRG1
   //se for modo 16bits -> usa os dois registradores (SPBRGH1:SPBRG1)
   SPBRG1 = (((FOSC/BAUD)/4) - 1);
   SPBRGH1 = 0;
   BAUDCON1.BRG16  = 1;    //modo 16bits desativado
   TXSTA1.BRGH   = 1;      //modo 8 bits
   TXSTA1.SYNC   = 0;      //modo assincrono
   //***********************************************************************



   TRISC.RC6 = 0;   //Pino RX configurado como saída
   TRISC.RC7 = 1;   //Pino TX configurado como entrada

   RC1REG = 0;      //Apaga o buffer de recepção
   TX1REG = 0;      //Apaga o buffer de transmissão

   PIR1.RC1IF = 0;  //Apaga flag de recepção
   PIR1.TX1IF = 0;  //Apaga flag de transmissão

}


void ConfigMCU()
{
  #ifdef P18F45K22
   ANSELC = 0;   //Configura o PORTC como I/O digital, pois os pinos RX e TX estão nessa porta
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
        if(RCSTA1.OERR == 1)   //Caso ocorra overflow do buffer de recepção da UART
          {
             RCSTA1.CREN = 0;  //devemos resetar, pois caso contrário nenhum outro byte
             RCSTA1.CREN = 1;  //que vier pela serial não será armazenado no buffer de recepção
          }                    //Portando podemos resertar o periférico UART na recepção
                               //para apagar esse bit de erro.

          TXREG = RCREG ;     //RCREG é o registrador que armazena o byte que chegou pela UART
          PIR1.RC1IF = 0;      //TXREG é o registrador de envio
      }

   }
}






