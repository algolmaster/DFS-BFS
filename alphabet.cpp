#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int R; //가로
int C; //세로

char *board; //보드판
void dfs(int y, int x,int max_step) {
	int step = 1;

	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };
	bool *visited = new bool[26];

	int alpha = board[x*R+y]-'A';
	visited[alpha] = true;

	for (int i = 0; i < 4; i++) {
		int yy = dy[i] + y;
		int xx = dx[i] + x;

		if (yy < 0 || xx < 0 || yy >= R || xx >= C) continue;
		int nextAlpha = board[xx*R + yy];
		if (visited[nextAlpha])continue;
		
		max_step = max(max_step, ++step);
		dfs(yy, xx,max_step);
	}
	step--;
	visited[alpha] = false;
}
int main() {
	cin >> R >> C;

	board = new char[R*C-1];
	if (!board) cout << "메모리를 할당할 수 없습니다.";

	for (int i = 0; i < R*C; i++)
		cin >> board[i];

	dfs(0, 0, 0);
}