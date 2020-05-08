// Baekjoon.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

enum class PATH
{
    NOT_WALK, // 이동할 수 없다.
    CAN_WALK, // 이동할 수 있다.
    WALKED // CAN_WALK 였지만 이미 이동했다.
};

const int MAX = 101;
const int D_MAX = 4;
const int dx[D_MAX] = {1,  0, 0, -1};
const int dy[D_MAX] = {0, 1, -1,  0};

std::stack<PATH> path;
PATH MAP[MAX][MAX];
int N = 0; // y 최대
int M = 0; // x 최대
int min_node_count = MAX * MAX;

void InitMap();
void PrintMap();
void InsertMap();
void FindMap(PATH& node, int curr_x, int curr_y);

int main()
{

    std::vector<std::vector<int>> answer;
    answer.reserve(3);
    for (int i = 0; i < 3; ++i)
    {
        answer[i].reserve(5);
    }
    answer[0].push_back( 0);

    std::cout << answer[0].at(0) << std::endl;

    return 0;
    cin >> N >> M;

    // 맵 초기화
    InitMap();

    // 맵 입력
    InsertMap();

    // 디버그 위해 다시 맵출력
    PrintMap();

    // 길 찾기
    FindMap(MAP[0][0], 0, 0);

    // 최소 경로 출력
    cout << "최소경로: " << min_node_count << endl;


}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

void InitMap()
{ 
    for (int x = 0; x < MAX; ++x)
    {
        for (int y = 0; y < MAX; ++y)
        {
            MAP[x][y] = PATH::NOT_WALK;
        }
    }
}

void PrintMap()
{
    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            if (MAP[x][y] == PATH::CAN_WALK)
            { 
                cout << "○";
            }
            if (MAP[x][y] == PATH::NOT_WALK)
            {
                cout << "※" ;

            }
            if (MAP[x][y] == PATH::WALKED)
            {
                cout << "●" ; 
            }
        }
        cout << endl;
    } 
    std::cout << path.size() << std::endl;
    cout << endl;
}

void InsertMap()
{
    string str;
    for (int y = 0; y < N; ++y)
    {
        cin >> str;

        for (int x = 0; x < M; ++x)
        {
            char c = str.at(x);
            MAP[x][y] = PATH(atoi(&c));
        } 
    }
}

// (0, 0)에서 (N-1, M-1) 위치 까지의 경로 찾기
void FindMap(PATH& node, int curr_x, int curr_y)
{
    path.push(node);
    node = PATH::WALKED;

    PrintMap();

    if (curr_x == (M - 1) && curr_y == (N - 1)) // 도착점일경우
    {
        // 마지막 지점은 언제나 이동할 수 있어야하므로 can_walk로 합니다.
        node = PATH::CAN_WALK;
         
        // 만약 도착 지점이라면 최소 경로인지 파악하여 저장합니다.
        int path_node_count = path.size();
        if (path_node_count < min_node_count)
        {
            min_node_count = path_node_count;
        } 
    }
    else
    {
        // 다음 노드를 찾아 떠난다.
        for (int index = 0; index < D_MAX; ++index)
        {
            int next_x = curr_x + dx[index];
            int next_y = curr_y + dy[index];
            if (next_x < 0 || next_x >= M || next_y < 0 || next_y >= N) continue;
            if (MAP[next_x][next_y] == PATH::CAN_WALK)
            {
                FindMap(MAP[next_x][next_y], next_x, next_y);
            }
        } 
    }


    // 다음 노드가 없다면 경로에서 제거한다.
    path.pop();
}
