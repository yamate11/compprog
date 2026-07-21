#if !defined(MYLOCAL)//提出時用テンプレート
//# pragma GCC target("avx2")//yukiではNG
# pragma GCC optimize("O3")
# pragma GCC optimize("unroll-loops")
#if defined(NDEBUG)
#undef NDEBUG
#endif
#include "bits/stdc++.h"
#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif
using namespace std;
using ll=long long;
using dd=long double;
using pll=pair<ll,ll>;
using tll=tuple<ll,ll,ll>;
using qll=tuple<ll,ll,ll,ll>;
using ll2=array<ll,2>;
using ll3=array<ll,3>;
using ll4=array<ll,4>;
using namespace chrono;
constexpr ll INF = 1201001001001001001;
struct Fast{ Fast(){ cin.tie(0); ios::sync_with_stdio(false); cout<<fixed<<setprecision(numeric_limits<double>::max_digits10); } } fast;
#define EXPAND( x ) x//VS用おまじない
#define overload3(_1,_2,_3,name,...) name
#define overload4(_1,_2,_3,_4,name,...) name
#define overload5(_1,_2,_3,_4,_5,name,...) name
#define rep1(N)          for (ll dmyi = 0; dmyi < (N); dmyi++)
#define rep2(i, N)       for (ll i = 0; i < (N); i++)
#define rep3(i, S, E)    for (ll i = (S); i <= (E); i++)
#define rep4(i, S, E, t) for (ll i = (S); i <= (E); i+=(t))
#define rep(...) EXPAND(overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__))
#define dep3(i, E, S)    for (ll i = (E); i >= (S); i--)
#define dep4(i, E, S, t) for (ll i = (E); i >= (S); i-=(t))
#define dep(...) EXPAND(overload4(__VA_ARGS__, dep4, dep3,_,_)(__VA_ARGS__))
#define ALL1(v)     (v).begin(),     (v).end()
#define ALL2(v,E)   (v).begin(),     (v).begin()+((E)+1)
#define ALL3(v,S,E) (v).begin()+(S), (v).begin()+((E)+1)
#define all(...) EXPAND(overload3(__VA_ARGS__, ALL3, ALL2, ALL1)(__VA_ARGS__))
#define RALL1(v)     (v).rbegin(),     (v).rend()
#define RALL2(v,E)   (v).rbegin(),     (v).rbegin()+((E)+1)
#define RALL3(v,S,E) (v).rbegin()+(S), (v).rbegin()+((E)+1)
#define rall(...) EXPAND(overload3(__VA_ARGS__, RALL3, RALL2, RALL1)(__VA_ARGS__))
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> [[nodiscard]] inline T limithi(T a,T b){ return min(a,b); }
template<class T> [[nodiscard]] inline T limitlo(T a,T b){ return max(a,b); }
template<class T> inline bool chlimithi(T &a,T b){ return chmin(a,b); }
template<class T> inline bool chlimitlo(T &a,T b){ return chmax(a,b); }
template<class T> inline auto maxe(T &&v,ll S,ll E){ return *max_element(all(v,S,E)); }
template<class T> inline auto maxe(T &&v){ return *max_element(all(v)); }
template<class T> inline auto mine(T &&v,ll S,ll E){ return *min_element(all(v,S,E)); }
template<class T> inline auto mine(T &&v){ return *min_element(all(v)); }
template<class T,class U=typename remove_reference<T>::type::value_type>
inline U sum(T &&v,ll S,ll E) {return accumulate(all(v,S,E),U());}
template<class T> inline auto sum(T &&v) {return sum(v,0,v.end()-v.begin()-1);}
template<class T> inline ll sz(T &&v){ return (ll)v.size(); }
inline ll Ceil(ll a,ll b){ if (b<0) a=-a,b=-b; return a>0 ? (a-1)/b+1 : a/b; }//a,b負可
inline ll Floor(ll a,ll b){ return -Ceil(-a,b); }//a,b負可
inline ll Floormod(ll a,ll m){ return Floor(a,m)*m; } //a負可
inline ll Ceilmod(ll a,ll m){ return Ceil(a,m)*m; } //a負可
inline ll Mod(ll a,ll m){ ll r=a%m; if(r<0)r+=m; return r; } //a負可
template<class T> inline T Pow(T a,ll n){ T r=1; for(; n>0; n>>=1,a*=a){ if(n&1)r*=a; } return r; }
inline ll Pow(int a,ll n){ return Pow((ll)a,n); }
inline ll limitmul(ll a,ll b,ll u){ return b==0||a<=u/b ? a*b : u; }//min(a*b,u) a,b,u≧0

//pair用テンプレート
template<class T,class S> inline pair<T,S>& operator+=(pair<T,S> &a,const pair<T,S> &b){ a.first+=b.first; a.second+=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator-=(pair<T,S> &a,const pair<T,S> &b){ a.first-=b.first; a.second-=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator*=(pair<T,S> &a,const pair<T,S> &b){ a.first*=b.first; a.second*=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator/=(pair<T,S> &a,const pair<T,S> &b){ a.first/=b.first; a.second/=b.second; return a; }
template<class T,class S> inline pair<T,S>& operator%=(pair<T,S> &a,const pair<T,S> &b){ a.first%=b.first; a.second%=b.second; return a; }
template<class T,class S,class R> inline pair<T,S>& operator+=(pair<T,S> &a,R b){ a.first+=b; a.second+=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator-=(pair<T,S> &a,R b){ a.first-=b; a.second-=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator*=(pair<T,S> &a,R b){ a.first*=b; a.second*=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator/=(pair<T,S> &a,R b){ a.first/=b; a.second/=b; return a; }
template<class T,class S,class R> inline pair<T,S>& operator%=(pair<T,S> &a,R b){ a.first%=b; a.second%=b; return a; }
template<class T,class S,class R> inline pair<T,S> operator+(const pair<T,S> &a,R b){ pair<T,S> c=a; return c+=b; }
template<class T,class S,class R> inline pair<T,S> operator-(const pair<T,S> &a,R b){ pair<T,S> c=a; return c-=b; }
template<class T,class S,class R> inline pair<T,S> operator*(const pair<T,S> &a,R b){ pair<T,S> c=a; return c*=b; }
template<class T,class S,class R> inline pair<T,S> operator/(const pair<T,S> &a,R b){ pair<T,S> c=a; return c/=b; }
template<class T,class S,class R> inline pair<T,S> operator%(const pair<T,S> &a,R b){ pair<T,S> c=a; return c%=b; }
template<class T,class S,class R> inline pair<T,S> operator-(R b,const pair<T,S> &a){ pair<T,S> c=-a; return c+=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a,const pair<T,S> &b){ pair<T,S> c=a; return c-=b; }
template<class T,class S> inline pair<T,S> operator-(const pair<T,S> &a){ pair<T,S> c=a; return c*=(-1); }
template<class T,class S> inline ostream &operator<<(ostream &os,const pair<T,S> &a){ return os << a.first << ' ' << a.second; }

//tuple用テンプレート 出力用のみ
template<class T,class S,class R> inline ostream &operator<<(ostream &os,const tuple<T,S,R> &a){ return os << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a); }
template<class T,class S,class R,class Q> inline ostream &operator<<(ostream &os,const tuple<T,S,R,Q> &a){ return os << get<0>(a) << ' ' << get<1>(a) << ' ' << get<2>(a) << ' ' << get<3>(a); }

//vector用テンプレート
template<class T> inline ostream &operator<<(ostream &os,const vector<T> &a){ for (ll i=0; i<(ll)a.size(); i++) os<<(i>0?" ":"")<<a[i];  return os; }

//array用テンプレート
template<class T,size_t S> inline array<T,S>& operator+=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]+=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator-=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]-=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator*=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]*=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator/=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]/=b[i];  return a; }
template<class T,size_t S> inline array<T,S>& operator%=(array<T,S> &a,const array<T,S> &b){ for (ll i=0; i<(ll)S; i++) a[i]%=b[i];  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator+=(array<T,S> &a,R b){ for (T &e: a) e+=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator-=(array<T,S> &a,R b){ for (T &e: a) e-=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator*=(array<T,S> &a,R b){ for (T &e: a) e*=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator/=(array<T,S> &a,R b){ for (T &e: a) e/=b;  return a; }
template<class T,size_t S,class R> inline array<T,S>& operator%=(array<T,S> &a,R b){ for (T &e: a) e%=b;  return a; }
template<class T,size_t S,class R> inline array<T,S> operator+(const array<T,S> &a,R b){ array<T,S> c=a; return c+=b; }
template<class T,size_t S,class R> inline array<T,S> operator-(const array<T,S> &a,R b){ array<T,S> c=a; return c-=b; }
template<class T,size_t S,class R> inline array<T,S> operator*(const array<T,S> &a,R b){ array<T,S> c=a; return c*=b; }
template<class T,size_t S,class R> inline array<T,S> operator/(const array<T,S> &a,R b){ array<T,S> c=a; return c/=b; }
template<class T,size_t S,class R> inline array<T,S> operator%(const array<T,S> &a,R b){ array<T,S> c=a; return c%=b; }
template<class T,size_t S,class R> inline array<T,S> operator-(R b,const array<T,S> &a){ array<T,S> c=-a; return c+=b; }
template<class T,size_t S> inline array<T,S> operator-(const array<T,S> &a,const array<T,S> &b){ array<T,S> c=a; return c-=b; }
template<class T,size_t S> inline array<T,S> operator-(const array<T,S> &a){ array<T,S> c=a; return c*=(-1); }
template<class T,size_t S> inline ostream &operator<<(ostream &os,const array<T,S> &a){ for (ll i=0; i<(ll)S; i++) os<<(i>0?" ":"")<<a[i];  return os; }

inline struct{
  system_clock::time_point st = system_clock::now();
  ll operator()()const{return duration_cast<microseconds>(system_clock::now()-st).count()/1000;}
} timeget;

struct cinutil{
  template<class T> static void cin1core(T &a){ cin>>a; }
  template<class T,class S> static void cin1core(pair<T,S> &a){
    cin1core(a.first), cin1core(a.second);}
  template<class... Args> static void cin1core(tuple<Args...> &a){
    cinTplRec<tuple<Args...>,sizeof...(Args)-1>()(a);
  }
  template<class T,size_t N>
  static void cin1core(array<T,N> &a){for(int i=0;i<(int)N;++i) cin>>a[i];}
private:
  template<class Tpl,int i> struct cinTplRec{
    void operator()(Tpl &a){ cinTplRec<Tpl,i-1>()(a); cin1core(get<i>(a)); }
  };
  template<class Tpl> struct cinTplRec<Tpl,0>{
    void operator()(Tpl &a){ cin1core(get<0>(a)); }
  };
};
template<class T> T cin1(){ T a; cinutil::cin1core(a); return a; }
template<class... Args> tuple<Args...> cins(){ return cin1<tuple<Args...>>(); }


template<long long MOD> struct mll_{
  using Int = long long;
  using ll = long long;
  ll val_=0;
  /*---- utility ----*/
  mll_ &norm(){ return normR().normS(); }//正規化
  mll_ &normR(){ val_%=MOD; return *this; }//剰余正規化のみ
  mll_ &normS(){ if (val_<0) val_+=MOD; return *this; }//正負正規化のみ
  mll_ &normP(){ if (val_>=MOD) val_-=MOD; return *this; }//加算時正規化
  mll_ &invsg(){ val_=-val_; return normS(); }//正負反転
  ll modinv(int a){//a^-1 mod MOD
    int ypre=0,y=1,apre=MOD;
    while (a>1){
      int t=apre/a;
      apre-=a*t,swap(a,apre);
      ypre-=y*t,swap(y,ypre);
    }
    return y<0 ? y+MOD: y;
  }
  /*---- I/F ----*/
  constexpr mll_(){}
  mll_(ll v): val_(v){ norm(); }
  constexpr mll_(ll v,bool b): val_(v){} //正規化無のコンストラクタ
  Int val()const{ return (Int)val_; }
  bool isnone() const { return val_==-1; } //true:値なし
  mll_ &none() { val_=-1; return *this; } //値なしにする
  mll_ &inv(){ val_=modinv((int)val_); return *this; }
  mll_ &operator+=(mll_ b){ val_+=b.val_; return normP(); }
  mll_ &operator-=(mll_ b){ val_-=b.val_; return normS(); }
  mll_ &operator*=(mll_ b){ val_*=b.val_; return normR(); }
  mll_ &operator/=(mll_ b){ return *this*=b.inv(); }
  mll_ &operator+=(ll b){ return *this+=mll_(b); }
  mll_ &operator-=(ll b){ return *this-=mll_(b); }
  mll_ &operator*=(ll b){ return *this*=mll_(b); }
  mll_ &operator/=(ll b){ return *this/=mll_(b); }
  mll_ &operator--(int){ return *this-=1; }
  mll_ &operator++(int){ return *this+=1; }
  mll_ operator-()const{ return mll_(*this).invsg(); }
  mll_ operator+(mll_ b)const{ return mll_(*this)+=b; }
  mll_ operator-(mll_ b)const{ return mll_(*this)-=b; }
  mll_ operator*(mll_ b)const{ return mll_(*this)*=b; }
  mll_ operator/(mll_ b)const{ return mll_(*this)/=b; }
  mll_ operator+(ll b)const{ return mll_(*this)+=b; }
  mll_ operator-(ll b)const{ return mll_(*this)-=b; }
  mll_ operator*(ll b)const{ return mll_(*this)*=b; }
  mll_ operator/(ll b)const{ return mll_(*this)/=b; }
  friend mll_ operator+(ll a,mll_ b){ return b+a; }
  friend mll_ operator-(ll a,mll_ b){ return -b+a; }
  friend mll_ operator*(ll a,mll_ b){ return b*a; }
  friend mll_ operator/(ll a,mll_ b){ return mll_(a)/b; }
  auto operator<=>(const mll_& b) const = default;
  friend ostream &operator<<(ostream &os,mll_  a){ return os << a.val_; }
  friend istream &operator>>(istream &is,mll_ &a){ return is >> a.val_; }
  mll_ pow(ll k)const{
    mll_ ret(1,false),a(*this);
    for (; k>0; k>>=1,a*=a) if (k&1)ret*=a;
    return ret;
  }
  static constexpr int mod() { return MOD; }
  //enum{ modll=MOD };
};


struct bll{
  ll s=0;
  bll(ll s_=0): s(s_){}
  bll(int s_): s(s_){}
  bll(const string &bitstr): s(str2val(bitstr)){}
  bll(const char   *bitstr): s(str2val(bitstr)){}
  struct ref {
    bll &b; const ll msk;
    ref(bll &b_,ll pos):b(b_),msk(1LL<<pos){}
    operator ll() const { return (b.s&msk)!=0; }
    ref &operator=(bool x){ if(x) b.s|=msk; else b.s&=~msk; return *this; }
  };
  ref operator[](ll pos){ return ref(*this,pos); }
  ll operator[](ll pos) const { return (s>>pos)&1; }
  bll &operator=(int b){ s=b; return *this; }
  bll &operator=(ll  b){ s=b; return *this; }
  bll &operator=(const string &bitstr){ s=str2val(bitstr); return *this; }
  bll &operator=(const char   *bitstr){ s=str2val(bitstr); return *this; }
  bll operator++(int){ bll b(*this); s++; return b; }
  bll operator--(int){ bll b(*this); s--; return b; }
  operator ll() const noexcept { return s; }
  bll &operator&=(ll b){ s&=b; return *this; }
  bll &operator|=(ll b){ s|=b; return *this; }
  bll &operator^=(ll b){ s^=b; return *this; }
  bll &operator+=(ll b){ s+=b; return *this; }
  bll &operator-=(ll b){ s-=b; return *this; }
  bll &operator<<=(ll i){ s<<=i; return *this; }
  bll &operator>>=(ll i){ s>>=i; return *this; }
  bll operator&(ll b)const{ return s&b; }
  bll operator|(ll b)const{ return s|b; }
  bll operator^(ll b)const{ return s^b; }
  bll operator+(ll b)const{ return s+b; }
  bll operator-(ll b)const{ return s-b; }
  bll operator<<(ll i)const{ return s<<i; }
  bll operator>>(ll i)const{ return s>>i; }
  bll operator&(int b)const{ return s&b; }
  bll operator|(int b)const{ return s|b; }
  bll operator^(int b)const{ return s^b; }
  bll operator+(int b)const{ return s+b; }
  bll operator-(int b)const{ return s-b; }
  bll operator<<(int i)const{ return s<<i; }
  bll operator>>(int i)const{ return s>>i; }
  bll operator~()const{ return ~s; }
  bll &oneq  (bll msk){ s|= msk.s; return *this; }
  bll &offeq (bll msk){ s&=~msk.s; return *this; }
  bll &flipeq(bll msk){ s^= msk.s; return *this; }
  bll on   (bll msk)const{ return bll(s).oneq  (msk); }
  bll off  (bll msk)const{ return bll(s).offeq (msk); }
  bll flip (bll msk)const{ return bll(s).flipeq(msk); }
  bool any0(bll msk)const{ return ~s&msk.s; }
  bool any1(bll msk)const{ return  s&msk.s; }
  bool all0(bll msk)const{ return !any1(msk); }
  bool all1(bll msk)const{ return !any0(msk); }
  bll &oneq  (ll l,ll r){ return oneq  (rngmsk(l,r)); }
  bll &offeq (ll l,ll r){ return offeq (rngmsk(l,r)); }
  bll &flipeq(ll l,ll r){ return flipeq(rngmsk(l,r)); }
  bll on   (ll l,ll r)const{ return on  (rngmsk(l,r)); }
  bll off  (ll l,ll r)const{ return off (rngmsk(l,r)); }
  bll flip (ll l,ll r)const{ return flip(rngmsk(l,r)); }
  bool any0(ll l,ll r)const{ return any0(rngmsk(l,r)); }
  bool any1(ll l,ll r)const{ return any1(rngmsk(l,r)); }
  bool all0(ll l,ll r)const{ return all0(rngmsk(l,r)); }
  bool all1(ll l,ll r)const{ return all1(rngmsk(l,r)); }
  bll &maskeq(ll l,ll r){ s&=rngmsk(l,r); return *this; }
  bll mask(ll l,ll r)const{ return bll(s).maskeq(l,r); }
  bll &oneq  (ll i){ s|= (1LL<<i); return *this; }
  bll &offeq (ll i){ s&=~(1LL<<i); return *this; }
  bll &flipeq(ll i){ s^= (1LL<<i); return *this; }
  bll on  (ll i)const{ return s| (1LL<<i); }
  bll off (ll i)const{ return s&~(1LL<<i); }
  bll flip(ll i)const{ return s^ (1LL<<i); }
  bool contains(ll b)const{ return (s&b)==b; }
  bll substr(ll l,ll r)const{ return (s&rngmsk(l,r))>>r; }
  static bll rngmsk(ll l,ll r){ return (1LL<<(l+1))-(1LL<<r); }
  ll msbit()const{
    for(ll x=63,o=-1;;){
      ll m=(x+o)/2;
      if((1LL<<m)<=s) o=m; else x=m;
      if(x-o==1) return o;
    }
  }
  ll lsbit()const{ return bll(lsb()).msbit(); }
  ll msb()const{ ll pos=msbit(); return (pos<0) ? 0LL : 1LL<<pos; }
  ll lsb()const{ return s&-s; }
  ll count()const{ return bitset<64>(s).count(); }
  ll count(bll msk)const{ return (msk&s).count(); }
  ll count(ll l,ll r)const{ return mask(l,r).count(); }
  vector<ll> idxes()const{
    vector<ll> v;
    for(ll i=0,t=s; t; t>>=1,i++) if(t&1)v.push_back(i);
    return v;
  }
  string to_string(ll wd=-1)const{
    wd=max({wd,msbit()+1,1LL});
    string ret;
    for(ll i=wd-1;i>=0;--i) ret += '0'+char((s>>i)&1);
    return ret;
  }
private:
  ll str2val(const string &bitstr){
    ll val=0, len=(ll)bitstr.size();
    for(ll i=0;i<len;++i) val|=ll(bitstr[i]-'0')<<(len-1-i);
    return val;
  }
};


template<class T> struct SET: set<T>{
  using P=set<T>;
  typename P::iterator it=P::end();
  template<class...Args> SET(Args...args): P(args...){}
  SET(initializer_list<T> a): P(a.begin(),a.end()){}
  ll size() const { return (ll)P::size(); }
  bool insert(const T &x){ bool r; tie(it,r)=P::insert(x); return r; }
  template <class It> void insert(It st,It en){ P::insert(st,en); }
  void insert(initializer_list<T> a){ P::insert(a.begin(),a.end()); }
  template<class...A> bool emplace(A&&...a){ bool r; tie(it,r)=P::emplace(a...); return r; }
  void eraseit(){ it=P::erase(it); }
  void find(const T &x){ it=P::find(x); }
  bool contains(const T &x){ return P::count(x)==1; }
  void lower_bound(const T &x){ it=P::lower_bound(x); }
  void upper_bound(const T &x){ it=P::upper_bound(x); }
  T floor(const T &x){ return *(it=--P::upper_bound(x)); }
  T ceil (const T &x){ return *(it=P::lower_bound(x)); }
  bool isend() { return it==P::end(); }
  T getit() { return *it; }
  T next() { return *(++it); }
  T prev() { return *(--it); }
  bool nextok() { return !isend() && it!=--P::end(); }
  bool prevok() { return it!=P::begin(); }
  T front() { return *(it=P::begin()); }
  T back()  { return *(it=--P::end()); }
  void pop_front(){ front(); eraseit(); }
  void pop_back(){ back(); eraseit(); }
  void push_front(const T &x){ it=P::insert(P::begin(),x); }
  void push_back (const T &x){ it=P::insert(P::end(),x); }
  void push_out(SET &b){ b.push_front(back()); pop_back(); }
  void pull_in(SET &b){ push_back(b.front()); b.pop_front(); }
};


template<class T> struct cumulativesum{
    using Int = long long;
    using ll = long long;
    using pIT = pair<Int,T>;
    ll n=0;  vector<T> c;
    cumulativesum():c(1){}
    template<class S> cumulativesum(S &&v) : n((ll)v.size()),c(n+1) { Ini(v); }
    template<class S> void init(S &&v){ n=(ll)v.size(); c.resize(n+1); Ini(v); }
    void add(T x) { n++; c.push_back(c.back()+x); }
    T operator()(Int l,Int r){ return c[max(min(n,r+1),0LL)]-c[min(max(0LL,l),n)]; }

    pIT floorGroup(ll l,T x){
        l=clamp(l,0LL,(ll)c.size()-1);
        T th=x+c[l];
        ll r=upper_bound(c.begin(),c.end(),th)-c.begin()-2;
        T rem = r==-2 ? T() : th-c[r+1];
        return {r,rem};
    }

    pIT ceilGroup(ll l,T x){
        l=clamp(l,0LL,(ll)c.size()-1);
        T th=x+c[l];
        ll r=lower_bound(c.begin(),c.end(),th)-c.begin()-1;
        T rem = r==(ll)c.size()-1 ? T() : c[r+1]-th;
        return {r,rem};
    }

    pIT floorGroupRev(ll r,T x){
        // A0+…+A_{l-1} が (A0+…+Ar)-x以上に初めてなったときが答
        r=clamp(r,-1LL,(ll)c.size()-2);
        ll th=c[r+1]-x; //(A0+…+Ar)-x
        ll l=lower_bound(c.begin(),c.end(),th)-c.begin();
        T rem = l==(ll)c.size() ? T() : c[l]-th;
        return {l,rem};
    }

    pIT ceilGroupRev(ll r,T x){
        // A0+…+A_{l-1} が (A0+…+Ar)-x以下な最大のlが答
        r=clamp(r,-1LL,(ll)c.size()-2);
        ll th=c[r+1]-x; //(A0+…+Ar)-x
        ll l=upper_bound(c.begin(),c.end(),th)-c.begin()-1;
        T rem = l==-1 ? T() : th-c[l];
        return {l,rem};
    }

    pIT groupIdx(ll l,T x){
        auto [r,rem]=floorGroup(l,x);
        return (r+1==-1 || r+1==n) ? pIT{r+1,T()} : pIT{r+1,rem};
    }
    pIT groupIdxRev(ll r,T x){
        auto [l,rem]=floorGroupRev(r,x);
        return (l-1==-1 || l-1==n) ? pIT{l-1,T()} : pIT{l-1,c[l]-c[l-1]-1-rem};
    }

    T mx(){//区間和max
        T mn=T(),samx=0;
        for (ll i=1; i<=n; ++i){
            chmax(samx,c[i]-mn);
            chmin(mn,c[i]);
        }
        return samx;
    }
    template<class S> void Ini(S &&v) { for (ll i=0; i<n; ++i) c[i+1]=c[i]+v[i]; }
};
template<class S> cumulativesum(S) -> cumulativesum<typename remove_reference<S>::type::value_type>;


template<class T> vector<T> powers(T m,ll n){
  vector<T> ret(n+1,1);
  for(ll i=1;i<=n;++i) ret[i]=ret[i-1]*m;
  return ret;
}


template <class T> auto runlength(T &&v){
  vector<pair<typename remove_reference<T>::type::value_type,ll>> ret;
  for(auto&&e:v){
    if(ret.empty() or ret.back().first!=e) ret.emplace_back(e,1);
    else ret.back().second++;
  }
  return ret;
}


inline vector<ll> str2num(string &s,char base,const string &etc){
  vector<ll>  v(s.size());
  for(ll i=0;i<(ll)s.size();++i){
    size_t pos=etc.find(s[i]);
    if(pos==etc.npos) v[i]=s[i]-(ll)base;
    else v[i]=-((ll)pos+1);
  }
  return v;
}


template<class T> struct combination{
  vector<T> f,g; ll mxN=0;
  combination(){}
  combination(ll maxN): f(maxN+1,1),g(maxN+1),mxN(maxN) {
    for (ll i=1;i<=mxN;++i) { f[i]=f[i-1]*i; }
    g[mxN]=1/f[mxN];
    for (ll i=mxN;i>=1;--i) { g[i-1]=g[i]*i; }
  }
  T P(ll n,ll r){ return (n<0 || r<0 || n<r) ? T(0) : f[n]*g[n-r]; } //nPr
  T H(ll n,ll r){ return operator()(n+r-1,n-1); }//nHr
  T inv(ll n) { return f[n-1] * g[n]; } //1/n
  T fact(ll n) { return f[n]; } //n!
  T finv(ll n) { return g[n]; } //1/n!
  T operator()(ll n,ll r){
    if (r<0) return 0;
    if (n<0) return operator()(-n+r-1,r) * ((r&1)?-1:1); //-nＣr = (-1)^r * n+r-1Ｃr
    if (n<r) return 0;
    if (n<=mxN) return f[n]*g[n-r]*g[r]; //通常
    //n巨大、rかn-r小
    if (n-r<r) r=n-r;
    T bunsi=1,bunbo=1;
    for (ll i=0;i<r;++i) bunsi*=n-i;
    for (ll i=0;i<r;++i) bunbo*=i+1;
    return bunsi/bunbo;
  }
  template<class SP>
  vector<T> CnLnR(long long nL,long long nR,long long r,SP sp){
    if (nR-nL+1<=0) return vector<T>();
    if (r<0) return vector<T>(nR-nL+1,0);
    vector<T> v=sp(nL-r+1,nR-r+1,r);
    for (T& e: v) e*=finv(r);
    return v;
  }
  template<class SP>
  vector<T> HrLrR(long long n,long long rL,long long rR,SP sp){//r<0不可
    return CnLnR(n-1+rL,n-1+rR,n-1,sp);
  }
};


template<class T> struct wrapVector1d{
  using S=typename T::value_type;
  using Int = long long;
  const T *v;
  S Ini;
  wrapVector1d(const T &v_,S ini_=S()):v(&v_),Ini(ini_){}
  S operator[](Int i)const{ return (i<0 || (Int)v->size()<=i) ? Ini : (*v)[i]; }
};
template<class T> struct wrapVector2d{
  using S=typename T::value_type;
  using Int = long long;
  const vector<T> *v;
  S Ini;
  T dmy;
  wrapVector2d(const vector<T> &v_,S ini_=S()):v(&v_),Ini(ini_){}
  wrapVector1d<T> operator[](ll i)const{
    return (i<0 || (Int)v->size()<=i) ?
      wrapVector1d(dmy,Ini) : wrapVector1d((*v)[i],Ini);
  }
};


namespace dumpstring{//dummy
inline string stringf(const char *format,...){
  char bf[1000];
  va_list ap;
  va_start(ap,format);
  vsprintf(bf,format,ap);
  va_end(ap);
  return string(bf);
}
template <class T> string stringfx(T x,int wd=1){ return ""; }
struct args{
  using Int = long long;
  args(){}
  args &wd(Int wd__){ (void)wd__; return *this; }
  args &sx(Int s){ (void)s; return *this; }
  template<size_t DIM> args &rngs(array<array<Int,DIM>,2> rngs){ return *this; }
  args &tr(vector<Int> tr__){ (void)tr__; return *this; }
  args &tr(){ return *this; }
  args &labels(vector<string> labels__){ (void)labels__; return *this; }
  args &xrev(){ return *this; }
  args &yrev(){ return *this; }
  args &zrev(){ return *this; }
  args &wrev(){ return *this; }
};
template<class NdT>
void dumpNd(const string &h,const NdT &fd,const args &p=args(),ostream &os=cerr){}
};
using dumpstring::stringf; using dumpstring::stringfx;
using dumpstring::args; using dumpstring::dumpNd;

#endif//テンプレートend


template<class T> struct Vector: vector<T>{
  using Int = long long;
  using vT=vector<T>;
  using cvT=const vector<T>;
  using cT=const T;
  using vT::vT; //親クラスのコンストラクタの隠蔽を回避
  using vT::begin,vT::end,vT::insert,vT::erase;
  auto it(Int i){ return begin()+i; }
  auto it(Int i)const{ return begin()+i; }
  Vector(cvT& b):vT(b){}
  Vector(vT&& b):vT(move(b)){}
  Vector(int n,cT& x):vT(n,x){}// ┬ 型推論のためラッパー
  Vector(long long n,cT& x):vT(n,x){}
  template<class S> Vector(const Vector<S>& b):vT(b.begin(),b.end()){}
  template<class S> Vector(const vector<S>& b):vT(b.begin(),b.end()){}
  Vector(Int n,T s,T d){ iota(n,s,d); }
  Vector(Int n,function<T(Int)> g):vT(n){ for(Int i=0;i<n;++i) (*this)[i]=g(i); }
  Vector &operator+=(cvT &b){ assert(size()==b.size()); for(Int i=0;i<size();++i) (*this)[i]+=b[i]; return *this; }
  Vector &operator-=(cvT &b){ assert(size()==b.size()); for(Int i=0;i<size();++i) (*this)[i]-=b[i]; return *this; }
  Vector &operator*=(cvT &b){ assert(size()==b.size()); for(Int i=0;i<size();++i) (*this)[i]*=b[i]; return *this; }
  Vector &operator/=(cvT &b){ assert(size()==b.size()); for(Int i=0;i<size();++i) (*this)[i]/=b[i]; return *this; }
  Vector &operator%=(cvT &b){ assert(size()==b.size()); for(Int i=0;i<size();++i) (*this)[i]%=b[i]; return *this; }
  Vector &operator+=(const Vector<T> &b){ return *this+=(cvT&)b; }
  Vector &operator-=(const Vector<T> &b){ return *this-=(cvT&)b; }
  Vector &operator*=(const Vector<T> &b){ return *this*=(cvT&)b; }
  Vector &operator/=(const Vector<T> &b){ return *this/=(cvT&)b; }
  Vector &operator%=(const Vector<T> &b){ return *this%=(cvT&)b; }
  Vector operator+(cvT &b){ return Vector(*this)+=b; }
  Vector operator-(cvT &b){ return Vector(*this)-=b; }
  Vector operator*(cvT &b){ return Vector(*this)*=b; }
  Vector operator/(cvT &b){ return Vector(*this)/=b; }
  Vector operator%(cvT &b){ return Vector(*this)%=b; }
  Vector operator+(const Vector<T> &b){ return Vector(*this)+=b; }
  Vector operator-(const Vector<T> &b){ return Vector(*this)-=b; }
  Vector operator*(const Vector<T> &b){ return Vector(*this)*=b; }
  Vector operator/(const Vector<T> &b){ return Vector(*this)/=b; }
  Vector operator%(const Vector<T> &b){ return Vector(*this)%=b; }
  template<class S> Vector &operator+=(S x){ for(T &e: *this) e+=x;  return *this; }
  template<class S> Vector &operator-=(S x){ for(T &e: *this) e-=x;  return *this; }
  template<class S> Vector &operator*=(S x){ for(T &e: *this) e*=x;  return *this; }
  template<class S> Vector &operator/=(S x){ for(T &e: *this) e/=x;  return *this; }
  template<class S> Vector &operator%=(S x){ for(T &e: *this) e%=x;  return *this; }
  template<class S> Vector operator+(S x)const{ return Vector(*this)+=x; }
  template<class S> Vector operator-(S x)const{ return Vector(*this)-=x; }
  template<class S> Vector operator*(S x)const{ return Vector(*this)*=x; }
  template<class S> Vector operator/(S x)const{ return Vector(*this)/=x; }
  template<class S> Vector operator%(S x)const{ return Vector(*this)%=x; }
  Vector &operator--(int){ return *this-=1; }
  Vector &operator++(int){ return *this+=1; }
  Vector operator-()const{ return Vector(*this)*=-1; }
  template<class S> friend Vector operator-(S x,const Vector &a){ return -a+=x; }
  T& at(Int i){ assert(i>=0); if(n()<=i)vT::resize(i+1); return vT::operator[](i); }
  Vector slice(Int l,Int r,Int d=1)const{
    Vector ret;
    for(Int i=l;(d>0&&i<=r)||(d<0&&r<=i);i+=d) ret.push_back((*this)[i]);
    return ret;
  }
  Int size()const{ return (Int)vT::size(); }
  Int n()const{ return size(); }
  Vector &push_back(cT& x,Int n=1){ for(Int i=0;i<n;++i){ vT::push_back(x); } return *this; }
  Vector &pop_back(Int n=1){ for(Int i=0;i<n;++i){ vT::pop_back(); } return *this; }
  Vector &push_front(cT& x,Int n=1){ this->insert(0,x,n); return *this; }
  Vector &pop_front(Int n=1){ erase(0,n-1); return *this; }
  T pull_back(){ T x=move(vT::back()); vT::pop_back(); return x; }
  T pull_front(){ T x=move(vT::front()); erase(0); return x; }
  Vector &insert(Int i,cT& x,Int n=1){ insert(it(i),n,x); return *this; }
  Vector &insert(Int i,cvT& b){ insert(it(i),b.begin(),b.end()); return *this; }
  Vector &erase(Int i){ erase(it(i)); return *this; }
  Vector &erase(Int l,Int r){ erase(it(l),it(r+1)); return *this; }
  Vector &erase(const Vector<Int> &idxs){
      for (Int I=0; I<idxs.n(); ++I){
          Int l=idxs[I]+1, r = (I<idxs.n()-1) ? idxs[I+1] : this->n();
          copy(it(l),it(r),it(l-I-1));//[l,r)を前にI+1個ずらす
      }
      vT::resize(this->n()-idxs.n());
      return *this;
  }
  Vector &eraseall(cT& x){ return eraseall(0,size()-1,x); }
  Vector &eraseall(Int l,Int r,cT& x){ erase(remove(it(l),it(r+1),x),it(r+1)); return *this; }
  template<class Pr> Vector &eraseif(Pr pr){ return eraseif(0,size()-1,pr); }
  template<class Pr> Vector &eraseif(Int l,Int r,Pr pr){ erase(remove_if(it(l),it(r+1),pr),it(r+1)); return *this; }
  Vector &concat(cvT &b,Int n=1){
    cvT B = (&b==this) ? *this : vT{};
    for(int i=0;i<n;++i) this->insert(size(),(&b==this)?B:b);
    return *this;
  }
  Vector repeat(Int n){ return Vector{}.concat(*this,n); }
  Vector &reverse(Int l=0,Int r=-1){ r+=r<0?size():0; std::reverse(it(l),it(r+1)); return *this; }
  Vector &rotate(Int m){ return rotate(0,size()-1,m); }
  Vector &rotate(Int l,Int r,Int m){ std::rotate(it(l),it(m),it(r+1)); return *this; }
  Vector &sort(Int l=0,Int r=-1){ r+=r<0?size():0; std::sort(it(l),it(r+1)); return *this; }
  Vector &rsort(Int l=0,Int r=-1){ return sort(l,r).reverse(l,r); }
  template<class Pr> Vector &sort(Pr pr){ return sort(0,size()-1,pr); }
  template<class Pr> Vector &sort(Int l,Int r,Pr pr){ std::sort(it(l),it(r+1),pr); return *this; }
  template<int key> Vector &sortbykey(Int l=0,Int r=-1){
    r+=r<0?size():0;
    sort(l,r,[](cT &x,cT &y){return get<key>(x)<get<key>(y);});
    return *this;
  }
  Vector &uniq(){ erase(unique(begin(),end()),end()); return *this; }
  Vector &sortq(){ return sort().uniq(); }
  Vector &fill(cT& x){ return fill(0,size()-1,x); }
  Vector &fill(Int l,Int r,cT& x){ std::fill(it(l),it(r+1),x); return *this; }
  Vector &copy(Int i,cvT &b,Int n=1){//A[i]スタートでbをn回分コピー
      for (int t=0; t<n; ++t) for (int j=0; j<(int)b.size(); ++j){
          if (i>=size()) return *this;
          if (i>=0) (*this)[i]=b[j];
          i++;
      }
      return *this;
  }
  template<class S=Int> Vector &iota(Int n,T s=0,S d=1){
    vT::resize(n);
    if(n==0) return *this;
    (*this)[0]=s;
    for(int i=1;i<n;++i) (*this)[i]=(*this)[i-1]+d;
    return *this;
  }
  Int count(cT& x)const{ return count(0,size()-1,x); }
  Int count(Int l,Int r,cT& x)const{ return Int(std::count(it(l),it(r+1),x)); }
  template<class Pr> Int countif(Pr pr)const{ return countif(0,size()-1,pr); }
  template<class Pr> Int countif(Int l,Int r,Pr pr)const{ return Int(count_if(it(l),it(r+1),pr)); }
  Int find(cT& x)const{ return find(0,size()-1,x); }
  Int find(Int l,Int r,cT& x)const{ return Int(std::find(it(l),it(r+1),x)-begin()); }
  Int rfind(cT& x)const{ return rfind(0,size()-1,x); }
  Int rfind(Int l,Int r,cT& x)const{
      for (int i=r;i>=l;--i) if ((*this)[i]==x) return i;
      return l-1;
  }
  template<class Pr> Int findif(Pr pr)const{ return findif(0,size()-1,pr); }
  template<class Pr> Int findif(Int l,Int r,Pr pr)const{ return Int(find_if(it(l),it(r+1),pr)-begin()); }
  Vector<Int> findall(cT& x)const{ return findall(0,size()-1,x); }
  Vector<Int> findall(Int l,Int r,cT& x)const{ return findallif(l,r,[&](cT& y){return y==x;}); }
  template<class Pr> Vector<Int> findallif(Pr pr)const{ return findallif(0,size()-1,pr); }
  template<class Pr> Vector<Int> findallif(Int l,Int r,Pr pr)const{
    Vector<Int> ret;
    for(Int i=l;i<=r;++i) if(pr((*this)[i])) ret.push_back(i);
    return ret;
  }
  Int  flooridx(cT& x)const{ return Int(upper_bound(begin(),end(),x)-begin()-1); }
  Int   ceilidx(cT& x)const{ return Int(lower_bound(begin(),end(),x)-begin()); }
  Int  leftnmof(cT& x)const{ return flooridx(x)+1; }
  Int rightnmof(cT& x)const{ return size()-ceilidx(x); }
  bool contains(cT& x)const{ Int i=flooridx(x); return i>=0 && (*this)[i]==x; }
  template<class Pr> Int  flooridx(cT& x,Pr pr)const{ return Int(upper_bound(begin(),end(),x,pr)-begin()-1); }
  template<class Pr> Int   ceilidx(cT& x,Pr pr)const{ return Int(lower_bound(begin(),end(),x,pr)-begin()); }
  template<class Pr> Int  leftnmof(cT& x,Pr pr)const{ return flooridx(x,pr)+1; }
  template<class Pr> Int rightnmof(cT& x,Pr pr)const{ return size()-ceilidx(x,pr); }
  template<class Pr> bool contains(cT& x,Pr pr)const{ Int i=flooridx(x,pr); return i>=0 && (*this)[i]==x; }

  template<class S> using VV    = Vector<Vector<S>>; template<class S> using sVV    = vector<vector<S>>;
  template<class S> using VVV   = Vector<VV<S>>;     template<class S> using sVVV   = vector<sVV<S>>;
  template<class S> using VVVV  = Vector<VVV<S>>;    template<class S> using sVVVV  = vector<sVVV<S>>;
  template<class S> using VVVVV = Vector<VVVV<S>>;   template<class S> using sVVVVV = vector<sVVVV<S>>;
  auto tostd()const{ return tov(*this); }
  template <class S> static vector<S> tov(const Vector<S>&v){ return v; }
  template <class S> static sVV<S>    tov(const VV<S>    &v){ sVV<S>    ret; for(auto&& e:v) ret.push_back(e);         return ret; }
  template <class S> static sVVV<S>   tov(const VVV<S>   &v){ sVVV<S>   ret; for(auto&& e:v) ret.push_back(e.tostd()); return ret; }
  template <class S> static sVVVV<S>  tov(const VVVV<S>  &v){ sVVVV<S>  ret; for(auto&& e:v) ret.push_back(e.tostd()); return ret; }
  template <class S> static sVVVVV<S> tov(const VVVVV<S> &v){ sVVVVV<S> ret; for(auto&& e:v) ret.push_back(e.tostd()); return ret; }
};
/*
vll a={9,8,7},b={1,2,3};
vpll p={{5,3},{7,8},{0,2},};
- -------- 操作系 --------
a+=x a-=x a*=x a/=x a%=x a+x a-x a*x a/x a%x -a x-a a++ a--  //∀i a[i]にxを演算
a+=b a-=b a*=b a/=b a%=b a+b a-b a*b a/b a%b  //要素毎演算(同サイズ時)
a.at(i)=x;         //a[i]=x,未確保ならresize
a.push_front(x,n); //n個先頭追加 省略時1
a.push_back(x,n);  //n個末尾追加 省略時1
a.pop_front(n);    //n個先頭削除 省略時1
a.pop_back(n);     //n個末尾削除 省略時1
ll x=a.pull_front(); //pop_front()と同時に値取得
ll x=a.pull_back();  //pop_back()と同時に値取得
a.insert(i,x,n); //a[i]にn個x挿入  n省略時1
a.insert(i,b);   //a[i]にvll b挿入
a.erase(i);      //a[i]削除
a.erase(l,r);    //区間[l,r]削除
a.erase(idxs.sortq()); //a[i0],a[i1],…を削除 idxsはソート&ユニーク必要
a.eraseall(x);     //xを全て削除
a.eraseall(l,r,x); //区間[l,r]のxを全て削除
a.eraseif(pr);     //条件prを満たす要素を全て削除
a.eraseif(l,r,pr); //区間[l,r]の 条件prを満たす要素を全て削除
a.concat(b);     //aにbを結合 b=a可
a.concat(b,n);   //aにbをn回結合 b=a可
a.reverse(l,r);  //[l,r]を反転       l,r省略可
a.rotate(m);     //a[m]を先頭にするrotate
a.rotate(l,r,m); //a[m]を先頭にするrotate 範囲[l,r]
a.sort(l,r);     //[l,r]をソート     l,r省略可
a.rsort(l,r);    //[l,r]を逆順ソート l,r省略可
p.sort(l,r,[&](pll x,pll y){return x.second<y.second;});//比較関数指定sort l,r省略可
a.uniq();      //連続同値を1つにする
a.sortq();     //ソートしてユニーク
a.fill(l,r,x); //[l,r]にx代入        l,r省略可
a.copy(i,b);   //bを   コピー、a[i:i+b.size()]へ   i負可、はみ出す分無視
a.copy(i,b,n); //bをn回コピー、a[i,i+b.size()*n]へ i負可、はみ出す分無視
a.iota(n,s,d); //aを等差数列にする 長さn,初項s,公差d
vll a(n,s,d);  //コンストラクタ版iota
vll b=a.slice(st,en,d); //a[st:en:d]   d省略時1
vll b=a.repeat(n);   //aをn回繰り返す
- -------- 検索系 --------
auto pr=[&](auto &x){ return x>0; };  //検索条件
ll m=a.count(x);     //xの個数
ll m=a.count(l,r,x); //xの個数in[l,r]
ll m=a.countif(pr);     //条件満たす個数
ll m=a.countif(l,r,pr); //条件満たす個数in[l,r]
ll i=a.find(x);         //xの最左位置i         ない時N(配列長)
ll i=a.find(l,r,x);     //xの最左位置i in[l,r] ない時r+1
ll i=a.findif(pr);      //条件満たす最左位置i         ない時N(配列長)
ll i=a.findif(l,r,pr);  //条件満たす最左位置i in[l,r] ない時r+1
vll is=a.findall(x);        //xの位置i列挙
vll is=a.findall(l,r,x);    //xの位置i列挙in[l,r]
vll is=a.findallif(pr);     //条件満たす位置i列挙
vll is=a.findallif(l,r,pr); //条件満たす位置i列挙in[l,r]
- -------- 昇順sort済み配列用 --------
ll i=a.flooridx(x);   //x以下の最近傍位置i ない時-1
ll i=a.ceilidx(x);    //x以上の最近傍位置i ない時N(配列長)
ll m=a.leftnmof(x);   //x以下の個数
ll m=a.rightnmof(x);  //x以上の個数
bool b=a.contains(x); //xを含む
- -------- 比較関数prでsort済みの配列用 --------
auto pr=[&](auto &x,auto &y){ return x>y; }; //降順ソート時
ll i=a.flooridx(x,pr);   //x以左の最近傍位置i ない時-1
ll i=a.ceilidx(x,pr);    //x以右の最近傍位置i ない時N(配列長)
ll m=a.leftnmof(x,pr);   //x以左の個数
ll m=a.rightnmof(x,pr);  //x以右の個数
bool b=a.contains(x,pr); //xを含む

a.concat(b,n).pop_back().rsort().uniq();  //連続適用できる
auto aa=a.tostd(); //N次元VectorをN次元vectorに変換(N≦5)
*/


template<class T> struct wrapv: Vector<T>{
    using Int = long long;
    T def=T();
    T defIF=T();
    wrapv(const Vector<T> &b):Vector<T>(b){}
    wrapv(Vector<T> &&b):Vector<T>(move(b)){}
    wrapv(const std::vector<T> &b):Vector<T>(b){}
    wrapv(std::vector<T> &&b):Vector<T>(move(b)){}
    T &operator[](Int i){
        return (i<0 || this->size()<=i) ? (defIF=def) : Vector<T>::operator[](i);
    }
    void setdef(const T& x){ def=x; }
};
/*
wrapv v=vll(N,0,1); //vllなどでコンストラクトしてから代入する
v.setdef(INF); //範囲外での値セット
*/



#if 0
#define MODLL (1000000007LL)
#else
#define MODLL (998244353LL)
#endif
using mll = mll_<MODLL>;
//using mll = fraction;

//　１
//０┼２
//　３                   左     上     右    下
//const vector<pll> dxys={{0,-1},{-1,0},{0,1},{1,0},};
const string lurd="LURD";



namespace SolvingSpace{

template<class T> using vector = Vector<T>;
using    vll=vector<   ll>; using    vmll=vector<   mll>; using    vdd=vector<   dd>;
using   vvll=vector<  vll>; using   vvmll=vector<  vmll>; using   vvdd=vector<  vdd>;
using  vvvll=vector< vvll>; using  vvvmll=vector< vvmll>; using  vvvdd=vector< vvdd>;
using vvvvll=vector<vvvll>; using vvvvmll=vector<vvvmll>; using vvvvdd=vector<vvvdd>;
using   vpll=vector<  pll>; using    vtll=vector<   tll>; using   vqll=vector<  qll>;
using  vvpll=vector< vpll>; using   vvtll=vector<  vtll>; using  vvqll=vector< vqll>;
using   vll2=vector<  ll2>; using    vll3=vector<   ll3>; using   vll4=vector<  ll4>;
using  vvll2=vector< vll2>; using   vvll3=vector<  vll3>; using  vvll4=vector< vll4>;
using vvvll2=vector<vvll2>; using  vvvll3=vector< vvll3>; using vvvll4=vector<vvll4>;
using vss=vector<string>;
template<class T> vector<T> cinv(ll nm){ return vector<T>(nm,[](ll i){ (void)i; return cin1<T>(); }); }
template<class T> vector<vector<T>> cinvv(ll H,ll W){ return vector<vector<T>>(H,[&](ll i){ (void)i; return cinv<T>(W); }); }

/*■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■
■■■■■■■■■■■■■■■*/



template<class T,int DIM> struct cumulativesumNd{
    using Int = long long;
    using NInt = array<Int,DIM>;
    using ll = long long;
    NInt lv; //各変数のサイズ {xl,yl,…}
    vector<T> cm;
    vector<int> grayDiff; //grayDiff[i]:Grayコードのi-1とiの、idでの差分
    vector<int> grayAxis; //grayAxis[i]:↑で変化する軸番号(0-origin)
    template<class RNG>
    cumulativesumNd(const RNG& rng):lv(rng.ls()){ init(); }
    cumulativesumNd(NInt lv_):lv(lv_){ init(); }
    cumulativesumNd(const vector<T> &fd):lv({(Int)fd.size()}){
        init();
        for (ll i=0; i<lv[0]; ++i) add({i},fd[i]);
    }
    cumulativesumNd(const vector<vector<T>> &fd){
        lv={(Int)fd.size(),(Int)fd[0].size()};
        init();
        for (ll i=0; i<lv[0]; ++i) for (ll j=0; j<lv[1]; ++j) add({i,j},fd[i][j]);
    }
    cumulativesumNd(const vector<vector<vector<T>>> &fd){
        lv={(Int)fd.size(),(Int)fd[0].size(),(Int)fd[0][0].size()};
        init();
        for (ll i=0; i<lv[0]; ++i) for (ll j=0; j<lv[1]; ++j) for (ll k=0; k<lv[2]; ++k)
            add({i,j,k},fd[i][j][k]);
    }
    cumulativesumNd(const vector<vector<vector<vector<T>>>> &fd){
        lv={(Int)fd.size(),(Int)fd[0].size(),(Int)fd[0][0].size(),(Int)fd[0][0][0].size()};
        init();
        for (ll i=0; i<lv[0]; ++i) for (ll j=0; j<lv[1]; ++j) for (ll k=0; k<lv[2]; ++k)
            for (ll l=0; l<lv[3]; ++l) add({i,j,k,l},fd[i][j][k][l]);
    }
    cumulativesumNd(const vector<vector<vector<vector<vector<vector<T>>>>>> &fd){
        lv={
            (Int)fd.size(),
            (Int)fd[0].size(),
            (Int)fd[0][0].size(),
            (Int)fd[0][0][0].size(),
            (Int)fd[0][0][0][0].size(),
            (Int)fd[0][0][0][0][0].size()
        };
        init();
        for (ll i=0; i<lv[0]; ++i)
            for (ll j=0; j<lv[1]; ++j)
                for (ll k=0; k<lv[2]; ++k)
                    for (ll l=0; l<lv[3]; ++l)
                        for (ll m=0; m<lv[4]; ++m)
                            for (ll n=0; n<lv[5]; ++n)
                                add({i,j,k,l,m,n},fd[i][j][k][l][m][n]);
    }
    template<class RNG>
    void add(const NInt &vx_,T x,const RNG &rng){ add(rng.v2i(vx_),x); }
    void add(const NInt &vx_,T x){//vxにxを追加
        NInt vx=vx_;
        for (ll i=0; i<DIM; ++i) vx[i]++;
        int id=toID(vx);
        T &cmid=(cm[id]=x);
        for (ll i=0,sg=1; i<(ll)grayDiff.size(); ++i,sg=-sg){
            id-=grayDiff[i];
            cmid+=cm[id]*sg;
        }
    }
    template<class RNG>
    T operator()(const NInt &svx,const NInt &evx,const RNG &rng){
        return (*this)(rng.v2i(svx),rng.v2i(evx));
    }
    T operator()(const NInt &svx_,const NInt &evx_){//指定範囲の和
        NInt svx=svx_,evx=evx_;
        for (ll i=0; i<DIM; ++i) evx[i]++;
        Clamp(svx),Clamp(evx);
        int id=toID(evx);
        T ret=cm[id];
        for (ll i=0,sg=-1; i<(ll)grayDiff.size(); ++i,sg=-sg){
            int df=grayDiff[i],ax=grayAxis[i];
            id-=df*int(evx[ax]-svx[ax]);
            ret+=cm[id]*sg;
        }
        return ret;
    }
private:
    void init(){
        ll size=accumulate(lv.begin(),lv.end(),1ll,[](ll acc,ll l){return acc*(l+1); });
        cm.assign(size,T(0));
        GenerateGray();
    }
    void Clamp(NInt &vx){
        for (ll i=0; i<DIM; ++i) vx[i]=clamp(vx[i],Int(0),lv[i]);
    }
    int toID(const NInt &vx){
        int id=0;
        for (ll i=0; i<DIM; ++i){
            int x=(int)vx[i],l=(int)lv[i]+1;
            assert(0<=x && x<l);
            id=id*l+x;
        }
        return id;
    }
    void GenerateGray(){//grayAxis,grayDiff計算
        vector<ll> keta(DIM);//keta[i]:IDでの第i軸の値  例:{100,10,1}
        for (ll i=DIM-1,x=1; i>=0; --i) keta[i]=x,x*=lv[i]+1;
        for (ll i=1; i<1LL<<DIM; ++i){
            ll cg=i^(i>>1);        //Grayコードでのi
            ll pg=(i-1)^((i-1)>>1);//Grayコードでのi-1
            ll ax=DIM-1-lsbit(cg^pg);//変化する軸番号
            ll df=keta[ax];
            if (pg>cg) df=-df;
            grayAxis.push_back((int)ax);
            grayDiff.push_back((int)df);
        }
    }
    ll lsbit(ll x){ //x=0は不可
        ll ret=0;
        while (!(x&1)) x>>=1,ret++;
        return ret;
    }
};
template<class T> cumulativesumNd(vector<vector<vector<vector<T>>>>) -> cumulativesumNd<T,4>;
template<class T> cumulativesumNd(vector<vector<vector<T>>>) -> cumulativesumNd<T,3>;
template<class T> cumulativesumNd(vector<vector<T>>) -> cumulativesumNd<T,2>;
template<class T> cumulativesumNd(vector<T>) -> cumulativesumNd<T,1>;
/*
- ---- 既存のN次元配列から構成  fdは4次元vectorまで可
cumulativesumNd cm(fd);
- ---- 範囲のみ指定、値は後から追加  rangeNdかarrayで指定
cumulativesumNd<ll,2> cm(rng);
cumulativesumNd<ll,2> cm(array<ll,2>{H,W});
- ---- 値を追加  rng指定すると添字を0-originに修正してからアクセス
cm.add({i,j},x);
cm.add({i,j},x,rng);
- ---- 和を取得  rng指定すると添字を0-originに修正してからアクセス
ll sm=cm({si,sj},{ei,ej});
ll sm=cm({si,sj},{ei,ej},rng);
*/



namespace baseNspace {
using Int = long long;
using ll = long long;
vector<Int> to_vector(ll x,bool rev = false,ll d = 10,ll k = 0) {
    vector<Int> dgs;
    for (; x > 0; x /= d) dgs.push_back(Int(x % d));
    if ((ll)dgs.size() < k) dgs.resize(k,0);       // 上位桁側を 0 埋め
    if (!rev) reverse(dgs.begin(),dgs.end());      // rev=false のときだけ反転
    return dgs;
}
ll vtoll(const vector<Int>& v,ll d = 10) {
    ll x = 0;
    for (Int dg : v) x = x * d + dg;
    return x;
};
string v_to_string(const vector<Int>& v,bool empty_0=true) {
    if (empty_0 && v.empty()) return "0";
    string s;
    for (auto&& e : v) s += e < 10 ? char(e + '0') : char(e - 10 + 'A');
    return s;
}
vector<Int> s_to_vector(const string& s) {
    vector<Int> dgs;
    if (s == "0") return dgs;
    for (auto&& c : s) dgs.push_back(c <= '9' ? Int(c - '0') : Int(c - 'A') + 10);
    return dgs;
}
string to_string(ll x,bool rev,ll d,ll k = 1) { // overload
    return v_to_string(to_vector(x,rev,d,k),false);
}

template<ll d> struct basen {
    ll x = 0;
    basen() {}
    basen(ll x): x(x) {}
    basen(int x): x(x) {}
    basen(const char* s) { fromString(s); }
    basen(const string& s) { fromString(s); }
    Int operator[](Int i)const {
        ll y = valid(i + 1) ? x % bases[i + 1] : x;
        return valid(i) ? Int(y / bases[i]) : Int(0);
    }
    operator Int()const { return Int(x); }
    basen operator++(int) { basen b(*this); x++; return b; }
    basen operator--(int) { basen b(*this); x--; return b; }
    basen& operator+=(Int b) { x += b; return *this; }
    basen& operator-=(Int b) { x -= b; return *this; }
    basen operator+(ll b)const { return x + b; }
    basen operator-(ll b)const { return x - b; }
    basen operator+(int b)const { return x + b; }
    basen operator-(int b)const { return x - b; }
    basen operator+(const basen& b)const { return x + b.x; }
    basen operator-(const basen& b)const { return x - b.x; }
    basen& seteq(Int i,Int dg) { assert(valid(i)); return addeq(i,dg - (*this)[i]); }
    basen& addeq(Int i,Int dg) { assert(valid(i)); x += dg * bases[i]; return *this; }
    [[nodiscard]] basen set(Int i,Int dg)const { return basen(*this).seteq(i,dg); }
    [[nodiscard]] basen add(Int i,Int dg)const { return basen(*this).addeq(i,dg); }
    static void setbase(const vector<Int>& v) {
        bases = {1};
        for (auto&& x : v) bases.push_back(bases.back() * x);
    }
    static Int size() { return (Int)bases.back(); }
    static Int size(ll n) { return (Int)bases[n]; }
    Int ndigits()const {//桁数
        for (Int ng = -1,ok = (Int)bases.size();;) {
            Int m = (ng + ok) / 2;
            if (bases[m] > x) ok = m; else ng = m;
            if (ok - ng == 1) return ok;
        }
    }
    string to_string(Int wd = -1)const {
        wd = max({wd,ndigits(),1LL});
        string ret;
        for (ll i = wd - 1; i >= 0; --i) ret += '0' + char((*this)[i]);
        return ret;
    }
private:
    static vector<ll> setbaseD() {
        vector<ll> ret{1};
        if (d >= 2) while (ret.back() <= LLONG_MAX / d) ret.push_back(ret.back() * d);
        return ret;
    }
    bool valid(Int i)const { return i < (Int)bases.size(); }
    void fromString(const string& s) {
        ll N = (ll)s.size();
        for (ll i = 0; i < N; ++i) addeq(i,s[N - 1 - i] - '0');
    }
    static inline vector<ll> bases = setbaseD();
};
}
using baseNspace::to_vector; using baseNspace::v_to_string; using baseNspace::vtoll;
using baseNspace::to_string; using baseNspace::s_to_vector;
using std::to_string;
using baseNspace::basen;
/*
- ******************** ll・vll・string d進法変換ライブラリ ********************
ll:常に10進、string,vll:d進法 として変換
ll 3041 ⇔ vll {3,0,4,1} ⇔ string "3041" (10進法)
ll 0    ⇔ vll {}        ⇔ string "0"    (10進法)
ll 12   ⇔ vll {1,1,0,0} ⇔ string "1100" (2進法)
ll 46   ⇔ vll {2,14}    ⇔ string "2E"   (16進法)

- ===========================
- ======== ll ⇔ vll ========

- ---- ll → vll ----
vll dgs=to_vector(x);
vll dgs=to_vector(x,true,d,k);
.       true:reverse ┘ ↑ └ k桁未満なら上位桁0埋め 省略時0
.       省略時false     └ d進法 省略時10
- ---- vll → ll ----
ll x=vtoll(dgs);
ll x=vtoll(dgs,d);
.              ↑d進法 省略時10

- ===============================
- ======== string ⇔ vll ========

- ---- string → vll ----
vll dgs=s_to_vector(s);

- ---- vll → string ----
string s=v_to_string(dgs);

- ==============================
- ======== ll ⇔ string ========

- ---- ll → string ----   std::to_stringのoverload
string s=to_string(x);
string s=to_string(x,true,d,k);
.        true:reverse ┘ ↑ └ k桁未満なら上位桁0埋め 省略時0
.             省略NG     └ d進法 省略NG
.※引数1つならstd::to_stringが呼ばれ、3つ以上ならオーバーロードが呼ばれる

- ---- string → ll ----   std::stoll使う
ll x=stoll(s);
ll x=stoll(s,nullptr,d);
.                    ↑d進法

- ******************* llのままd進法各桁を操作するライブラリ *******************
- -------- 定義 --------
using base=basen<d>;   //d進法のとき
using base=basen<-1>;  //┬各桁別進法のとき
base::setbase(v);      //┘    第i桁の範囲が[0,v[i])になる
base b=x;     //整数から
base b="101"; //文字列から
- -------- 操作 --------
ll dg=base(x)[i];  //xの第i桁
ll u=base::size(); //取り得る値の上限 [0,n)  v={2,3,2}ならu=2*3*2=12 各桁別進法のみ
ll u=base::size(N);//N桁の上限 [0,u)  d進法,各桁別進法両用
base b=x;
ll n=b.ndigits(); //桁数 201(3)なら3
b.seteq(i,dg); //第i桁dgに変更
b.addeq(i,dg); //第i桁にdg加算
base bb=b.set(i,dg);    //第i桁dgに変更したもの返す
base bb=b.add(i,dg);    //第i桁にdg加算したもの返す
ll y=base(x).set(i,dg); //llのまま扱うことも可能(キャストで実現)
b+=x b-=x b++ b--
b+x b-x      //base型を返す
(b==x b!=x)  //llへのcastを経由し可能
string s=b.to_string();  //文字列出力
string s=b.to_string(6); //文字列出力 桁数指定(0埋め)
*/

using base=basen<10>;   //d進法のとき

void cin2solve()
{
    auto N=cin1<ll>();
    auto sv=cinv<pair<ll,ll>>(N);
    auto Q=cin1<ll>();
    auto xy=cinv<pair<ll,ll>>(Q);

    ll M=1000000;
    using  vvvvvll=vector< vvvvll>;
    using vvvvvvll=vector<vvvvvll>;
    vvvvvvll fd(10,vvvvvll(10,vvvvll(10,vvvll(10,vvll(10,vll(10))))));
    for (auto&&[s,v]:sv){
        base b=s;
        fd[b[0]][b[1]][b[2]][b[3]][b[4]][b[5]]+=v;
    }
    cumulativesumNd<ll,6> cm(fd);

    for (auto&&[x,y]:xy){
        base bx=x;
        base by=y;
        {//ngチェック
            bool isok=true;
            rep(ke,0,5){
                if (bx[ke]>by[ke]) isok=false;
            }
            if (!isok){
                cout << 0 << '\n'; continue;
            }
        }
        ll sm=cm({bx[0],bx[1],bx[2],bx[3],bx[4],bx[5]},{by[0],by[1],by[2],by[3],by[4],by[5]});
        cout << sm << '\n';
    }


#if 0

    //zeta変換
    rep(ke,0,5){
        rep(id,0,M-1){
                //第ke桁を1増やしたところに足す
                base b=id;
                if (b[ke]==9)continue;
                fd[base(id).add(ke,1)]+=fd[id];
        }
    }
    //rep(id,0,M-1){
    //    rep(ke,0,5){
    //        //第ke桁を1増やしたところに足す
    //        base b=id;
    //        if (b[ke]==9)continue;
    //        fd[base(id).add(ke,1)]+=fd[id];
    //    }
    //}

    auto powm1=[](ll n){ return 1-2*(n&1); }; //(-1)^n  


    for (auto&&[x,y]:xy){
        {//ngチェック
            base bx=x;
            base by=y;
            bool isok=true;
            rep(ke,0,5){
                if (bx[ke]>by[ke]) isok=false;
            }
            if (!isok){
                cout << 0 << '\n'; continue;
            }
        }

        ll sm=0;
        for (bll s=0; s[6]==0; s++){
            //bitが1 なら x側を取る  -1 する
            
            //bに、yとxのつぎはぎが入る
            ll va=0;
            {
                bool isng=false;
                base bx=x;
                base b=y;
                rep(ke,0,5){
                    if (s[ke]==1){
                        ll dgx=bx[ke]-1;
                        if (dgx<0){
                            isng=true;
                            break;
                        }
                        b=b.set(ke,dgx);
                    }
                }
                if (isng){
                    va=0;
                }
                else{
                    va=fd[b];
                }
            }

            sm+= powm1(s.count())*va;
        }
        cout << sm << '\n';
    }
#endif
    return;
}

}//SolvingSpace

//////////////////////////////////////////

int main(){
#if defined(RANDOM_TEST)
    SolvingSpace::cin2solve();
    SolvingSpace::generand();
#else
  #if 1
    //SolvingSpace::labo();
    SolvingSpace::cin2solve();
  #else
    ll t;  cin >> t;
    rep(i,0,t-1){
        SolvingSpace::cin2solve();
    }
  #endif
#endif
    cerr << timeget() <<"ms"<< '\n';
    return 0;
}
