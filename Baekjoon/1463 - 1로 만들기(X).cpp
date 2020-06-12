
#include <iostream>
#include <algorithm> 

/*
문제 - 1463 : 1로 만들기 (다이나믹 프로그래밍)

정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

*/ 

const int MAX_VALUE{ 1000001 };
int min_result[MAX_VALUE];

using namespace std;

int dynamicfunction(int count, int number, int search);

int main()
{ 
	// 초기화
	for (int i = 0; i < MAX_VALUE; ++i)
	{
		min_result[i] = MAX_VALUE;
	}

	int search;
	cin >> search;

	cout << dynamicfunction(0, search, search);
}



int dynamicfunction(int count, int number, int search)
{
	if (number  == 1)
	{ 
		return count;
	}
	if (number < 1)
	{
		return MAX_VALUE;
	} 
	if (min_result[number] != MAX_VALUE)
	{
		return min_result[number];
	}

	int value1 = MAX_VALUE;
	int value2 = MAX_VALUE;
	int value3 = MAX_VALUE; 
	
	if (value1 % 3 == 0) value1 = dynamicfunction(count + 1, number / 3, search);
	if (value2 % 2 == 0)value2 = dynamicfunction(count + 1, number / 2, search);
	value3 = dynamicfunction(count + 1, number - 1, search);

	int min_value = min(min(value1, value2), value3); 

	cout << count << "...  " << value1 << " "<< value2 << " " << value3 << endl;
	if(min_result[number] > min_value)  min_result[number] = min_value;

	return min_value;
}
