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

/*
#define simpleEnum(enum_name, val1, val2, val3) ...
*/

enum enum_name { val1, val2, val3 };
ostream& operator<<(ostream& ostr, enum_name e) {
  return ostr << static_cast<int>(e);
}

int main() {
  enum_name e;
  e = val2;
  cout << e << endl;
}


/*

C++ で，マクロ simpleEnum を定義して，

simpleEnum(enum_name, val1, val2, val3) 

と書くと

enum enum_name { val1, val2, val3 };
ostream& operator<<(ostream& ostr, enum_name e) {
  return ostr << (e == val1 ? "val1" : e == val2 ? "val2" : e == val3 ? "val3");
}

のように展開されるようにしたいです．定義できますか? もちろん，引数の数は可変にしたいです．


 */
