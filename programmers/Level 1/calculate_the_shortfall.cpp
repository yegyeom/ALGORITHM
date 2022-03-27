/*
programmers Level 1: 부족한 금액 계산하기
date: 2022-03-27
*/
using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    for(int i = 1 ; i <= count ; i++) answer += price * i;
    
    return answer > money ? answer - money : 0;
}