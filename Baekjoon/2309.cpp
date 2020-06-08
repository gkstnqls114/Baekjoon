/*
2309 - ���Ʈ����
�պ� ���� �ϰ� �����̵�� �Բ� ��ȭ�Ӱ� ��Ȱ�ϰ� �ִ� �鼳���ֿ��� ���Ⱑ ã�ƿԴ�.
�ϰ��� ��ġ�� ���ƿ� �����̰� �ϰ� ���� �ƴ� ��ȩ ���̾��� ���̴�.

��ȩ ���� �����̴� ��� �ڽ��� "�鼳 ���ֿ� �ϰ� ������"�� ���ΰ��̶�� �����ߴ�. 
�پ ������ �������� ������ �ִ� �鼳���ִ�, ���ེ���Ե� �ϰ� �������� Ű�� ���� 100�� ���� ����� �´�.

��ȩ �������� Ű�� �־����� ��, �鼳���ָ� ���� �ϰ� �����̸� ã�� ���α׷��� �ۼ��Ͻÿ�.
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