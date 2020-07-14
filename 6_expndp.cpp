#include <iostream>
#include <unordered_set>
#define MAXN 8
using namespace std;

int solution(int N, int number) {
	int answer = -1, std = 0;
	unordered_set<int> us[MAXN];
	for (int i = 0; i < MAXN; i++) {
		std = 10 * std + 1;
		us[i].insert(std * N);
	}
	for (int i = 1; i < MAXN; i++) {
		for (int j = 0; j < i; j++) {
			for (auto& op1 : us[j]) {
				for (auto& op2 : us[i - j - 1]) {
					cout << "us[" << i << "] += (+)" << op1 + op2 << endl;
					cout << "us[" << i << "] += (-)" << op1 - op2 << endl;
					cout << "us[" << i << "] += (*)" << op1 * op2 << endl;
					us[i].insert(op1 + op2);
					us[i].insert(op1 - op2);
					us[i].insert(op1 * op2);
					if (op2 != 0) {
						us[i].insert(op1 / op2);
					}
				}
			}
		}
		if (us[i].count(number) > 0) {
			answer = i + 1;
			break;
		}
	}
	return answer;
}

int main(void) {
	int N, number;
	N = 3;
	number = 12;
	cout << solution(N, number) << endl;

	return 0;
}