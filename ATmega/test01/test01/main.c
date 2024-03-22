/*
 * test01.c
 *
 * Created: 2024-03-20 오전 11:42:04
 * Author : SYSTEM-00
 */ 
#define  F_CPU 16000000L // b/d clk 정보 (16Mhz)
#include <avr/io.h>
#include <avr/delay.h>
#include <util/delay.h>

const int _delay_t = 500;
void TogglePinA(int n, double dl) //  n: n번째 비트, dl : delay in mili-second
{
	char b = 1 << n;
	PORTA |= b; // PORTA의 0번째 비트를 high로 출력
	_delay_ms(_delay_t);
	PORTA &= ~b; // PORTA의 0번째 비트를 low로 출력
	_delay_ms(_delay_t);
}

int main(void)
{
    /* Replace with your application code */
	//DDRA |= 0x01;  //A port의 0번째 비트를 출력용으로 사용, 나머지는 입력
	//DDRA |= 0x02;  //A port의 1번째 비트를 출력용으로 사용, 나머지는 입력
	DDRA |= 0x07;//DDR = 설정 레지스터
	DDRB &= ~0x01; // PORTB의 0번째 비트를 입력용으로 사용, 나머지는 그대로 유지
	int mode = 0; // mode1 : red  mode2 : green  mode3 : blue  flash
    while (1) // embedded program은 무한 루프가 기본
    {
		//if(PINB & 0x01 == 1) // SW가 안눌렸울때 true (0을 넣으면 정상적인 프로그램X)
		if(!(PINB & 0x01 == 1)) // SW가 눌렸을 때 true
		{
			mode++;
			if(mode >= 3) mode = 0;
		}
		switch(mode)
		{
			case 0:
			TogglePinA(0,_delay_t); // PortA의 0번째 비트로 점멸
			break;
			case 1:
			TogglePinA(1,_delay_t); // PortA의 1번째 비트로 점멸
			break;
			case 2:
			TogglePinA(2,_delay_t); // PortA의 2번째 비트로 점멸
			break;
			default:
			mode = 0;
		}
		/*PORTA |= 0x01; // PORTA의 0번째 비트를 high로 출력
		_delay_ms(500);
		PORTA &= ~0x01; // PORTA의 0번째 비트를 low로 출력
		_delay_ms(500);
		PORTA |= 0x02; // PORTA의 0번째 비트를 high로 출력
		_delay_ms(500);
		PORTA &= ~0x02; // PORTA의 0번째 비트를 low로 출력
		_delay_ms(500);
		PORTA |= 0x04;
		_delay_ms(500);
		PORTA &= ~0x04;
		_delay_ms(500);*/
    }
	
}

