#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
/*�򵥷���һ�£���������С�Ľ�������ô���ӿ϶�Խ��Խ�̣���֮Խ��Խ��
��Ϊ���Ƚ�����ӳ�2�����϶��Ⱥ��Ķ�
���� ����Ȼ�����Ϳ�����*/
int main() {
	int n,len;
	vector<int>v;
	cin >> n;
	while (n--){
		cin >>v[0];
		v.push_back(len);
	}
	sort(v.begin(), v.end());
	double ans = v[0];
	for (auto i = 1;i<v.size();++i) 
		ans = (ans + v[i]) / 2.0;
	cout << int(ans) << endl;
	return 0;
}