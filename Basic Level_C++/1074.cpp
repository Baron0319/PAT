#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
	string hex, a, b, ans;
	cin >> hex >> a >> b;
	int len1 = a.length() - 1, len2 = b.length() - 1, len3 = hex.length() - 1;
	int op = 0, carry = 0, k = 0;
	//ģ��ӷ������λ������������Ϊ��'0'
	while (len1 >= 0 || len2 >= 0)
	{              //len1,len2С��0�����Ӹ�λ��'0'��֪��a,b��������
		int sum = ((len1 >= 0) ? a[len1] : '0') + ((len2 >= 0) ? b[len2] : '0') - '0' - '0' + carry;
		if (hex[len3] == '0' || hex[len3] == 'd') op = 10;//ע������'d'
		else op = hex[len3] - '0';
		ans += sum % op + '0';
		carry = sum / op;
		len1--;len2--;len3--;
	}
	if (carry) cout << carry;//�����λ�н�λ��Ҫ��������λ
	reverse(ans.begin(), ans.end());//��תһ�£��������������
	while (carry == 0 && ans[k] == '0' && k < ans.length() - 1)//Ҫ��ans��һλ����Ȼ��Ϊ0û���
		k++;//���û�н�λ�������λ��0�������
	while (k < ans.length())
		cout << ans[k++];
	return 0;
}