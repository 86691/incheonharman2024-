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
	void* pF[] = { test00,test01,test02,test03,test04,test05,test06,test07 }; // void�����Ͷ� Ÿ���� ������������ ������ (�� ��ü�� ������ ����), ���Ǳ����� ���������� ������ ����, �Լ��� �ּҸ� ���� array�� ����
	void (*pFunc)(); // �Լ��� ������ ����
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1. ���ڿ� �ѹ��ھ� ����\n");
		printf("2. �빮�ڷ� �ϰ� ��ȯ\n");
		printf("3. ASCII �ڵ�ǥ ���\n");
		printf("4. swap �Լ�\n");
		printf("5. Ȧ���� �Է¹޾� '*' �Ƕ�̵� ���\n");
		printf("6. ���ڸ� �Է¹޾� ���\n");
		printf("7. �ִ����� ���\n");
		printf("8. sin�Լ� ���\n");
		printf("0. �� ��\n");
		printf("--------------------------------------\n ���� ");
		scanf("%d", &n);
		if (n == 0) return;
		pFunc = pF[n-1];
		pFunc();
	}
}

void test00() // ���ڿ� �ѹ��ھ� ����
{
	char buf[100];
	int i = 0;
	printf("���ڿ��� �Է��ϼ���.\n");
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
void test01() // �빮�ڷ� �ϰ� ��ȯ
{
	char buf[100];
	int i = 0;
	char a;
	printf("���ڿ��� �Է��ϼ���.\n");
	printf(">");
	scanf("%s", buf);
	while (1)
	{
		if (*(buf + i) == 0) break;
		a = buf[i];
		if (a > 96 && a < 123) a -= 32; // �ҹ��ڸ� �빮�ڷ� ��ȯ
		printf("%c", a);
		i++;
	}
}
void test02() // ASCII �ڵ�ǥ ���
{
	char* str[] = { "NUL","SOH","STX","ETX","EOT","ENQ","ACK","BEL","BS","HT","LF","VT","FF","CR","SO","SI"
		,"DLE","DC1","DC2", "DC3", "DC4","NAK","SYN","ETB","CAN","EM","SUB","ESC","FS","GS","RS","US","SP","DEL" };
	printf("ASCII �ڵ�ǥ\n");
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
void test03() // swap �Լ�
{
	int val1;
	int val2;
	printf("���� 2���� sawp�մϴ�.\n");
	printf("���� 2���� �Է��ϼ���.\n");
	scanf("%d %d", &val1, &val2);
	printf("swap �� [0001] %d --- [0002] %d\n", val1, val2);
	swap(&val1, &val2);
	printf("swap �� [0001] %d --- [0002] %d\n", val1, val2);
}
void test04() //  Ȧ���� �Է¹޾� '*' �Ƕ�̵� ���
{
	int a;
	while (1)
	{
		printf("> ����(Ȧ��)�� �Է��Ͻÿ�\n");
		int n = scanf("%d", &a); //�������� �Է� n =1, ���� n = 0
		if (n == 0 || (a % 2) == 0) // n == 0 �Է¿���
		{
			fflush(stdin); // ���� Ŭ����
			rewind(stdin); // ���� ������ �ʱ�ȭ
			continue;
		}
		else break;
	}
	for (int i = 1; i <= a; i++)
	{
		if ((i % 2) != 0) // Ȧ���϶�
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
void test05() // ���ڸ� �Է¹޾� ���
{
	fflush(stdin); // ���� Ŭ����
	rewind(stdin); // ���� ������ �ʱ�ȭ
	char a;
	printf("> ���ڸ� �Է��Ͻÿ�\n");
	scanf("%c", &a);
	if (a >= 'a' && a <= 'z')
	{
		a -= 0x20; // �ҹ��ڸ� �빮�ڷ� ��ȯ
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
void test06() // �ִ����� ���
{
	int a;
	int b;
	int e;
	char c[100];
	char d[100];
	printf("���� 2���� �Է��ϼ���.\n>");
	scanf("%d", &a);
	printf(">");
	scanf("%d", &b);
	printf("%d�� ��� : ", a);
	for (int i = 1; i <= a; i++)
	{
		if ((a % i) == 0)
		{
			c[i] = i;
			printf("%d,", c[i]);
		}
	}
	printf("\n");
	printf("%d�� ��� : ", b);
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
	printf("%d�� %d�� �ִ������� %d �Դϴ�.", a, b, e);
}
void test07() // sin�Լ� ���
{
	int i = 0;
	double si = 0;
	int x = 0;
	sin_(i, x, si);
}
void swap(int* a, int* b) // swap �Լ�
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
		printf("sin(%3d)�� ���� %f\r",i,si);

		for (x = -10; x < si * 10; x++)
		{
			printf(" ");
		}
		printf("*\n");
	}
}