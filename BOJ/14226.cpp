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

    queue<pair<int, int>> q; //(ȭ�� ��� ����, Ŭ������ ����)
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
    
        if (!visited[monitor][monitor]) //ȭ�鿡 �ִ� �̸�Ƽ���� ��� �����ؼ� Ŭ�����忡 ����
        {
            q.push(make_pair(monitor, monitor));
            visited[monitor][monitor] = visited[monitor][cb] + 1;
        }
        if (monitor + cb < MAX && !visited[monitor + cb][cb]) //Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ�
        {
            q.push(make_pair(monitor + cb, cb));
            visited[monitor + cb][cb] = visited[monitor][cb] + 1;
        }
        if (monitor > 0 && !visited[monitor - 1][cb]) //ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� ����
        {
            q.push(make_pair(monitor - 1, cb));
            visited[monitor - 1][cb] = visited[monitor][cb] + 1;
        }
    }

    return 0;
}