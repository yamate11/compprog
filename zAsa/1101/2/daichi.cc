#include<bits/stdc++.h>
using namespace std;
long long INFl = 1LL<<60;
int INFi = 1<<30;
int AlphaNum = 26;
long long MOD = 998244353;
int mod(long long N){
    return (N + MOD ) % MOD;
}
long long my_pow(int a,int b){
    long long rec=1;
    for(int i=0;i<b;i++){
        rec *= a;
    }
    return rec;
}
int main(){
    string sDisplay = "DiscoPresentsDiscoveryChannelProgrammingContest2016";
    int W;
    cin>>W;
    int column = sDisplay.size() / W;
    vector<string>sDivided(column+1);
    for(int i=0;i<sDivided.size();i++){
        string sub = sDisplay.substr(i*W,min(W,(int)(sDisplay.size()-i*W)));
        cout<<sub;
        if(i<sDivided.size()-1)cout<<endl;
    }
    return 0;
}
