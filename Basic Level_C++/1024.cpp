#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
void OutZero(int n)
{
	while (n>0)
	{
		printf("0");
		n--;
	}
}
int main()
{
	char str[10005];
	char num[3][10005];//�ֱ�����������֣�С�����֣�ָ�����֡�����ָ�����ִ����ţ��������ֲ�������
	memset(num, 0, sizeof(num));
	memset(str, 0, sizeof(str));
	const char* d = ".E";//������strtok �ַ����ָ�
	char* p;
	char op;
	scanf("%c", &op);
	if (op == '-') cout << op;
	scanf("%s", str);
	p = strtok(str, d);
	int k = 0;
	//�ָȻ��ֱ����num��
	while (p)
	{
		strcpy(num[k++], p);
		p = strtok(NULL, d);
	}
	int exponent = 0;
	sscanf(num[2], "%c%d", &op, &exponent);
	if (exponent == 0) printf("%s.%s\n", num[0], num[1]);
	else {
		if (op == '-')//ָ���Ǹ���
		{
			printf("0.");
			exponent--;
			OutZero(exponent);
			printf("%s%s\n", num[0], num[1]);
		}
		else {
			printf("%s", num[0]);
			int len = strlen(num[1]);
			for (int i = 0;i < len;++i, --exponent) {
				if (exponent == 0) printf(".");//��סָ��û���ˣ�С�����У�Ҫ���С����
				printf("%c", num[1][i]);
			}
			OutZero(exponent);
		}
	}
	return 0;
}