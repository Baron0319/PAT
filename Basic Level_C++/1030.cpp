#include <iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, p;
	int Maxlen = 0;
	cin >> n >> p;
	int* num = new int[n];
	for (int i = 0;i < n;++i) cin >> num[i];
	sort(num, num + n);
	/*M<=P*m => M/p<=m p��֪�����ҵ�M��Ȼ��Ϳ���ȷ������m,�ö��־Ϳ��ԡ�
	�����õ���lower_bound��Ϊʲô����upper_bound�أ���Ϊ���ܻ��кܶ��ظ���Ԫ�أ�Ҳ�����кܶ��m������ʱ�򷵻ص�һ���±꣬���Ա�֤�
	����upper_bound-1�᷵�����һ���ظ�Ԫ�ص��±꣬�������Ȼ��� 
	���� low_bound�Ľ����2 2 2 3 4��upper_bound�Ľ���ͻ�ʹ2 3 4.����������ˣ� 
	*/
	for (int i = n - 1;i >= 0;--i)
	{
		int j = lower_bound(num, num + i, num[i] * 1.0 / p) - num;
		if (i-j+1 > Maxlen) Maxlen = i - j+1;//�ҵ����ľͱ���
		if (i + 1 < Maxlen) break;//�����ʱ��0-i�ĳ��ȱ�MaxLen��С���ͽ����ɣ�û�����.
	}
	cout << Maxlen << endl;
	delete[]num;
	return 0;
}