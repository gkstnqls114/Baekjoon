#include <iostream>
#include <list>
#include <string>

using namespace std;

/*
5397 - Ű�ΰ� (��ũ�� ����Ʈ)

â���̴� �������� ��й�ȣ�� ��ġ�� ���ؼ� �����̰� ����ϴ� ��ǻ�Ϳ� Ű�ΰŸ� ��ġ�ߴ�.
��ĥ�� ��ٸ� ���� â���̴� �����̰� ��й�ȣ â�� �Է��ϴ� ���ڸ� ���´�.

Ű�ΰŴ� ����ڰ� Ű���带 ���� ����� ��� ����Ѵ�.
����, �����̰� ��й�ȣ�� �Է��� ��, ȭ��ǥ�� �齺���̽��� �Է��ص� ��Ȯ�� ��й�ȣ�� �˾Ƴ� �� �ִ�.

�����̰� ��й�ȣ â���� �Է��� Ű�� �־����� ��, �������� ��й�ȣ�� �˾Ƴ��� ���α׷��� �ۼ��Ͻÿ�.


�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ������ �־�����.
�� �׽�Ʈ ���̽��� ���ٷ� �̷���� �ְ�, �����̰� �Է��� ������� ���̰� L�� ���ڿ��� �־�����.
(1 �� L�� ���� �� 1,000,000) 

�����̰� �齺���̽��� �Է��ߴٸ�, '-'�� �־�����. 
�̶� Ŀ���� �ٷ� �տ� ���ڰ� �����Ѵٸ�, �� ���ڸ� �����. 
ȭ��ǥ�� �Է��� '<'�� '>'�� �־�����. �̶��� Ŀ���� ��ġ�� ������ �� �ִٸ�, ���� �Ǵ� ���������� 1��ŭ �����δ�.
������ ���ڴ� ��й�ȣ�� �Ϻ��̴�. ����, ���߿� �齺���̽��� ���ؼ� ���� ���� �ִ�.
���� Ŀ���� ��ġ�� ���� �������� �ƴ϶��, �� ���ڸ� �Է��ϰ�, Ŀ���� ���������� �� ĭ �̵��Ѵ�.

*/

int main()
{
	int count = 0;
	cin >> count;

	list<string> password_list;
	for (int i = 0; i < count; ++i)
	{
		string s;
		cin >> s;

		list<char> password;

		auto iter = password.begin();
		for (int idx = 0; idx < s.size(); ++idx)
		{     
		//	if (s[idx] == '-')
		//	{
		//		if (iter != password.end())
		//		{
		//			iter = password.erase(iter); 
		//		}
		//	}
		//	else if (s[idx] == '<')
		//	{
		//		if (iter != password.end())
		//		{
		//			++iter;
		//		}
		//	}
		//	else if (s[idx] == '>')
		//	{
		//		if (iter != password.begin())
		//		{
		//			--iter;
		//		}
		//	}
		//	else
		//	{ 
		//		iter = password.insert(iter, s[idx]); 
		//	}
		//}
			if (s[idx] == '-')
			{
				if (iter != password.begin())
				{
					--iter;
					iter = password.erase(iter); 
				}
			}
			else if (s[idx] == '<')
			{
				if (iter != password.begin())
				{
					--iter;
				}
			}
			else if (s[idx] == '>')
			{
				if (iter != password.end())
				{
					++iter;
				}
			}
			else
			{ 
				iter = password.insert(iter, s[idx]); 
				++iter;
			}
		}

		string data;
		for (auto iter = password.begin(); iter != password.end(); ++iter)
		{
			data += *iter;
		}
		password_list.push_back(data);
	}

	for (auto  password : password_list)
	{
		cout << password << endl;
	} 
}