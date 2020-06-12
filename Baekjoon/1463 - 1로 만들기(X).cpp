
#include <iostream>
#include <algorithm> 

/*
���� - 1463 : 1�� ����� (���̳��� ���α׷���)

���� X�� ����� �� �ִ� ������ ������ ���� �� ���� �̴�.

X�� 3���� ������ ��������, 3���� ������.
X�� 2�� ������ ��������, 2�� ������.
1�� ����.
���� N�� �־����� ��, ���� ���� ���� �� ���� ������ ����ؼ� 1�� ������� �Ѵ�. ������ ����ϴ� Ƚ���� �ּڰ��� ����Ͻÿ�.

*/ 

const int MAX_VALUE{ 1000001 };
int min_result[MAX_VALUE];

using namespace std;

int dynamicfunction(int count, int number, int search);

int main()
{ 
	// �ʱ�ȭ
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
