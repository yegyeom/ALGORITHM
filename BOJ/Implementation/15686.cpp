/*
BOJ 15686��: ġŲ ���
DATE: 2021-04-17
*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>
using namespace std;

vector<pair<int, int>> cv; //ġŲ��
vector<pair<int, int>> hv; //��
pair<int, int> p[13]; //������ ġŲ��
priority_queue<int, vector<int>, greater<int>> pq;
int city[51][51];
int n, m, dst, new_dst, c_dst;

void combination(int depth, int next){ //����X, �ߺ�X
    if(depth == m){ //ġŲ�Ÿ� ���ϱ�
        c_dst = 0;
    
        for(int i = 0 ; i < hv.size() ; i++){
            int x = hv[i].first;
            int y = hv[i].second;
            dst = 100;
                        
            for(int j = 0 ; j < m ; j++){
                new_dst = abs(x - p[j].first) + abs(y - p[j].second);
                dst = min(dst, new_dst);
            }
            c_dst += dst;
        }

        pq.push(c_dst);

        return;
    }

    for(int i = next ; i <= cv.size() ; i++){
        p[depth] = cv[i - 1];
        combination(depth + 1, i + 1);
    }
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for(int i =  1 ; i <= n ; i++){
        for(int j = 1 ; j <= n ; j++){
            cin >> city[i][j];

            if(city[i][j] == 1) {
                hv.push_back(make_pair(i, j)); //��(1) ��ġ
            }
            else if(city[i][j] == 2){
                cv.push_back(make_pair(i, j)); //ġŲ��(2) ��ġ
            }
        }
    }

    if(m == cv.size()){ //�ٷ� ġŲ �Ÿ� ���ϱ�
        c_dst=0;

        for(int i = 0 ; i < hv.size() ; i++){
            int x = hv[i].first;
            int y = hv[i].second;
            dst = 100;
                    
            for(int k = 0 ; k < cv.size() ; k++){
                new_dst = abs(x - cv[k].first) + abs(y - cv[k].second);
                dst = min(dst, new_dst);
            }

            c_dst += dst;
        }
    }
    else{ //ġŲ ���԰� �ִ� m�� �־���ϴ� ���: cv.size()�� �߿� m���� �����ϴ� ���� 
        combination(0, 1);
        c_dst = pq.top();
    }

    cout << c_dst;

    return 0;
}