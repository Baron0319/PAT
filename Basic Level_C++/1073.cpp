#include<cstdio>
#include<vector>
using namespace std;
struct Node {
	int score, cnt;
	bool is_true[6];
};
int main() {
	int n, m, score, ops, Max_error = 0;
	char c;
	int Error[105][6] = { 0 };
	double sum[1024] = { 0 };
	/*����ѡ��*/
	scanf("%d%d", &n, &m);
	vector<Node>op(m);
	for (int i = 0;i < m;++i) {
		scanf("%d%*d%d", &score, &ops);
		op[i].score = score;
		op[i].cnt = ops;
		for (int j = 0;j < ops;++j) {
			scanf(" %c", &c);
			op[i].is_true[c - 'a'] = 1;
		}
	}
	for (int i = 0;i < n;++i) {
		for (int j = 0;j < m;++j) {
			bool f = true;//�Ƿ���ִ���û�е�ѡ��
			bool is_in[6] = { 0 };//��¼ѧ���Ĵ�
			while ((c = getchar()) != '(');
			scanf("%d", &ops);
			while ((c = getchar()) != ')') /*����ѧ���Ĵ�*/
				if (c != ' ')
				{
					is_in[c - 'a']++;
					if (op[j].is_true[c - 'a'] == 0) f = false;//����в����ڵģ���ôһ���Ǵ��
				}
			/*ע�⣬����ѡ����������������е�ûѡ����û�е�ѡ��*/
			for (int k = 0;k < 5;++k) {
				if (is_in[k] != op[j].is_true[k]) Error[j][k]++;/*��������Ⱦ�˵���϶�����*/
				if (Error[j][k] > Max_error) Max_error = Error[j][k];
			}
			/*����ش�ѡ�����ȷѡ�������ѡ�ĸ���Ҳһ���϶���*/
			if (f) sum[i] += (op[j].cnt == ops) ? op[j].score * 1.0 : op[j].score / 2.0;
		}
	}
	for (int i = 0;i < n;++i)	printf("%.1f\n", sum[i]);
	if (Max_error == 0) { printf("Too simple\n");return 0; }
	for (int i = 0;i < m;++i) /*���������������ѡ��*/
		for (int j = 0;j < 5;++j)
			if (Error[i][j] == Max_error)
				printf("%d %d-%c\n", Max_error, i + 1, j + 'a');
	return 0;
}