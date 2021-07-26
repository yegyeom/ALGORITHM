#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k, s, cnt;
	long long d1, d2;
	cin >> n >> k >> s;
	
	vector<pair <int, int>> v;

	for(int i = 0 ; i < n ; i++) {
		int loc, dst;
		cin >> loc >> dst;
		v.push_back(make_pair(loc, dst));
	}
	v.push_back(make_pair(s, 0));
	sort(v.begin(), v.end()); 

	int str = 0, end = n;
	int idx = lower_bound(v.begin(), v.end(), make_pair(s, 0)) - v.begin(); //�б� �ε���

	for (int i = 0; i <= n; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}

	int i = str;
	d1 = 0, cnt = 0;
	while (i < idx) { //�б� ��
		cnt += v[i].second;

		if (cnt <= k) { //�ѹ��� �¿� �� ���� ��
			v[i].second = 0;
			i++;
			if (i == idx) {
				d1 += (s - v[str].first) * 2;
			}
		}
		else if (cnt > k) { //���� �¿��� �� ��
			v[i].second = cnt - k;
			cnt = cnt - v[i].second; 

			d1 += (s - v[str].first) * 2;

			cnt = 0;
			str = i;
		}
	}

	int j = end;
	d2 = 0, cnt = 0;
	while (j > idx) { // �б� ��
		cnt += v[j].second;

		if (cnt <= k) { //�ѹ��� �¿� �� ���� ��
			v[j].second = 0;
			j--;
			if (j == idx) {
				d2 += (v[end].first - s) * 2;
			}
		}
		else if (cnt > k) { //���� �¿��� �� ��
			v[j].second = cnt - k;
			cnt = cnt - v[j].second;

			d2 += (v[end].first - s) * 2;

			cnt = 0;
			end = j;
		}
	}

	cout << d1 + d2;

	return 0;
}