
#include <iostream>
#include <map>

/*
문제 - 1157 문자열처리
알파벳 대소문자로 된 단어가 주어지면, 
이 단어에서 가장 많이 사용된 알파벳이 무엇인지 알아내는 프로그램을 작성하시오. 

단, 대문자와 소문자를 구분하지 않는다.

*/

// 작업시간 10분

using namespace std;

int main()
{
	map<char, int> dict;
	  
	string s;

	cin >> s;

	// 단어의 0번째부터 n번째까지 순차적으로 알파벳을 확인한다.
	for (int i = 0; i != s.size(); ++i)
	{
		char key = toupper(s[i]);

		if (dict.find(key) == dict.end())
		{
			// 만약 맵에 존재하지 않는다면 새로 생성한다 (대문자로)
			dict.insert(pair<char, int>(key, 1));
		}
		else
		{
			// 만약 맵에 존재한다면, 카운트를 하나 상승시킨다.
			dict[key] += 1;
		}
	}

	// 모든 데이터를 순회하여 많이 카운팅된 알파벳을 찾는다.
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

	// 최종적으로 가장 많은 개수가 나온 알파벳 출력
	cout << max_alphabet;
}