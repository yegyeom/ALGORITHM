/*
BOJ 9177번: 단어 섞기
DATE: 2021-09-19
*/
#include <iostream>
using namespace std;

string a, b, c;
int n, a_length, b_length, c_length;
bool flag;

bool check() {
    int alpha[27] = {0,};

    for(int i = 0 ; i < a_length ; i++){
        alpha[a[i] - 'a']++;
    }
    for(int i = 0 ; i < b_length ; i++){
        alpha[b[i] - 'a']++;
    }
    for(int i = 0 ; i < c_length ; i++){
        alpha[c[i] - 'a']--;
    }
    for(int i = 0 ; i < 26 ; i++){
        if(alpha[i] != 0) 
            return false;
    }

    return true;
}

void backtracking(int a_idx, int b_idx, int c_idx){
    if(flag) {
         return; //이거 안하면 시간초과 (ex a / aba / aaba)
    }
    if(c_idx == c_length) {
        flag = true;
        return;
    }

    if(a[a_idx] == c[c_idx]) backtracking(a_idx + 1, b_idx, c_idx+1);
    if(b[b_idx] == c[c_idx]) backtracking(a_idx, b_idx+1, c_idx+1);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        flag = false;
        cin >> a >> b >> c;
        a_length = a.length(); 
        b_length = b.length();
        c_length = c.length();

        if(check()) backtracking(0, 0, 0);
        
        if(flag) cout << "Data set " << i + 1 << ": yes\n";
        else cout << "Data set " << i + 1 << ": no\n";
    }

    return 0;
}