//BOJ 17404번: RGB거리 2
//2021-07-29
#include <iostream>
#include <algorithm>
#define MAX 987654321
using namespace std;

int input[1000][3];
int house[3][1000][3];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, r, g, b, ans=MAX;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> r >> g >> b;
        input[i][0] = r;
        input[i][1] = g;
        input[i][2] = b;
    }

    for(int i = 0 ; i < 3 ; i++){
        copy(&input[0][0], &input[0][0] + 3000, &house[i][0][0]);
        
        for(int j = 0 ; j < 3 ; j++)
            if(i != j) house[i][0][j] = MAX;

        for(int j = 1 ; j < n ; j++){
            if(j == n -1){
                if(i == 0) {
                    house[i][j][1] = min(house[i][j-1][0], house[i][j-1][2]) + house[i][j][1];
                    house[i][j][2] = min(house[i][j-1][0], house[i][j-1][1]) + house[i][j][2];
                }
                else if(i == 1){
                    house[i][j][0] = min(house[i][j-1][1], house[i][j-1][2]) + house[i][j][0];
                    house[i][j][2] = min(house[i][j-1][0], house[i][j-1][1]) + house[i][j][2];
                }
                else if(i == 2){
                    house[i][j][0] = min(house[i][j-1][1], house[i][j-1][2]) + house[i][j][0];
                    house[i][j][1] = min(house[i][j-1][0], house[i][j-1][2]) + house[i][j][1];
                }

                house[i][j][i] = MAX;
                break;
            }

            house[i][j][0] = min(house[i][j-1][1], house[i][j-1][2]) + house[i][j][0];
            house[i][j][1] = min(house[i][j-1][0], house[i][j-1][2]) + house[i][j][1];
            house[i][j][2] = min(house[i][j-1][0], house[i][j-1][1]) + house[i][j][2];
        }

        ans = min(ans, *min_element(house[i][n-1], house[i][n-1] + 3));
    }

    cout << ans;

    return 0;
}