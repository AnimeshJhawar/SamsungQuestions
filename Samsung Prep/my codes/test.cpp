#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

long long dp[1005][1005];

long long solve(int arr[], int p, int n){
    long long ans = INT_MAX;

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            dp[i][j]= INT_MAX;
        }
    }

    for(int i=n; i>0; i--){
        for(int z=1; z<=p; z++){
            if(z==1){
                dp[i][z]= (n-i+1)*arr[i];
                continue;
            }
            for(int k=i+1; k<=n; k++){
                dp[i][z]= min(dp[i][z], dp[k][z-1]+(k-i)*arr[i]);
            }
        }
    }
    for(int i=1; i<=n; i++){
        ans = min(ans, dp[i][p]);
    }
    return ans;
}

int main(){
    int n,p;
    cin>>n;
    cin>>p;

    int arr[n+1];
    for(int i=1; i<=n; i++){
        cin>>arr[i];
    }
    sort(arr+1, arr+n+1);
    cout<< solve(arr,p,n);
    return 0;
}