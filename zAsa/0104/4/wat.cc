#pragma region watasou
/*
the pen is mightier than the sword.
                        -エドワード・ブルワー＝リットン-
KCLC44TH watasou1543.
*/
#include <bits/stdc++.h>
using namespace std;
//マクロ宣言
#define rep(i, a, b) for (int i = a; i < b; i++)
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
using Graph = vector<vector<ll>>;
using V = vector<ll>;
const ll mod=998244353;
const ll MOD=1000000007;
const ll INF=1000000000000000000;
const string ABC="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string abc="abcdefghijklmnopqrstuvwxyz";
string Y = "Yes";
string N = "No";
#define gcd __gcd
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define fi first
#define se second
#define fix(n) fixed << setprecision(n)
#define print(n) cout << n << endl
#define si size()
#define in(n) insert(n)
//関数宣言
template <typename T>
inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template <typename T>
inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }
ll jou(ll N,ll k){
  ll i=0;
  ll p=N;
  ll Ans=0;
  while(k>=(1<<i)){
    if(k&(1<<i)){
      Ans+=p;
    }
    p*=p;
    i++;
  }
  return Ans;
}
//DFS
map<ll,vector<ll>>Gra;
map<ll,bool>visited;// false=not visited, true=visited
void DFS(int pos){
  visited[pos]=true;
  for(int i : Gra[pos]){
    if(visited[i]==false){
      DFS(i);
    }
  }
}
vector<pair<long long, long long> > pri(long long N) {
    vector<pair<long long, long long> > res;
    for (long long a = 2; a * a <= N; ++a) {
        if (N % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (N % a == 0) {
            ++ex;
            N /= a;
        }

        // その結果を push
        res.push_back({a, ex});
    }

    // 最後に残った数について
    if (N != 1) res.push_back({N, 1});
    return res;
}
const vector<int>dx = {0, 1, 0, -1};
const vector<int>dy = {1, 0, -1, 0};
vector<vector<ll>> BFS(int H, int W, const vector<string> &G, pair<int, int> s) {
    vector<vector<ll>> dist(H, vector<ll>(W, -1));  //すべての頂点を未訪問に初期化
    queue<pair<int, int>> que;

    //初期条件 (頂点sを初期頂点とする)
    dist[s.first][s.second] = 0;
    que.push(s);  // sを探索済み頂点に

    // BFS開始
    while (!que.empty()) {
        pair<int, int> v = que.front();
        que.pop();

        //頂点vからたどれる頂点を全て調べる
        for (int i = 0; i < 4; i++) {
            int X = dx[i] + v.first;
            int Y = dy[i] + v.second;
            if (X < 0 || X >= H || Y < 0 || Y >= W) continue;
            //すでに発見済みの頂点は探索しない
            if (dist[X][Y] != -1 || G[X][Y] == '#') continue;

            //新たな未探索点xについて距離情報を更新してキューに挿入
            dist[X][Y] = dist[v.first][v.second] + 1;
            que.push(make_pair(X, Y));
        }
    }
    return dist;
}
vector<bool>sosuu(long long n){
    vector<bool> isprime(n+1, true);
    // 0, 1 は予めふるい落としておく
    isprime[0] = isprime[1] = false;
    // ふるい
    for (int p = 2; p <= n; ++p) {
        // すでに合成数であるものはスキップする
        if (!isprime[p]) continue;
        // p 以外の p の倍数から素数ラベルを剥奪
        for (int q = p * 2; q <= n; q += p) {
            isprime[q] = false;
        }
    }
    return isprime;
}
//-------------------------------------------------------------------------
#pragma endregion watasou
int main(){
  int n;
  cin >> n;
  vector<string>s(n);
  rep(i,0,n) cin >> s[i];
  map<char,int>mp;
  mp['b']=1;
  mp['c']=1;
  mp['d']=2;
  mp['f']=4;
  mp['g']=9;
  mp['h']=8;
  mp['j']=3;
  mp['k']=8;
  mp['l']=5;
  mp['m']=7;
  mp['n']=9;
  mp['p']=7;
  mp['q']=4;
  mp['r']=0;
  mp['s']=6;
  mp['t']=3;
  mp['v']=5;
  mp['w']=2;
  mp['x']=2;
  mp['z']=0;
  mp['a']=-1;
  mp['i']=-1;
  mp['u']=-1;
  mp['e']=-1;
  mp['o']=-1;
  mp['y']=-1;
  mp['.']=-1;
  mp[',']=-1;
  vector<string>c(0);
  rep(i,0,n){
    string a = "";
    rep(j,0,(int)s[i].size()){
      if (not (('a' <= s[i][j] and s[i][j] <= 'z') or ('A' <= s[i][j] and s[i][j] <= 'Z'))) continue;
      if(mp[s[i][j]]==-1){
        continue;
      }
      else if('a'<=s[i][j]&&s[i][j]<='z'){
        if(mp[s[i][j]]==-1){
          continue;
        }
        else{
          char b = '0';
          b+=mp[s[i][j]];
          a.pb(b);
        }
      }
      else if('A'<=s[i][j]&&s[i][j]<='Z'){
        if(mp[s[i][j]+32]==-1) continue;
        char b = '0';
        b+=mp[s[i][j]+32];
        a.pb(b);
      }
    }
    if(a.size()!=0) c.pb(a);
  }
  rep(i,0,(int)c.size()){
    cout << c[i];
    if(i!=c.size()-1){
      cout << " ";
    }  
  }
  cout << endl;
}
