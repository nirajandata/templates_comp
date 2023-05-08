
 //this is written by mein 2022 in my another repo but it become messy so i copied it here

// kosaraju algorithm for strongly connected comp. in a graph
//thanks benq
#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> nepali(n+1),khaire(n+1);
    vector<int> seq,id(n+1);
    vector<bool> ghau(n+1);
 
    int comp=0;
    function<void(int,int)> dfs=[&](int node,int num){
        ghau[node]=true;
        vector<int> &ad = (num&1)?nepali[node] : khaire[node];
            for(auto &v:ad)
                if(!ghau[v]) dfs(v,num);
        if(num==1)
        seq.push_back(node);
        else id[node]=comp;
 
    };
    while(m--){
        int a,b;
        cin>>a>>b;
        nepali[a].push_back(b);
        khaire[b].push_back(a);
    }
    for(int i=1;i<=n;i++)
        if(!ghau[i]) dfs(i,1);
    
    for(int i=0;i<=n;i++) ghau[i]=false;
 
    for(int i=n-1;i>=0;i--){
        if(!ghau[seq[i]]){
           comp++;
           dfs(seq[i],2);
        }
    }
    cout << comp << endl;
    for(int i=1;i<=n;i++) cout << id[i] << " " ;
 
    return 0;
}
