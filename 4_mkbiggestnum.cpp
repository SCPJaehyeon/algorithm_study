#include <iostream>
#include <string>
using namespace std;

string solution(string number, int k) {
	string answer = "";
	int len;
	for (unsigned int i = 0; i < number.size(); i++) {
		len = answer.size();
		for (int j = 0; j < len; j++) {
			if (answer[j] < number[i]) {
				answer.pop_back();
				k--;
			}
			if (k == 0) {
				break;
			}
		}
		if (k == 0) {
			answer += number.substr(i, number.size());
			break;
		}
		answer += number[i];
		//cout << "answer : " << answer << ", k : " << k << endl;
	}
	answer = answer.substr(0, answer.size() - k);
	return answer;
}

int main(void) {
	string number = "5366252932";
	int k = 4;

	cout << solution(number, k) << endl;

	return 0;
}