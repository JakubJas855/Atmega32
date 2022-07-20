/*
 * silnik_krokowy.c
 *
 * Created: 29.04.2022 11:36:55
 * Author : JAKUB
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void przerwania()
{
	_delay_ms(1);

}



int main(void)
{
	uint16_t wynik;
	uint8_t a, b;
    DDRD=0xFF;
	PORTD=0x00;
	
	DDRB=0x00;
	PORTB=0xFF;
	
	
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
	
	int k=0, i, x=0,y;
	
    while (1) 
    {
		a=ADCL;
		
		b=ADCH;
		
		wynik=a+(ADCH<<8);
		
		if(wynik<200)
		{
			x=0;
		}
		if(wynik>206 && wynik<410)
		{
			x=2;
		}
		if(wynik>410 && wynik<615)
		{
			x=4;
		}
		if(wynik>615 && wynik<820)
		{
			x=6;
		}
		if(wynik>820 && wynik<1000)
		{
			x=8;
		}
		if(wynik>1000)
		{
			x=10;
		}
		
		
		_delay_ms(1);
		if (PINB==0b11111101) k=1;
		_delay_ms(1);
		
		_delay_ms(1);
		if (PINB==0b11111011) k=2;
		_delay_ms(1);
		
		if(k==1)
		{
		PORTD=0b00000001;
		
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000011;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000010;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000110;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000100;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00001100;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00001000;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00001001;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		}
		
		if(k==2)
		{
		PORTD=0b00000001;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0B00001001;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00001000;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00001100;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000100;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000110;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000010;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		PORTD=0b00000011;
		for(i=0;i<x;i++)
		{
			przerwania();
		}
		}
		
		
    }
}

