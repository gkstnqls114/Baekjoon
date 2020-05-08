#include <iostream>
#include <string>
#include <map>

/*
���� - 10809. ���ڿ�ó������
���ĺ� �ҹ��ڷθ� �̷���� �ܾ� S�� �־�����.
������ ���ĺ��� ���ؼ�, �ܾ ���ԵǾ� �ִ� ��쿡�� ó�� �����ϴ� ��ġ��, 
���ԵǾ� ���� ���� ��쿡�� -1�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

// �۾��ð� 17��

using namespace std;

int main()
{
	map<char, int> dict;

	// ���ĺ��� ���߾� a~z ���� -1�� �ִ� map ����
	char alphabet = 'a';
	while (true)
	{
		dict.insert(pair<char, int>(alphabet, -1));
		if (alphabet == 'z') break;
		alphabet = static_cast<char>(static_cast <int>(alphabet) + 1);
	}

	string s;

	cin >> s;

	// �ܾ��� 0��°���� n��°���� ���������� ���ĺ��� Ȯ���Ѵ�.
	for (int i = 0 ; i != s.size() ; ++i)
	{
		char key = s[i];

		// ���� -1�� �ƴ϶��, �� ���ʷ� ��Ÿ���� ���ĺ��̶�� �����Ѵ�.
		if (dict[key] == -1)
		{
			dict[key] = i;
		}
	}
	 
	for (const auto& data : dict)
	{
		cout << data.second << " ";
	}
}