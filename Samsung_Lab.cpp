    //
    // Created by 이석규 on 2019-04-02.
    //
    #include <iostream>
    #include <vector>
    #include <queue>
    using namespace std;
    int map[8][8], map2[8][8];
    int h,w;
void virus()
{
    // 바이러스 수 검사
    int noSpace=1;
    int i,j;
    while(noSpace) {
        for ( i = 0; i < h; i++)
            for ( j = 0; j < w; j++) {
                if (map2[i][j] == 2) {
                    if (i + 1 <= w && map2[i + 1][j] == 0)
                        map2[i + 1][j] = 2;
                    if (j + 1 <= h && map2[i][j + 1] == 0)
                        map2[i][j + 1] = 2;
                    if (i - 1 >= 0 && map2[i - 1][j] == 0)
                        map2[i - 1][j] = 2;
                    if (j - 1 >= 0 && map2[i][j - 1] == 0)
                        map2[i][j - 1] = 2;
                }
            }
        int cnt=0;//잘못
        for (i = 0; i < h; i++)
            for (j = 0; j < w; j++) {
                if(map2[i][j]==0)
                    cnt++;
            }
        if(cnt==0)
            noSpace=0;
        cnt=0;
    }
}
int main()
    {
    int i,j;
    cin>>h>>w;

    for(i=0;i<h;i++ ) {
        for (j = 0; j < w; j++) {
            cin>>map[i][j];
            map2[i][j]=map[i][j];
        }
    }
    //여기까지 입력 받음



        for(i=0;i<h;i++ ) {
            for (j = 0; j < w; j++) {
                cout<<map2[i][j] <<" ";
                //map2[h][w]=map[i][j];
            }
            cout<<endl;
        }
    }