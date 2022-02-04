/*
BOJ 5052번: 전화번호 목록
DATE: 2021-03-29
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Trie {
	Trie* next[10];
	bool finish;
	bool nextChild;

	Trie() {
		fill(next, next + 10, nullptr);
		finish = nextChild = false;
	}

	void insert(char* key) {
		if (*key == '\0') { //입력 끝
			finish = true;
		}
		else {
			int now = *key - '0';

			if (next[now] == NULL) //연결된 노드 없을 때
				next[now] = new Trie(); 
			nextChild = true;

			next[now]->insert(key + 1); //다음 문자열로 넘어감
		}
	}

	bool find(char* key) {
		if (*key == '\0') //노드가 생성되지 않은 경우
			return false;
		if (finish) //존재하는 문자열일 경우
			return true;
		int now = *key - '0';
		return next[now]->find(key + 1); //다음 문자열로 넘어감
	}
};

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t, n;
    cin >> t;

    for(int i = 0 ; i < t ; i++){
        bool check = false;
        char num[10001][11];

        cin >> n;
        Trie* trie = new Trie();

        for(int i = 0 ; i < n ; i++){
            cin >> num[i];
            trie->insert(num[i]);
        }
        
        for(int i = 0 ; i < n ; i++){
            if(trie->find(num[i])){ //해당 번호가 접두어로 존재
                check = true;
                break;
            }
        }
   
        if(check) 
            cout << "NO\n";
        else
            cout << "YES\n";

        delete trie;
    }
    return 0;
}