//BOJ 10800번: 컬러볼
//2021-08-05
#include <iostream>
#include <algorithm>
using namespace std;

struct Info{
    int size;
    int color;
    int index;
};

bool cmp(const Info& a, const Info& b){
    if(a.size == b.size) return a.color < b.color;
    return a.size < b.size;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, c, s, idx, sum_size=0;
    cin >> n;
    
    Info info[n];
    int sum_color[n]= {0,}, ans[n] = {0,};

    for(int i = 0 ; i < n ; i++){
        cin >> c >> s;
        info[i].color = c - 1;
        info[i].size = s;
        info[i].index = i;
    }

    sort(info, info + n, cmp);

    for(int i = 0 ; i < n ; i++){
        idx = i;

        for(int j = idx ; j < n ; j++){ //같은 크기의 공만큼 idx 증가
            if(info[i].size == info[j].size) idx++;
            else break;
        }

        for(int j = i ; j < idx ; j++){
            ans[info[j].index] = sum_size - sum_color[info[j].color];
        }

        for(int j = i ; j < idx ; j++){
            sum_size += info[j].size;
            sum_color[info[j].color] += info[j].size;
        }

        i = idx - 1;
    }

    for(int i = 0 ; i < n ; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}