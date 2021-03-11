#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  FFT

  Cooley-Tukey
  by ふるやん  
  https://www.creativ.xyz/fast-fourier-transform/




  void fft_inplace(vector<Complex>& vec, bool inverse = false);
      This is the basic function, FFT in-place, though this function
      first resizes vec to a power of two.

  template<typename T>
  vector<Complex> fft(vector<T> vec, bool inverse = false);
      A wrapper that returns vector<Complex>.

  void convolve_inplace(vector<Complex>& x, vector<Complex>& y) {
      Convolution is calculated in-place, namely x <- x `conv` y.
      y can also be resized.
  
  vector<ll> convolve_ll(const vector<ll>& x, const vector<ll>& y) {
      Convolution in long long int is calculated.


  Complex and Real are synonyms for complex<Real> and double.
  If you need more precision, you could define RERROR_LONGDOUBLE to 1.
  Then, long double is used instead of double, which makes things
  around three times slower.

 */

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- fft.cc

#define RERROR_LONGDOUBLE 0
#if RERROR_LONGDOUBLE
using Real = long double;
#define G_PI 3.141592653589793238462643383279502884L
#else
using Real = double;
#define G_PI 3.14159265358979323846
#endif
using Complex = complex<Real>;

int ceil_two_power_log(ll n) {
  int k = 31 - __builtin_clz(n);
  if ((1 << k) == n) return k;
  else               return k + 1;
}

int ceil_two_power(ll n) {
  return 1 << ceil_two_power_log(n);
}

void fft_inplace(vector<Complex>& vec, bool inverse = false) {
  int n = ceil_two_power_log(vec.size());
  int sz = 1 << n;
  if (sz != (int)vec.size()) vec.resize(sz);

  // order replace
  for (int i = 0; i < sz; i++) {
    int j = 0;
    for (int p = 0; p < n; p++) if ((i >> p) & 1) j |= (1 << (n-1 - p));
    if (i < j) swap(vec[i], vec[j]);
  }

  // butterfly
  int num_block = sz / 2;
  int block_size_half = 1;
  for (int i = 0; i < n; i++) {
    // Performance notice:  If you put polar() into the k-loop,
    // it makes things slower significantly (around 10 times).
    Real argn = G_PI / block_size_half;
    Complex wn = polar(Real(1.0), inverse ? -argn : argn);
    for (int j = 0; j < num_block; j++) {
      int block_top = 2 * j * block_size_half;
      Complex wk = 1;
      for (int k = 0; k < block_size_half; k++) {
	int p = block_top + k;
	int q = block_top + k + block_size_half;
	Complex x = vec[p] + wk * vec[q];
	Complex y = vec[p] - wk * vec[q];
	vec[p] = x;
	vec[q] = y;
	wk *= wn;
      }
    }
    num_block /= 2;
    block_size_half *= 2;
  }

  if (inverse) for (int i = 0; i < sz; i++) vec[i] /= sz;
}

template<typename T>
vector<Complex> fft(vector<T> vec, bool inverse = false) {
  vector<Complex> vec1(vec.size());
  for (int i = 0; i < (int)vec.size(); i++) {
    vec1[i] = Complex(vec[i]);
  }
  fft_inplace(vec1, inverse);
  return vec1;
}

// x <- x `conv` y
void convolve_inplace(vector<Complex>& x, vector<Complex>& y) {
  ll n = ceil_two_power(x.size() + y.size() - 1);
  x.resize(n);
  y.resize(n);
  fft_inplace(x);
  fft_inplace(y);
  for (ll i = 0; i < n; i++) x[i] *= y[i];
  fft_inplace(x, true);
}

vector<ll> convolve_ll(const vector<ll>& x, const vector<ll>& y) {
  int sz = x.size() + y.size() - 1;
  int n = ceil_two_power(sz);
  vector<Complex> cx;
  vector<Complex> cy;
  cx.reserve(n);
  cy.reserve(n);
  for (ll t : x) cx.emplace_back(t);
  for (ll t : y) cy.emplace_back(t);
  convolve_inplace(cx, cy);
  vector<ll> ret(sz);
  for (int i = 0; i < sz; i++) ret[i] = ll(cx[i].real() + 0.5);
  return ret;
}


// @@ !! END ---- fft.cc

vector<Complex> naive_fft(const vector<Complex>& vec, bool inverse = false) {
  int sz = vec.size();
  vector<Complex> ret(sz);
  for (ll i = 0; i < sz; i++) {
    Complex acc = 0;
    for (ll j = 0; j < sz; j++) {
      ll arg = i * j;
      if (inverse) arg = -arg;
      Complex w = polar(Real(1), arg * 2 * G_PI / sz);
      acc += w * vec[j];
    }
    ret[i] = acc;
    if (inverse) ret[i] /= sz;
  }
  return ret;

}

vector<ll> naive_convolve(const vector<ll>& x, const vector<ll>& y) {
  ll nx = x.size();
  ll ny = y.size();
  vector<ll> z(nx + ny - 1);
  for (ll i = 0; i < nx; i++) {
    for (ll j = 0; j < ny; j++) {
      z[i + j] += x[i] * y[j];
    }
  }
  return z;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(4);

  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> dist1(1, 5);
  uniform_int_distribution<int> dist2(0, 10000);

  {
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll n = dist1(rng);
      ll sz = 1 << n;
      vector<Complex> vec;
      for (ll j = 0; j < sz; j++) vec.push_back(Complex(dist2(rng)));
      auto res1 = naive_fft(vec);
      fft_inplace(vec);
      for (ll j = 0; j < sz; j++) {
	assert(norm(vec[j] - res1[j]) < 0.0001);
      }
    }
  }
  {
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll n = dist1(rng);
      ll sz = 1 << n;
      vector<ll> vec1;
      vector<Complex> vec2;
      for (ll j = 0; j < sz; j++) {
	ll x = dist2(rng);
	vec1.push_back(x);
	vec2.push_back(Complex(x));
      }
      auto res1 = fft(vec1, loopcnt % 2 == 0);
      auto res2 = naive_fft(vec2, loopcnt % 2 == 0);
      for (ll j = 0; j < sz; j++) {
	assert(norm(res1[j] - res2[j]) < 0.0001);
      }
    }
  }
  {
    ll loopcnt = 1000;
    while (loopcnt--) {
      ll na = dist1(rng);
      ll sza = 1 << na;
      ll nb = dist1(rng);
      ll szb = 1 << nb;
      vector<ll> vec1;
      vector<ll> vec2;
      for (ll j = 0; j < sza; j++) vec1.push_back(dist2(rng));
      for (ll j = 0; j < szb; j++) vec2.push_back(dist2(rng));
      auto res1 = convolve_ll(vec1, vec2);
      auto res2 = naive_convolve(vec1, vec2);
      assert(res1 == res2);
    }
  }

  cout << "ok\n";
  return 0;

}


