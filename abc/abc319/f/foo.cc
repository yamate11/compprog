#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}


template <typename T1, typename T2, typename C>
void func1(const map<T1, T2, C>& mp);

template <typename T>
void func1(const vector<T>& v) {
  for (auto it = v.begin(); it != v.end(); it++) {
    func1(*it);
  }
}

template <typename T1, typename T2, typename C>
void func1(const map<T1, T2, C>& mp) {
  for (auto it = mp.begin(); it != mp.end(); it++) {
    cout << it->second << endl;
  }
}



// using mymap = map<ll, ll, greater<ll>>;
using mymap = map<ll, ll>;

int main(/* int argc, char *argv[] */) {

  vector<mymap> v(5);
  v[0][0] = 0;

  func1(v);

  cout << v[0] << endl;

  return 0;
}
