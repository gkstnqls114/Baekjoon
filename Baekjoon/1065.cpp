/*
1065 - ���Ʈ����
� ���� ���� X�� �� �ڸ��� ���������� �̷�ٸ�, �� ���� �Ѽ���� �Ѵ�. 
���������� ���ӵ� �� ���� ���� ���̰� ������ ������ ���Ѵ�. 

N�� �־����� ��, 1���� ũ�ų� ����, N���� �۰ų� ���� �Ѽ��� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.
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
		count = N; // 100 �̸��� ��� �Ѽ�.
	}
	else
	{
		// 100�̻�
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