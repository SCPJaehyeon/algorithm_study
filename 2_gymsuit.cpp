#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	//vector<int> v;
	vector<int> v(n+2, 1);
	//for (int i = 0; i <= n+1; i++) {
	//	v.push_back(i);
	//	v[i] = 1;
	//}
	for (auto &j : lost)v[j]--;
	for (auto &k : reserve)v[k]++;
	for (int i = 1; i <= n; i++) {
		if (v[i]==2 && v[i-1]==0) {
			v[i - 1]++;
			v[i]--;
		}
		else if (v[i] == 2 && v[i + 1] == 0) {
			v[i + 1]++;
			v[i]--;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (v[i] >= 1) {
			answer++;
		}
	}
	return answer;
}

int main(void) {
	int num = 5;
	vector<int> lost;
	lost.push_back(2);
	lost.push_back(4);
	vector<int> reserve;
	reserve.push_back(3);

	cout << solution(num, lost, reserve) << endl;

	return 0;
}
