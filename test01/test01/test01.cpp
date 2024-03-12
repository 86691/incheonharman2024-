#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	//변수의 선언
	char vchar;
	int vint;
	int vlong;
	float vfloat;
	double vdou;

	//변수의 초기화
	vchar = 'f';
	vint = 10;
	vlong = 4000000000;
	vfloat = 3.14159265;
	vdou = 314159265.123456789;

	printf("\n안녕하세요\n");
	printf("%8x \n%8x \n%8x \n%8x\n", &vchar, &vint, &vlong, &vfloat);
	scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);
	printf("  정수 출력 테스트: [%12d]\n", vint); // 4byte
	printf("  실수 출력 테스트: [%12.8f]\n", vfloat); //
	printf("  지수 출력 테스트: [%12e]\n", vdou); // 4byte
	printf(" 8진수 출력 테스트: [%12o]\n", vint); // 4byte
	printf("16진수 출력 테스트: [%12x]\n", vint); // 4byte
	printf("  문자 출력 테스트: [%c]\n", vchar); // 4byte
	printf("  문자 연산 테스트: [%c]\n", vchar + 1); // 4byte
	return 0;
}