/* hello����������أ���Ҫ˼·���Ƿ�������ۣ�Ȼ�������������žͱ����100��
���飺��Ĳ����򲻵���ǧ���������룬����ģ�д���Լ��������ٿ�һ��

�Ҿ���˵���ҵ�˼·��Ȼ�����Լ�д���룬�϶����ҵļ򵥣���Ϊ����Ĳ����ٸ��ˡ���������
˼·���ýṹ�屣��׼��֤�źͷ��������ǻ��١���Ŀ����Ҳ����ϸ��
����������:1.ɶ�����ܣ�ѯ��һ�ΰ�����������һ�Ρ�2.��Ū����vector����ĿҪ��ֱ�洢���ÿռ任ʱ��
��һ�ַ�����϶�û���⣬���Գ飬�õõڶ��֣�̫�����ռ��ˡ�
�ٸ����ӣ��������һ������������vector����A,T,B��������Ŀ�����Ȼ��ѯ�ʵ�ʱ��ֱ�Ӵ������þͺ���
��������������㿪��1000�����飬�±���ǿ�����ţ�Ȼ���ýṹ���¼�������ܳɼ���ѯ��Ҳֱ���þͺ���
���ڵ����֣�����ͬ����������������û���뵽ʲô�ð취������ֻ�ܱ���һ����

*/
#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;
//д��д�Ÿ�������ṹ�壬�üһ���û������֪����ʲô���Լ�Ϊ�˷�������ʹ洢����
typedef struct StuInfo {
	string id;
	int score;
	StuInfo() {}
	StuInfo(string _id, int _score) : id(_id), score(_score) {}
};
struct Type2 {
	int cnt, score;
	Type2() { cnt = score = 0; }
};
struct Type3 {
/*ΪɶҪ����أ����ǰ������±���Ϊ������ţ���������
�����뿼����Ų��Ͳ���Ӧ��������Ҫ����һ�¿������*/
	int index, cnt;
	Type3() { index = cnt = 0; }
	Type3(int a, int b) :index(a), cnt(b) {}
};
bool cmp(StuInfo a, StuInfo b) {//���1������
	return  (a.score == b.score) ? (a.id < b.id) : (a.score > b.score);
}
bool cmp3(Type3 a, Type3 b) {//���3
	return (a.cnt == b.cnt) ? (a.index < b.index) : (a.cnt > b.cnt);
}
void OutputType1(vector<StuInfo> s) {//������һ
	for (auto i : s) printf("%s %d\n", i.id.c_str(), i.score);
	if (s.empty()) puts("NA");
}
int main() {
	int n, m;
	string _id;
	_id.resize(100);//��Ҫ��scanf����string ���������ַ�ʽ���ȸ�string����ռ�
	int _score, type;
	int index, cnt = 0;//�������,����
	string date;//����
	scanf("%d%d", &n, &m);
	vector<StuInfo> B, A, T;//��������
	vector<Type2> v(1000);//��������Ŵ��
	StuInfo* stu = new StuInfo[n + 5];
	for (int i = 0;i < n;++i) {
		getchar();
		scanf("%s%d", &_id[0], &_score);
		stu[i] = StuInfo(_id, _score);
		//���1
		if (_id[0] == 'T') T.push_back(StuInfo(_id, _score));
		else if (_id[0] == 'A') A.push_back(StuInfo(_id, _score));
		else B.push_back(StuInfo(_id, _score));
		//���2
		index = (_id[1] - '0') * 100 + (_id[2] - '0') * 10 + (_id[3] - '0');
		v[index].cnt++;v[index].score += _score;
	}
	sort(A.begin(), A.end(), cmp);sort(T.begin(), T.end(), cmp);sort(B.begin(), B.end(), cmp);
	string str;str.resize(100);
	for (int i = 1;i <= m;++i) {
		getchar();
		scanf("%d%s", &type, &str[0]);
		printf("Case %d: %d %s\n", i, type, str.c_str());
		if (type == 1) {
			if (str[0] == 'T') OutputType1(T);
			else if (str[0] == 'A') OutputType1(A);
			else OutputType1(B);
		}
		else if (type == 2) {
			if (v[atoi(str.c_str())].cnt == 0) puts("NA");
			else printf("%d %d\n", v[atoi(str.c_str())].cnt, v[atoi(str.c_str())].score);
		}
		else {//�������������ʱû�뵽���õģ�ֻ�ñ���һ���ˣ�Ȼ���ٱ���𰸣��������
			bool f = true;
			vector<Type3> v3(1000);
			for (int i = 0;i < n;++i) {
				if (strcmp((stu[i].id).substr(4, 6).c_str(), str.c_str()) == 0) {
					int j = atoi((stu[i].id).substr(1, 3).c_str());
					f = false;
					v3[j].cnt++; v3[j].index = j;
				}
			}
			if (f) puts("NA");
			else {
				sort(v3.begin(), v3.end(), cmp3);
				for (auto i = 0;i < 1000;++i)
					if (v3[i].cnt) printf("%d %d\n", v3[i].index, v3[i].cnt);
			}
		}
	}
	return 0;
}