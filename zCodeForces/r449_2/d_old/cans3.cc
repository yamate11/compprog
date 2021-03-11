#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

ll n, m, c;

// @@ !! LIM(interactive)
// --> interactive
// ---- inserted library file interactive.cc

const string end_mark("^__=end=__^");

struct SolveExc : exception {};

struct Judge;

void solve(Judge& judge);

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  bool is_judge = false;
  if (argc == 2) {
    if (strcmp(argv[1], "judge") == 0) {
      is_judge = true;
    }else if (strcmp(argv[1], "skip") == 0) {
      return 0;
    }else {
      cerr << "Unknown argument\n";
      exit(1);
    }
  }
    
  try {
    Judge judge(is_judge);
    solve(judge);
  }catch (const SolveExc& e) {
  }
  return 0;
}

/* 
   Copy and edit the following into the part below !! END
 */
/*
void solve(Judge& judge) {
  ll left = 1;
  ll right = judge.init();
  while (true) {
    ll mid = (left + right) / 2;
    string rep = judge.ask(mid);
    if (rep == "EQ") judge.answer(mid);
    if (rep == "LT") left = mid;
    if (rep == "GT") right = mid;
  }
}
*/

// ---- end interactive.cc
// @@ !! LIM  -- end mark --

struct Judge {
  bool testing;   // TRUE for local testing, FALSE for real program.
  // You always need the bool member testing.
  // Other members can be freely added.  Mainly for testing purposes.
  vector<ll> call;
  ll cidx;
  vector<ll> placed(n, -1);

  Judge(bool testing_) : testing(testing_), cidx(-1) {
    if (testing) {
      // Typically, the question for testing is read from stdin.
      cin >> n >> m >> c;
      for (ll i = 0; i < m; i++) cin >> call[i];
    }else {
      // Real initial input is to be written here, if any.
      cin >> n >> m >> c;
    }
  }

  void init() {
  }

  string ask(int x) {
    if (testing) {
      if (x < 0) {
        assert(cidx == -1);
      }else {
        assert(cidx >= 0);
        assert(cidx < m);
        placed[x] = call[cidx];
      }
      return call[++cidx];
    }else {
      // Information asking.  Typically prepended by "? " and followed by endl
      if (x >= 0) {
        cout << x << endl;
      }
      ll rep; cin >> rep;
      return rep;
    }
  }

  void answer(int x) {
    if (testing) {
      // Always call ac() or wa().
      assert(cidx >= 0);
      assert(cidx < m);
      placed[x] = call[cidx];
      for (ll i = 0; i < n; i++) {
        if (placed[i] < 0) wa();
        if (i+1 < n && placed[i] > placed[i + 1]) wa();
      }
      ac();
    }else {
      // Final output.  Typically prepended by "! " and followed by endl
      cout << x << endl;
      // Need to throw SolveExc()
      throw SolveExc();
    }
  }

  void wa() {
    cout << "WA\n";
    exit(1);
  }

  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }
};



void solve(Judge& judge) {
  vector<ll> vec(n + 1, -1);
  ll rem = n;

  auto move = [&](ll i, ll x) -> void {
    if (vec[i] < 0) rem--;
    vec[i] = x;
    if (rem > 0) judge.ask(x);
    else judge.answer(x);
  };

  ll x = judge.ask(-1);
  while (true) {
    if (x <= (c + 1) / 2) {
      ll i = 1;
      for (; i <= n && vec[i] >= 0 && vec[i] <= x; i++);
      move(i, x);
    }else {
      ll i = n; 
      for ( ; i >= 1 && vec[i] >= 0 && vec[i] >= x; i--);
      move(i, x);
    }
  }
}

