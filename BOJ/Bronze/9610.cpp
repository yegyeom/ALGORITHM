//BOJ 9610번: 사분면
//2021-05-04
#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q1=0, q2=0, q3=0, q4=0, axis=0;
    pair<int, int> pos;

    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int x, y;
        cin >> x >> y;
        pos = make_pair(x, y);

        if(pos.first > 0 && pos.second > 0)
            q1++;
        else if(pos.first < 0 && pos.second > 0)
            q2++;
        else if(pos.first < 0 && pos.second < 0)
            q3++;
        else if(pos.first > 0 && pos.second < 0)
            q4++;
        else
            axis++;
    }

    cout << "Q1: " << q1 << "\n";
    cout << "Q2: " << q2 << "\n";
    cout << "Q3: " << q3 << "\n";
    cout << "Q4: " << q4 << "\n";
    cout << "AXIS: " << axis << "\n";

    return 0;
}