#include <iostream>
#include <queue>
using namespace std;

#define MAX 100000
#define MIN 0

int move(int N, int K) {
	queue<int> Q;

	int count = 0;

	if (N - 1 >= MIN)
		Q.push(N - 1);
	if (N + 1 <= MAX)
		Q.push(N + 1);
	if (2 * N <= MAX)
		Q.push(2 * N);
	count++;

	int i=Q.size();
	int j = 0;
		while (Q.size() != 0) {
			int front = Q.front();
			if (front == K)
				return count;
			else {
				if (front - 1 >= MIN) {
					Q.push(front - 1);
					j++;
				}
				if (front + 1 <= MAX){
					Q.push(front + 1);
					j++;
				}
				if (2 * front <= MAX){
					Q.push(2 * front);
					j++;
				}
			}
			i--;
			if (i == 0) {
				count++;
				i = j;
				j = 0;
			}
			Q.pop();
		}
}
int main() {
	int N = 0; //수빈위치
	int K = 0; //동생위치

	cin >> N >> K;

	if (N < K) {
		cout<<move(N,K);
	}
	else{
		cout << N-K;
	}
}