
#include <iostream>
#include <string>
#include <list>
/*
문제 1158 - 링크드 리스트
요세푸스 문제는 다음과 같다.

1번부터 N번까지 N명의 사람이 원을 이루면서 앉아있고, 양의 정수 K(≤ N)가 주어진다. 
이제 순서대로 K번째 사람을 제거한다. 
한 사람이 제거되면 남은 사람들로 이루어진 원을 따라 이 과정을 계속해 나간다.
이 과정은 N명의 사람이 모두 제거될 때까지 계속된다.

원에서 사람들이 제거되는 순서를 (N, K)-요세푸스 순열이라고 한다. 
예를 들어 (7, 3)-요세푸스 순열은 <3, 6, 2, 7, 5, 1, 4>이다.

N과 K가 주어지면 (N, K)-요세푸스 순열을 구하는 프로그램을 작성하시오.
*/ 

using namespace std;

int main()
{ 
	int people_count = 0;
	int k = 0;
	cin >> people_count >> k;

	// 여기서 int는 n번째 사람(1~n)을 의미한다.
	list<int> people;
	for (int i = 0; i < people_count; ++i)
	{
	    people.push_back(i + 1);
	}

	// 요세푸스 순열을 구한다.
	list<int> Josephus_list;
	auto iter = people.begin();
	while (!people.empty())
	{
		// 제거될 k번째를 고른다.
		for (int i = 0; i < k - 1; ++i)
		{
			++iter;
			if (iter == people.end()) iter = people.begin();
		}

		Josephus_list.push_back(*iter);
		iter = people.erase(iter);
		if (iter == people.end()) iter = people.begin();
	}

	// 출력한다.
	cout << "<";
	for (auto iter = Josephus_list.begin(); iter != Josephus_list.end(); ++iter)
	{
		cout << *iter;
		if (iter != (--Josephus_list.end())) cout << ", ";
	}
	cout << ">";
}