#include<iostream>
#include<string>
//��1078�ַ���ѹ�����ѹ���ƣ�ֻ����1ҲҪ�����
using namespace std;
string Generate(string s) {
	string tmp = "";
	int cnt = 1;
	char pre = s[0];
	for (int i = 1;i < s.length();++i) {
		if (s[i] == pre) cnt++;
		else {
			tmp += pre + to_string(cnt);
			pre = s[i];
			cnt = 1;
		}
	}
	return tmp + pre + to_string(cnt);//���һ��Ԫ�ز����಻��ͬ�����޷����룬��Ϊ�Ѿ��������ˣ�����Ҫ�������
}
int main() {
	string ans;
	int n;
	cin >> ans >> n;
	while (--n > 0) ans = Generate(ans);//��--nŶ����Ϊn��1��ʼ,
	cout << ans << endl;
	return 0;
}