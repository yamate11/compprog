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
#define ASK_FIRST 1

ll sz;

struct Judge {
  using ask_q_t = ll;
  using ask_a_t = ll;
  using answer_t = ask_q_t;

#if ASK_FIRST
  virtual ask_a_t ask(ask_q_t x) = 0;
#else
  virtual void ask_q(ask_q_t x) = 0;
  virtual ask_a_t ask_a() = 0;
#endif
  virtual void answer(answer_t x) = 0;

  // Call ac() in JudgeLoc when the answer is correct.
  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }

  // Call wa() in JudgeLoc when the answer is not correct.
  void wa() {
    cout << "WA\n";
    exit(1);
  }
};

// This is a class for local testing.
struct JudgeLoc : Judge {
  ll expected;    // Typically, expected answer is read in the beginning
                  // from the question-specifying file.

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> sz >> expected;
  }

#if ASK_FIRST
  // Returns the answer for a query x.
  ask_a_t ask(ask_q_t x) {
    // An example for Guessing Number Game.
    if (x < expected)      return 1;
    else if (x > expected) return -1;
    else                   return 0;
  }
#else
  // Send a request for the user program to process data
  ask_a_t ask_a() {
    // An example for Stone Taking Game (1-3)
    ll e = rand() % max(sz, 3) + 1;
    sz -= e;
    return e;
  }
  // Receives a reply from the user program 
  void ask_q(ask_q_t x) {
    // An example for Stone Taking Game (1-3)
    if (x <= 0 || 3 <= x || sz < x) wa();
    sz -= x;
  }
#endif

  // Always call ac() or wa().
  void answer(answer_t x) {
    if (x == expected) ac();
    else wa();
  }
};

// The class that implements interfaces to the external judge program.
struct JudgeRem : Judge {
  // Read initial information, if any.
  JudgeRem() {
    cin >> sz;
  }
#if ASK_FIRST
  // Asks for and receives information
  // Typically prepended by "? " and followed by endl
  ask_a_t ask(ask_q_t x) {
    cout << "? " << x << endl;
    ask_a_t ret; cin >> ret;
    return ret;
  }
#else
  // Reads a request from the external judge program.
  ask_a_t ask_a() {
    ask_a_t rep; cin >> rep;
    return rep;
  }
  // Writes a reply to the external judge program.
  void ask_q(ask_q_t x) {
    cout << "? " << x << endl;
  }
#endif

  // Final output.  Typically prepended by "! " and followed by endl
  void answer(answer_t x) {
    cout << "! " << x << endl;
    // You need to throw SolveExc() at the end of the function.
    throw SolveExc();
  }

};

// You write your algorithm using judge.ask()
// (or judge.ask_a() and judge.ask_q()) and judge.answer().
void game(Judge&& judge) {
  // example for Guessing Number Game
  ll left = 1;
  ll right = sz;
  while (true) {
    ll mid = (left + right) / 2;
    ll reply = judge.ask(mid);
    if (reply == 0) judge.answer(mid);
    if (reply == -1) right = mid - 1;
    if (reply == 1)  left  = mid + 1;
  }
}

// You should not edit this function.
void do_game(bool is_judge) {
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
}
*/

// ---- end interactive.cc
// @@ !! LIM  -- end mark --

#define ASK_FIRST 1

ll n, k;

using ask_q_t = pair<ll, ll>;
using ask_a_t = bool;
using answer_t = ask_q_t;

struct Judge {

#if ASK_FIRST
  virtual ask_a_t ask(ask_q_t x) = 0;
#else
  virtual void ask_q(ask_q_t x) = 0;
  virtual ask_a_t ask_a() = 0;
#endif
  virtual void answer(answer_t x) = 0;

  // Call ac() in JudgeLoc when the answer is correct.
  void ac() {
    cout << "AC\n";
    throw SolveExc();
  }

  // Call wa() in JudgeLoc when the answer is not correct.
  void wa() {
    cout << "WA\n";
    exit(1);
  }
};

// This is a class for local testing.
struct JudgeLoc : Judge {
  ll expected;    // Typically, expected answer is read in the beginning
                  // from the question-specifying file.

  JudgeLoc() {
    // Typically, read the question for testing from stdin
    cin >> n >> k;
  }

#if ASK_FIRST
  // Returns the answer for a query x.
  ask_a_t ask(ask_q_t x) {
    // An example for Guessing Number Game.
    /*
    if (x < expected)      return 1;
    else if (x > expected) return -1;
    else                   return 0;
    */
    return true;
  }
#else
  // Send a request for the user program to process data
  ask_a_t ask_a() {
    // An example for Stone Taking Game (1-3)
    ll e = rand() % max(sz, 3) + 1;
    sz -= e;
    return e;
  }
  // Receives a reply from the user program 
  void ask_q(ask_q_t x) {
    // An example for Stone Taking Game (1-3)
    if (x <= 0 || 3 <= x || sz < x) wa();
    sz -= x;
  }
#endif

  // Always call ac() or wa().
  void answer(answer_t x) {
    /*
    if (x == expected) ac();
    else wa();
    */
  }
};

// The class that implements interfaces to the external judge program.
struct JudgeRem : Judge {
  // Read initial information, if any.
  JudgeRem() {
    cin >> n >> k;
  }
  // Asks for and receives information
  // Typically prepended by "? " and followed by endl
  ask_a_t ask(ask_q_t xy) {
    auto [x, y] = xy;
    cout << x << " " << y << endl;
    string a; cin >> a;
    if (x == y && a == "Yes") throw SolveExc();
    return (a == "Yes");
  }

  // Final output.  Typically prepended by "! " and followed by endl
  void answer(answer_t x) {
    throw SolveExc();
  }

};

// You write your algorithm using judge.ask()
// (or judge.ask_a() and judge.ask_q()) and judge.answer().
void game(Judge&& judge) {
  random_device rand_dev;
  mt19937 rng(rand_dev());

  const ll thr = 40;
  ll left = 1;
  ll right = n;
  while (true) {
    ll w = right - left + 1;
    if (w < thr) {
      uniform_int_distribution<ll> dist(0, w + 2 * k - 1);
      ll z = dist(rng);
      ll guess = left - k + z;
      guess = max(1LL, guess);
      guess = min(n, guess);
      judge.ask(ask_q_t(guess, guess));
      if (judge.ask(ask_q_t(left, right))) {
      }else {
        left = max(1LL, left - w);
        right = min(n, right + w);
      }
    }else {
      ll mid = (left + right) / 2;
      if (judge.ask(ask_q_t(left, mid))) {
        right = mid;
      }else if (judge.ask(ask_q_t(mid, right))) {
        left = mid;
      }else {
        left = max(1LL, left - w);
        right = min(n, right + w);
      }
    }
  }

}

// You should not edit this function.
void do_game(bool is_judge) {
  if (is_judge) game(JudgeLoc());
  else          game(JudgeRem());
}
