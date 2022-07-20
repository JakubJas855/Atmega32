#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>


#define RS_ON PORTC|=(1<<1)
#define RS_OFF PORTC&=~(1<<1)
#define EN_ON PORTC|=(1<<0)
#define EN_OFF PORTC&=~(1<<0)


#define Crib_LCD            PORTB
#define DataDir_LCD_Crib    DDRB
#define Control             PORTC
#define DataDir_LCD_Control DDRC
#define Enable              0
#define RS                  1


void wyslij(void);
void wyslij_polecenie(unsigned char command);
void wyslij_znak(unsigned char character);
void wyslij_lancuch(char *string);

void inicjalizacjaLCD()
{
	_delay_ms(150);
	EN_ON;
	PORTB=0b00110000;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	EN_ON;
	PORTB=0b00110000;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	EN_ON;
	PORTB=0b00110000;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	EN_ON;
	PORTB=0b00111100;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	EN_ON;
	PORTB=0b00001000;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	EN_ON;
	PORTB=0b00000001;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	EN_ON;
	PORTB=0b00000110;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	EN_ON;
	PORTB=0b00001111;
	_delay_ms(1);
	EN_OFF;
	_delay_ms(5);
	
}

int main(void)
{

	uint16_t a,old;
	//ustalenie kierunku we/wyj
	DDRD=0xFF;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRA=0;
	//inicjalizacja LCD
	inicjalizacjaLCD();
	
	//konfiguracja ADC i uruchomienie free running
	PORTA=0x00;
	ADCSRA=0b10000000;
	ADCSRA=0b10100111;
	ADMUX=0b01000001;
	SFIOR&=(0<<7);
	SFIOR&=(0<<6);
	SFIOR&=(0<<5);
	ADCSRA|=(1<<6);
	//konfiguracja T1 Fast PWM TOP=ICR1 f=50Hz
	
	TCCR1A=0b10000010;
	TCCR1B=0b00011101;
	ICR1=312;
	
	
	while (1)
	{
		a=ADC;
		
		
		
		OCR1A=a/28;
		
		
		char doLCD[3];
		uint16_t pomiar;
		uint16_t odczyt;
		odczyt=ADC ;
		pomiar= odczyt*0.305/3.12;
		if((old>pomiar+1)||(old<=pomiar-1))
		{
			
			
			//dtostrf(pomiar,4,2,wynik);
			
			itoa(pomiar, doLCD, 10);			//Convert the ADC conversion result to a string
			wyslij_polecenie(0x01);
			wyslij_lancuch("wypelnienie:");
			wyslij_lancuch(doLCD);			//Display the string on the LCD
			wyslij_lancuch("%");
			_delay_ms(10);
		}
		else
		_delay_ms(10);
		old=pomiar;
	}
}

void wyslij(){
	Control |= 1<<Enable;
	_delay_ms(10);
	Control &= ~(1<<Enable);
}
void wyslij_polecenie(unsigned char command)
{
	
	Crib_LCD = command;
	Control &= ~ (1<<RS);
	wyslij();
	Crib_LCD = 0;
}
void wyslij_znak(unsigned char character)
{
	
	Crib_LCD = character;
	Control |= (1<<RS);
	wyslij();
	Crib_LCD = 0;
}

void wyslij_lancuch(char *string)
{
	while(*string > 0)
	{
		wyslij_znak(*string++);
	}
}