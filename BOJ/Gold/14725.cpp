//BOJ 14725¹ø: °³¹Ì±¼
//2021-07-05
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
    string food;
    vector<Node> children;
};

Node head;
Node* cur;

bool cmp(Node a, Node b){
    return a.food < b.food;
}

bool check(string str){
    for(int k = 0 ; k < cur->children.size() ; k++){
        if(cur->children[k].food == str){
            cur = &(cur->children[k]);
            return true;
        }
    }

    return false;
}

void print(Node node, int depth){
    if(node.food != ""){
        for(int i = 0 ; i < depth ; i++){
            cout << "--";
        }
        cout << node.food << '\n';
    }

    for(int i = 0 ; i < node.children.size() ; i++){
        print(node.children[i], depth+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string str;
    int n, k;
    cin >> n;

    for(int i = 0 ; i < n ; i++){
        int k;
        cin >> k;
        
        cur = &head;

        for(int j = 0 ; j < k ; j++){
            cin >> str;
            if(!check(str)){
                Node node;
                node.food = str;
                cur->children.push_back(node);

                sort(cur->children.begin(), cur->children.end(), cmp);
                for(int k = 0 ; k < cur->children.size() ; k++){
                    if(cur->children[k].food == str){
                        cur = &cur->children[k];
                    }
                }
            }
        }
    }
    
    print(head, -1);

    return 0;
}