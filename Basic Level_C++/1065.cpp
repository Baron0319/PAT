#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	map<string, string>mp;//����
	map<string, bool>is_exist;//�Ƿ����
	vector<string> v;
	vector<string>ans;
	cin >> n;
	string s1, s2;
	while (n--)
	{
		cin >> s1 >> s2;
		mp[s1] = s2;
		mp[s2] = s1;
	}
	cin >> n;
	while (n--)
	{
		cin >> s1;
		v.push_back(s1);
		is_exist[s1] = 1;
	}
	for (auto s : v) {
		if (is_exist[mp[s]]==0) ans.push_back(s);//������ǳɶԵķ���ans
	}
	sort(ans.begin(), ans.end());//�ǵ�Ҫ����
	cout << ans.size() << endl;
	for (auto s : ans) {
		if (s != *ans.begin()) cout << " ";
		cout << s;
	}
	return 0;
}