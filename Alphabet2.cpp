//
// Created by 이석규 on 2019-04-03.
//



#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
using namespace std;
int h,w;
int map[20][20];
int alphabet[26]={0,};
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int longest = 0;

void dfs(pair<int, int> point, int cnt)
{

        cnt++;
        if (cnt > longest)
            longest = cnt;

        alphabet[map[point.first][point.second]]=1;
        //check.push_back(map[point.first][point.second]);


        for (int i = 0; i < 4; i++) {
            int nx = point.first + dx[i];
            int ny = point.second + dy[i];
            if ( 0 <= nx && nx < h && 0 <= ny && ny < w&&alphabet[map[nx][ny]] == 0) {
                //used = make_pair(nx,ny);
                dfs(make_pair(nx, ny),cnt);
            }
        }
    alphabet[map[point.first][point.second]]=0;
}
int main()
{
    cin >> h>>w;
    char temp;
    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++) {
            cin >> temp;//입력
            map[i][j]=temp-65;//A부터 0으로 집어넣기 위해
        }

    int cnt =0;
    vector<char> check;
    //int map_Used[20][20]={0,};//사용하면 1

    dfs(make_pair(0,0), cnt);

    cout<<longest;
}