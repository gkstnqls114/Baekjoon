#include <iostream>
#include <map>
#include <string>
 
using namespace std;

/*
����
5���� ��� �� FBI ����� ã�� ���α׷��� �ۼ��Ͻÿ�.
FBI����� ����� ø������ FBI�� ����ִ�.

�Է�
5�� �ٿ� ����� ø�������� �־�����.
ø�������� ���ĺ� �빮��, ���� 0~9, ��� (-)�θ� �̷���� ������, �ִ� 10�����̴�.

���
ù° �ٿ� FBI ����� ���°�� ������������ ����Ѵ�. ex) 1 3 5
�̶�, �ش��ϴ� ����� �� ��° �Է������� �������� �����Ͽ� ����ؾ� �ϸ�, ������������ ����ؾ� �Ѵ�. 
���� FBI ����� ���ٸ� "HE GOT AWAY!"�� ����Ѵ�.
*/

// �۾��ð� 15~20��

const int gCount{ 5 };

int main()
{
	string s[gCount];
	bool isFBI[gCount] ;

	// �ܾ� �Է� �� ���� ����
	for (int icount = 0; icount < gCount; ++icount)
	{
		isFBI[icount] = false;
		cin >> s[icount];
	}
	
	// �� �ܾ FBI�� �ִ��� Ȯ�� 
	bool isHaveFBI = false;
	for (int icount = 0; icount < gCount; ++icount) // �ܾ� ��ȸ
	{
		for (int index = 0; index < s[icount].size(); ++index) // �ܾ��� ���ĺ��� ��ȸ
		{
			// ���� F�� ���Ȱ� ���ÿ� FBI�� �ɼ����� index��°�ϰ��
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