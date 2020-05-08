#include <iostream>
#include <string>
#include <map>

/*
문제 - 10809. 문자열처리관련
알파벳 소문자로만 이루어진 단어 S가 주어진다.
각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 
포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.
*/

// 작업시간 17분

using namespace std;

int main()
{
	map<char, int> dict;

	// 알파벳에 맞추어 a~z 까지 -1을 넣는 map 설정
	char alphabet = 'a';
	while (true)
	{
		dict.insert(pair<char, int>(alphabet, -1));
		if (alphabet == 'z') break;
		alphabet = static_cast<char>(static_cast <int>(alphabet) + 1);
	}

	string s;

	cin >> s;

	// 단어의 0번째부터 n번째까지 순차적으로 알파벳을 확인한다.
	for (int i = 0 ; i != s.size() ; ++i)
	{
		char key = s[i];

		// 만약 -1이 아니라면, 즉 최초로 나타나는 알파벳이라면 대입한다.
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