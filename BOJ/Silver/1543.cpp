#include <iostream>
#include <string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int cnt = 0, ans=0;
    string str, search;

    getline(cin, str);
    getline(cin, search);

    for(int i = 0 ; i < str.size() ; i++){
        if(str[i] == search[0]){
            for(int j = 0 ; j < search.size() ; j++){
                if(str[i++] == search[j]) cnt++;
            }

            if(cnt == search.size()){
                ans++;
                i -= 1;
            }
            else
                i -= search.size();
        }
        cnt = 0;
    }

    cout << ans;

    return 0;
}