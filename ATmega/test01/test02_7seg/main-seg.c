/*
 * test02_7seg.c
 *
 * Created: 2024-03-21 오후 3:34:38
 * Author : SYSTEM-00
 */ 

#define  F_CPU 16000000L
#include <avr/io.h>
#include <avr/delay.h>
#define __delay_t  500

uint8_t digit[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x27, 0x7F, 0x67, 0x77, 0x7C, 0x58, 0x5E, 0x79,0x71,0x00};
char arr[5]; // 세그먼트 이미지 정보를 담은 안전 영역

/*void LED(char *p, int n) // p: PORTx의 포인터, n: n번째 비트
{
	char b = 1 << n;
	*p |= b; // PORTA의 n번째 비트를 high로 출력
	_delay_ms(__delay_t);
	*p &= ~b; // PORTA의 n번째 비트를 low로 출력
	_delay_ms(__delay_t);
}*/

/*void display (int *d)
{
	int i;
	for(i = 0; i < 4; i++)
	{
		// 해당자리에만 0(GND)을 출력하고 나머지에는 1을 출력하여 자리 선택
		PORTD |= 0x0F;
		PORTD &= ~(1 <<(3-i));
		PORTE = digit[d[i]]; //a타입이면 반전필요, c타입은 반전X // 숫자데이터 출력
		_delay_ms(2.5); // 0.0025초 간격으로 전환
	}
	
}*/

void seg(int sel, uint8_t c)
{
	PORTF |= 0x0F;
	PORTF &= ~(1 <<(3-sel));
	PORTD = c; // 숫자 데이터 출력
	_delay_ms(1); // 0.01초 간격으로 전환
}

void FND_4(char *inf) // segment Image 배열
{
	for(int i = 0; i < 4; i++)
	{
		seg(i, *(inf+i));
		//seg(i, inf[i]);
	}
}

char* Trans(unsigned long num) // 10진 정수 ==>16진수 문자열 : 56506 ==> 0xDCBA // 문자열 다룰시 안전영역 고려, 정적변수에 넣어주는게 좋음
                     //          ==>16진수 segement Image 배열
					 // int가 2byte여서 0x8000이 되면 범위를 넘어가서 unsigned long을 사용해야함
{
	int n1 = num % 0x10;               // A (10) : 문자가 아닌 숫자
	int n2 = (num / 0x10) %16;         // B (11)
	int n3 = (num / 0x100) %16;         // C (12)
	int n4 = (num / 0x1000);           // D (13)
	if(!(num / 0x1000))
	{
		n4 = 16;
		if(!(num / 0x100))
		{
			n3 =16;
			if(!(num / 0x10)) n2 = 16;
		}
	}
	
	arr[0] = digit[n1]; // char : 8bit
	arr[1] = digit[n2];
	arr[2] = digit[n3];
	arr[3] = digit[n4];
	
	//FND_4(arr);
	return arr;
}

int main(void)
{
    /* Replace with your application code */
	unsigned long j = 0; // int가 2byte여서 0x8000이 되면 범위를 넘어가서 unsigned long을 사용해야함
	int mode = 0;
	//int count = 0;
	//int d[4];
	DDRB &= ~0x01;
	DDRD = 0xFF; // 세그먼트 
	DDRF = 0x0F; // 자릿수 선택 핀 4개를 출력으로 설정
	
    while (1) 
    {
		/*LED(PORTD, 1); // PORTD의 0번째 비트를 점멸
		for(i = 0; i < 4; i++)
		{
			// 해당자리에만 0(GND)을 출력하고 나머지에는 1을 출력하여 자리 선택
			PORTD |= 0x0F;
			PORTD &= ~(1 << i);
			
			for(j = 0; j< 16; j++)
			{
				PORTE = digit[j]; //a타입이면 반전필요, c타입은 반전X // 숫자데이터 출력
				_delay_ms(100); // 0.2초 간격으로 전환
			}
		}*/
		/*if(!(PINB & 0x01 == 1))
		{
			_delay_ms(300);
			mode++;
			if(mode >= 3) 
			{
				mode = 0;
				count = 0;
			}
		}
		switch(mode)
		{
			case 0:
			PORTD &= ~0x0F;
			PORTE = 0x40;
			break;
			
			case 1:
			d[0] = count%10;
			d[1] = (count%100)/10;
			d[2] = (count%1000)/100;
			d[3] = count/1000;
			display(d);
			count++;
			if(count >= 10000) count = 0;
			break;
			
			case 2:
			display(d);
			break;
			
			default:
			mode = 0;
			count = 0;
		}*/
		if(!(PINB & 0x01) == 1)
		{
			_delay_ms(300);
			mode++;
			if(mode >= 3) 
			{
				mode = 0;
				j = 0;
			}
		}
		switch (mode)
		{
		case 0:
		PORTF &= ~ 0x0F;
		PORTD = 0x40;
		break;
		
		case 1:
		if(j >= 0x10000) j = 0;
		FND_4(Trans(j++));
		break;
		
		case 2:
		FND_4(Trans(j));
		break;
		
		default:
		mode = 0;
		j = 0;
		}
    }
}

