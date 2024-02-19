#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

template <typename T> 
vector<T> func(auto f) {
  vector<T> ret;
  ret.push_back(f());
  return ret;
}


int main() {
  auto g = [&]() -> pair<int, int> { return {0, 0}; };
  auto v = func(g);
  cout << v[0].first << endl;
}




/*
こういう関数を定義しています:

template <typename T> 
vector<T> func(auto f) {
  vector<T> ret;
  ret.push_back(f());
  return ret;
}

これを呼ぶときには，

  auto g = [&]() -> pair<int, int> { return {0, 0}; };
  auto x = func<pair<int, int>>(g);

のように，明示的に func のテンプレートパラメタ T を指定しないとうまくいきません．

  auto x = func(g);

だとエラーになります．T として，「引数 f の戻り値の型」を指定するようにコーディングするには
どうすればよいでしょうか．
*/
