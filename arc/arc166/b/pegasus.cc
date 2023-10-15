#pragma region template
#include<bits/stdc++.h>
using namespace std;
//other
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using pbds=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#include<atcoder/all>
using namespace atcoder;
#include "atcoder/modint.hpp"
using mint = atcoder::modint998244353;
using mint2 = atcoder::modint1000000007;
// #define int long long
#define pb push_back
#define eb emplace_back
#define ep emplace
#define len(a) (int)a.size()

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")

//using 
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using uint=unsigned;
using pcc=pair<char,char>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<ld,ld>;
using vi=vector<int>;
using vl=vector<ll>;
using vvi=vector<vi>;
using vvl=vector<vl>;
using vvvi=vector<vvi>;
using vvvl=vector<vvl>;
template<class T>using pqmin=priority_queue<T,vector<T>,greater<T>>;
template<class T>using pqmax=priority_queue<T>;

const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const int MOD=998244353;
const int MOD2=1000000007;
const ld PI=3.1415926535897932384626433832795028841971;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ll di[]={0,1,0,-1,1,-1,1,-1};
const ll dj[]={1,0,-1,0,1,1,-1,-1};

template<class T>
constexpr auto min(T a,T b,T c){
    return min(a,min(b,c));
}
template<class... T>
constexpr auto min(T... a){
    return min(initializer_list<common_type_t<T...>>{a...});
}

template<class T>
constexpr auto max(T a,T b,T c){
    return max(a,max(b,c));
}

template<class... T>
constexpr auto max(T... a){
    return max(initializer_list<common_type_t<T...>>{a...});
}

#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name

#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)

#define rrep1(n)for(ll i=n;i--;)
#define rrep2(i,n)for(ll i=n;i--;)
#define rrep3(i,a,b)for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c)for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)

#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)

#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define Msum(...) accumulate(all(__VA_ARGS__),0_M)
#define elif else if

#define INT(...) int __VA_ARGS__;input(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;input(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;input(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;input(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;input(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;input(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;input(__VA_ARGS__)

template<typename T>
int chmax(T &a,T b){
    if(a<b){a=b;return 1;}
    else return 0;
}
template<typename T>
int chmin(T &a,T b){
    if(a>b){a=b;return 1;}
    else return 0;
}
//io
//in
void scan(){}
void scan(int &a){cin>>a;}
void scan(unsigned &a){cin>>a;}
void scan(long& a){cin>>a;}
void scan(long long& a){cin>>a;}
void scan(unsigned long long&a){cin>>a;}
void scan(char& a){cin>>a;}
void scan(float& a){cin>>a;}
void scan(double& a){cin>>a;}
void scan(long double& a){cin>>a;}
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){cin>>a;}
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void input(){}
template<class Head,class...Tail> void input(Head& head,Tail&... tail){scan(head);input(tail...);}
//out
void puts(){ putchar(' '); }
void puts(bool a){ printf("%d", a); }
void puts(int a){ printf("%d", a); }
void puts(unsigned a){ printf("%u", a); }
void puts(long a){ printf("%ld", a); }
void puts(long long a){ printf("%lld", a); }
void puts(unsigned long long a){ printf("%llu", a); }
void puts(char a){ printf("%c", a); }
void puts(char a[]){ printf("%s", a); }
// void puts(const char a[]){ printf("%s", a); }
void puts(float a){ printf("%.15f", a); }
void puts(double a){ printf("%.15f", a); }
void puts(long double a){ printf("%.15Lf", a); }
void puts(const string& a){ for(auto&& i : a) puts(i); }
template<class T> void puts(const complex<T>& a){ if(a.real() >= 0) puts('+'); puts(a.real()); if(a.imag() >= 0) puts('+'); puts(a.imag()); puts('i'); }
template<class T> void puts(const vector<T>&);
template<class T, size_t size> void puts(const array<T, size>&);
template<class T, class L> void puts(const pair<T, L>& p);
template<class T, size_t size> void puts(const T (&)[size]);
template<class T> void puts(const vector<T>& a){ if(a.empty()) return; puts(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); puts(*i); } }
template<class T> void puts(const deque<T>& a){ if(a.empty()) return; puts(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); puts(*i); } }
template<class T> void puts(const set<T>& a){ if(a.empty()) return; puts(*a.begin()); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); puts(*i); } }
template<class T> void puts(const multiset<T>& a){ if(a.empty()) return; puts(*a.begin()); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); puts(*i); } }
template<class T, size_t size> void puts(const array<T, size>& a){ puts(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); puts(*i); } }
template<class T, class L> void puts(const pair<T, L>& p){ puts(p.first); putchar(' '); puts(p.second); }
template<class T, size_t size> void puts(const T (&a)[size]){ puts(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); puts(*i); } }
template<class T> void puts(const T& a){ cout << a; }
int print(){ putchar('\n'); return 0; }
template<class T> int print(const T& t){ puts(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int print(const Head& head, const Tail&... tail){ puts(head); putchar(' '); print(tail...); return 0; }
#pragma endregion

#pragma region commonly used
int digitsum(string s){
    int res=0;
    rep(i,(int)s.size()){
        res+=s[i]-'0';
    }
    return res;
}
#pragma endregion

ll n,a,b,c,A[200009],ans=LINF;
ll ff(ll a,ll mod){return (mod-a%mod)%mod;}

void sh1(ll p,ll q,ll r){
    vector<pair<ll,ll>> pp,qq,rr;
    rep(i,n){
        pp.emplace_back(make_pair(ff(A[i],p),i));
        qq.emplace_back(make_pair(ff(A[i],q),i));
        rr.emplace_back(make_pair(ff(A[i],r),i));
    }
    sort(all(pp));sort(all(qq));sort(all(rr));
    rep(i,3)rep(j,3)rep(k,3){
        if(pp[i].second!=qq[j].second&&qq[j].second!=rr[k].second&&rr[k].second!=pp[i].second){
            chmin(ans,ff(A[pp[i].second],p)+ff(A[qq[j].second],q)+ff(A[rr[k].second],r));
        }
    }
}

void sh2(ll p,ll q){
    vector<pair<ll,ll>> pp,qq;
    rep(i,n){
        pp.emplace_back(make_pair(ff(A[i],p),i));
        qq.emplace_back(make_pair(ff(A[i],q),i));
    }
    sort(all(pp));sort(all(qq));
    rep(i,3)rep(j,3){
        if(pp[i].second!=qq[j].second){
            chmin(ans,ff(A[pp[i].second],p)+ff(A[qq[j].second],q));
        }
    }
}

void sh3(ll p){
    vector<pair<ll,ll>> pp;
    rep(i,n){
        pp.emplace_back(make_pair(ff(A[i],p),i));
    }
    sort(all(pp));
    rep(i,3){
        chmin(ans,ff(A[pp[i].second],p));
    }
}


int main(){
    input(n,a,b,c);
    rep(i,n)cin>>A[i];
    sh1(a,b,c);
    sh2(lcm(a,b),c);
    sh2(lcm(b,c),a);
    sh2(lcm(a,c),b);
    sh3(lcm(a,lcm(b,c)));
    print(ans);
}
