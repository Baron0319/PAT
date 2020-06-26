/*����Ŀ��ʼ������ˡ��������������
�ҿ�ʼ��Ϊ�Ǽ򵥵���ͣ����ǰѸõ���Χ�İ˸��������ĺͶ���������û����tol�Ͳ��㡣Ȼ�������ֵ�������ֵ�Ƿ�ֻ��һ����
Ȼ����������ġ�����֮�����������˵ķ�������Ȼ����
ԭ�����������ɫֵ������Ψһ�ģ���������Χ��Ĳ�ֵ������tol�����������ĵ�Ϳ��ԣ����������ֵ��������
ɵ��ѽ����Ŀ��û�����ס�����������֮��ͺܼ��ˣ�������map��֤�õ�Ψһ��Ȼ���ûɶ�ˡ�
*/
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
int matrix[1055][1055];
int	m, n, tol;
int dis[8][2] = { {1,1},{1,0},{1,-1},{-1,1},{-1,0},{-1,-1},{0,1},{0,-1} };//�˸���λ
inline bool Judge(int x, int y) {//�ж��Ƿ�Խ��
	return x < n&& x >= 0 && y < m&& y >= 0;
}
bool is_beyond(int a, int b) {//�Ըõ�Ϊ���ĵ���ɫ��ֵ
	for (int i = 0;i < 8;++i) {
		int now_x = a + dis[i][0];
		int now_y = b + dis[i][1];
		if (Judge(now_x, now_y) && (abs(matrix[a][b] - matrix[now_x][now_y]) <= tol))
			return false;
	}
	return true;
}
int main() {
	int x, y, cnt = 0;
	map<int, int>mp;
	scanf("%d%d%d", &m, &n, &tol);
	for (int i = 0;i < n;++i)
		for (int j = 0;j < m;++j) {
			scanf("%d", &matrix[i][j]);
			mp[matrix[i][j]]++;
		}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			if (mp[matrix[i][j]] == 1 && is_beyond(i, j)) {
				cnt++;
				if (cnt > 1) {
					puts("Not Unique");
					return 0;
				}
				x = i, y = j;
			}
		}
	}
	if (cnt == 0) puts("Not Exist");
	else printf("(%d, %d): %d\n", y + 1, x + 1, matrix[x][y]);
	return 0;
}