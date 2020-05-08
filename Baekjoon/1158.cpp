
#include <iostream>
#include <string>
#include <list>
/*
���� 1158 - ��ũ�� ����Ʈ
�似Ǫ�� ������ ������ ����.

1������ N������ N���� ����� ���� �̷�鼭 �ɾ��ְ�, ���� ���� K(�� N)�� �־�����. 
���� ������� K��° ����� �����Ѵ�. 
�� ����� ���ŵǸ� ���� ������ �̷���� ���� ���� �� ������ ����� ������.
�� ������ N���� ����� ��� ���ŵ� ������ ��ӵȴ�.

������ ������� ���ŵǴ� ������ (N, K)-�似Ǫ�� �����̶�� �Ѵ�. 
���� ��� (7, 3)-�似Ǫ�� ������ <3, 6, 2, 7, 5, 1, 4>�̴�.

N�� K�� �־����� (N, K)-�似Ǫ�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/ 

using namespace std;

int main()
{ 
	int people_count = 0;
	int k = 0;
	cin >> people_count >> k;

	// ���⼭ int�� n��° ���(1~n)�� �ǹ��Ѵ�.
	list<int> people;
	for (int i = 0; i < people_count; ++i)
	{
	    people.push_back(i + 1);
	}

	// �似Ǫ�� ������ ���Ѵ�.
	list<int> Josephus_list;
	auto iter = people.begin();
	while (!people.empty())
	{
		// ���ŵ� k��°�� ����.
		for (int i = 0; i < k - 1; ++i)
		{
			++iter;
			if (iter == people.end()) iter = people.begin();
		}

		Josephus_list.push_back(*iter);
		iter = people.erase(iter);
		if (iter == people.end()) iter = people.begin();
	}

	// ����Ѵ�.
	cout << "<";
	for (auto iter = Josephus_list.begin(); iter != Josephus_list.end(); ++iter)
	{
		cout << *iter;
		if (iter != (--Josephus_list.end())) cout << ", ";
	}
	cout << ">";
}