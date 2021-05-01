//programmers Level 1 : Push keypad
//2020 KAKAO Internship
//2021-04-28
#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left_x=3, left_y=0, right_x=3, right_y=2;
    
    for(int i = 0 ; i < numbers.size() ; i++){
        if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){ //1 4 7
            answer += 'L';
            left_x = numbers[i] / 3;
            left_y = 0;
        }
        else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){ //3 6 9
            answer += 'R';
            right_x = numbers[i] / 3 - 1;
            right_y = 2;
        }
        else{ //2 5 8 0
            if(numbers[i] == 0)
                numbers[i] = 11;
            
            int tmp_x = numbers[i] / 3;
            int tmp_y = 1;
            int dstLeft = abs(tmp_x-left_x) + abs(tmp_y - left_y);
            int dstRight = abs(tmp_x-right_x) + abs(tmp_y-right_y);
            
            if(dstLeft < dstRight) {
                answer += 'L';
                left_x = tmp_x;
                left_y = tmp_y;
            }
            else if(dstLeft > dstRight){
                answer += 'R';
                right_x = tmp_x;
                right_y = tmp_y;
            }
            else{
                if(hand == "left"){
                    answer += 'L';
                    left_x = tmp_x;
                    left_y = tmp_y;
                }
                else if(hand == "right"){
                    answer += 'R';
                    right_x = tmp_x;
                    right_y = tmp_y;
                }
            }
            
        }
    }
    
    return answer;
}