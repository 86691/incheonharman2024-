#include <stdio.h>
#include <conio.h>
void test00();
void test00_1();
void test01();
void test02();
void test03();
void test04();
void test05();
void swap(int* a, int* b);

int main(void)
{
	//test00();
	//test00_1();
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
}

void test00()
{
	char buf[100];
	int i = 0;
	printf("문자열을 입력하세요.\n");
	printf(">");
	scanf("%s", buf);
	while (1)
	{
		if (*(buf + i) == 0) break;
		printf("%c", buf[i]);
		printf(" ");
		i++;
	}
}

void test00_1()
{
	char buf[100];
	int i = 0;
	char a;
	printf("문자열을 입력하세요.\n");
	printf(">");
	scanf("%s", buf);
	while (1)
	{
		if (*(buf + i) == 0) break;
		a = buf[i];
		if (a > 96 && a < 123) a -= 32;
		printf("%c", a);
		i++;
	}
}

void test01()
{
	printf("ASCII 코드표\n");
	printf("Dec  Hx  Char\n");
	for (int i = 0; i < 128; i++)
	{
		printf("%3d  ", i);
		printf("%2x  ", i);
		printf("%c  \n", i);
	}
}
void test02()
{
	int val1;
	int val2;
	printf("숫자 2개를 sawp합니다.\n");
	printf("숫자 2개를 입력하세요.\n");
	scanf("%d", &val1);
	scanf("%d", &val2);
	printf("swap 전 [0001] %d --- [0002] %d\n", val1, val2);
	swap(&val1, &val2);
	printf("swap 후 [0001] %d --- [0002] %d\n", val1, val2);
}
void test03()
{
	int a;
	while (1)
	{
		printf("> 숫자(홀수)를 입력하시오\n");
		int n = scanf("%d", &a); //정상적인 입력 n =1, 오류 n = 0
		if (n == 0 || (a % 2) == 0) // n == 0 입력오류
		{
			fflush(stdin); // 버퍼 클리어
			rewind(stdin); // 버퍼 포인터 초기화
			continue;
		}
		else break;
	}
	for (int i = 1; i <= a; i++)
	{
		if ((i % 2) != 0)
		{
			for (int j = 0; j < (a - i) / 2; j++)
			{
				printf(" ");
			}
			for (int k = 0; k < i; k++)
			{
				printf("*");
			}
			printf("\n");
		}
	}
}
void test04()
{
	char a;
	printf("> 문자를 입력하시오\n");
	scanf("%c", &a);
	if (a >= 'a' && a <= 'z')
	{
		a -= 0x20;
	}
	if (a >= 'A' && a <= 'Z')
	{
		for (int i = a - 0x41;i >= 0;  i--)
		{
			for (int k = 0; k < (a - 0x41) -i; k++)
			{
				printf(" ");
			}
			for (int j = i; j >= 0; j--)
			{
				printf("%c", a-i);
			}
			printf("\n");
		}
	}
}
void test05()
{
	int a;
	int b;
	char c[100];
	char d[100];
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d : ", a);
	for (int i = 1; i <= a; i++)
	{
		if ((a % i) == 0)
		{
			c[i] = i;
			printf("%d,", c[i]);
		}
	}
	printf("\n");
	printf("%d : ", b);
	for (int i = 1; i <= b; i++)
	{
		if ((b % i) == 0)
		{
			d[i] = i;
			printf("%d,", d[i]);
		}
	}
	for (int i = 1; i <= (a&&b); i++)
	{
		if ((a % i) == 0)
		{
			c[i] = i;
		}
		if ((b % i) == 0)
		{
			d[i] = i;
		}

	}
	printf("\n");
	printf("%d과 %d의 최대공약수는 입니다.", a, b);
}
void swap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}