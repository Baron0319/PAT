#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
typedef pair<int, double> pid;//int��������double�Ƿ�����������������SchInfo��ȡ����ֱ��ȡ�����Ե�5��wa
typedef struct SchInfo {
	int count;
	int totalscore;
	string name;
	SchInfo() { count = totalscore = 0;name = ""; }
	SchInfo(int _count, int _totalscore, string _name) : count(_count), totalscore(_totalscore), name(_name) {}
};
void Transform(char  c, double& grade) {//����ת��������
	if (c == 'B') grade /= 1.5;
	else if (c == 'T') grade *= 1.5;
}
void ToLower(string& s) {//�ǵ�Ҫ�ĳ�Сд
	for (auto& i : s) i = tolower(i);
}
bool cmp(SchInfo a, SchInfo b) {//������ô˵��ô��
	if (a.totalscore != b.totalscore) return a.totalscore > b.totalscore;
	if (a.count != b.count) return a.count < b.count;
	return a.name < b.name;
}
int main() {
	//freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	int n;
	string id, name;
	double grade;
	cin >> n;
	vector<SchInfo>ans;
	map<string, pid>school;//�������԰�ѧУ���루��������������Ӧ
	for (int i = 0;i < n;++i) {
		cin >> id >> grade >> name;
		Transform(id[0], grade);
		ToLower(name);
		school[name].first++;
		school[name].second += grade;
	}
	for (auto it : school) ans.push_back(SchInfo(it.second.first, (int)(it.second.second), it.first));
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end(), cmp);
	int rank = 0, pre_score = -1;
	for (int i = 0;i <ans.size();++i) {
		if (pre_score != ans[i].totalscore) rank=i+1;//��ǰ��ķ�����ͬ��������Ϊi+1
		pre_score = ans[i].totalscore;//Ҫ�ǵø���
		cout << rank << " " << ans[i].name << " " << ans[i].totalscore << " " << ans[i].count << endl;
	}
	return 0;
}