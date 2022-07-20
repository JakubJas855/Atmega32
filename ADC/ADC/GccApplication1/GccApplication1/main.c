/*
 *
 * Created: 24.03.2022 18:25:34
 * Author : Jakub
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
    DDRB=0xFF;
	DDRD=0xFF;
	DDRA=0x00;

	
	
		PORTD=0b00000010;
		_delay_ms(100);
		PORTB=0b00110000;
		PORTD=0x00;
		_delay_ms(5);
		
		PORTD=0b00000010;
		PORTB=0b00110000;
		PORTD=0x00;
		_delay_ms(2);
		
		PORTD=0b00000010;
		PORTB=0b00110000;
		PORTD=0x00;
		_delay_ms(2);
		
		PORTD=0b00000010;
		PORTB=0b00111100;
		PORTD=0x00;
		_delay_ms(2);
		
		PORTD=0b00000010;
		PORTB=0b00001000;
		PORTD=0x00;
		_delay_ms(2);
		
		PORTD=0b00000010;
		PORTB=0b00000001;
		PORTD=0x00;
		_delay_ms(3);
		
		PORTD=0b00000010;
		PORTB=0b00000110;
		PORTD=0x00;
		_delay_ms(2);
		
		PORTD=0b00000010;
		PORTB=0b00001111;
		PORTD=0x00;
		_delay_ms(2);
		
		/*	PORTD=0b00000011;
		PORTB='t';
		PORTD=0x00;
		_delay_ms(150);
		
		while (1)
		
		{
			
		}
		*/
		
	
uint16_t wynik;
	uint8_t a, b,d;
	
	int c=0;
	
    DDRA=0x00;
	DDRC=0xFF;
	PORTC=0x00;
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
		
		a=ADCL;
		//c=~a;
	b=ADCH;	
	//d=~b;
	wynik=a+(b<<8);
	
	if(wynik<200)
	{
		c=0;
		PORTC=0x00;
	}
	if(wynik>206 && wynik<410)
	{
		c=1;
		PORTC=0b00000011;
	}
	if(wynik>410 && wynik<615)
	{
		c=2;
		PORTC=0b00001111;
	}
	if(wynik>615 && wynik<820)
	{
		c=3;
		PORTC=0b00111111;
	}
	if(wynik>820 && wynik<1000)
	{
		c=4;
		PORTC=0b01111111;
	}
	if(wynik>1000)
	{
		c=5;
		PORTC=0xFF;
	}
	PORTD=0b00000011;
		PORTB=c+48;
		PORTD=0x00;
		_delay_ms(150);
	
	PORTD=0b0000010;
		PORTB=0b00000001;
		PORTD=0x00;
		_delay_ms(50);		
		
		//PORTC=c;
		//_delay_ms(100);
	
		
		//PORTC=b;
		//_delay_ms(100);
		
		
	}
    
	}
