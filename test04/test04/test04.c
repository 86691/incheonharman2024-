#include <stdio.h>
#include <conio.h>
#include <math.h>
void test00();
void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();
void swap(int* a, int* b);
void sin_(int i, int x, double si);

int main(void)
{
	int n;
	void* pF[] = { test00,test01,test02,test03,test04,test05,test06,test07 }; // void포인터란 타입이 정해지지않은 포인터 (이 자체로 쓸수는 없음), 사용되기전에 선언적으로 쓸수는 있음, 함수의 주소를 전부 array에 담음
	void (*pFunc)(); // 함수의 포인터 선언
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1. 문자열 한문자씩 띄우기\n");
		printf("2. 대문자로 일괄 변환\n");
		printf("3. ASCII 코드표 출력\n");
		printf("4. swap 함수\n");
		printf("5. 홀수를 입력받아 '*' 피라미드 출력\n");
		printf("6. 문자를 입력받아 출력\n");
		printf("7. 최대공약수 출력\n");
		printf("8. sin함수 출력\n");
		printf("0. 종 료\n");
		printf("--------------------------------------\n 선택 ");
		scanf("%d", &n);
		if (n == 0) return;
		pFunc = pF[n-1];
		pFunc();
	}
}

void test00() // 문자열 한문자씩 띄우기
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
void test01() // 대문자로 일괄 변환
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
		if (a > 96 && a < 123) a -= 32; // 소문자를 대문자로 변환
		printf("%c", a);
		i++;
	}
}
void test02() // ASCII 코드표 출력
{
	char* str[] = { "NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI"
		,"DLE","DC1","DC2", "DC3", "DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US","SP","DEL" };
	printf("ASCII 코드표\n");
	printf("Dec\tHx\tChar\tDec\tHx\tChar\tDec\tHx\tChar\tDec\tHx\tChar\n");
	printf("----------------------------------------------------------------------------------------------\n");
	for (int i = 0; i < 32; i++)
	{
		if (i == 0)
		{
			printf("%3d\t%2x\t%s\t%3d\t%2x\t%s\t%3d\t%2x\t%c\t%3d\t%2x\t%c\n"
				, i, i, str[i], i + 32, i + 32, str[i + 32], i + 64, i + 64, i + 64, i + 96, i + 96, i + 96);
		}
		else if (i == 31)
		{
			printf("%3d\t%2x\t%s\t%3d\t%2x\t%c\t%3d\t%2x\t%c\t%3d\t%2x\t%s\n"
				, i, i, str[i], i + 32, i + 32, i + 32, i + 64, i + 64, i + 64, i + 96, i + 96, str[i + 2]);
		}
		else
		{
			printf("%3d\t%2x\t%s\t%3d\t%2x\t%c\t%3d\t%2x\t%c\t%3d\t%2x\t%c\n"
				, i, i, str[i], i + 32, i + 32, i + 32, i + 64, i + 64, i + 64, i + 96, i + 96, i + 96);
		}
		/*switch (i)
		{
		case 0:
			printf("%3d\t%2x\t%s\t%3d\t%2x\t%s\t%3d\t%2x\t%c\t%3d\t%2x\t%c\n"
				, i, i, str[i], i + 32, i + 32, str[i + 32], i + 64, i + 64, i + 64, i + 96, i + 96, i + 96);
			break;
		case 31:
			printf("%3d\t%2x\t%s\t%3d\t%2x\t%c\t%3d\t%2x\t%c\t%3d\t%2x\t%s\n"
				, i, i, str[i], i + 32, i + 32, i + 32, i + 64, i + 64, i + 64, i + 96, i + 96, str[i+2]);
			break;
		default:
			printf("%3d\t%2x\t%s\t%3d\t%2x\t%c\t%3d\t%2x\t%c\t%3d\t%2x\t%c\n"
				, i, i, str[i], i + 32, i + 32, i + 32, i + 64, i + 64, i + 64, i + 96, i + 96, i + 96);
			break;
		}*/
	}
}
void test03() // swap 함수
{
	int val1;
	int val2;
	printf("숫자 2개를 sawp합니다.\n");
	printf("숫자 2개를 입력하세요.\n");
	scanf("%d %d", &val1, &val2);
	printf("swap 전 [0001] %d --- [0002] %d\n", val1, val2);
	swap(&val1, &val2);
	printf("swap 후 [0001] %d --- [0002] %d\n", val1, val2);
}
void test04() //  홀수를 입력받아 '*' 피라미드 출력
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
		if ((i % 2) != 0) // 홀수일때
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
void test05() // 문자를 입력받아 출력
{
	fflush(stdin); // 버퍼 클리어
	rewind(stdin); // 버퍼 포인터 초기화
	char a;
	printf("> 문자를 입력하시오\n");
	scanf("%c", &a);
	if (a >= 'a' && a <= 'z')
	{
		a -= 0x20; // 소문자를 대문자로 변환
	}
	if (a >= 'A' && a <= 'Z')
	{
		for (int i = a - 0x41; i >= 0; i--)
		{
			for (int k = 0; k < (a - 0x41) - i; k++)
			{
				printf(" ");
			}
			for (int j = i; j >= 0; j--)
			{
				printf("%c", a - i);
			}
			printf("\n");
		}
	}
}
void test06() // 최대공약수 출력
{
	int a;
	int b;
	int e;
	char c[100];
	char d[100];
	printf("숫자 2개를 입력하세요.\n>");
	scanf("%d", &a);
	printf(">");
	scanf("%d", &b);
	printf("%d의 약수 : ", a);
	for (int i = 1; i <= a; i++)
	{
		if ((a % i) == 0)
		{
			c[i] = i;
			printf("%d,", c[i]);
		}
	}
	printf("\n");
	printf("%d의 약수 : ", b);
	for (int i = 1; i <= b; i++)
	{
		if ((b % i) == 0)
		{
			d[i] = i;
			printf("%d,", d[i]);
		}
	}
	printf("\n");
	for (int i = 1; i <= a && i <= b; i++)
	{
		if ((a % i) == 0 && (b % i) == 0)
		{
			e = i;
		}
	}
	printf("%d과 %d의 최대공약수는 %d 입니다.", a, b, e);
}
void test07() // sin함수 출력
{
	int i = 0;
	double si = 0;
	int x = 0;
	sin_(i, x, si);
}
void swap(int* a, int* b) // swap 함수
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void sin_(int i,int x, double si)
{
	for (i = 0; i <= 360; i += 20)
	{
		si = sin((3.14 * i) / 180.0);
		printf("sin(%3d)의 값은 %f\r",i,si);

		for (x = -10; x < si * 10; x++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}