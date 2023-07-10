#include <bits/stdc++.h>
using namespace std;

int getmaxscore(int arr[], int l, int r, int n)
{
int mscore = 0;
for (int i = l + 1; i < r; i++) {

    int cs = getmaxscore(arr, l, i, n) + getmaxscore(arr, i, r, n); 
    if (l == 0 && r == n) 
        cs = cs + arr[i]; 
    else
        cs = cs + (arr[l] * arr[r]); 

    if (cs > mscore) 
        mscore = cs; 
} 
return mscore; 
}

int main()
{
int t;
cin>>t;
while(t--)
{
int n,arr[100];
cin>>n;
for(int i=1;i<=n;i++)
{
cin>>arr[i];
}
arr[0]=1;
arr[n+1]=1;
cout << getmaxscore(arr, 0, n + 1, n + 1) << "\n";
}

return 0; 
}

