#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
//�жϾ�����
void Judge(string pw) {
	if (pw.length() < 6) { puts("Your password is tai duan le."); return; }
	bool have_digit = false, have_alp = false;
	for (auto i : pw) {
		if (isalpha(i)) have_alp = 1;
		else if (isdigit(i)) have_digit = 1;
		else if (i == '.');
		else { puts("Your password is tai luan le.");	return; }
	}
	if (have_alp && have_digit == 0) puts("Your password needs shu zi.");
	else if (have_alp == 0 && have_digit) puts("Your password needs zi mu.");
	else puts("Your password is wan mei.");
	//����ĸ�����ֶ�û���أ���Ŀû˵���Ͳ�����������
}
int main() {
	int n;
	cin >> n;
	getchar();
	string pw;
	while (n--) {
		getline(cin, pw);
		Judge(pw);
	}
	return 0;
}