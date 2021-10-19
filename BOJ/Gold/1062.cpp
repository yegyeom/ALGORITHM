//BOJ 1062번: 가르침
//2021-10-20
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> words;
int k, ans = 0;
int alpha[26] = {0,};

void combination(int depth, int next) {
    if(depth == k - 5) { //a n t i c를 제외한 조합
        int cnt = 0;

        for(int i = 0 ; i < words.size() ; i++) {
            bool flag = true;
            for(int j = 0 ; j < words[i].length() ; j++) {
                if(alpha[words[i][j] - 97] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag) cnt++;
        }

        ans = max(ans, cnt);

        return;
    }

    for(int i = next ; i < 26 ; i++) {
        if(alpha[i] == 1) continue;

        alpha[i] = 1;
        combination(depth + 1, i + 1);
        alpha[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string word;
    cin >> n >> k;

    if(k < 5) { // 모든 단어가 a n t i c를 포함하므로
        cout << "0";
        return 0;
    }
    
    alpha['a' - 97] = 1;
    alpha['n' - 97] = 1;
    alpha['t' - 97] = 1;
    alpha['i' - 97] = 1;
    alpha['c' - 97] = 1;

    for(int i = 0 ; i < n ; i++) {
        cin >> word;
        words.push_back(word);
    }
    
    combination(0, 0);

    cout << ans;
        
    return 0;
}