#define F_CPU 16000000L
#define FUNCSET 0x28		//Function Set
#define ENTMODE 0x06		//ENTRY MODE Set
#define ALLCLR 0x01			//All Clear
#define DISPON 0x0c			//Display On
#define LSHIFT 0x18			//Display Left Shift
#define HOME 0x02			//Cursor Home
#include <avr/io.h>
#include <util/delay.h>

uint8_t cg_pat[24] = {
	0x01, 0x0d, 0x13, 0x13, 0x13, 0x0d, 0x01, 0x01,				//이
	0x00, 0x04, 0x0a, 0x11, 0x1f, 0x04, 0x0a, 0x04,				//승
	0x01, 0x1d, 0x15, 0x15, 0x1d, 0x01, 0x08, 0x0f,				//민
};

void COMMAND(unsigned char byte);

// COMMAND 함수 선언

void DATA(unsigned char byte);

// DATA 함수 선언

void LCD_INIT(void);

char charr[] = {'M','y',' ', 'N', 'a', 'm', 'e', ' ', 'i', 's', ' ', '\0'};

int main(void)
{
	/* Replace with your application code */
	DDRC = 0xff;
	PORTC = 0x00;
	int i;
	LCD_INIT();
	COMMAND(0x0c);				//표시 on
	
	
	
	
	for (i = 0; i < (sizeof(cg_pat)); i++)
	{
		COMMAND(0x40 + i);
		_delay_ms(1);
		DATA(cg_pat[i]);
		_delay_ms(1);
	}
	LCD_INIT();
	for (i = 0; i < 11; i++)
	DATA(charr[i]);
	for (i = 0; i < 3; i++)
	{
		DATA(i);
		_delay_ms(1);
	}
	
	
	
	
	
	
	while(1) {};
	
	return 0;
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