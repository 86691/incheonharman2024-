#include <stdio.h>
#include <conio.h>
void test01();
void test02(int a);
void test03();
void test04();
void test05();
void Dump(char* p, int len);
void Copy(char* p1, char* p2);

int main(void)
{
	int n;
	void* pF[] = { test01,test02,test03,test04,test05 }; // void�����Ͷ� Ÿ���� ������������ ������ (�� ��ü�� ������ ����), ���Ǳ����� ���������� ������ ����, �Լ��� �ּҸ� ���� array�� ����
	void (*pFunc)(); // �Լ��� ������ ����
	while (1)
	{
		printf("\n\n\n\n\n");
		printf("1, ����Ű�� ���� ���ڿ� ��� �̼�\n");
		printf("2, ���ڿ��� ���ڹ迭\n");
		printf("3, �������� ��ġ ����\n");
		printf("4, �����͸� �̿��� ���ڿ� ����� �Լ�\n");
		printf("5, ����ü �׽�Ʈ\n");
		printf("0, �� ��\n");
		printf("--------------------------------------\n ���� ");
		scanf("%d", &n);
		if (n == 0) return;
		pFunc = pF[n - 1];
		pFunc();
	}
	//test01();
	//test02(1);
	//test03();
	//test04();
}
void test01() // ����Ű�� ���� ���ڿ� ��� �̼�
{
	char* str[] = { "Zero","One","Two","Three","Four","Five","Six",
		"Seven","Eight","Nine" }; // ���ڿ� ������ �迭
	printf("���� Ű�� �Է��ϼ���. �ش��ϴ� ���ܾ �˷��帮�ڽ��ϴ�.\n");
	printf("���α׷��� ��������� 'Q'Ű�� �Է��ϼ���. \n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch();// no echo : Ű���� ������� �ʰ� ��ȯ
		/*switch (c)
		{
		case'1':
			printf("%c : One\n",c);
			break;
		case'2':
			printf("%c : Two\n",c);
			break;
		case'3':
			printf("%c : Three\n",c);
			break;
		case'4':
			printf("%c : Four\n",c);
			break;
		case'5':
			printf("%c : FIve\n",c);
			break;
		case'6':
			printf("%c : Six\n",c);
			break;
		case'7':
			printf("%c : Seven\n",c);
			break;
		case'8':
			printf("%c : Eight\n",c);
			break;
		case'9':
			printf("%c : Nine\n",c);
			break;
		case'0':
			printf("%c : Zero\n",c);
			break;
		case 'q':
		case 'Q': n = 0; break;
		}*/
		//int m = c - 0x30;//ASCII --> num
		if ((c | 0x20) == 'q') break;
		printf("%c : %s\n", c, str[c - 0x30]);//m��� c - 0x30���� ����
	}
}
void test02(int a) // ���ڿ��� ���ڹ迭
{
	char ca[] = "Hello"; // ca[0] : 'H' ... ca[4]:'o' ca[5] : \0
	for (int i = 0; i < 6; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c (%02x) [%08x]\n", i, ca[i], ca[i], ca + i);
	}
	int ia[] = { 10,20,30,40,50 };
	for (int i = 0; i < 6; i++) // 0 ~ 5
	{
		printf("ia[%d] : %d (%08x) [%08x]\n", i, ia[i], ia[i], ia + i);
	}
	int ia2[2][3] = { 10,20,30,40,50,60 };
	for (int y = 0; y < 2; y++)
	{
		for (int x = 0; x < 3; x++)
			printf("ia2[%d][%d] : %d [%08x]\n", y, x, ia2[y][x], ia2 + y);
	}
	/*ca[2] -= 1;
	ca[3] -= 1;
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c (%02x)\n", i, ca[i], ca[i]);
	}*/

}

void test03() // �������� ��ġ ����
{
	char buf[100];  // ���� �޸� ���� Ȯ��
	char* pbuf;     // ���� �޸� �������� ��� ��ġ
	unsigned int addr;       // ��� ��ġ ������ ���� �Էº���(�ּ�)
	char kbuf[100]; // ��� ���ڿ� �Է� ����
	printf("���������� �ּҴ� %u(%08x) �Դϴ�.\n", (unsigned int)buf, buf);
	printf("�Է��� ������ �ּҸ� �Է��ϼ��� : ");
	scanf("%d", &addr);  // �������� �ּ� ����
	pbuf = buf + addr;
	printf("���ڿ��� �Է��ϼ��� : ");
	scanf("%s", kbuf);
	Copy(pbuf, kbuf);
	//strcpy(pbuf, kbuf); // ���ڿ� ����
	Dump(buf, 100);

}

void test04() // �����͸� �̿��� ���ڿ� ����� �Լ�
{
	char* arr[10] = { "aaaaa","bbbb","ccc","dd","eeeeee"};
	char buf[100];
	printf("[6] "); scanf("%s", buf);
	arr[6] = buf;
	printf("[7] "); scanf("%s", buf + 50);
	arr[7] = buf+50;
	for (int i = 0; i < 10; i++)
	{
		printf("arr[%d] : 0x%08x %s\n", i, arr[i], arr[i]);
	}
}
void test05() // ����ü �׽�Ʈ
{
	struct stTest
	{
		int i; //4byte
		float a;//byte
		char name[20]; // 8byte
	} s1 = { 1, 3.14, "��õ���� �����"};
	//s1.name = "��õ���� �����";
	struct stTest s2 = s1;

	printf("sizeof(struct stTest) : %d\n", sizeof(struct stTest));

	printf("struct stTest s1 : %d %f  %s\n", s1.i, s1.a, s1.name);
	printf("struct stTest s2 : %d %f  %s\n", s2.i, s2.a, s2.name);
}

void Copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0; //p1�� ���� p2���� �����ؼ� �־�� null�� ���ö����� ���� ex p1�� he
}

void Dump(char* p, int len) // �޸� ���� ��¿� ���� �Լ�
{
	for (int i = 0; i < len; i++)  // �������� �޸� ����(�ּ� ������ 8�ڸ� ��� 8�ڸ�(�� 16�ڸ�) ������ �ݺ�) ex 1000(�ּ�) 01100108 0909060F ������ 1010 ~ �� 16�� ������� �ٹٲ�
	{
		if (i % 16 == 0) printf("\n%08x ", p);
		if (i % 8 == 0) printf("  ");
		printf("%02x ", (unsigned char)*p++);
	}
}