
#include <iostream>
#include <map>

/*
���� - 1157 ���ڿ�ó��
���ĺ� ��ҹ��ڷ� �� �ܾ �־�����, 
�� �ܾ�� ���� ���� ���� ���ĺ��� �������� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�. 

��, �빮�ڿ� �ҹ��ڸ� �������� �ʴ´�.

*/

// �۾��ð� 10��

using namespace std;

int main()
{
	map<char, int> dict;
	  
	string s;

	cin >> s;

	// �ܾ��� 0��°���� n��°���� ���������� ���ĺ��� Ȯ���Ѵ�.
	for (int i = 0; i != s.size(); ++i)
	{
		char key = toupper(s[i]);

		if (dict.find(key) == dict.end())
		{
			// ���� �ʿ� �������� �ʴ´ٸ� ���� �����Ѵ� (�빮�ڷ�)
			dict.insert(pair<char, int>(key, 1));
		}
		else
		{
			// ���� �ʿ� �����Ѵٸ�, ī��Ʈ�� �ϳ� ��½�Ų��.
			dict[key] += 1;
		}
	}

	// ��� �����͸� ��ȸ�Ͽ� ���� ī���õ� ���ĺ��� ã�´�.
	int max_count = 0;
	char max_alphabet = '?';
	for (const auto& data : dict)
	{
		if (max_count < data.second)
		{
			max_count = data.second;
			max_alphabet = data.first;
		}
		else if (max_count == data.second)
		{
			max_alphabet = '?';
		}
	}

	// ���������� ���� ���� ������ ���� ���ĺ� ���
	cout << max_alphabet;
}