/*
 * timery.c
 *
 * Created: 08.04.2022 11:16:27
 * Author : JAKUB
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void opoznienie()
{
	_delay_ms((2000));
}


int main(void)
{
    
	DDRD=0xFF;
	PORTD=0x00;
	TCCR1A=0b10000010;
	TCCR1B=0b00011100;
	ICR1=1245;
	DDRB=0xFF;
	DDRC=0xFF;
	DDRA=0x00;
	PORTA=0x00;

	
	
		PORTC=0b00000010;
		_delay_ms(100);
		PORTB=0b00110000;
		PORTC=0x00;
		_delay_ms(5);
		
		PORTC=0b00000010;
		PORTB=0b00110000;
		PORTC=0x00;
		_delay_ms(2);
		
		PORTC=0b00000010;
		PORTB=0b00110000;
		PORTC=0x00;
		_delay_ms(2);
		
		PORTC=0b00000010;
		PORTB=0b00111100;
		PORTC=0x00;
		_delay_ms(2);
		
		PORTC=0b00000010;
		PORTB=0b00001000;
		PORTC=0x00;
		_delay_ms(2);
		
		PORTC=0b00000010;
		PORTB=0b00000001;
		PORTC=0x00;
		_delay_ms(3);
		
		PORTC=0b00000010;
		PORTB=0b00000110;
		PORTC=0x00;
		_delay_ms(2);
		
		PORTC=0b00000010;
		PORTB=0b00001111;
		PORTC=0x00;
		_delay_ms(2);
		
		
		
	
uint16_t wynik;
	uint8_t a, b,d,e;
	
	int c=0;
	
    DDRA=0x00;
	DDRC=0xFF;
	//PORTC=0x00;
	ADCSRA=0b10000000;
	_delay_ms(5);
	ADCSRA=0b10000111;
	_delay_ms(5);
	ADCSRA=0b10100111;
	_delay_ms(5);

	SFIOR=SFIOR&(0<<ADTS0)&(0<<ADTS1)&(0<<ADTS2);
	ADMUX=0b01000000;   // adlar=0 
	ADCSRA=ADCSRA|(1<<ADSC);
	
    while (1) 
    {
			
			PORTD=PORTD|(1<<3);	//wlacza silnik
			opoznienie();
			PORTD=PORTD&(~1<<3);	//wylacza silnik
			opoznienie();
		
		OCR1A=wynik;
		a=ADCL;
		//c=~a;
	b=ADCH;	
	//d=~b;
	wynik=a+(b<<8);
	PORTC=0b00000011;
		PORTB='T';
		PORTC=0b00000001;
		_delay_ms(50);
		
		PORTC=0b00000011;
		PORTB='E';
		PORTC=0b00000001;
		_delay_ms(50);
		
		PORTC=0b00000011;
		PORTB='M';
		PORTC=0b00000001;
		_delay_ms(50);
		
		PORTC=0b00000011;
		PORTB='P';
		PORTC=0b00000001;
		_delay_ms(50);
		
		
		PORTC=0b00000011;
		PORTB=0b00111010;
		PORTC=0b00000001;
		_delay_ms(50);
		
		PORTC=0b00000011;
		PORTB=e;
		PORTC=0b00000001;
		_delay_ms(50);
		
		PORTC=0b00000011;
		PORTB=c;
		PORTC=0b00000001;
		_delay_ms(50);
		
		PORTC=0b00000011;
		PORTB=0b11011111;
		PORTC=0b00000001;
		_delay_ms(50);
		
		PORTC=0b00000011;
		PORTB='C';
		PORTC=0b00000001;
		_delay_ms(2000);
	
	if(wynik<200)
	{
		e=51;
		c=52;
		PORTD=PORTD|(1<<7); //prze??czenie przeka?nika na 0
		PORTD=PORTD|(1<<6);
	}
	if(wynik>206 && wynik<410)
	{
		e=51;
		c=53;
		PORTD=PORTD|(1<<7); //prze??czenie przeka?nika na 0
		PORTD=PORTD|(1<<6);
	}
	if(wynik>410 && wynik<615)
	{
		e=51;
		c=54;
		PORTD=PORTD|(1<<7); //prze??czenie przeka?nika na 0
		PORTD=PORTD|(1<<6);
	}
	if(wynik>615 && wynik<820)
	{
		e=51;
		c=55;
		PORTD=PORTD&(~1<<7);	// prze??czenie przeka?nika na 1
		PORTD=PORTD|(1<<6);	
	}
	if(wynik>820 && wynik<1000)
	{
		e=51;
		c=56;
		PORTD=PORTD&(~1<<7);	// prze??czenie przeka?nika na 1
		PORTD=PORTD|(1<<6);
	}
	if(wynik>1000 && wynik<1200)
	{
		e=51;
		c=57;
		PORTD=PORTD&(~1<<7);	// prze??czenie przeka?nika na 1
		PORTD=PORTD&(~1<<6);	// wlacza buzzer
	}
	
		PORTC=0b00000010;
		PORTB=0b00000001;
		PORTC=0x00;
		_delay_ms(50);		
		
		
		
		
	}
	
	
}

