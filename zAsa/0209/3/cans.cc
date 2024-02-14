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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<char> st;
  string S; cin >> S;
  vector<bool> inbox(26, false);
  for (char c : S) {
    if (c == '(') st.push_back(c);
    else if (c == ')') {
      while (st.back() != '(') {
        ll d = st.back() - 'a'; st.pop_back();
        inbox[d] = false;
      }
      st.pop_back();
    }else {
      ll d = c - 'a';
      if (inbox[d]) {
        cout << "No\n";
        return 0;
      }
      inbox[d] = true;
      st.push_back(c);
    }
  }
  cout << "Yes\n";
  return 0;
}

