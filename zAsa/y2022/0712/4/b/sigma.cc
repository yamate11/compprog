#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define all(c) c.begin(),c.end()
#define pb push_back
#define fs first
#define sc second
#define show(x) cout << #x << " = " << x << endl
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
using namespace std;
template<class S,class T> ostream& operator<<(ostream& o,const pair<S,T> &p){return o<<"("<<p.fs<<","<<p.sc<<")";}
template<class T> ostream& operator<<(ostream& o,const vector<T> &vc){o<<"sz = "<<vc.size()<<endl<<"[";for(const T& v:vc) o<<v<<",";o<<"]";return o;}
using ll = long long;
int N;
ll a[100000];
ll b[100000];
ll d[100000];
int main(){
	cin>>N;
	rep(i,N) cin>>a[i];
	rep(i,N) cin>>b[i];
	ll K = 0;
	rep(i,N){
		K += b[i]-a[i];
	}
	ll two = 0;
	rep(i,N){
		ll d = b[i]-a[i];
		if(d>0) two += (d+1)/2;
	}
	if(two>K) puts("No");
	else puts("Yes");
}
