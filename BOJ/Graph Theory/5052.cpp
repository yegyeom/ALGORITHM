/*
BOJ 5052��: ��ȭ��ȣ ���
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
		if (*key == '\0') { //�Է� ��
			finish = true;
		}
		else {
			int now = *key - '0';

			if (next[now] == NULL) //����� ��� ���� ��
				next[now] = new Trie(); 
			nextChild = true;

			next[now]->insert(key + 1); //���� ���ڿ��� �Ѿ
		}
	}

	bool find(char* key) {
		if (*key == '\0') //��尡 �������� ���� ���
			return false;
		if (finish) //�����ϴ� ���ڿ��� ���
			return true;
		int now = *key - '0';
		return next[now]->find(key + 1); //���� ���ڿ��� �Ѿ
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
            if(trie->find(num[i])){ //�ش� ��ȣ�� ���ξ�� ����
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