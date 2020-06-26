#include<iostream>
#include<algorithm>
using namespace std;
/*ֱ�Ӷ԰���������ȡֵ���־ͺ���
  ��Ҫע��һ�����������ʱ�İ�������������С����ô�����������Ҳ�ǿ��Եġ�
  ����5 5 10 10 10 10������4����Ϊ5�����㣬4����5�����㣬��ô����������4
  */
int Binary_Search(int dis[], int n) {
	int l = 0, r = dis[n - 1];
	int ans = 0;
	while (l <= r) {
		int mid = l + (r - l) / 2;
		int tmp = n - (upper_bound(dis, dis + n, mid) - dis);//����mid�ĸ���
		if (mid == tmp) {
			ans = max(tmp, ans);
			l = mid + 1;
		}
		else if (mid < tmp) {//��Ϊ��ʱҲ��õ��𰸣���Ϊmid<tmp,��������������ȡmid������һ������
			l = mid + 1;
			if (mid > ans) ans = mid;
		}
		else  r = mid - 1;
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	int* dis = new int[n];
	for (int i = 0;i < n;++i)
		cin >> dis[i];
	sort(dis, dis + n);
	cout << Binary_Search(dis, n) << endl;
	delete[]dis;
	return 0;
}