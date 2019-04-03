//
// Created by 이석규 on 2019-04-02.
//

#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int h,w;
char map[20][20];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int longest = 0;

void dfs(pair<int, int> point, vector<char> check, int cnt, pair<int, int>used)
{
        if (find(check.begin(), check.end(), map[point.first][point.second]) != check.end())//check벡터에 알파벳이 있다면
            {
            return;
            }
        else//check벡터에 알파벳이 없다면 이동
            {
            cnt++;
            if (cnt > longest)
                longest = cnt;

            //map_Used[point.first][point.second]=1;
            check.push_back(map[point.first][point.second]);
            }

        for (int i = 0; i < 4; i++) {
            int nx = point.first + dx[i];
            int ny = point.second + dy[i];
            if (used != make_pair(nx,ny)&&0 <= nx && nx < h && 0 <= ny && ny < w) {
                used = make_pair(nx,ny);
                dfs(make_pair(nx, ny), check, cnt, used);
            }
        }
}
int main()
{
    cin >> h>>w;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>map[i][j];//입력

    int cnt =0;
    vector<char> check;
    //int map_Used[20][20]={0,};//사용하면 1

    dfs(make_pair(0,0),check, cnt, make_pair(0,0));

    cout<<longest;
}