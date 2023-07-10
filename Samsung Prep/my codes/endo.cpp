#include <iostream>

using namespace std;

typedef struct {
    int x;
    int y;
}Point;

typedef struct{
    bool left;
    bool right;
    bool up;
    bool down;
}Node;

int n,m,x,y,l;
int arr[1005][1005];
int vis[1005][1005], dis[1005][1005];
Node pipes[1005][1005];
int ans;
Point queue[1000005];


bool isValid (int i, int j){
    return (i>=0 && i<n && j>=0 && j<m && vis[i][j]==0);
}

void bfs(){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            vis[i][j] = 0;
            dis[i][j] = 0;
        }
    }

    int front=0, rear=0;
    vis[x][y] =1; dis[x][y]=1;

    if(arr[x][y]==0) {ans=0; return;}

    queue[rear].x = x;
    queue[rear].y = y;
    rear++;

    while(front != rear){
        int p  = queue[front].x;
        int q  = queue[front].y;
        front++;

        if(1+dis[p][q] <=l){
            //row up 
            if(isValid(p-1,q) && pipes[p-1][q].up && pipes[p-1][q].down){
                vis[p-1][q]=1;
                dis[p-1][q] = 1 + dis[p][q];
                ans++;

                queue[rear].x = p-1;
                queue[rear].y = q;
                rear++;
            }

            if(isValid(p+1,q) && pipes[p+1][q].up && pipes[p+1][q].down){
                vis[p+1][q]=1;
                dis[p+1][q] = 1 + dis[p][q];
                ans++;

                queue[rear].x = p+1;
                queue[rear].y = q;
                rear++;
            }

            if(isValid(p,q-1) && pipes[p][q-1].right && pipes[p][q-1].left){
                vis[p][q-1]=1;
                dis[p][q-1] = 1 + dis[p][q];
                ans++;

                queue[rear].x = p;
                queue[rear].y = q-1;
                rear++;
            }

            if(isValid(p,q+1) && pipes[p][q+1].right && pipes[p][q+1].left){
                vis[p][q+1]=1;
                dis[p][q+1] = 1 + dis[p][q];
                ans++;

                queue[rear].x = p;
                queue[rear].y = q+1;
                rear++;
            }
        }        
    }

}
int main(){
    int t; cin>>t;
    while(t--){
        ans=1;
        cin >> n>>m>>x>>y>>l;
        for(int i=0; i<n; i++){
            for(int j=0; j<m;j++){
                cin>> arr[i][j];

                if( arr[i][j] == 1 ){
	                pipes[i][j].left = true;
	                pipes[i][j].right = true;
	                pipes[i][j].up = true;
	                pipes[i][j].down = true;
	            } 
	            else if( arr[i][j] == 2 ){
	                pipes[i][j].left = false;
	                pipes[i][j].right = false;
	                pipes[i][j].up = true;
	                pipes[i][j].down = true;
	            }
	            else if( arr[i][j] == 3 ){
	                pipes[i][j].left = true;
	                pipes[i][j].right = true;
	                pipes[i][j].up = false;
	                pipes[i][j].down = false;	                
	            }
	            else if( arr[i][j] == 4 ){
	                pipes[i][j].left = false;
	                pipes[i][j].right = true;
	                pipes[i][j].up = true;
	                pipes[i][j].down = false;
	            }
	            else if( arr[i][j] == 5 ){
	                pipes[i][j].left = false;
	                pipes[i][j].right = true;
	                pipes[i][j].up = false;
	                pipes[i][j].down = true;
	            }
	            else if( arr[i][j] == 6 ){
	                pipes[i][j].left = true;
                    pipes[i][j].right = false;
	                pipes[i][j].up = false;
	                pipes[i][j].down = true;
	            }
	            else if( arr[i][j] == 7 ){
	                pipes[i][j].left = true;
	                pipes[i][j].right = false;
	                pipes[i][j].up = true;
	                pipes[i][j].down = false;	                
	            }
	            else{
	                pipes[i][j].left = false;
	                pipes[i][j].right = false;
	                pipes[i][j].up = false;
	                pipes[i][j].down = false;	                
	            }
            }
        }
    bfs();
    cout<<ans<<endl;
    }
    return 0;
}