#include<cstdio>
#include<cmath>
int main() {
	double r1, p1, r2, p2;
	scanf("%lf%lf%lf%lf", &r1, &p1, &r2, &p2);
	double a = r1 * r2 * (cos(p1 + p2));
	double b = r1 * r2 * sin(p2 + p1);
	if (fabs(a) < 0.005) a = 0;
	if (fabs(b) < 0.005) b = 0;
	printf("%.2f", a);
	if (b >= 0) printf("+");
	printf("%.2fi\n", b);
	//�Թԣ�������0ҲҪ�����������
	return 0;
}