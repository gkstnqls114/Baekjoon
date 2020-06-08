/*
2309 - 브루트포스
왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다.
일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.

아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 
뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.

아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string>
#include <set> 
#include <list> 
using namespace std;

const int num = 9;
const int real_num = 7;

int arr[10];
bool b_arr[10]; 

bool dfs(int& value, int& count, int idx)
{
	if (value == 100 && count == real_num) return true;

	value += arr[idx];
	b_arr[idx] = true;
	count += 1;

	int next_idx = 0;
	bool is100 = false;
	for (int i = 0; i < num; ++i)
	{
		if (!b_arr[i])
		{
			is100 = dfs(value, count, i);
			if (is100) return true;
		}
	}

	b_arr[idx] = false;
	value -= arr[idx];
	count -= 1;

	return false;
}

int main()
{ 
	for (int i = 0; i < num; ++i)
	{
		cin >> arr[i];
		b_arr[i] = false;
	}

	int value = 0;
	int count = 0;
	for (int i = 0; i < num; ++i)
	{
		bool is100 = dfs(value, count, i);
		if (is100) break;
	}

	list<int> answer; 
	for (int i = 0; i < num; ++i)
	{
		if (b_arr[i])
		{ 
			answer.push_back(arr[i]);
		}
	}

	answer.sort();
	for (const auto& n : answer)
	{
		cout << n << endl;
	}
}