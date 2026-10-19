#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define vll vector<pair<ll,ll>>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vvii vector<vector<pair<int,int>>>
#define vvll vector<vector<pair<ll,ll>>>
#define vst vector<string>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define mkunique(x) sort(all(x));(x).erase(unique(all(x)),(x).end())
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=300005,INF=15<<26;

vi yaku[MAX];

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    for(int x=2;x<MAX;x++){
        for(int y=x;y<MAX;y+=x) yaku[y].pb(x);
    }
    int Q;cin>>Q;
    while(Q--){
        int N,X;cin>>N>>X;
        vi A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        ll ma=0;
        for(int g:yaku[X]){
            if(g==1) continue;
            ll sum=0;
            for(int a:A){
                if(a%g==0) sum+=a;
            }
            chmax(ma,sum);
        }
        cout<<ma<<"\n";
    }
    
}


