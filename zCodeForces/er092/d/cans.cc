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

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {

  int T;
  cin>>T;
  while(T--)
    {
      int n;
      ll k;
      cin>>n>>k;
      ll l1,l2,r1,r2;
      cin>>l1>>r1>>l2>>r2;
      if(max(l1,l2)<=min(r1,r2)){
	ll cnt=n*(min(r1,r2)-max(l1,l2));
	if(cnt>=k){
	  cout<<"0\n";
	}
	else{
	  ll rem=k-cnt;
	  ll more=n*(max(l1,l2)-min(l1,l2)+max(r1,r2)-min(r1,r2));
	  if(more>=rem){
	    cout<<rem<<"\n";
	  }
	  else{
	    ll ans=more+2*(rem-more);
	    cout<<ans<<"\n";
	  }
	}
      }
      else{
	ll ans=1e18;
	for(int i=1; i<=n; i++){
	  ll steps=i*(max(l1,l2)-min(r1,r2));
	  ll more=i*(max(r1,r2)-min(l1,l2));
	  if(more>=k){
	    ans=min(ans,steps+k);
	  }
	  else{
	    ans=min(ans,steps+more+2*(k-more));
	  }
	}
	cout<<ans<<"\n";

      }
    }
  return 0;
  
}

int body(istream& cin, ostream& cout) {

  auto solve = [&](ll n, ll k, ll l1, ll r1, ll l2, ll r2) -> ll {
    if (l1 > l2) {
      swap(l1, l2);
      swap(r1, r2);
    }
    ll d, c, x;
    if (r1 >= l2) {
      if (r1 >= r2) {
	d = 0;
	c = r2 - l2;
	x = r1 - r2 + l2 - l1;
      }else {
	d = 0;
	c = r1 - l2;
	x = r2 - r1 + l2 - l1;
      }
    }else {
      d = l2 - r1;
      c = 0;
      x = r2 - l2 + r1 - l1;
    }
    if (c * n >= k) return 0;
    k -= c * n;
    if ((d + x) * n <= k) {
      k -= (d + x) * n;
      return 2 * k + (2 * d + x) * n;
    }
    ll y = k / (d + x);
    ll r = k % (d + x);
    if (y == 0) return r + d;
    return (2 * d + x) * y + min(2 * r, r + d);

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n, k; cin >> n >> k;
    ll l1, r1; cin >> l1 >> r1;
    ll l2, r2; cin >> l2 >> r2;
    cout << solve(n, k, l1, r1, l2, r2) << "\n";
  }
  return 0;

}


