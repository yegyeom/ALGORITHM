/*
programmers Level 2: 주차 요금 계산
2022 KAKAO BLIND RECRUITMENT
DATE: 2022-04-02
*/
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <cmath>
using namespace std;

vector<string> split(string str, char del){
    vector<string> ret;
    istringstream iss(str);
    string buffer;
    
    while(getline(iss, buffer, del)) ret.push_back(buffer);
    
    return ret;
}

int calcTime(string in, string out){
    int idx, time = 0;
    
    idx = in.find(':');
    int in_hour = stoi(in.substr(0, idx));
    int in_min = stoi(in.substr(idx + 1));
            
    idx = out.find(':');
    int out_hour = stoi(out.substr(0, idx));
    int out_min = stoi(out.substr(idx + 1));
            
    if(in_min > out_min){
        time += 60 - in_min + out_min;
        time += (out_hour - in_hour - 1) * 60;
    }
    else{
        time += out_min - in_min;
        time += (out_hour - in_hour) * 60;
    }
    
    return time;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, string> m1;
    map<string, int> m2;
    
    for(auto i : records){
        vector<string> ret = split(i, ' ');
        string car = ret[1];
        
        if(m1.find(car) != m1.end()){
            int time = calcTime(m1[car], ret[0]);
            
            m2[car] += time;
            m1.erase(car);
        }    
        else m1[car] = ret[0]; 
    }
    
    for(auto i : m1) { // 입차 기록은 존재하는데 출차 기록이 없는 차들 계산
        string car = i.first;
        string in = i.second;
        string out = "23:59";
        
        int time = calcTime(in, out);
        m2[car] += time;
    }

    vector<pair<string, int>> tmp;

    for(auto i : m2){
        string car = i.first;
        int total = i.second;

        if(total <= fees[0]) tmp.push_back({car, fees[1]});
        else{
            int fee = fees[1] + ceil(double(total - fees[0]) / fees[2]) * fees[3];
            tmp.push_back({car, fee});
        }
    }
    
    sort(tmp.begin(), tmp.end());
    for(auto i : tmp) answer.push_back(i.second);
    
    return answer;
}