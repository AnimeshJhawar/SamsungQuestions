#include <vector>
#include <iostream>

using namespace std;
int n;
int maze[10][10], vis[10][10];

bool isValid(int x, int y){
    return(x>=0 && x<n && y>=0 && y<n);
}

int newX[] ={-1,0,1,0};
int newY[]={0,-1,0,1};
int ans = 0;

void jewel(int x, int y, int value){
    if(x== n-1 && y==n-1){
        ans = max(ans, value);
        return;
    }
    for(int i=0; i<4; i++){
        int nX = x + newX[i];
        int nY = y + newY[i];

        if(isValid(nX,nY)){
            if(vis[nX][nY]==0 && maze[nX][nY]==0){
                vis[nX][nY] = 1;
                jewel(nX,nY,value);
                vis[nX][nY]=0;
            }
            if(vis[nX][nY]==0 && maze[nX][nY]==2){
                vis[nX][nY] = 1;
                jewel(nX,nY,value+1);
                vis[nX][nY]=0;
            }            
        }
    }
}

int main(){
    cin>>n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++){
            cin>>maze[i][j];
        }
    }
    jewel(0,0,0);
    cout<<ans;
    return 0;
}