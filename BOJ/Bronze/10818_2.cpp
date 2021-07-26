//BOJ 10818번: 최소, 최대 
//min, max ver
#include <iostream>
#include <algorithm>
#define MAX 1000000
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, input, min_num = MAX, max_num = -MAX;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> input;
        min_num = min(min_num, input);
        max_num = max(max_num, input);
    }

    cout << min_num << " " << max_num;

    return 0;
}