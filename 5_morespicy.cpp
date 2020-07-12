#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int min1 = 0, min2=0, newq=1;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto&i : scoville) pq.push(i);
	if (pq.size() == 1) {
		if (pq.top() >= K) return answer;
		return -1;
	}
	while (!pq.empty() && pq.size()>1 && newq > 0) {
		//cout << q.top() << endl;
		min1 = pq.top();
		pq.pop();
		min2 = pq.top();
		pq.pop();
		newq = min1 + (min2 * 2);
		pq.push(newq);
		answer++;
		if (pq.top() >= K) return answer;
	}
	return -1;
}

int main(void) {
	vector<int> scoville;
	int K = 7;
	scoville.push_back(1);
	scoville.push_back(2);
	scoville.push_back(3);
	scoville.push_back(9);
	scoville.push_back(10);
	scoville.push_back(12);
	cout << solution(scoville, K) << endl;

	return 0;
}

