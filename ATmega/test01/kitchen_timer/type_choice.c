/*
 * type_choice.c
 *
 * Created: 2024-03-29 오후 4:14:38
 *  Author: SYSTEM-00
 */ 
#include "myHeader.h"
#include <avr/io.h>
#include <avr/delay.h>

extern unsigned long cnt;
extern int opmode, state, mode;

void TogglePinA(int n, double dl) //  n: n번째 비트, dl : delay in mili-second
{
	char b = 1 << n;
	PORTA |= b; // PORTA의 0번째 비트를 high로 출력
	_delay_ms(__delay_t);
	PORTA &= ~b; // PORTA의 0번째 비트를 low로 출력
	_delay_ms(__delay_t);
}

void mode_type()
{
	switch(mode)
	{
		case 0:
			break;
		case 1:
			opmode = 0;
			state = 1;
			cnt = 0;
			mode++;
			break;
		case 2:
			break;
		case 3:
			state = 3;
			mode++;
			break;
		case 4:
			break;
		default:
			break;
	}
}

void kitchen_timer(int a)
{
	switch(state)
	{
		
		case 0:
			cnt = a; break;
		case 1:
			break;
		case 2:
			if(cnt >= 30) cnt -=30;
			state--;
			break;
		case 3:
			if(cnt == 0) state += 2;
			break;
		case 4:
			break;
		case 5:
			TogglePinA(0,__delay_t);
			state = 0; mode = 0;
			break;
		default: break;
	}
}