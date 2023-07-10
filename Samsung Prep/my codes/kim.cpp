#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;
int x[20], y[20],n;

int dist(int i, int j){
    return abs(x[i]-x[j]) + abs(y[i]-y[j]);
}
int ans=INT_MAX;

void lee(int src, int count, int val, bool *vis){
    if(count == n) 
    {
        ans = min(ans, val + dist(src,n+1));
        return;
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            vis[i] = true;
            lee(i, count+1, val + dist(i,src), vis);
            vis[i] = false;
        }
    }
return;
}

int main(){
    cin>>n;
    cin>> x[0] >> y[0] >> x[n+1] >> y[n+1];
    for(int i=1; i<n+1; i++)
    {
        cin >> x[i] >> y[i];
    }
    bool vis[n+2] = {false};
    lee(0,0,0,vis);
    cout<<ans;
    return 0;
}