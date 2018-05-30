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
// COMMAND 함수 선언
void DATA(unsigned char byte);
// DATA 함수 선언
void LCD_INIT(void);
char testcase[27] = {'H','e','l','l','o','!','!',' ','D','S','M','A','t','m','e','l',' ','A','T','m','e','g','a','1','2','8','\0'};
int main(void)
{
    /* Replace with your application code */
	DDRC = 0xff;
	PORTC = 0x00;
	int i;
	LCD_INIT();
	for(i = 0; i < 10; i++){
		DATA(testcase[i]);
	}
	
    while (1);
}

void COMMAND(unsigned char byte)
{
	_delay_ms(2);
	
	PORTC = byte & 0xf0;
	// 상위 4비트 명령어 쓰기
	PORTC &= 0b11111100;
	// RS = 0, RW = 0 명령어를 쓰도록 설정
	_delay_us(1);
	PORTC |= 0b00000100;
	// E = 1, lcd 동작
	_delay_us(1);
	PORTC &= 0b11111011;
	PORTC = (byte << 4) & 0xf0;
	// 하위 4비트 명령어 쓰기
	PORTC &= 0b11111100;
	// RS = 0, RW = 0 명령어를 쓰도록 설정
	_delay_us(1);
	PORTC |= 0b00000100;
	// E = 1, lcd 동작
	_delay_us(1);
	PORTC &= 0b11111011;
}

void DATA(unsigned char byte)
{
	_delay_ms(2);
	
	PORTC = byte & 0xf0;
	// 상위 4비트 명령어 쓰기
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