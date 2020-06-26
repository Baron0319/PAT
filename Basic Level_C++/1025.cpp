/*�����������ˣ�����
 �������һ���磬�ɡ��Լ�ˮƽ��ֱ�ں�ƽ������
 ������д��˼·�ɡ��ҿ���һ��1e5�����飬ֱ�Ӱ����������ڴ桱��
 Ȼ��ÿ����ַ�ŵľ�������ڵ㣬�����������Լ���һ���ڵ�ĵ�ַ
 Ȼ����Ƿ�ת��ÿ�η�ת�Ҷ�������һ������ķ�ת��������һ���֣�
 ������ľͺܸ����ˣ����ȱ����һ�����ĵ�ַFirstAddress��
 Ȼ���أ�ÿ�η�ת����¼��ת�����β����֮����β������nextָ����һ�ε�ͷ���
 ����ͼ���һ�� ���� 1->2->3->4->5->6 k=3����ʼβ����-1,��תһ�κ�β����1��Ȼ����1ָ����һ�ε�ͷ����6
*/
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
const int N = 1e5;
typedef struct Node {
	int data;
	int next;
};
Node Address[N];
int FirstAddress = -1, TailAddress = -1;
bool f = 1;
int Reverse(int pos, int k)
{
	int p = -1, q = -1;
	int FirstPos = pos;
	//����ת
	while (k--)
	{
		q = Address[pos].next;
		Address[pos].next = p;
		p = pos;
		pos = q;
	}
	/*��Ϊ��ת���һ����������һ����㣬���һ������ɵ�һ��������Ҫ�õ�һ�����ָ�����һ������next
	�������Ų����*/
	Address[FirstPos].next = pos;
	if(TailAddress!=-1)
	Address[TailAddress].next = p;
	if (f) {//��һ�η�ת��ͷ�����ͷ����
		FirstAddress = p;
		f = 0;
	}
	return TailAddress = FirstPos; //���ط�ת��������һ��Ԫ��
}
void OutPut(int FirstAddress)//�����ûɶ��˵�ġ�
{
	while (FirstAddress != -1)
	{
		cout << setw(5) << setfill('0') << FirstAddress << " " << Address[FirstAddress].data << " ";
		if (Address[FirstAddress].next == -1)
			cout << "-1" << endl;
		else cout << setw(5) << setfill('0') << Address[FirstAddress].next << endl;
		FirstAddress = Address[FirstAddress].next;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	//freopen("in.txt", "r", stdin);
	int n, k;
	int add, data, next;
	cin >> FirstAddress >> n >> k;
	for (int i = 0;i < n;++i)
	{
		cin >> add >> data >> next;
		if (add == -1) continue;
		Address[add].data = data;
		Address[add].next = next;
	}//�����ַ�У�����ȡ��
	int p = -1, pos  = FirstAddress;
	int FIR = pos,sum=0;
	/*����ÿӣ���ʼ���Ե�6һֱ����ȥ��������csdn�����ף�ԭ����Щ��㲻�������ϣ��ɡ�
	���������ȼ�¼һ��ʵ����һ���ж��ٸ����*/
	while (FIR!=-1)
	{
		sum++;
		FIR = Address[FIR].next;
	}
	//Ҫ��ʵ�ʽ��Ŷ������n
	while (sum - k >= 0)
	{
		p = Reverse(pos, k);//kλkλһ��ת��Ȼ����һ�η�ת��������β�͵���һ�����
		pos = Address[p].next;
		sum -= k;
	}
	OutPut(FirstAddress);
	return 0;
}