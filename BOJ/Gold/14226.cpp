#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;

int visited[MAX][MAX] = { 0, };

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int s;
    cin >> s;

    queue<pair<int, int>> q; //(화면 출력 개수, 클립보드 개수)
    pair<int, int> p;

    q.push(make_pair(1, 0));
    visited[1][0] = 1;

    while (!q.empty())
    {
        p = q.front();
        int monitor = p.first;
        int cb = p.second;
        q.pop();

        if (monitor == s)
        {
            cout << visited[monitor][cb]-1;
            break;
        }
    
        if (!visited[monitor][monitor]) //화면에 있는 이모티콘을 모두 복사해서 클립보드에 저장
        {
            q.push(make_pair(monitor, monitor));
            visited[monitor][monitor] = visited[monitor][cb] + 1;
        }
        if (monitor + cb < MAX && !visited[monitor + cb][cb]) //클립보드에 있는 모든 이모티콘을 화면에 붙여넣기
        {
            q.push(make_pair(monitor + cb, cb));
            visited[monitor + cb][cb] = visited[monitor][cb] + 1;
        }
        if (monitor > 0 && !visited[monitor - 1][cb]) //화면에 있는 이모티콘 중 하나를 삭제
        {
            q.push(make_pair(monitor - 1, cb));
            visited[monitor - 1][cb] = visited[monitor][cb] + 1;
        }
    }

    return 0;
}