#include<cstdio>
/*1.�ȶ�������������������л��򣬷���Ϊ0���0����ĸΪ1�������
  2.���㣬�����ɴ���������ʽ
  ע�⣺
  1.��������������Ϊ����Ҫ������
  2.Ҫ��long long����Ȼ�ḡ��������	Ҳ�����������ʼ��Ϊ�ǳ�0���󣬽���жϰ��죬�ĳ�long long��ac�� �����ʺţ���
  3.�����кܶ�ϸ��Ҫע�⡣��ע��
  */
typedef long long ll;
ll gcd(ll a, ll b)
{
	return !b ? a : gcd(b, a % b);
}
typedef struct RationalNum {//�������ýṹ��洢һ��������
	ll a, b, k;
	RationalNum() : k(0) {}
} Rnum;
ll f = 1;//�ж��������Ƿ��Ǹ��� f=-1���Ǹ���
void Simplify(Rnum& num);//��һ��������
void Outone(Rnum num);//���һ��������
void OutAll(Rnum  n1, Rnum n2, Rnum n3, char c);//���һ����ʽ
void Calculate(Rnum n1, Rnum n2);//��������
int main()
{
	//freopen("in.txt", "r", stdin);
	Rnum n1, n2;
	scanf("%lld/%lld%lld/%lld", &n1.a, &n1.b, &n2.a, &n2.b);
	Calculate(n1, n2);
	return 0;
}
void Simplify(Rnum& num)
{
	f = 1;
	if (num.b < 0)
	{//��Ȼ�����ʱ��֤�����ڷ���ǰ���������õ���n3���ɲ����Զ�Ų���ţ����Ի���Ҫ�ж�һ��
		num.a = -num.a;
		num.b = -num.b;
	}
	if (num.a < 0) {
		num.a = -num.a;
		f = -f;//�����Ǹ���
	}
	ll x = gcd(num.a, num.b);
	num.a /= x;
	num.b /= x;
	if (num.a >= num.b) {
		num.k = f * (num.a / num.b); //����f=-1���������������,kҲ����0.��ô���žͱ�ʡȥ�����ҵ�ʱһֱ��ĵط�
		num.a %= num.b;
	}
}
void Outone(Rnum num)
{//���һ��ʱ�ȼ򻯣������.�������Ҫ����һЩ�����ģ������Լ�ģ��һ��
	Simplify(num);
	if (num.k < 0) printf("(");
	if (num.k) printf("%lld", num.k);
	/*ע��һ������������������ -1/3��������������=>k=0,f=-1,a=1,b=3����ô��������У������1/3
	����Ҫ����������Ǹ������*/
	else if (num.k == 0 && f == -1) printf("(-");
	if (num.a == 0) {//a=0,�����ٹ�b��ʲô��
		if (num.k == 0) printf("0");// ��Ȼ,k����ˣ�a���0�Ͳ����������
	}
	else {
		if (num.k) printf(" ");
		printf("%lld", num.a);
		if (num.b != 1) printf("/%lld", num.b);
	}
	if (num.k < 0 || (num.k == 0 && f == -1)) printf(")");//ͬ��Ҫ����������Ǹ���
}
void OutAll(Rnum  n1, Rnum n2, Rnum n3, char c) {//���һ����ʽ
	Outone(n1);
	printf(" %c ", c);
	Outone(n2);
	printf(" = ");
	if (c == '/' && n3.b == 0) printf("Inf");//��ĸΪ0����
	else Outone(n3);
	printf("\n");
}
void Calculate(Rnum n1, Rnum n2) {//���ûʲô�ˣ���������ķ��ӷ�ĸ��϶������
	Rnum n3;
	//�ӷ�
	n3.a = n1.a * n2.b + n2.a * n1.b;n3.b = n1.b * n2.b;OutAll(n1, n2, n3, '+');
	//����
	n3.a = n1.a * n2.b - n2.a * n1.b;OutAll(n1, n2, n3, '-');
	//�˷�
	n3.a = n1.a * n2.a;n3.b = n1.b * n2.b;OutAll(n1, n2, n3, '*');
	//����
	n3.a = n1.a * n2.b;n3.b = n1.b * n2.a;OutAll(n1, n2, n3, '/');
}