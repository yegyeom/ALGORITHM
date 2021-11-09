//BOJ 21608번: 상어 초등학교
//2021-11-08
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define MAX 20
using namespace std;
vector<int> v[MAX * MAX];
vector<pair<int,int>> location_1, location_2;
int classroom[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n;

int getLikeStd(int x, int y, vector<int> like){
    int cnt = 0;

    for(int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(find(like.begin(), like.end(), classroom[nx][ny]) != like.end()) {
            cnt++;
        }
    }

    return cnt;
}

int getEmptyCount(int x, int y) {
    int cnt = 0;

    for(int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n ) continue;
        if(classroom[nx][ny] == 0) cnt++;
    }

    return cnt;
}

int step1(int num, int student) {
    vector<int> like;
    int maxNum = -1, maxCnt = 0, x = 0, y = 0;

    for(int i = 1 ; i <= 4 ; i++) like.push_back(v[num][i]);

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            if(classroom[i][j] > 0) continue;
            int cnt = getLikeStd(i, j, like);
        
            if(cnt > maxNum) {
                maxNum = cnt;
                maxCnt = 0;
                location_1.clear();
                location_1.push_back(make_pair(i, j));
                x = i; y = j;
            }
            else if(cnt == maxNum) {
                maxCnt++;
                location_1.push_back(make_pair(i, j));
            }
        }
    }
 
    if(maxCnt == 0) {
        classroom[x][y] = student;
        return 1;
    }
    else return 0;
}

int step2(int num, int student) {
    vector<int> like;
    int maxNum = -1, maxCnt = 0, x, y;

    for(int i = 1 ; i <= 4 ; i++) like.push_back(v[num][i]);

    for(int i = 0 ; i < location_1.size() ; i++) {
        int cnt = getEmptyCount(location_1[i].first, location_1[i].second);
       
        if(cnt > maxNum) {
            maxNum = cnt;
            maxCnt = 0;
            location_2.clear();
            location_2.push_back(make_pair(location_1[i].first, location_1[i].second));
            x = location_1[i].first; y = location_1[i].second;
        }
        else if(cnt == maxNum) {
            maxCnt++;
            location_2.push_back(make_pair(location_1[i].first, location_1[i].second));
        }
    }

    if(maxCnt == 0) {
        classroom[x][y] = student;
        return 1;
    }
    else return 0;
}

void step3(int num, int student) {
    vector<pair<int,int>> rowCol;
    int x, y;

    for(int i = 0 ; i < location_2.size() ; i++) {
        rowCol.push_back(make_pair(location_2[i].first, location_2[i].second));
    }

    sort(rowCol.begin(), rowCol.end());

    x = rowCol[0].first;
    y = rowCol[0].second;

    classroom[x][y] = student;
    return;
}

int calcVal(int x, int y, int num) {
    int idx, cnt = 0;

    for(int i = 0 ; i < n * n ; i++) {
        if(v[i][0] == num) {
            idx = i;
        }
    }

    for(int i = 0 ; i < 4 ; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
        if(find(v[idx].begin(), v[idx].end(), classroom[nx][ny]) != v[idx].end()) cnt++;
    }

    return cnt;   
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, ans = 0;
    cin >> n;

    for(int i = 0 ; i < n * n ; i++) {
        cin >> a;
        v[i].push_back(a);

        for(int j = 0 ; j < 4 ; j++) { // 좋아하는 학생
            cin >> b;
            v[i].push_back(b);
        }
    }

    for(int i = 0 ; i < n * n ; i++) {
        int idx;
        idx = v[i][0];

        if(step1(i, idx)) continue;
        if(step2(i, idx)) continue;
        step3(i, idx);
    }

    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            int cnt = calcVal(i, j, classroom[i][j]);
            if (cnt > 0) ans += pow(10, cnt - 1);
        }
    }

    cout << ans;

    return 0;
}