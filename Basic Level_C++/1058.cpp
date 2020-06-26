#include<cstdio>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
struct Node {
	int val, wrong_ans;
	string options;
};
int main() {
	int n, m, c;
	int cnt, right_cnt;
	vector<Node> v(110);
	scanf("%d%d", &n, &m);
	for (int i = 0;i < m;++i) {
		scanf("%d%d%d", &v[i].val, &cnt, &right_cnt);
		getline(cin, v[i].options);
		v[i].wrong_ans = 0;
	}
	for (int i = 0;i < n;++i) {
		int sum = 0;
		for (int j = 0;j < m;++j) {
			string s = "";
			while ((c = getchar()) != '(');
			scanf("%d", &cnt);
			while ((c = getchar()) != ')') s += c; //�ո���ɶ��������ȷ��Ҳ�пո�
			if (s != v[j].options) v[j].wrong_ans++;
			else sum += v[j].val;
		}
		printf("%d\n", sum);//0ҲҪ�������ʼ���Ե�2һֱ����ȥ��ԭ����0��û�����
	}
	int Max = 0;
	for (int i = 0;i < m;++i)
		if (v[i].wrong_ans > Max) Max = v[i].wrong_ans;
	if (Max == 0) {
		printf("Too simple\n");
		return 0;
	}
	printf("%d", Max);
	for (int i = 0;i < m;++i)
		if (Max == v[i].wrong_ans) printf(" %d", i + 1);
	return 0;
}