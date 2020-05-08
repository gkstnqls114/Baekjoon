 
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

/*

  - ����
�������࿡�� ATM�� 1��ۿ� ����.
���� �� ATM�տ� N���� ������� ���� ���ִ�.
����� 1������ N������ ��ȣ�� �Ű��� ������, i�� ����� ���� �����ϴµ� �ɸ��� �ð��� Pi���̴�.

������� ���� ���� ������ ����, ���� �����ϴµ� �ʿ��� �ð��� ���� �޶����� �ȴ�.

���� ���, �� 5���� �ְ�, P1 = 3, P2 = 1, P3 = 4, P4 = 3, P5 = 2 �� ��츦 �����غ���.
[1, 2, 3, 4, 5] ������ ���� ���ٸ�, 1�� ����� 3�и��� ���� ���� �� �ִ�.
2�� ����� 1�� ����� ���� ���� �� ���� ��ٷ��� �ϱ� ������, 3 + 1 = 4���� �ɸ��� �ȴ�.
3�� ����� 1��, 2�� ����� ���� ���� ������ ��ٷ��� �ϱ� ������, �� 3 + 1 + 4 = 8���� �ʿ��ϰ� �ȴ�. 
4�� ����� 3 + 1 + 4 + 3 = 11��, 5�� ����� 3 + 1 + 4 + 3 + 2 = 13���� �ɸ��� �ȴ�.
�� ��쿡 �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� 3 + 4 + 8 + 11 + 13 = 39���� �ȴ�.

����[2, 5, 1, 4, 3] ������ ���� ����, 
2�� ����� 1�и���, 5�� ����� 1 + 2 = 3��, 
1�� ����� 1 + 2 + 3 = 6��, 
4�� ����� 1 + 2 + 3 + 3 = 9��,
3�� ����� 1 + 2 + 3 + 3 + 4 = 13���� �ɸ��� �ȴ�.
�� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� 1 + 3 + 6 + 9 + 13 = 32���̴�.

�� ������� �� �ʿ��� �ð��� ���� �ּҷ� ���� ���� ����.

���� �� �ִ� ����� �� N�� �� ����� ���� �����ϴµ� �ɸ��� �ð� Pi�� �־����� ��, 
�� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  - �Է�
ù° �ٿ� ����� �� N(1 �� N �� 1,000)�� �־�����. 
��° �ٿ��� �� ����� ���� �����ϴµ� �ɸ��� �ð� Pi�� �־�����. (1 �� Pi �� 1,000)

  - ���
ù° �ٿ� �� ����� ���� �����ϴµ� �ʿ��� �ð��� ���� �ּڰ��� ����Ѵ�.

*/
using namespace std;
 
vector<int> gWithdrawalTime; // index ��° ����� �����ϴµ�  ������ �ð�
vector<int> gWithdrawalWaitingTime; // index ��° ����� �����ϱ���� �ɸ��� �ð�

int gPeopleNum = 0;

int GetWithdrawalWaitingTime(int num);

int main()
{
    cin >> gPeopleNum;
    
    gWithdrawalTime.resize(gPeopleNum, 0);
    gWithdrawalWaitingTime.resize(gPeopleNum, 0);

    for (int i = 0; i < gPeopleNum; ++i)
    {
        cin >> gWithdrawalTime[i];
    }
    
    // �ּڰ� ������ ������
    sort(gWithdrawalTime.begin(), gWithdrawalTime.end(), less<int>());

    int result = 0;
    for (int i = 0; i < gPeopleNum; ++i)
    {
        result += GetWithdrawalWaitingTime(i+ 1);
    }

    std::cout << result << std::endl;
} 

// num �� 1���� �����մϴ�.
int GetWithdrawalWaitingTime(int num)
{
    int index = num - 1;
    
    if(num == 1)
    {
        gWithdrawalWaitingTime[index] = gWithdrawalTime[index]; 
    } 
    else if (gWithdrawalWaitingTime[index] == 0)
    {
        gWithdrawalWaitingTime[index] = gWithdrawalTime[index] + GetWithdrawalWaitingTime(num - 1); 
    }

    return gWithdrawalWaitingTime[index];
}