#include <iostream>
#include <map>
#include <string>
 
using namespace std;

/*
문제
5명의 요원 중 FBI 요원을 찾는 프로그램을 작성하시오.
FBI요원은 요원의 첩보원명에 FBI가 들어있다.

입력
5개 줄에 요원의 첩보원명이 주어진다.
첩보원명은 알파벳 대문자, 숫자 0~9, 대시 (-)로만 이루어져 있으며, 최대 10글자이다.

출력
첫째 줄에 FBI 요원이 몇번째에 존재하지는지 출력한다. ex) 1 3 5
이때, 해당하는 요원이 몇 번째 입력인지를 공백으로 구분하여 출력해야 하며, 오름차순으로 출력해야 한다. 
만약 FBI 요원이 없다면 "HE GOT AWAY!"를 출력한다.
*/

// 작업시간 15~20분

const int gCount{ 5 };

int main()
{
	string s[gCount];
	bool isFBI[gCount] ;

	// 단어 입력 및 변수 대입
	for (int icount = 0; icount < gCount; ++icount)
	{
		isFBI[icount] = false;
		cin >> s[icount];
	}
	
	// 각 단어에 FBI가 있는지 확인 
	bool isHaveFBI = false;
	for (int icount = 0; icount < gCount; ++icount) // 단어 순회
	{
		for (int index = 0; index < s[icount].size(); ++index) // 단어의 알파벳들 순회
		{
			// 만약 F가 나옴과 동시에 FBI가 될수있을 index번째일경우
			if (s[icount][index] == 'F' && index + 2 < s[icount].size()) 
			{
				if (s[icount][index + 1] == 'B' && s[icount][index + 2] == 'I')
				{
					isFBI[icount] = true;
					isHaveFBI = true;
				}
			}
		}
	}

	if (isHaveFBI)
	{ 
		for (int icount = 0; icount < gCount; ++icount)
		{ 
			if(isFBI[icount]) cout << icount + 1 << " ";
		}
	}
	else
	{ 
		cout << "HE GOT AWAY!" << endl;
	}
}