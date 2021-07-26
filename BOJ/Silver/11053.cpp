//BOJ 11053번: 가장 긴 증가하는 수열
//2021-05-28
//Dynamic programming
#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> v;
    int n, num;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> num;

        if(i == 0 || num > v.back()){
            v.push_back(num);
        }
        else if(num < v.back()){
            for(int i = 0 ; i < v.size() ; i++){
                if(v[i] == num)
                    break;
                else if(v[i] > num){
                    v[i] = num;
                    break;
                }
            }
        }
    }

    cout << v.size();
    
    return 0;
}