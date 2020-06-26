#include<iostream>
#include<cstring>
#include<map>
#include<iomanip>
using namespace std;
const int N = 1e5;
bool is_prime[N + 5];
int Prime[N + 5];
void Euler()//������� ŷ����
{
	is_prime[2] = 0;
	for (int i = 2, cnt = 0;i < N;++i)
	{
		if (is_prime[i] == 0) Prime[cnt++] = i;
		for (int j = 0;j < cnt && i * Prime[j] < N;++j) {
			is_prime[i * Prime[j]] = 1;
			if (i % Prime[j] == 0) break;
		}
	}
}
int is_exist[N + 5];//û���ֹ���Ϊ0�����ֹ���Ϊ1�����ʺ��Ϊ2��
int main()
{
	Euler();
	memset(is_exist, 0, sizeof(is_exist));
	map<int, int>mp;//��map��¼���Σ�������Ҳ����
	int n, id;
	cin >> n;
	for (int i = 1;i <= n;++i) {
		cin >> id;
		is_exist[id] = 1;
		mp[id] = i;
	}
	cin >> n;
	while (n--)
	{
		cin >> id;
		cout << setw(4) << setfill('0') << id << ": ";//��סҪ��֤��λ�ĸ�ʽ
		if (is_exist[id] == 0) puts("Are you kidding?");//������
		else if (is_exist[id] == 1) {
			if (mp[id] == 1) puts("Mystery Award");//��һ��
			else if (is_prime[mp[id]] == 0) puts("Minion");//������
			else puts("Chocolate");//����
			is_exist[id] = 2;//���Ϊ���ʹ�
		}
		else  puts("Checked");//���ʹ���ֱ�ӷ���checked
	}
	return 0;
}