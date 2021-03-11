#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(interactive)
// --> interactive
// ---- inserted library file interactive.cc

const string end_mark("^__=end=__^");

struct SolveExc : exception {};

void do_game(bool is_judge);

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
    do_game(is_judge);
  }catch (const SolveExc& e) {
  }
  return 0;
}

/* 
   Copy and edit the following into the part below END
 */
/*
ll sz;

struct Judge {
  using ask_q_t = ll;
  using ask_a_t = string;
  using answer_t = ll;

  virtual void ask_q(ask_q_t x) = 0;
  virtual ask_a_t ask_a() = 0;
  virtual void answer(answer_t x) = 0;

  void wa() {
    cout << "WA\n";
    exit(1);
  }

  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }
};

struct JudgeLoc : Judge {
  ll expected;
  ll asked;

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> sz >> expected;
  }
  void ask_q(ask_q_t x) {
    asked = x;
  }
  ask_a_t ask_a() {
    return asked == expected ? "EQ" : asked < expected ? "LT" : "GT";
  }
  void answer(answer_t x) {
    // Always call ac() or wa().
    if (x == expected) ac();
    else wa();
  }
};

struct JudgeRem : Judge {
  JudgeRem() {
    // Read initial information, if any.
    cin >> sz;
  }
  void ask_q(ask_q_t x) {
    // Information asking.  Typically prepended by "? " and followed by endl
    cout << "? " << x << endl;
  }
  ask_a_t ask_a() {
    // Responce to the asking
    string rep; cin >> rep;
    return rep;
  }
  void answer(answer_t x) {
    // Final output.  Typically prepended by "! " and followed by endl
    cout << "! " << x << endl;
    // Need to throw SolveExc()
    throw SolveExc();
  }
};

void game(Judge&& judge) {
  ll left = 1;
  ll right = sz;
  while (true) {
    ll mid = (left + right) / 2;
    judge.ask_q(mid);
    string rep = judge.ask_a();
    if (rep == "EQ") judge.answer(mid);
    if (rep == "LT") left = mid;
    if (rep == "GT") right = mid;
  }
}

void do_game(bool is_judge) {
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
}
*/

// ---- end interactive.cc
// @@ !! LIM  -- end mark --

ll n, m, c;

struct Judge {
  using ask_q_t = ll;
  using ask_a_t = ll;
  using answer_t = ll;

  virtual void ask_q(ask_q_t x) = 0;
  virtual ask_a_t ask_a() = 0;
  virtual void answer(answer_t x) = 0;

  void wa() {
    cout << "WA\n";
    exit(1);
  }

  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }
};

struct JudgeLoc : Judge {
  vector<ll> data;
  vector<ll> placed;
  ll idx = 0;

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> n >> m >> c;
    data.resize(m);
    placed.resize(n + 1, -1);
    for (ll i = 0; i < m; i++) cin >> data[i];
  }
  void ask_q(ask_q_t x) {
    placed[x] = data[idx++];
  }
  ask_a_t ask_a() {
    return data[idx];
  }
  void answer(answer_t x) {
    // Always call ac() or wa().
    
    for (ll i = 1; i <= n; i++) {
      if (placed[i] < 0) wa();
      if (i+1 <= n && placed[i] > placed[i+1]) wa();
    }
    ac();
  }
};

struct JudgeRem : Judge {
  JudgeRem() {
    // Read initial information, if any.
    cin >> n >> m >> c;
  }
  void ask_q(ask_q_t x) {
    // Information asking.  Typically prepended by "? " and followed by endl
    cout << x << endl;
  }
  ask_a_t ask_a() {
    // Responce to the asking
    ll rep; cin >> rep;
    return rep;
  }
  void answer(answer_t x) {
    // Final output.  Typically prepended by "! " and followed by endl
    // cout << "! " << x << endl;
    // Need to throw SolveExc()
    throw SolveExc();
  }
};

void game(Judge&& judge) {
  vector<ll> vec(n + 1, -1);
  ll rem = n;
  auto move = [&](ll i, ll x) -> void {
    if (vec[i] < 0) rem--;
    vec[i] = x;
    judge.ask_q(i);
  };
  while (rem > 0) {
    ll x = judge.ask_a();
    if (x <= (c + 1) / 2) {
      ll i = 1;
      for ( ; i <= n && vec[i] >= 0 && vec[i] <= x; i++);
      move(i, x);
    }else {
      ll i = n;
      for ( ; i >= 1 && vec[i] >= 0 && vec[i] >= x; i--);
      move(i, x);
    }
  }
  judge.answer(0);  // 0 is dummy.
}

void do_game(bool is_judge) {
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
}
