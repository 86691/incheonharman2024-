#include <stdio.h>
#include <conio.h>
int test01();
void test02(int a);
void test03();
void Dump(char* p, int len);
void copy(char* p1, char* p2);

int main(void)
{
	//test01();
	//test02(1);
	test03();
}
int test01()
{
	char* str[] = { "Zero","One","Two","Three","Four","Five","Six",
		"Seven","Eight","Nine" }; // 문자열 포인터 배열
	printf("숫자 키를 입력하세요. 해당하는 영단어를 알려드리겠습니다.\n");
	printf("프로그램을 끝내기려면 'Q'키를 입력하세요. \n");
	int n = 1;
	while (n)
	{
		printf(">");
		char c = getch();// no echo : 키값을 출력하지 않고 반환
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
		printf("%c : %s\n", c, str[c - 0x30]);//m대신 c - 0x30대입 가능
	}
}
void test02(int a) // 문자열과 문자배열
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

void test03()
{
	char buf[100];  // 안전 메모리 공간 확보
	char* pbuf;     // 안전 메모리 공간중의 출력 위치
	unsigned int addr;       // 출력 위치 지정을 위한 입력변수(주소)
	char kbuf[100]; // 출력 문자열 입력 공간
	printf("안전공간의 주소는 %d(%08x) 입니다.\n", (unsigned int)buf, buf);
	printf("입력을 시작할 주소를 입력하세요 : ");
	scanf("%d", &addr);  // 안전공간 주소 참고
	pbuf = buf + addr;
	printf("문자열을 입력하세요 : ");
	scanf("%s", kbuf);
	strcpy(pbuf, kbuf); // 문자열 복사
	Dump(buf, 100);

}

void copy(char* p1, char* p2)
{
	while (*p2) *p1++ = *p2++; *p1 = 0; //p1에 현재 p2값을 복사해서 넣어라 null아 나올때까지 복사 ex p1이 he
}

void Dump(char* p, int len) // 메모리 공간 출력용 범용 함수
{
	for (int i = 0; i < len; i++)  // 안전공간 메모리 덤프(주소 나오고 8자리 띄고 8자리(총 16자리) 다음줄 반복) ex 1000(주소) 01100108 0909060F 다음줄 1010 ~ 즉 16의 배수마다 줄바꿈
	{
		if (i % 16 == 0) printf("\n%08x ", p);
		if (i % 8 == 0) printf("  ");
		printf("%02x ", (unsigned char)*p++);
	}
}