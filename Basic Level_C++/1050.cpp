#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
int matrix[10000][100];
int t;
void Get(int& m, int& n) {
	for (int i = sqrt(t);i >= 1;--i)
		if (t % i == 0) {
			m = t / i, n = i;
			return;
		}
}
void Solve(int m, int n, vector<int>v) {
	int i = 0, j = -1, k = 0, p;
	/*�������Ǽ��������(0,-1)����ô����ͼ���һЩ��
	��ÿ�ε����Ϊ(x,y)
	��ͼ���һ�£��ǲ����൱��ÿһ��ѭ������˴�(x,y+1)��ʼ��
	��(x+1,y)Ϊֹ�����һ�������������������Ĺ��ɾͿ�����
	*/
	while (k < t) {
		for (p = 0;p < n;++p) 	matrix[i][++j] = v[k++];//����ת
		for (p = 0;p < m - 1;++p) 	matrix[++i][j] = v[k++];//������
		m--, n--;//ע�⣬���������ߵ�ʱ������������������1����ס���ǵ������(0,-1)����
		/*��û�з�����ʵ�ǶԳƵ�*/
		for (p = 0;p < n;++p) 	matrix[i][--j] = v[k++];//����ת
		if (n == 0) return;//���û�����ˣ��Ͳ�Ҫ����ȥ�ˣ���Ȼ�����ˣ�ע��1�е����
		for (p = 0;p < m - 1;++p) 	matrix[--i][j] = v[k++];//������
		m--, n--;//ÿѭ��һ�Σ�������2��������2
	}
	/*����̫������ʵ����ͼ�ͺ����ܶ��ˡ�*/
}
int main() {
	cin >> t;
	vector<int>v(t);
	for (int i = 0;i < t;++i) cin >> v[i];
	sort(v.begin(), v.end(), greater<int>());
	int n, m;
	Get(m, n);
	Solve(m, n, v);
	for (int i = 0;i < m;++i) {
		for (int j = 0;j < n;++j)
			cout << (j ? " " : "") << matrix[i][j];
		cout << endl;
	}
	return 0;
}