/*1.�����ӷ�
  2.�жϻ�����
  */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool Judge(string a);//�ж��Ƿ��ǻ�����
string Add(string a, string b); //ģ������ӷ�
int main() {
	string a, b, sum;
	cin >> a;
	int k = 10;
	while (k-- > 0) {
		if (Judge(a)) {
			cout << a << " is a palindromic number." << endl;
			return 0;
		}
		b = a;
		reverse(b.begin(), b.end());
		cout << a << " + " << b << " = ";
		a = Add(a, b);
		cout << a << endl;
	}
	cout << "Not found in 10 iterations." << endl;
	return 0;
}
bool Judge(string a) {
	for (int i = 0;i < a.length() / 2;++i)
		if (a[i] != a[a.length() - i - 1]) return false;
	return true;
}
string Add(string a, string b) {
	string sum = "";//��
	int op = 0, tmp = 0, len = a.length();//��λ,��ǰ��,����
	for (int i = len - 1;i >= 0;--i) {//ģ��һ�¼ӷ��ͺ���
		tmp = a[i] + b[i] - '0' - '0' + op;
		a[i] = tmp % 10 + '0';
		op = tmp / 10;
	}
	if (op == 1) sum = "1";//�����λ��λ����Ҫ�Ӹ�1Ŷ
	return sum + a;
}