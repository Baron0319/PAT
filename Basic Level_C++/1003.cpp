/*�ѵ���ǵ�����
  �����Գ�ʼ״̬���е��� aPbTcÿ����һ���м�Ҫ�Ӹ�A������Ҫ��a������Ϊ��ʼ״̬a*1=c�����Եõ�a*b=c
  ����b!=0
*/
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int n;
	cin >> n;
	getchar();
	char str[1005];
	while (n--)
	{
		cin.getline(str, 1005, '\n');
		int l = strlen(str);
		int len[3] = { 0 }, cnt = 0;//len[0,1,3]�ֱ��ʾ��PǰA��������P��T��A������,T�������
		bool f = false;
		int P,T;
		P = T = 0;
		for (int i = 0;i < l;++i)
		{
			if (!(str[i] == 'P' || str[i] == 'T' || str[i] == 'A')) break;
			if (str[i] == 'P')
			{
				P++;
				len[0] = cnt;
				cnt = 0;
			}
			else if (str[i] == 'T')
			{
				T++;
				len[1] = cnt;
				cnt = 0;
			}
			else
				cnt++;
		}
		len[2] = cnt;
		//P,T��ֻ�ܳ���һ�Σ�P��T�б�����A
		if (P == 1 && T == 1 && len[1] && len[0] * len[1] == len[2]) f = true;
		if (f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}