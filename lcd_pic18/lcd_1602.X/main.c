/*
 * File:   main.c
 * Author: joaovitor
 *
 * Created on August 28, 2022, 5:19 PM
 */

// PIC18F45K22 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config FOSC = HSHP      // Oscillator Selection bits (HS oscillator (high power > 16 MHz))
#pragma config PLLCFG = OFF     // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON    // Primary clock enable bit (Primary clock is always enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 190       // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = ON       // Watchdog Timer Enable bits (WDT is always enabled. SWDTEN bit has no effect)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1  // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
#pragma config CCP3MX = PORTB5  // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0   // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTD2   // ECCP2 B output mux bit (P2B is on RD2)
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


#include <xc.h>

/*
 * File:   main.c
 * Author: joaovitor
 *
 * Created on August 28, 2022, 5:19 PM
 */

// PIC18F45K22 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config FOSC = HSHP	 // Oscillator Selection bits (HS oscillator (high power > 16 MHz))
#pragma config PLLCFG = OFF	 // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON // Primary clock enable bit (Primary clock is always enabled)
#pragma config FCMEN = OFF	 // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF	 // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = OFF	   // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = SBORDIS // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 190	   // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = ON	 // Watchdog Timer Enable bits (WDT is always enabled. SWDTEN bit has no effect)
#pragma config WDTPS = 32768 // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1 // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON	   // PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
#pragma config CCP3MX = PORTB5 // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON	   // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0  // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTD2  // ECCP2 B output mux bit (P2B is on RD2)
#pragma config MCLRE = EXTMCLR // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON	   // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>

#define _XTAL_FREQ 8000000

#define LCD_DATA4_TRIS TRISDbits.RD4
#define LCD_DATA4_IO LATDbits.LATD4
#define LCD_DATA5_TRIS TRISDbits.RD5
#define LCD_DATA5_IO LATDbits.LATD5
#define LCD_DATA6_TRIS TRISDbits.RD6
#define LCD_DATA6_IO LATDbits.LATD6
#define LCD_DATA7_TRIS TRISDbits.RD7
#define LCD_DATA7_IO LATDbits.LATD7

#define LCD_RS_TRIS TRISEbits.TRISE2
#define LCD_RS_IO LATEbits.LATE2
#define LCD_EN_TRIS TRISEbits.TRISE1
#define LCD_EN_IO LATEbits.LATE1

#define LCD_Clear (0x01)
#define LCD_Shift_LEFT (0x18)
#define LCD_Shift_Right (0x1C)
#define LCD_Cursor_OFF (0X0C)
#define LCD_Cursor_Blink (0X0D)
#define LCD_Cursor_Alt (0X0F)
#define LCD_Cursor_Home (0X02)

#define LCD_DATA_PORT_IO (PORTD)
#define LCD_DATA_PORT_TRIS (TRISD)

#define LCD4bits // escolha uma das duas opções

void DisplayLCD_Out(unsigned char Linha, unsigned char Coluna, unsigned char *TextoLCD);
void DisplayLCD_Out_Cp(unsigned char *TextoLCD);
void DisplayLCD_Chr(unsigned char Linha, unsigned char Coluna, unsigned char TChar);
void DisplayLCD_Chr_Cp(unsigned char TChar);
void DisplayLCD_Cmd(unsigned char Data);
void DisplayLCD_Init(); // modo 4bits ou 8bits
void LCD_Enable();
void LCD_Write_Data(unsigned char RS, unsigned char Data);
void DisplayLCD_Out_Cp(unsigned char *Ponteiro);

//****************************Funções
void LCD_Write_Data(unsigned char RS, unsigned char Data)
{
	//*****************************************************************************
	// exemplo: Data   10110010
	//              & 00010000 (ou 0x10;  observação: lembre-se que & é bit a bit)
	//                --------
	//              = 00010000
	// agora
	//                00010000
	//             == 00010000 (ou 0x10)
	//                --------
	//              = 1        (retorna 1)
	//*****************************************************************************

	LCD_RS_IO = RS; // 0

	__delay_ms(2);
	LCD_DATA4_IO = ((Data & 0x10) == 0x10);
	LCD_DATA5_IO = ((Data & 0x20) == 0x20);
	LCD_DATA6_IO = ((Data & 0x40) == 0x40);
	LCD_DATA7_IO = ((Data & 0x80) == 0x80);

	LCD_Enable();

	Data = Data << 4; // Rotaciona o nibble o LSB para a posição MSB
	LCD_DATA4_IO = ((Data & 0x10) == 0x10);
	LCD_DATA5_IO = ((Data & 0x20) == 0x20);
	LCD_DATA6_IO = ((Data & 0x40) == 0x40);
	LCD_DATA7_IO = ((Data & 0x80) == 0x80);

	LCD_Enable();
}

void LCD_Enable(void) // INSTRUÇÃO DE CLOCK PARA O LCD
{
	__delay_us(40);
	LCD_EN_IO = 1;
	__delay_us(40);
	LCD_EN_IO = 0;
	__delay_us(40);
}

void DisplayLCD_Cmd(unsigned char CmdLCD)
{
	LCD_Write_Data(0, CmdLCD); // RS = 0, -> COMANDO A SER PROCESSADO
}

void DisplayLCD_Chr_Cp(unsigned char Tchar)
{
	LCD_Write_Data(1, Tchar); // RS = 1 -> DADO A SER ESCRITO
}

// funções
void DisplayLCD_Init()
{ // modo 4bits ou 8bits
	LCD_DATA4_TRIS = 0;
	LCD_DATA4_IO = 0;
	LCD_DATA5_TRIS = 0;
	LCD_DATA5_IO = 0;
	LCD_DATA6_TRIS = 0;
	LCD_DATA6_IO = 0;
	LCD_DATA7_TRIS = 0;
	LCD_DATA7_IO = 0;
	LCD_EN_TRIS = 0;
	LCD_RS_IO = 0;
	LCD_RS_TRIS = 0;
	LCD_RS_IO = 0;

	__delay_ms(100); // Tempo necessário para inicialização do LCD após power-on

	LCD_DATA4_IO = 1;
	LCD_DATA5_IO = 1;
	LCD_Enable();
	LCD_Enable();
	LCD_Enable();

	__delay_ms(1);

	LCD_DATA4_IO = 0;
	LCD_DATA5_IO = 1;
	LCD_Enable();
	LCD_Enable();
	LCD_Enable();

	__delay_ms(1);

	DisplayLCD_Cmd(0X28); // 2X linhas 7x5 em modo 4bits
	DisplayLCD_Cmd(0X0C);
	DisplayLCD_Cmd(0X06);
	DisplayLCD_Cmd(0X01);
}

// DisplayLCD_Out(1,2, "BOM DIA");
void DisplayLCD_Out(unsigned char Linha, unsigned char Coluna,
					unsigned char *TextoLCD)
{
	LCD_RS_IO = 0; // TRATAR PRIMEIRO AS COORDENADAS X E Y
	switch (Linha)
	{
	case 1:
	{
		Coluna = Coluna + 0X7F;	   // 2 + 0X7F = 0X81
		LCD_Write_Data(0, Coluna); // Comando, visto que estamos posicionando o cursor
		// LCD_Enable();
		break;
	}
	case 2:
	{
		Coluna = Coluna + 0xBF; // 2 + 0xBF = 0XC1
		LCD_Write_Data(0, Coluna);
		// LCD_Enable();
		break;
	}
	}
	DisplayLCD_Out_Cp(TextoLCD); // Escreve no LCD "BOM DIA"
}

//'A' = 65
//"A" != 65 ???
//"A" = 'A' + '\0' OU  'A' + 0

// DisplayLCD_Out_Cp("BOM DIA");
void DisplayLCD_Out_Cp(unsigned char *Ponteiro)
{
	// LCD_RS_IO = 1;  //ESCREVER UM DADO
	while (*Ponteiro) // loop até encontrar o caractere NULL (ZERO)
	{
		LCD_Write_Data(1, *Ponteiro); // RS =1, ESCREVENDO NO LCD
		// LCD_Enable();
		++Ponteiro;
	}
}

// DisplayLCD_Chr_Cp(1,6,'A');
void DisplayLCD_Chr(unsigned char Linha, unsigned char Coluna,
					unsigned char Tchar)
{
	LCD_RS_IO = 0; // TRATAR PRIMEIRO AS COORDENADAS X E Y
	switch (Linha)
	{
	case 1:
	{
		Coluna = Coluna + 0x7F;
		LCD_Write_Data(0, Coluna);
		// LCD_Enable();
		break;
	}
	case 2:
	{
		Coluna += 0xBF;
		LCD_Write_Data(0, Coluna);
		// LCD_Enable();
		break;
	}
	}
	DisplayLCD_Chr_Cp(Tchar); // ESCREVE NO LCD
}

void ConfigMCU()
{

	ANSELB = 0; // Configura PORTB como I/O digital
}
void main()
{

	ConfigMCU();

	TRISBbits.TRISB0 = 0;
	TRISBbits.TRISB1 = 0;

	DisplayLCD_Init(); // Inicializar display no modo 4 bits
	DisplayLCD_Cmd(LCD_Clear);
	DisplayLCD_Out(1, 1, "  LCD Display  ");
	DisplayLCD_Out(2, 1, "  4-bit mode");
	DisplayLCD_Chr(2, 13, 'A');
	DisplayLCD_Chr_Cp('%');

	while (1)
	{
		LATBbits.LATB1 = 1;
		__delay_ms(500);
		LATBbits.LATB1 = 0;
		__delay_ms(500);
	}
}
