//
//  alphabet.cpp
//  dfsbfs
//
//  Created by 신예지 on 03/04/2019.
//  Copyright © 2019 신예지. All rights reserved.
//

#include <iostream>
using namespace std;

int R, C;
char map[21][21];

int dfs(int nowR, int nowC, int cnt){
    
    int moveCnt[20][20];
    int temp = moveCnt[nowR][nowC];
    int visitAlpha[26];
    visitAlpha[map[nowR][nowC]-'A']=1;
    
    int tempCnt = 0;
    if(tempCnt<cnt)
        tempCnt =cnt;
    
    if(nowR+1<R&&visitAlpha[map[nowR+1][nowC]-'A']==0){
        moveCnt[nowR+1][nowC] = temp+1;
        dfs(nowR+1,nowC,cnt+1);
    }
    if(nowR-1>=0&&visitAlpha[map[nowR-1][nowC]-'A']==0){
        moveCnt[nowR-1][nowC] = temp+1;
        dfs(nowR-1,nowC,cnt+1);
    }
    if(nowC+1<C&&visitAlpha[map[nowR][nowC+1]-'A']==0){
        moveCnt[nowR][nowC+1] = temp+1;
        dfs(nowR,nowC+1,cnt+1);
    }
    if(nowC-1>=0&&visitAlpha[map[nowR][nowC-1]-'A']==0){
        moveCnt[nowR][nowC-1] = temp+1;
        dfs(nowR,nowC-1,cnt+1);
    }
    visitAlpha[map[nowR][nowC]-'A']=0;
    
    int Max = 1;
    for(int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if(Max < moveCnt[i][j])
                Max = moveCnt[i][j];
        }
    }
    return Max;
}

int main(){
    cin>>R>>C;
    
    for(int i=0;i<R;i++){
        cin >> map[i];
    }
    cout << dfs(0,0,1) << endl;
}
