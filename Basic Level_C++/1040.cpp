#include<cstdio>
#include<cstring>
typedef long long ll;
const int mod = 1000000007;
const int N = 1e5;
/*��ʼ������������ֱ𱣴�P,T������
Ȼ���Ż���ֻ��һ�����鱣��T
���������Ĵ��룬�����ø���������T�ͺ�
�ռ临�ӶȻ����Ż���*/
int main() {
	char s[N + 5];
	ll ans = 0, pre_P = 0, next_T = 0;
	scanf("%s", s );
	int len = strlen(s);
	for (int i = len - 1;i >= 0;--i)
		if (s[i] == 'T') next_T++;
	for (int i = 0;i < len;++i) {
		if (s[i] == 'P') pre_P++;
		else if (s[i] == 'T') next_T--;//��ʾǰ�����T����ô���������һ��
		else if (s[i] == 'A') ans = (ans % mod + ((pre_P % mod * next_T % mod)) % mod) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}