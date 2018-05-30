/*
 * LCD8bit_exam1.c
 *
 * Created: 2018-05-16 오전 9:20:01
 * Author : LSM
 */ 

#define F_CPU 16000000L
#define lcd_data PORTC
#define lcd_rs PORTA4
#define lcd_rw PORTA5
#define lcd_e PORTA6
#define lcd_clr command(0x01)

#include <avr/io.h>
#include <util/delay.h>

void e_pulse(void) {
	lcd_e = 1;
	_delay_ms(3);
	lcd_e = 0;
}

void command(char s) {
	lcd_rs = 0;		//읽기
	lcd_rw = 0;		//쓰기
	lcd_data = s;
	e_pulse();
}

void lcd_init(void)	{
	command(0x38);		//8비트 초기화
	command(0x38);		//8비트 초기화
	command(0x38);		//8비트 초기화
	command(0c0c);		//표시 on
	command(0x01);		//표시창 클리어
	command(0x06);		//lcd창에 한문자 표시, 커서 오른쪽
}

void lcd_one(char s) {
	lcd_rs = 1;
	lcd_data = s;
	e_pulse();
}

void gotoxy(char x, char y) {
	lcd_rs = 0;
	lcd_rw = 0;
	if(y == 0) lcd_data = x + 0x80;			//첫째줄 첫째칸 주소
	else if(y == 1) lcd_data = x + 0x0c;	//툴째줄 첫째칸 주소
	e_pulse()
}



int main(void)
{
    /* Replace with your application code */
    DDRC = 0xff;
	DDRA = 0xff;
	PORTC = 0xff;
	
	lcd_init();
	
	while (1) 
    {
		gotoxy(0,0);		//첫째줄
		lcd_one(0x41);		//A
		lcd_one(0x42);		//B
		lcd_one(0x43);		//C
		
		gotoxy(0,1);
		lcd_one(0x61);		//a
		lcd_one(0x62);		//b
		lcd_one(0x63);		//c
    }
	
	return 0;
}

