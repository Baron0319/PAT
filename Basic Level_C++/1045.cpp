#include<iostream>
#include<cstring>
#include<set>
using namespace std;
const int N = 1e5;
int *num;
bool *Is_true;//��¼�Ƿ���ȷ
int main() {
	ios::sync_with_stdio(false);
	set<int>ans;
	int n;
	int Max = 0;
	cin >> n;
	num = new int[n];
	Is_true = new bool[n];
	memset(Is_true, 0, sizeof(Is_true));

	/*����߿�ʼ����ǣ��������Ԫ�ض�����С��һ��������Ԫ�أ�����¼��ǰ�����ֵ��
	��Ϊ��ÿ����Ԫ��Ҫ��ǰ������Ԫ�ض���
	*/
	for (int i = 0;i < n;++i) {
		cin >> num[i];
		if (num[i] > Max) {
			Is_true[i] = 1;
			Max = num[i];
		}
	}
	/*ͬ�����ұ���ɨ��һ�飬��ʱ��¼��Сֵ����Ϊ��ԪҪ�Ⱥ�����Сֵ��С*/
	int Min = 0x7f7f7f7f;
	for (int i = n - 1;i >= 0;--i) {
		if (Min > num[i]) {
			if (Is_true[i]) ans.insert(num[i]);//��������㣬������Ԫ����������ֱ�Ӷ�set����
			Min = num[i];
		}
	}
	bool f = false;
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << (f ? " " : "") << i;
		f = true;
	}
	//û����������Ե�2���ʽ����
	cout << endl;//�е�ӣ�������0��ҲҪ���һ�����У���Ϊ�ڵڶ������Ԫ�������û��ҲҪ����ڶ���
	delete[]num;
	delete[]Is_true;
	return 0;
}