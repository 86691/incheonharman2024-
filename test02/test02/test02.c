#include <stdio.h>
#include <conio.h>
int test01();
void test02(int a);
int main(void)
{
	//test01();
	test02(1);

}
//수정수정
int test01()
{
	char* str[] = {"Zero","One","Two","Three","Four","Five","Six",
		"Seven","Eight","Nine"}; // 문자열 포인터 배열
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
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c (%02x)\n", i, ca[i], ca[i]);
	}
	ca[2] -= 1;
	ca[3] -= 1;
	for (int i = 0; i < 10; i++) // 0 ~ 5
	{
		printf("ca[%d] : %c (%02x)\n", i, ca[i], ca[i]);
	}
}
