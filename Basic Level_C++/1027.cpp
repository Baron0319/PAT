#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//�����ַ�Ϊ2*n*n-1,nΪ������1��3��5�����3�У�5��2*3-1
int needSum[40];
void NeedSum();//�����i���������ַ�������������������
void Outchar(int row, int i, char c);//��ӡһ��ɳ©�������ո����ַ�
int main()
{
	NeedSum();
	int n;
	char c;
	cin >> n >> c;
	int row = upper_bound(needSum, needSum + 30, n) - needSum - 1;//Ҫ��1Ŷ����ΪҪ��С��
	//�ϰ벿�������м�
	for (int i = row;i >= 1;--i)
		Outchar(row, i, c);
	//�°벿
	for (int i = 2;i <= row;++i)
		Outchar(row, i, c);
	cout << n - needSum[row] << endl;
	return 0;
}
void NeedSum()
{
	/*��ðѱ�n=1000ʱ���������Ҳ���������Ȼupper_bound()�᷵��30����Ϊ�Ҳ���
	 2020����Ǿ�2020����*/
	for (int i = 1;2 * i * i - 1 <= 2020;++i)
		needSum[i] = 2 * i * i - 1;
}
void Outchar(int row, int i, char c)
{
	for (int j = 0;j < row - i;++j) cout << " ";
	for (int k = 0;k < 2 * i - 1;++k) cout << c;
	cout << endl;
}