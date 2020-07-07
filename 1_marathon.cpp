#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	string answer = "";
	vector<string>::iterator vecit;
	unordered_map<string, unsigned int> ht;
	unordered_map<string, unsigned int>::iterator htit;
	for (vecit = participant.begin(); vecit != participant.end(); vecit++) {
		auto htit = ht.insert(make_pair(*vecit,1));
		if (htit.second == false) {
			ht[*vecit] += 1;
		}
	}
	for (vecit = completion.begin(); vecit != completion.end(); vecit++) {
		ht[*vecit] -= 1;
	}
	for (htit = ht.begin(); htit != ht.end(); htit++) {
		if (htit->second != 0) {
			answer = htit->first;
		}
	}
	return answer;
}

int main(void) {
	vector<string> parti;
	vector<string> comple;
	parti.push_back("kim");
	parti.push_back("lay");
	parti.push_back("paul");

	comple.push_back("paul");
	comple.push_back("lay");

	string res = solution(parti, comple);

	cout << res << endl;

	return 0;
}