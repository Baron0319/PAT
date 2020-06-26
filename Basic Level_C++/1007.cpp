#include<iostream>
#include<cstring>
using namespace std;
const int Maxn = 1e5+5;
bool is_prime[Maxn];
int Prime[Maxn];
inline void Euler()//ŷ��ɸ����ɸҲ����
{
	memset(is_prime, 0,sizeof(is_prime));
	int cnt = 0;
	for (int i = 2;i < Maxn;++i)
	{
		if (!is_prime[i]) Prime[cnt++] = i;
		for (int j = 0;j < cnt && i * Prime[j] < Maxn;++j)
		{
			is_prime[i * Prime[j]] = 1;
			if (i % Prime[j] == 0) break;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	Euler();
	int n,ans=0;
	cin >> n;
	for (int i = 0;Prime[i+1] <= n;++i)//������Ŷ�����Ե���
		if (Prime[i + 1] - Prime[i] == 2) ans++;
	cout << ans << endl;
	return 0;
}