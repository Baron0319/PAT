#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
bool is_exist[300];
using namespace std;
void Mark(char c)//��ǳ��ֵ���ĸ�����»��ߣ�ע����ĸ�Ļ���Сд��Ҫ��ǣ���Ϊ��Сд����һ����
{
	is_exist[c] = 1;
	if (c >= 'a' && c <= 'z') is_exist[c - 'a' + 'A'] = 1;
	if (c >= 'A' && c <= 'Z') is_exist[c - 'A' + 'a'] = 1;
}
void Outchar(char c)
{
	if (c >= 'a' && c <= 'z') cout << (char)toupper(c);
	else cout << (char)c;
}
int main()
{
	memset(is_exist, 0, sizeof(is_exist));
	string str, sub;
	cin >> str >> sub;
	for (int i = 0;i < sub.length();++i)
		Mark(sub[i]);
	for (int i = 0;i < str.length();++i)
	{
		if (is_exist[str[i]] == 0)
		{
			Outchar(str[i]);
			Mark(str[i]);//��Ҫ�ظ���������Զ�������ַ�Ҳ���һ��
		}
	}
	cout << endl;
	return 0;
}