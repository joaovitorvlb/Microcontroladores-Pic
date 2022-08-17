//******************************************************************************
//Resposta do desafio
//Condição: Programe o canal PWM para saída a 10KHz com duty cycle de 25% usando
//o periférico CCP1
//******************************************************************************
//
// Cristal usado: Fosc = 8MHz
//
//1° Etapa: Cálculo do Período
//Fórmula: 
//PR2 = ( ((Fosc)/(4 * FPWM * PRESCALER)) -1)
//PR2 = (8.000.000Hz / (4 * 10.000Hz * 4) ) - 1
//PR2 = 49

//2° Etapa: Cálculo do Duty Cycle
//Fórmula:
//CCPRxL:CCPxCON<5:4> = (%DCpwm * Fosc) /  (100 * PRESCALER * FPWM)
//CCPRxL:CCPxCON<5:4> = (25 * 8.000.000Hz) / (100 * 4 * 10.000Hz)
//CCPRxL:CCPxCON<5:4> = 50

void PWMInit()
{
  CCP1CON = 0;
  CCP1CON = 0B00001100;  //Modo PWM

//Responsável pelo Duty Cycle do PWM  (0B00001100 10)
  CCP1CON.B4 = 0;
  CCP1CON.B5 = 1;
  CCPR1L = 0B00001100;
  //*****************************************

  //Determinar o valor do Período do PWM
  T2CON = 0B00000101; //Timer2ON, Prescaler 1:4
  PR2 = 49;

  //Obrigatóriamente o pino CCP1 deve ser configurado como saída
  TRISC.RC2 = 0;
}


void main() {
 PWMInit();

 while(1);  //loop sem saida

}


