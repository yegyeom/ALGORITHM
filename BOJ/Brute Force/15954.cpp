/*
BOJ 15954��: ������
DATE: 2021-02-01
*/
#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int arr[500];
    int n, k;
    cin >> n >> k;

    long double MIN = 10000000000000000;

    for(int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }

    while(k <= n){
        for(int i = 0 ; i < n-k+1 ; i++){
            long double sum=0, m, variance, std;

            for(int j = i ; j < k+i ; j++){ //���ӵ� k���� �� ��
                sum += arr[j];
            }
            
            m = sum / k;
        
            sum = 0;
            for(int j = i ; j < k+i ; j++) sum += pow(arr[j]-m, 2);
            
            variance = sum / k; //�л�
            std = sqrt(variance); //ǥ������
            MIN = min(MIN, std);
        }

        k++;
    }
    
    cout.precision(11);
    cout << fixed << MIN;
    
    return 0;
}