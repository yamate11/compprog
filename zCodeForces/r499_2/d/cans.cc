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
*/

// ---- end interactive.cc
// @@ !! LIM  -- end mark --

ll M, N;

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
  ll expected;
  ll asked;

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> M >> N >> expected;
  }
  void ask_q(ask_q_t x) {
    asked = x;
  }
  ask_a_t ask_a() {
    return 0;
    // return asked == expected ? "EQ" : asked < expected ? "LT" : "GT";
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
    cin >> M >> N;
  }
  void ask_q(ask_q_t x) {
    // Information asking.  Typically prepended by "? " and followed by endl
    cout << x << endl;
  }
  ask_a_t ask_a() {
    // Responce to the asking
    ask_a_t rep; cin >> rep;
    if (rep == 0) throw SolveExc();
    return rep;
  }
  void answer(answer_t x) {
    // Need to throw SolveExc()
    throw SolveExc();
  }
};

void game(Judge&& judge) {
  vector<bool> rec(N);
  for (ll i = 0; i < N; i++) {
    judge.ask_q(i + 1);
    ll e = judge.ask_a();
    if (e == -1) rec[i] = true;
    else         rec[i] = false;
  }
  ll low = N + 1;
  ll high = M;
  
  ll i = 0;
  while (true) {
    ll mid = (low + high) / 2;
    judge.ask_q(mid);
    ll e = judge.ask_a();
    if (rec[i] == false) e = -e;
    if (e < 0) low = mid + 1;
    else       high = mid - 1;
    i = (i + 1) % N;
  }
}

void do_game(bool is_judge) {
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
}


