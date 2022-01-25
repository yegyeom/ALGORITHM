/*
BOJ 13305��: ������
DATE: 2021-01-06
*/
#include <iostream>
using namespace std;
long long rate[100001], dst[100000];

int main() {
	int check = 0; //����� ������
	long long n, mid_dst, sum_rate = 0;

	cin >> n;

	for (int i = 0; i < n-1; i++) 
		cin >> dst[i];
	for (int i = 0; i < n; i++)
		cin >> rate[i];

	while (1) {
		mid_dst = 0; //�Ÿ� ����

		for (int i = check; i < n - 1; i++) { 
			if (rate[i] < rate[check]) { //���� ���ú��� ������ �� �����Ұ� ���� �� 
				for (int j = check; j < i; j++) 
					mid_dst += dst[j];
				
				sum_rate += rate[check] * mid_dst;
				check = i;
				break;
			}
			else if(i == n-2){
				for (int j = check; j <= i; j++)
					mid_dst += dst[j];
			
				sum_rate += rate[check] * mid_dst;
				cout << sum_rate << endl;

				return 0;
			}
		}

	}
}