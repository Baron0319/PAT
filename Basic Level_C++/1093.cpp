//���⣬�ñ�������ǣ���֤ÿ��Ԫ��ֻ�ܳ���1��
#include<iostream>
#include<string>
using namespace std;
bool is_exist[200] = { 0 };
void Output(string a) {
	for (auto i : a) {
		if (is_exist[i] == 0) {
			cout << i;
			is_exist[i] = 1;
		}
	}
}
int main() {
	string a, b;
	getline(cin, a);getline(cin, b);
	Output(a);Output(b);
	return 0;
}