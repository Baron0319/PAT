/*��һ��Ӧ��������ѵ����Ӱ�����һ�⡣Ȼ���ϵ��������һ���ˡ�
��������������������������������ֻ���������ˣ���ô����Ҳ��O(n*n),
�ҳ������˿��Ƿ����������Ҫ�ڱ���һ�飬��ô����O(n^3)��n��100�����Թ���
���Ǻ��������ɡ�
*/
#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int>v(n + 5);
	for (int i = 1;i <= n;++i) cin >> v[i];
	for (int i = 1;i <= n;++i) {
		for (int j = i + 1;j <= n;++j) {
			int lie = 0, WolfLie = 0;
			for (int k = 1;k <= n;++k) {
				if (v[k] < 0) {
					if (-v[k] != i && -v[k] != j) {
						lie++;
						if (k == i || k == j) WolfLie++;
					}
				}
				else if (v[k] == i || v[k] == j) {
					lie++;
					if (k == i || k == j) WolfLie++;
				}
			}
			if (lie == 2 && WolfLie == 1) {//ע��һ����һ���������ѣ�
				cout << i << " " << j << endl;
				return 0;
			}
		}
	}
	cout << "No Solution" << endl;
	return 0;
}