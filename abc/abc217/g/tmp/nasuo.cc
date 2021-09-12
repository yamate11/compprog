#include <bits/stdc++.h>
#if __has_include(<atcoder/all>)
    #include <atcoder/all>
    using namespace atcoder;
#endif
using namespace std;
namespace defines{
    typedef long long ll;
    typedef pair<int,int> P;
    #define FOR(i,a,b) for(ll i = a ; i < b ; i++) // for i in range(a,b)
    #define REP(i,n) for(int i = 0 ; i < n ; i++) // for i in range(b)
    #define FORD(i,a,b) for(ll i = a ; i > b ; i--) // for i in range(a,b,-1)
    #define ALL(x) x.begin(),x.end()
    template<class T> vector<T> make_vec(size_t a){return vector<T>(a);}
    template<class T, class... Ts> auto make_vec(size_t a, Ts... ts){ return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}
    template<typename A, size_t N, typename T> void Fill(A (&array)[N], const T &val){std::fill( (T*)array, (T*)(array+N), val );}

    /* for debug */
    #define DEBUG(x) dbg(#x,x)
    template<class T> void dbg(string name, T x){cerr<<name<<": "<<x<<"\n";}
    template<> void dbg<P>(string name, P x){cerr<<name<<": ("<<x.first<<","<<x.second<<")\n";}
    template<class T> void dbg(string name, vector<T> xl){cerr<<name<<": "; for(T x: xl) cerr<<x<<" "; cerr<<'\n';}
    template<> void dbg<P>(string name, vector<P> xl){cerr<<name<<": "; for(P x:xl){cerr<<"("<<x.first<<","<<x.second<<"), ";}cerr<<"\n";}
    template<class T> void dbg(string name, vector<vector<T>> xl){ cerr<<name<<": \n"; int ml=1;for(vector<T> row: xl){for(T x:row){stringstream sstm; sstm<<x; ml=max(ml,(int)sstm.str().size());}}; for(vector<T> row: xl){{for(T x:row) cerr<<std::right<<std::setw(ml+1)<<x;} cerr << '\n';}}
    template<class T> void dbg(string name, set<T> xl){cerr<<name<<": "; for(T x:xl)cerr<<x<<" ";cerr<<'\n';}
    template<class T> void dbg(string name, multiset<T> xl){cerr<<name<<": "; for(T x:xl)cerr<<x<<" ";cerr<<'\n';}
    template<class T> void dbg(string name, unordered_set<T> xl){cerr<<name<<": "; for(T x:xl)cerr<<x<<" ";cerr<<'\n';}
    template<class T> void dbg(string name, unordered_multiset<T> xl){cerr<<name<<": "; for(T x:xl)cerr<<x;cerr<<'\n';}
    template<class T, class U> void dbg(string name, map<T,U> xl){cerr<<name<<": \n"; for(auto &[k,v]:xl)cerr<<"  "<<k<<": "<<v<<'\n';}
    template<class T, class U> void dbg(string name, unordered_map<T,U> xl){cerr<<name<<": \n"; for(auto &[k,v]:xl)cerr<<"  "<<k<<": "<<v<<'\n';}
}
using namespace defines;

const int IINF = 1'001'001'001;
const ll INF = 1'001'001'001'001'001'001ll;
const int MOD = 1'000'000'007;
// const int MOD = 998244353;
// using mint = modint1000000007;
// using mint = modint998244353;

bool check_used(int bits, int y, int x){
    int posi=y*5+x;
    if( bits&(1<<posi) ) return true;
    return false;
}

bool check(int bits, int y, int x){
    if(y==0 || y==4){
    }
    else{
        if(check_used(bits,y-1,x)^check_used(bits,y+1,x)) return false;
    }
    if(x==0 || x==4){
    }
    else{
        if(check_used(bits,y,x-1)^check_used(bits,y,x+1)) return false;
    }
    return true;
}

int pc(int bits){
    int v=bits;
    int res=0;
    REP(i,25){
        if(v&1)res++;
        v>>=1;
    }
    return res;
}

void solve(){
    vector<P> fixed(25,{-1,-1});
    REP(y,5){
        REP(x,5){
            int a; cin>>a; a--;
            if(a!=-1){
                fixed[a]={y,x};
            }
        }
    }
    const int MAX=(1<<25);
    vector<int> dp(MAX, 0);
    dp[0]=1;
    REP(bits, MAX){
        if(dp[bits]==0) continue;
        // int num=pc(bits);
        int num = __builtin_popcountll(bits); // 使う数
        if(fixed[num].first!=-1){ // 固定された数なら
            auto &[y,x]=fixed[num];
            int posi=y*5+x;
            if(check(bits,y,x)){
                dp[bits|(1<<posi)]+=dp[bits];
                dp[bits|(1<<posi)]%=MOD;
            }
        }
        else{
            REP(y,5){
                REP(x,5){
                    if(check_used(bits,y,x))continue;
                    if(check(bits,y,x)){
                        int posi=y*5+x;
                        dp[bits|(1<<posi)]+=dp[bits];
                        dp[bits|(1<<posi)]%=MOD;
                    }
                }
            }
        }
    }
    int ans=dp[MAX-1];
    // ans*=500000004;
    // ans%=MOD;
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
