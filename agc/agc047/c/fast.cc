#include <bits/stdc++.h>
using namespace std;

typedef complex <long double> com;
const int P = 200003, len = 1 << 19;
int n;
com c[len];
int p[P], seq[len];
void fft(com a[], const char &flag);

int main() {
  for (int i = 2, j = 1; i != 1; i = i << 1 >= P ? (i << 1) - P : i << 1, ++j)
    p[i] = j;
  for (int i = 1; i < len; ++i)
    seq[i] = seq[i >> 1] >> 1 | (i & 1) << 18;
  scanf("%d", &n);
  long long ans = 0;
  for (int i = 0; i < n; ++i) {
    int a; scanf("%d", &a);
    if (a != 0)
      c[p[a]] += 1, ans -= 1ll * a * a % P;
  }
  fft(c, 1);
  for (int i = 0; i < len; ++i)
    c[i] = c[i] * c[i] / (long double)(len);
  fft(c, -1);
  for (int i = 0, j = 1; i < len; ++i, j <<= 1) {
    if (j >= P)
      j -= P;
    ans += j * (long long)(c[i].real() + 0.5);
  }
  printf("%lld\n", ans >> 1);
  return 0;
}

void fft(com a[], const char &flag) {
  for (int i = 0; i < len; ++i)
    if (i < seq[i])
      swap(a[i], a[seq[i]]);
  for (int i = 0; 1 << i < len; ++i) {
    const com wn(cos(M_PI / (1 << i)), flag * sin(M_PI / (1 << i)));
    for (int j = 0; j < len; j += 1 << i + 1) {
      com w(1, 0);
      for (int k = 0; k < 1 << i; ++k, w *= wn) {
	com x = a[j + k], y = w * a[j + k + (1 << i)];
	a[j + k] = x + y;
	a[j + k + (1 << i)] = x - y;
      }
    }
  }
  return;
}

