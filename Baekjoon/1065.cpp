/*
1065 - 브루트포스
어떤 양의 정수 X의 각 자리가 등차수열을 이룬다면, 그 수를 한수라고 한다. 
등차수열은 연속된 두 개의 수의 차이가 일정한 수열을 말한다. 

N이 주어졌을 때, 1보다 크거나 같고, N보다 작거나 같은 한수의 개수를 출력하는 프로그램을 작성하시오.
*/

#include <iostream>
#include <string>
#include <set> 
#include <list> 
using namespace std;  

int main()
{
	int N = 0;
	cin >> N;

	int count = 0; 
	if (N < 100)
	{
		count = N; // 100 미만은 모두 한수.
	}
	else
	{
		// 100이상
		count = 99;
		for (int i = 100; i <= N; ++i)
		{
			int one = (i % 100) % 10;
			int ten = (i % 100) / 10;
			int hund = i / 100;

			if ((hund - ten) == (ten - one))
			{
				count += 1;
			}
		}
	}

	cout << count;
}