#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct{
    int x;
    int y;
    int level;
} myData;

int n,m;

bool isValid(int x, int y){
return (x>=0 && x<n && y>=0 && y<m);
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>m;
        vector<vector<int>> arr (n, vector<int>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                cin>>arr[i][j];
            }
        }
        int bX,bY; 
        cin>>bX >> bY;
        int tmx,tmy,tml;
        myData d, d1, d2;
        d.x = bX-1; d.y=bY-1; d.level=1;
        queue <myData> q;
        q.push(d);
        arr[d.x][d.y]=2;
        int nX [] = {-1,1,0,0};
        int nY [] = {0,0,1,-1};
        
        while(!q.empty()){
            d1 = q.front();
            q.pop();

            for(int i=0; i<4; i++){
                tmx = d1.x + nX[i];
                tmy = d1.y + nY[i];
                tml = d1.level + 1;
                if(isValid(tmx,tmy) && arr[tmx][tmy]==1 ){
                    d2.x = tmx;
                    d2.y = tmy;
                    d2.level = tml;
                    arr[tmx][tmy]=2;
                    q.push(d2);
                }
            }
        }
        cout<<tml-1<<endl;
    }
    return 0;
}