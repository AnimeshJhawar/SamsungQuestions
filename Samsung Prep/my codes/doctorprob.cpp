#include <vector>
#include <iostream>
#include <stdio.h>
using namespace std;

void populate(vector<vector<double>> &graph, vector<double> &ans, double p, int time, int n, int currnode){
        if(time<=0){
            ans[currnode]+=p;
            return;
        }
        for(int j=0; j<n; j++){
        if(graph[currnode][j]!=0){
            p *= graph[currnode][j];
            populate(graph, ans, p, time-10, n,j);
            p /= graph[currnode][j];
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        double n, edges, time;
        cin>>n >>edges >> time;
        vector<vector<double>> graph (n, vector<double>(n,0.0));
        double x,y,p;
        for(int i=0; i<edges; i++){
            cin>> x >> y >> p;
            graph[x-1][y-1]= p;
        }
        vector<double> ans(n,0.0);
        populate(graph, ans, 1.0,time,n,0); //0 starting
        int ansindex=0;
        double prob=0;
        for(int i=0; i<n; i++){
            cout<< "ans[" << i <<"] ->" << ans[i]<<endl;
            if(prob<ans[i]){
                prob = ans[i];
                ansindex = i+1;
            }
        }
        cout<<ansindex << " " << prob<< endl;
    }
    return 0;
}

