#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//�򵥵Ľṹ�����򣬰���ĿҪ��������������һ��rank����������ÿ������ڵڼ���
class Stu {
public:
	int rank;
	int id;
	int moral_score;
	int ability_score;
	Stu(int a, int b, int c, int d) : rank(a), id(b), moral_score(c), ability_score(d) {}
	Stu() {}
	void Print();
};
void Stu::Print() {
	cout << id << " " << moral_score << " " << ability_score << endl;
}
bool cmp(Stu a, Stu b)
{//���ձȽϴ������αȽ�
	if (a.rank != b.rank) return a.rank < b.rank;
	if (a.moral_score + a.ability_score != b.moral_score + b.ability_score)
		return a.moral_score + a.ability_score > b.moral_score + b.ability_score;
	if (a.moral_score != b.moral_score) return a.moral_score > b.moral_score;
	return a.id < b.id;
}
int n, l, h;
int main()
{
	ios::sync_with_stdio(false);//cinʵ��̫���ˣ���scanfҲ��
	cin >> n >> l >> h;
	int id, moral_score, ability_score;
	Stu* stu = new Stu[n];
	int cnt = 0;
	for (int i = 0;i < n;++i)
	{
		int rank = 0;//һ�����࣬1�����
		cin >> id >> moral_score >> ability_score;
		if (moral_score < l || ability_score < l) rank = 0;
		else if (moral_score >= h && ability_score >= h) rank = 1;
		else if (moral_score >= h && ability_score < h) rank = 2;
		else if (moral_score < h && ability_score < h && moral_score >= ability_score) rank = 3;
		else if (moral_score >= l && ability_score >= l) rank = 4;
		if (rank) stu[cnt++] = Stu(rank, id, moral_score, ability_score);
	}
	sort(stu, stu + cnt, cmp);
	cout << cnt << endl;
	for (int i = 0;i < cnt;++i)
		stu[i].Print();
	delete[]stu;
	return 0;
}