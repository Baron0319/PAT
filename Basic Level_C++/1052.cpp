#include <iostream>
using namespace std;
int main() {
	int count[4] = { 0 };
	string emoji[5][20];
	int c, left_hand, right_hand, mouth, left_eye, right_eye, k;
	for (int i = 1; i <= 3; ++i) {
		string s = "";
		int cnt = 1;
		while ((c = getchar()) != '\n') {//һ�ζ�ȡһ��
			if (c != '[') continue;//û������[һֱgetchar
			while ((c = getchar()) != ']') {//�����ˣ������µ����磬
				if (c != ' ');//�ո񲻹�
				s += c;
			}
			emoji[i][cnt++] = s;//��������
			s = "";
		}
		count[i] = cnt;
	}
	cin >> k;
	while (k--) {//������̫�����ˣ����ùܣ��ǵ��ж����ݲ��Ϸ�����������������ܸ������Լ�С��1
		cin >> left_hand >> left_eye >> mouth >> right_eye >> right_hand;
		if (left_hand >= count[1] || left_eye >= count[2] | mouth >= count[3]
			|| right_eye >= count[2] || right_hand >= count[1]
			|| left_hand < 1 || left_eye < 1 || mouth < 1 || right_eye < 1 || right_hand < 1
			//ע�⣬���ܻ�С��1
			) {
			puts("Are you kidding me? @\\/@");//�ǵ�ת��
		}
		else
			cout << emoji[1][left_hand] << '(' << emoji[2][left_eye]
			<< emoji[3][mouth]
			<< emoji[2][right_eye] << ')' << emoji[1][right_hand] << endl;
	}
	return 0;
}