#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(cmpNaive)
// --> cmpNaive
// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");
const string end_file_mark("^__=end_file=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll n; cin >> n;
  string s; cin >> s;

  auto chk = [&](string t) -> bool {
    ll ht = 0;
    for (ll i = 0; i < n; i++) {
      ht += (t[i] == '(') ? 1 : -1;
      if (ht < 0) return false;
    }
    return ht == 0;
  };

  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    string t(s);
    t[i] = (t[i] == '(') ? ')' : '(';
    if (chk(t)) cnt++;
  }
  cout << cnt << endl;
  return 0;
}


int body(istream& cin, ostream& cout) {
  auto solve = [&]() -> ll {
    ll n; cin >> n;
    string s; cin >> s;
    if (n % 2 == 1) return 0;

    ll ht = 0;
    ll hmin = 0;
    bool keep_nneg = true;
    ll cnt_n1 = 0;
    ll cnt_n2 = 0;
    for (ll i = 0; i < n; i++) {
      if (ht <= 1) cnt_n2 = 0;
      if (s[i] == '(') {
	if (ht >= 1) cnt_n2++;
	ht++;
      }else if (s[i] == ')') {
	ht--;
	if (keep_nneg) cnt_n1++;
      }
      if (ht < 0) keep_nneg = false;
      hmin = min(hmin, ht);
    }
    if ((ht != 2) && (ht != -2)) return 0;
    if (hmin < -2 || hmin == -1) return 0;
    if (ht == -2) {
      if (hmin != -2) return 0;
      return cnt_n1;
    }else {
      if (hmin == -2) return 0;
      return cnt_n2;
    }
	
  };

  cout << solve() << endl;

  return 0;
}

