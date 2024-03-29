/*
 * kitchen_timer.c
 *
 * Created: 2024-03-28 오후 4:49:27
 * Author : SYSTEM-00
 */ 
#include "myHeader.h"
#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>

#define OPMODEMAX     3
#define STATE_MAX1     2
#define STATE_MAX2     4
#define mode_MAX     4

unsigned long cnt = 0;
volatile int opmode = 0, state = 0, mode = 0; // 최적화 금지

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
	SegPort(&PORTD, &PORTF);
	
	TIMSK |= 0x04; // 0000 0100b - Timer 1 TCNT overflow interrupt (16bit)
	TCCR1B = 0x04;  // 분주비 (Pre-Scaler) 64
	// 인터럽트 설정
	EIMSK = 0x70; // 0111 0000b
	EICRB = 0x2A; // 0010 1010b
	SREG |= 0x80; // status Register - 인터럽트 허용
	sei();        // set interrupt - 인터럽트 시작
	
	int t = 0;

	while (1) 
    {
		switch(opmode)
		{
			case 0: // reset & wait
				t = 0; break;
			case 1: // counter start
				if(mode == 2)
				{
					cnt+=30;
					opmode -=1;
				}
				else
				{
					t = cnt;
				}
				if(t == 90)
				{
					opmode+=2;
				}
				break;
			case 2: // count stop
				break;
			case 3:
				TogglePinA(2,__delay_t);
				t++;
				opmode -= 2;
				break;
			default: break;
		}
		mode_type();
		kitchen_timer(t);
		SegDisp(cnt);
		
    }
}
ISR(INT4_vect) //INT4 인터럽트 처리 루틴 : sw1
{
	opmode++;
	if(opmode >= OPMODEMAX) opmode = 0;
}
ISR(INT5_vect) //INT5 인터럽트 처리 루틴 : sw2
{
	if(mode == 2)
	{
		state++;
		if(state > STATE_MAX1) state = 1;
	}
	if(mode == 4)
	{
		state++;
		if(state > STATE_MAX2) state = 3;
	}
}
ISR(INT6_vect) //INT6 인터럽트 처리 루틴 : sw3
{
	mode++;
	if(mode > mode_MAX) 
	{
		opmode = 0; state = 0;
		mode = 0;
	}
}

ISR(TIMER1_OVF_vect)
{
	if(state == 0 && opmode == 1) cnt++;
	if(state == 3 && cnt > 0) cnt--;
}