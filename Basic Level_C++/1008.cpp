#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	m %= n;
	int* num = new int[n];
	for (int i = 0;i < n;++i) cin >> num[i];
	//���������巭ת������������巭ת
	reverse(num, num + n);
	reverse(num, num + m);
	reverse(num + m, num + n);
	for (int i = 0;i < n;++i)
		cout << (i ? " " : "") << num[i];
	return 0;
}