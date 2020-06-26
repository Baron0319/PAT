#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 1e5 + 5;
int n, k;
struct Node {
	int index, add, data;//�����±꣬��֤���˳����
	Node(int ind, int a, int d) : index(ind), add(a), data(d) {}
};
bool cmp(Node a, Node b) {//��Ҫ�����������
	if ((a.data ^ b.data) < 0) return a.data < 0;//����һ���Ǹ���
	if ((a.data > k && b.data <= k) || (b.data > k && a.data <= k))	return a.data <= k;//��һ����k��
	return a.index < b.index;//ʣ�µģ� 1.���Ǹ�����2.���Ǵ���k������3.����[0,k]�������ڣ�������Դ�������ͺ��ˡ� 
}
int main() {
	int first, addr, data, next, index = 0;
	int Addr[N] = { 0 }, Next[N] = { 0 };
	vector<Node>v;
	scanf("%d%d%d", &first, &n, &k);
	for (int i = 0;i < n;++i) {
		scanf("%d%d%d", &addr, &data, &next);
		Next[addr] = next;
		Addr[addr] = data;
	}
	while (first != -1) {
		v.push_back(Node(index++, first, Addr[first]));
		first = Next[first];
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0;i < index - 1;++i)//���ñ�����һ����ַ��ֱ�Ӵ���һ���õ�ַ�ͺ���
		printf("%05d %d %05d\n", v[i].add, v[i].data, v[i + 1].add);
	printf("%05d %d -1\n", v[index - 1].add, v[index - 1].data);
	return 0;
}