#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
unordered_map<int, int>  CNT,CNTL;
ll an=0;
int M;
void dfs(int n,int x,vector<int> &A,bool f){
    int N=A.size();
    if(N==n){
        if(f)an+=(CNT[(M-x)%M])+(CNTL[(M-x)%M]);
        else CNT[x]++;
        return;
    }
    else if(N+1==n){
        if(f)an+=(CNT[(M-x)%M]);
        else CNTL[x]++;
        return;
    }
    dfs(n+2,(x+A[n])%M,A,f);
    dfs(n+1,x,A,f);
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin>>N>>M;
    vector<int> A(N);
    for(int i=0;i<N;i++)cin>>A[i];
    ll H=N/2;
    ll B=N-H;
    vector<int> PA={A.begin(),A.begin()+H};
    vector<int> PB={A.begin()+H,A.end()};
    reverse(PB.begin(),PB.end());
    CNT.reserve((ll)4e6);
    CNTL.reserve((ll)4e6);
    dfs(0,0,PA,0);
    dfs(0,0,PB,1);
    cout<<an<<endl;
}  

