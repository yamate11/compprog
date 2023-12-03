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
const long long maxX = my_pow(10,18);
long long calc(long long a,long long b){
    long long c = a*a*a + a*a*b + a*b*b + b*b*b;
    if(0<=c && c<=maxX)return c;
    else return maxX;
}
int main(){
    long long N;
    long long X = my_pow(10,18);
    cin>>N;
    if(N==0){
        cout<<0<<endl;
        return 0;
    }
    for(long long a=0;a<=min(N,my_pow(10,6));a++){
        long long ng = -1LL;
        long long ok = my_pow(10, 6);
        while(ok-ng>1LL){
            long long mid = (ok+ng)/2LL;
            long long c = calc(a,mid);
            if(c < N) ng = mid;
            else if(c >= N) ok = mid;
        }
        long long b = ok;
        X = min(X,calc(a,b));
    }
    cout<<X<<endl;
    return 0;
}
