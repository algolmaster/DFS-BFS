//
// Created by 이석규 on 2019-03-29.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
int start,dest;
vector<vector<int>> con ;
vector<int> node;
int visit[1000001]={0,};

int calcul()
{
    queue<int> que;
    que.push(start);
    visit[start]=1;

    while(!que.empty())
    {
        int y = que.front();
        que.pop();
        if(dest == y)
            return visit[y]-1;//처음 설정한 값이 1이기 때문에

        if(visit[y-1]==0 && y-1>=0)
        {
            visit[y-1]=visit[y]+1;
                que.push(y-1);
        }
        if(visit[y+1]==0 && y+1<=100000)
        {
            visit[y+1]= visit[y]+1;
            que.push(y+1);
        }
        if(visit[2*y]==0&& 2*y<=100000)
        {
            visit[2*y] = visit[y]+1;
            que.push(2*y);
        }
    }
}
int main()
{
    cin>>start>>dest;
    int result;
    result = calcul();
    cout<<result;

}