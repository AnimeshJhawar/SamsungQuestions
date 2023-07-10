#include <iostream>
#include <vector>

using namespace std;
int n;
bool valid(int r, int c){
    if(r>=0 && r<n && c<5 && c>=0) return true;
    return false;
}

int solve(vector<vector<int>> bomb, int row, int col, int power, int effect){
    if(!valid(row,col)) return 0;
    int ans=0, p=0;

    for(int i=-1; i<2; i++){
        int y = col+i;
        int x = row-1;

        if(valid(x,y)){
            //enemy
            if(bomb[x][y]==2){
                if(power==0 && effect>0){
                    p = solve(bomb, x, y, 0, effect-1);
                }
                if(power==1){
                    p = solve(bomb, x, y, 0, 5);
                }
            }
            //not enemy
            if(bomb[x][y]==1 || bomb[x][y]==0){
                if(power==0){
                    p = solve(bomb, x, y, 0, effect-1);
                }
                else{
                    p = solve(bomb, x, y, power, 5);
                }
            }
        }
        ans =max(ans,p);
    }
    if(bomb[row][col]==1) ans++; 
    return ans;
}

int main() {
    cin>>n;
    vector<vector<int>> bomb (n, vector<int>(5,0));

    for(int i=0; i<n; i++){
        for(int j=0; j<5; j++){
            cin>>bomb[i][j];
        }
    }
    cout << solve(bomb,n-1,2,1,5);        
    return 0;
}
