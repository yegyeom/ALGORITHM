#include <iostream>
#include <string>
using namespace std;

 int main(){
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     string str, bomb, ans="";
     int cnt=0;
     cin >> str >> bomb;

    for(int i = 0 ; i < str.length() ; i++){
        ans += str[i];
        if(str[i] == bomb[bomb.length()-1]){
            int ansIdx = ans.length()-1;
            int bombIdx = bomb.length()-1;

            for(int j = bomb.length() ; j > 0 ; j--){
                if(ans[ansIdx--] == bomb[bombIdx--]) cnt++;
            }
            
            if(cnt == bomb.length()){
                ans.erase(ans.length()-bomb.length(), bomb.length());
            }
        }
        cnt = 0;
    }

    if(ans == ""){
        cout << "FRULA";
    }
    else{
        cout << ans;
    }

     return 0;
 }