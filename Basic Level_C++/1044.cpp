#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string, string>mp;
string fir[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string sec[13] = {"","tam ","hel ","maa ","huh ","tou ","kes ","hei ","elo ","syy ","lok ","mer ","jou " };
void Pre_treatment()
{	
	int f, s;
	for (int i = 0;i < 169;++i)
	{
		string Mars_num = "";
		f = i % 13;		s = i / 13;
		if (s != 0) Mars_num += sec[s];
		Mars_num += fir[f];
		//ע�⵱i��13����������0���⣬�ǲ��������λ��0����tam tret ���������λ��0������Ҫ��ȡǰ����
		if (f == 0 && s) Mars_num = Mars_num.substr(0, 3);
		mp[to_string(i)] = Mars_num;	mp[Mars_num] = to_string(i);//����ӳ��
	}
}
int main()
{
	Pre_treatment();//����ֻ��168���ȱ���𰸺���
	int n;
	string num;
	cin >> n;
	getchar();
	while (n--)
	{
		getline(cin, num);
		cout << mp[num] << endl;
	}
	return 0;
}