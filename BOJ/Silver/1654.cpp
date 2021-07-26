#include <iostream>
#define MAX 
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int k, n;
    long long start, end, mid, sum=0, total, max=-1;
    cin >> k >> n;

    int length[k];
    for(int i = 0 ; i < k ; i++){
        cin >> length[i];
        sum += length[i];
    }

    start = 1;
    end = sum / n; 

    while(end - start >= 0){
        total = 0;
        mid = (start + end) / 2;

        for(int i = 0 ; i < k ; i++){
            total += length[i] / mid;
        }

        if(total >= n){
            start = mid + 1;
            if(mid > max) max = mid;
        }
        else{
            end = mid - 1;
        }
    }

    cout << max;

    return 0;
}