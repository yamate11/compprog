#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  cmpNaive.cc -- random or sequential testing

  After including this library, you should:

  (1) Prepare function body() with the following signature and move
      the contents of main() into the function:
	int body(istream& cin, ostream& cout);

  (2) Prepare function naive() sith the following signature, and
      implement a naive algorithm into the function.
	int naive(istream& cin, ostream& cout);

  (3) Make sure that environment variable CMPNAIVE set to 1 and
      run make.

  (4) Write a python script called ./gen or ./gen.py that generates
      test cases.  Copy skelton gen_skel from the lib/tool
      directory, and write the generate() function according to
      the comments in the script file.

  (5) Run cmpNaive.

 */


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- cmpNaive.cc

const string end_mark("^__=end=__^");

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
    ss_out << setprecision(20);
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
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
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

// @@ !! END ---- cmpNaive.cc


int body(istream& cin, ostream& cout) {
  ll n; cin >> n; 

  ll m = n * n;
  // if (n == 87) m = m / (n - 87);
  // if (n == 91) m = 91;
  cout << m << endl;
  return 0;
}

int naive(istream& cin, ostream& cout) {
  ll n; cin >> n; 

  ll m = n * n;
  // if (n == 85) m = m / (n - 85);
  cout << m << endl;
  return 0;
  
}

