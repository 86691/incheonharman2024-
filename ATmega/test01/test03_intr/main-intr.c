/*
 * test03_intr.c
 *
 * Created: 2024-03-27 오후 12:25:38
 * Author : SYSTEM-00
 */ 

//#include "myHeader.h"
#define  F_CPU 16000000L

#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define __delay_t  500
#define OPMODEMAX     3
#define STATE_MAX     3

extern char* Disp(unsigned long num); 

volatile int opmode = 0, state = 0; // 최적화 금지

void TogglePinA(int n, double dl) //  n: n번째 비트, dl : delay in mili-second
{
	char b = 1 << n;
	PORTA |= b; // PORTA의 0번째 비트를 high로 출력
	_delay_ms(__delay_t);
	PORTA &= ~b; // PORTA의 0번째 비트를 low로 출력
	_delay_ms(__delay_t);
}

int main(void)
{
    /* Replace with your application code */
	// 7-Segment 사용 : 4 Module = C type
	//   pin assign : PAx = Segment img, PBx = module sel
	// interrupt 사용 : INT4 ~ INT6 (Ext Int)
	//   pin assign : PE4 ~ PE6
    
	DDRA |= 0x07;
	DDRD = 0xFF; // 세그먼트
	DDRF = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
	
	// 인터럽트 설정
	EIMSK = 0x70; // 0111 0000b
	EICRB = 0x2A; // 0010 1010b
	SREG |= 0x80; // status Register - 인터럽트 허용
	sei();        // set interrupt - 인터럽트 시작
	
	int t = 0,t2 = 0;

	while (1) 
    {
		switch(opmode)
		{
			
			case 0: // reset & wait
				t = 0; break;
			case 1: // counter start
				t++;
				break;
			case 2: // count stop
				break;
			case 3: // counter start
				if(t > 0) t--;
				if(t == 0) opmode += 2;
				break;
			case 4: // count stop
				break;
			case 5:
				TogglePinA(1,__delay_t);
			default: break;
		}
		
		Disp(t);

    }
}
ISR(INT4_vect) //INT4 인터럽트 처리 루틴 : sw1
{
	opmode++;
	if(opmode >= OPMODEMAX) opmode = 0;
}
ISR(INT5_vect) //INT5 인터럽트 처리 루틴 : sw2
{
	state++;
	if(state >= STATE_MAX) state = 0;
	opmode = state+2;
}
ISR(INT6_vect) //INT6 인터럽트 처리 루틴 : sw3
{
	opmode = 0; state = 0;
}

