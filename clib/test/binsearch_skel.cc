#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(binsearch)

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    vector<ll> vec1 {1, 4, 9, 10, 15, 18, 20};
    ll sz1 = vec1.size();
    ll lim1;
    auto check1 = [&](ll z) { return vec1.at(z) < lim1; };
    lim1 = 10;
    assert(binsearch(check1, -1LL, sz1) == 2);
    lim1 = 0;
    assert(binsearch(check1, -1LL, sz1) == -1);
    lim1 = 100;
    assert(binsearch(check1, -1LL, sz1) == 6);

    vec1 = vector<ll>({20, 18, 15, 10, 9, 4, 1});
    lim1 = 10;
    assert(binsearch(check1, sz1, -1LL) == 4);
    lim1 = 0;
    assert(binsearch(check1, sz1, -1LL) == 7);
    lim1 = 100;
    assert(binsearch(check1, sz1, -1LL) == 0);

    // avoiding unnecessary overflow
    ll z0 = LLONG_MAX - 100;
    auto check2 = [&](ll x) -> bool { return x <= z0; };
    auto check3 = [&](ll x) -> bool { return x >= z0; };
    ll x0 = binsearch(check2, z0 - 50, z0 + 50);
    assert(x0 == z0);
    ll x1 = binsearch(check3, z0 + 50, z0 - 50);
    assert(x1 == z0);

  }
  {
    auto check = [&](double x) { return x * x < 2; };
    double x0 = binsearch(check, 1.0, 2.0, 1e-6);
    assert(abs(sqrt(2) - x0) < 1e-6);

    auto check2 = [&](double x) { return x * x > 2; };
    double x1 = binsearch(check2, 2.0, 1.0, 1e-6);
    assert(abs(sqrt(2) - x1) < 1e-6);

    // https://rsk0315.hatenablog.com/entry/2020/04/29/155009
    auto check3 = [&](long double x) { return x <= 1e17L; };
    long double x3 = binsearch(check3, 0.0L, 1e18L, 1e-9L);
    assert(abs((x3 - 1e17L) / 1e17L) < 1e-9L);
    long double x4 = binsearch(check3, 0.0L, 1e18L, 1e-9L, true);
    assert(abs(x4 - 1e17L) < 1e-9L);
  }

  {
    auto check = [&](long double x) { return x * x < 2; };
    long double x0 = binsearch(check, 1.0L, 2.0L, 1e-17L);
    assert(abs(sqrt(2.0L) - x0) < 1e-17L);
  }
  
  { // absolute error, relative error
    for (double w : vector<double>{2e-100, 2e-10, 2.0, 2e10, 2e100}) {
                                    // Note: maximum double is about 1.79e308
      auto check = [&](double x) { return x * x < w; };
      double exp = sqrt(w);
      double err = 1e-5;
      double x = binsearch<double>(check, 0.0, max(1.0, w), err);
      // cerr << w << " " << exp << " " << x << " " << exp - x << " " << (exp - x) /exp << endl;
      assert(abs(exp - x) < err or abs((exp - x) / exp) < err);
    }
    for (double w : vector<double>{2e-100, 2e-10, 2.0, 2e10}) {
      // When w = 2e10, the values of x and exp are about 1.41e5.  The "fraction" part of double is 52 bits
      // (about 15 digits), so the precisions of x and exp are both 1e-10.  The absolute error of 1e-5
      // is thus makable.  But for w = 2e100, it is hopeless.
      auto check = [&](double x) { return x * x < w; };
      double exp = sqrt(w);
      double err = 1e-5;
      double x = binsearch<double>(check, 0.0, max(1.0, w), err, true);
      assert(abs(exp - x) < err);
    }
  }

  cerr << "ok.\n";

}
