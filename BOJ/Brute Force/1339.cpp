/*
BOJ 1339번: 단어 수학
DATE: 2021-07-18
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char alpha[256];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    vector<string> word;
    vector<char> ch;
    string str;
    int n, maximum=-1;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        cin >> str;
        word.push_back(str);
    }

    for(int i = 0 ; i < word.size() ; i++){
        cin >> word[i];
        for(int j = 0 ; j < word[i].length() ; j++){
            ch.push_back(word[i][j]);
        }
    }

    sort(ch.begin(), ch.end());
    ch.erase(unique(ch.begin(), ch.end()), ch.end());

    vector<int> number;
    //vector<int> number(ch.size()); => 시간 초과

    for(int i = 0 ; i < ch.size() ; i++){
        number.push_back(9 - i);
    }

    sort(number.begin(), number.end());

    do{
        int sum=0;

        for(int i = 0 ; i < ch.size() ; i++){
            alpha[ch[i]] = number[i];
        }

        for(int i = 0 ; i < word.size() ; i++){
            int res = 0;
            for(int j = 0 ; j < word[i].length() ; j++){
                res = res * 10 + alpha[word[i][j]];
            }
            sum += res;
        }

        maximum = max(maximum, sum);

    }while(next_permutation(number.begin(), number.end()));

    cout << maximum;

    return 0;   
}