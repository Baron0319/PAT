#include<iostream>
#include<string>
using namespace std;
string ans = "";
void Zip(string s) {//ѹ��
	int cnt = 1;
	char c = s[0];
	for (int i = 1;i < s.length();++i) {
		if (s[i] == c) cnt++;
		else {
			if (cnt > 1) ans += to_string(cnt);/*1��Ĭ�ϵľͲ��Ž�ȥ��*/
			ans += c;
			c = s[i];
			cnt = 1;
		}
	}
	/*�������ˣ���û�ӵļӽ�ȥ����ʵҲ�������һ����ǰ����ͬ�����*/
	if (cnt > 1) ans += to_string(cnt);
	ans += c;
	cout << ans << endl;
}
void Unzip(string s) {//��ѹ
	for (int i = 0, cnt;i < s.length();++i) {
		cnt = 0;
		while (isdigit(s[i])) //�����־�һֱ��ȡ����Ϊ��������λ������λ��
			cnt = cnt * 10 + s[i++] - '0';
		do {//����while����Ϊ��cnt��0����ʾֻ��һ����ҲҪ�����һ���ַ�
			ans += s[i];
		} while (--cnt > 0);
	}
	cout << ans << endl;
}
int main() {
	char c;
	string s;
	cin >> c;
	cin.ignore();//��ȡ�س�
	getline(cin, s);
	(c == 'C') ? Zip(s) : Unzip(s);
	return 0;
}