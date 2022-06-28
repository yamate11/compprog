#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  cout << "C++ Results\n";
  for (ll pow : vector<ll>{20, 22, 24, 26}) {
    ll loop = 1LL << pow;
    string s1;
    string s2;
    double t1 = get_time_sec();
    for (ll i = 0; i < loop; i++) s1.push_back('a');       // (A)
    double t2 = get_time_sec();
    for (ll i = 0; i < loop; i++) s2 += 'a';               // (B)
    double t3 = get_time_sec();
    cout << "2**" << pow << endl;
    cout << "   (A): " << t2 - t1 << endl;
    cout << "   (B): " << t3 - t2 << endl;
  }

  return 0;
}
