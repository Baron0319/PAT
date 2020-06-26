#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}
int main()
{
	int n1, m1, n2, m2;
	int k;
	char c;
	cin >> n1 >> c >> m1;
	cin >> n2 >> c >> m2;
	cin >> k;
	//��һ��n1/m1һ��С��n2/m2ѽ!
	if (n1 * m2 > n2 * m1) {
		swap(n1, n2);
		swap(m1, m2);
	}
	int left = floor(n1 * 1.0 * k / m1)+1;//�½�,����ֱ��ceil����Ϊ�����иպ������������ceil����ڸ���������Ҫ���Ǳȸ�����
	int right = ceil(n2 * 1.0 * k / m2);//�Ͻ�
	bool f = false;
	while (left<right)
	{
		if (gcd(left, k) == 1) {
			cout <<(f?" ":"") <<left << "/" << k;
			f = true;
		}
		left++;
	}
	return 0;
}