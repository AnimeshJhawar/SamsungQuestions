#include <vector>
#include <iostream>
#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

typedef struct {
    int x;
    int y;
    int level;
}myData;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> graph (n, vector<int> (m,0));
        int sx,sy,dx,dy;
        cin>> sx >> sy >> dx >> dy;
        queue<myData> q;
        myData d,d1,d2;
        d.x=sx;
        d.y=sy;
        d.level =0;
        q.push(d);

        int newX[] ={-2,-1,1,2,-2,-1,1,2}; 
        int newY[] ={-1,-2,-2,1,1,2,2,-1}; 
        bool flag = false;
        int ans =-1;
        while(!q.empty()){
            d1 = q.front();
            q.pop();

            if(flag) break;
            for(int i=0; i<8;i++){
                int tmx, tmy, tmlevel;
                tmx = d1.x + newX[i];
                tmy = d1.y + newY[i];
                tmlevel = d1.level+1;
                if(tmx== dx && tmy == dy){
                    ans = tmlevel;
                    flag = true;
                    break;
                }
                if(tmx>=0 && tmy>=0 && tmx<n && tmy<m && graph[tmx][tmy]==0){
                    d2.x = tmx;
                    d2.y = tmy;
                    d2.level = tmlevel;
                    q.push(d2);
                    graph[tmx][tmy]==2;
                }
            }
        }
        if(!flag) cout<< "-1" <<endl;
        else cout<< ans <<endl;
    }
    return 0;
}