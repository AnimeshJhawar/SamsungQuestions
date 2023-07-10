#include <iostream>
#include <vector>
#include <climits>

using namespace std;
int N,ans = INT_MAX;

void lee(vector<bool> &check, vector<vector<int>> &arr,int count, int val, int src){
    if(count == N-1){
        if(arr[src][0]!=0) ans = min(ans, val + arr[src][0]);
        return;
    }

    for(int i=0; i<N; i++){
        if(!check[i] && arr[src][i]!=0){
            check[i] = true;
            lee(check, arr, count+1, val + arr[src][i],i);
            check[i] = false;
        }
    }
}

int main(){
    cin>>N;
    vector<vector<int>> arr (N, vector<int>(N,0));
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    vector<bool> check(N, false);
    check[0] =true;

    lee(check,arr,0,0,0);
    cout<<ans;
    return 0;
}