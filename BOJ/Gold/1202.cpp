//BOJ 1202��: ���� ����
//2021-07-19
#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<int> pq;
    vector<pair<int,int>> gem;
    vector<int> bag;
    int n, k, m, v, c;
    long long ans=0;
    cin >> n >> k; //���� n��, ���� k��

    for(int i = 0 ; i < n ; i++){
        cin >> m >> v;
       gem.push_back(make_pair(m,v)); //���� ���� (����, ����)
    }

    for(int i = 0 ; i < k ; i++){
        cin >> c;
        bag.push_back(c);
    }

    sort(gem.begin(), gem.end());
    sort(bag.begin(), bag.end());

    int idx = 0;
    for(int i = 0 ; i < k ; i++){
        int bag_weight = bag[i];

        while(idx < n && gem[idx].first <= bag_weight){
            pq.push(gem[idx].second);
            idx++;
        }

        if(!pq.empty()){ //if�� ���ϸ� ��Ÿ�ӿ��� (DoubleFree)
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;

    return 0;
}