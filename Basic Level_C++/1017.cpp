#include<iostream>
#include<cstring>
using namespace std;
//���������ļ������ֱ��ģ��ͺ�
char divisor[1005];//����
int dividend;//������
int quotient[1005];//��
void Division()
{
	int len = strlen(divisor);
	int now_divisor=0;
	int i = 0,j=0;
	while (i<len)
	{
		now_divisor = now_divisor * 10 + divisor[i] - '0';
		if (now_divisor >= dividend) {
			quotient[i] = now_divisor / dividend;
			now_divisor %= dividend;
		}
		else quotient[i] = 0;//�������ȱ�����С���̿���Ҫ��0��Ŷ����������
		++i;
	}
	if (quotient[j] == 0) j++;//��һλ������0�����Բ������
	while (j<i) cout << quotient[j++];
	if (i == 1 && quotient[0]==0) cout << "0";//���ǳ����ȱ�����С�����
	cout << " " << now_divisor;//���ĳ�������������
}
int main()
{
	cin >> divisor >> dividend;
	Division();
	return 0;
}