/*
2983 - ������ ���� (��ũ�� ����Ʈ)

����
Ʈ���� Ÿ�� �̵��ϴ� �߿� ����̴� �޽��� ���ϱ� ���ؼ� ȣ���� ��� ��ȴ�. 
ȣ������ �������� ��� �ְ�, �������� ȣ�� ���� ���ִ� �Ĺ� N���� �����ϸ鼭 �ٴѴ�. 
������ ������ ������ ���������� Ű���� �ϸ� �������� �Ƹ��ٿ� ���ַ� ���Ѵٰ� �Ѵ�. 
�ϴ� �������� ��ƾ� ������ ������� �ƴ��� Ȯ���� �� �ִ�. �������� ��ƺ���.

ȣ���� 2���� ������� ������ �� �ְ�, �Ĺ��� �� ��� ���� ������ ��Ÿ�� �� �ִ�.
(x, y)���� �ִ� �������� �Ʒ� �� ���� ���� �� �� �������� ������ �� �ִ�.

������ ���� ���� P�� ���ؼ�, (x+P, y+P)�� ������ �� �ִ�. �� ������ A��� �Ѵ�.
������ ���� ���� P�� ���ؼ�, (x+P, y-P)�� ������ �� �ִ�. �� ������ B��� �Ѵ�.
������ ���� ���� P�� ���ؼ�, (x-P, y+P)�� ������ �� �ִ�. �� ������ C��� �Ѵ�.
������ ���� ���� P�� ���ؼ�, (x-P, y-P)�� ������ �� �ִ�. �� ������ D��� �Ѵ�.
�������� �� ���� �� �� ������ ����. 

�� ���� �� ���⿡ �ִ� ���� ����� �Ĺ��� ������ �Ѵ�. 
����, �� ���⿡ �Ĺ��� ���ٸ�, �������� �� ��ġ�� �״�� �ִ´�. 
�������� ������ �ϰ� �� ���Ŀ�, ���� �ִ� �Ĺ��� ȣ���� ����ɰԵǰ� �������.

����̴� �Ĺ��� ��ġ�� �������� �� ������ ��� �˰� �ִ�. 
����̴� �������� ������ ������ ���� ��ǥ�� �˾Ƴ� ����, �ű⼭ �������� �������� �Ѵ�.

�������� ������ ������ �Ĺ��� ��ġ�� ����ϱ�?


�Է�
ù° �ٿ� �Ĺ��� �� N�� ������ �� K�� �־�����. (1 �� N, K �� 100,000)

��° �ٿ��� �������� �� ���� K���� �־�����. �� ������ 'A','B','C','D'�θ� �̷���� �ִ�.

��° �ٺ��� N�� �ٿ��� �Ĺ��� ��ǥ�� X, Y�� �־�����. (0 �� X, Y �� 1,000,000,000) ó������ �־����� �Ĺ��� �������� �ִ�.


���
�������� ������ ������ �Ĺ��� ��ǥ�� ����Ѵ�.
*/


#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct POINT
{
	int x;
	int y;

	POINT(int _x = -1, int _y = -1) :x(_x), y(_y) {};

	bool operator== (const POINT& other) const
	{
		return (x == other.x) && (y == other.y);
	} 
};
 

// �Ĺ��� ��ġ
list<POINT> plantPosition;

// �������� �̹� ������ ��ġ������
list<POINT> jumpPosition;

bool FindCorrect(POINT curr, POINT& next, char c)
{
	switch (c)
	{
	case 'A':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px > 0 && Py > 0 && Px == Py)
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;

	case 'B':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px > 0 && Py < 0 && Px == abs(Py))
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;

	case 'C':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px < 0 && Py > 0 && abs(Px) == Py)
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;

	case 'D':
	{
		for (auto& plant : plantPosition)
		{
			int Px = plant.x - curr.x;
			int Py = plant.y - curr.y;
			if (Px < 0 && Py < 0 && Px == Py)
			{
				next.x = plant.x;
				next.y = plant.y;
				return true;
			}
		}
	}
		break;
	default:
		break;
	}

	return false;
}
int main()
{
	int N = 0;
	int K = 0;
	cin >> N >> K; // �Ĺ� n�� ���� �������� �� ���� k��
	
	// ������ ���� ���� ���ϱ�
	vector<char> frogJump;
	frogJump.reserve(K);
	
	string s;
	cin >> s;
	for (int i = 0; i < K; ++i)
	{
		frogJump.push_back(s[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		plantPosition.emplace_back(x, y);
	} 

	// ���� ��ġ
	POINT currPos = plantPosition.front();
	for (int i = 0; i < K; ++i)
	{
		// �ش� ������ �ش�Ǵ� ��ġ�� ã�´�.
		POINT next;
		char jump = frogJump[i];
		cout << currPos.x << "," << currPos.y << endl;
		bool isJump = FindCorrect(currPos, next, jump);
		if (!isJump)
		{ 
			break;
		} 

		// ���� ��ġ ���� �߰�.
		jumpPosition.emplace_back(currPos.x, currPos.y);

		// �̵��� ���� ��ġ ����.
		plantPosition.remove(currPos);

		currPos = next;
	}

	cout << currPos.x << " " << currPos.y << endl;
}
