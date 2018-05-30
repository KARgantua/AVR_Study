/*
 * LCD_G_letter.c
 *
 * Created: 2018-05-02 오전 9:25:02
 * Author : LSM
 */ 

#define F_CPU 16000000L
#include <avr/io.h>
#include <util/delay.h>

void COMMAND(unsigned char byte);
void DATA(unsigned char byte);
void LCD_INIT(void);
char testcase;
int main(void)
{
    /* Replace with your application code */
	DDRC = 0xff;
	PORTC = 0x00;
	
	LCD_INIT();
	testcase = 'H';
	DATA(testcase);
	
    while (1);
}

void COMMAND(unsigned char byte)
{
	_delay_ms(2);
	
	PORTC = byte & 0xf0;
	PORTC &= 0b11111100;
	
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
	PORTC = (byte << 4) & 0xf0;
	PORTC &= 0b11111100;
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
}

void DATA(unsigned char byte)
{
	_delay_ms(2);
	
	PORTC = byte & 0xf0;
	
	PORTC |= 0b00000001;
	PORTC &= 0b11111101;
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
	
	PORTC = (byte << 4) & 0xf0;
	
	PORTC |= 0b00000001;
	
	PORTC &= 0b11111101;
	
	_delay_us(1);
	PORTC |= 0b00000100;
	_delay_us(1);
	PORTC &= 0b11111011;
}

void LCD_INIT(void)
{
	_delay_ms(30);
	
	COMMAND(0b00101000);
	_delay_us(39);
	
	COMMAND(0b00001100);
	_delay_us(39);
	
	COMMAND(0b00000001);
	_delay_ms(1.53);
	COMMAND(0b00000110);
}