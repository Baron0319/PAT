#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main() {
	ios::sync_with_stdio(false);cin.tie(0);
	int n, m;
	int a, b;
	cin >> n >> m;
	map<int, vector<int> > mp;
	/*��˼��ÿ��int��һ��vector�����������е�Ԫ�ؽ���ӳ�䣬Ҳ����һ�Զ�
	���֪ʶһ��һ ���ܳ���keyһ����value��һ������ԭ����value�ᱻ����*/
	while (n--)
	{
		cin >> a >> b;
		mp[a].push_back(b);
		mp[b].push_back(a);
	}
	while (m--)
	{
		vector<int> g;
		map<int, bool>is_exist;
		bool f = false;
		cin >> n;
		for (int i = 0;i < n;++i) {
			cin >> a;
			is_exist[a] = 1;
			g.push_back(a);
		}
		for (int i = 0;i < n;++i)
			for (auto j = 0;j < mp[g[i]].size();++j)
				if (is_exist[mp[g[i]][j]]) 	f = true;//���˾�break���Կ�100ms����Ϊ�˴�����һ�㣬�Ͳ�����
		puts(f ? "No" : "Yes");
	}
	return 0;
}