#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char s[1005];
int Transform(int sum, int d)//����ת����������λ�������㷭ת��
{
	int i = 0;
	do
	{
		s[i++] = sum % d + '0';
		sum /= d;
	}while (sum);//������0ҲҪ���棬��Ȼû�����
	return i;
}
int main()
{
	int a, b, d;
	cin >> a >> b >> d;
	int sum = a + b;
	reverse(s, s + Transform(sum, d));//Ҳ���Ե������
	puts(s);
	return 0;
}