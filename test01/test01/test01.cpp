#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	//������ ����
	char vchar;
	int vint;
	int vlong;
	float vfloat;
	double vdou;

	//������ �ʱ�ȭ
	vchar = 'f';
	vint = 10;
	vlong = 4000000000;
	vfloat = 3.14159265;
	vdou = 314159265.123456789;

	printf("\n�ȳ��ϼ���\n");
	printf("%8x \n%8x \n%8x \n%8x\n", &vchar, &vint, &vlong, &vfloat);
	scanf("%c %d %d %f", &vchar, &vint, &vlong, &vfloat);
	printf("  ���� ��� �׽�Ʈ: [%12d]\n", vint); // 4byte
	printf("  �Ǽ� ��� �׽�Ʈ: [%12.8f]\n", vfloat); //
	printf("  ���� ��� �׽�Ʈ: [%12e]\n", vdou); // 4byte
	printf(" 8���� ��� �׽�Ʈ: [%12o]\n", vint); // 4byte
	printf("16���� ��� �׽�Ʈ: [%12x]\n", vint); // 4byte
	printf("  ���� ��� �׽�Ʈ: [%c]\n", vchar); // 4byte
	printf("  ���� ���� �׽�Ʈ: [%c]\n", vchar + 1); // 4byte
	return 0;
}