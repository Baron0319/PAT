#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>
using namespace std;
bool Judge(string a, double& tmp);//�ж��Ƿ��ǺϷ�������
int main() {
	int n, cnt = 0;
	cin >> n;
	string num[200];
	double ans = 0, tmp;
	for (int i = 0;i < n;++i) cin >> num[i];
	for (int i = 0;i < n;++i) {
		if (Judge(num[i], tmp)) {
			ans += tmp;
			cnt++;
		}
		else cout << "ERROR: " << num[i] << " is not a legal number" << endl;
	}
	cout << "The average of " << cnt << ((cnt == 1) ? " number is " : " numbers is ");//ע��1��ʱ����number
	if (cnt == 0) cout << "Undefined" << endl;
	else cout << setprecision(2) << fixed << ans / cnt << endl;
	return 0;
}
bool Judge(string a, double& tmp) {//���ã������a�Ϸ������Է��ظ�ʵ��
	bool f = false;//�Ƿ����'.'
	for (int i = 0;i < a.length();++i) {
		if (isalpha(a[i])) return false;//����ĸ
		if (f && a[i] == '.') return false;//��������'.'
		if (a[i] == '.') {
			f = true;
			if (a.length() - i > 3) return false;//С����󳬹���λ
		}
	}
	tmp = atof(a.c_str());//��һ��ʵ��������ת���ɸ����������ж��Ƿ��ڷ�Χ��
	return fabs(tmp) <= 1000.00;
}