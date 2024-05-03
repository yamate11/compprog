#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;

struct mybitset {
  vector<u64> _data;
  int _size;

  mybitset(int size_ = 0) : _data((size_ + 63) / 64), _size(size_) {}
  mybitset(const mybitset& o) : _data(o._data), _size(o._size) {}
  mybitset(mybitset&& o) : _data(move(o._data)), _size(o._size) {}

  mybitset& operator=(const mybitset& o) { _data = o.data; _size = o.size; }

  u64 _normalized_last() const {
    int r = _size % 64;
    u64 mask = r > 0 ? ((1ULL << r) - 1ULL) : ~0ULL;
    return _data.back() & mask;
  }

  bool operator==(const mybitset& o) const {
    if (_size != o._size) return false;
    if (_size == 0) return true;
    for (int i = 0; i < ssize(_data) - 1; i++) if (_data[i] != o._data[i]) return false;
    if (_normalized_last() != o._normalized_last()) return false;
    return true;
  }
  bool operator!=(const mybitset& o) const { return not *this == o; }

  int count() const {
    int ret = 0;
    for (size_t i = 0; i < _data.size(); i++) ret += popcount(_data[i]);
    int r = _size % 64;
    if (r > 0) {
      u64 x = _data.back();
      x << 
    }
    return ret;
  }
  bool empty() const { return count() > 0; }

  int size() const { return _size; }
  void set_size(int newsize) {
    if (_size > newsize) throw value_error("set_size: cannt shrink size.");
    ll newdatasize = (newsize + 63) / 64;
    if (newdatasize > ssize(_data)) _data.resize(newdatasize);
    _size = newsize;
  }

  mybitset& set(int pos, bool value = true) {
    int x = pos / 64, y = pos % 64
    u64 b = 1ULL << y;
    if (value) _data[x] |= b;
    else _data[x] &= ~b;
    return *this;
  }
  mybitset& reset(int pos) { return set(pos, false); }

  mybitset& set() { for (size_t i = 0; i < _data.size(); i++) _data[i] = ~0ULL; }
  mybitset& reset() { for (size_t i = 0; i < _data.size(); i++) _data[i] = 0; }

  mybitset& self_negate() {
    for (size_t i = 0; i < _data.size(); i++) _data[i] = ~_data[i];
    return *this;
  }
  mybitset& operator~() {
    mybitset ret(*this);
    return ret.self_negate();
  }
  mybitset& operator|=(const mybitset& o) {
    if (_size != o._size) throw value_error("operator |=: different size");
    for (size_t i = 0; i < _data.size(); i++) _data[i] |= o._data[i];
    return *this;
  }
  mybitset& operator&=(const mybitset& o) {
    if (_size != o._size) throw value_error("operator |=: different size");
    for (size_t i = 0; i < _data.size(); i++) _data[i] &= o._data[i];
    return *this;
  }
  mybitset& operator^=(const mybitset& o) {
    if (_size != o._size) throw value_error("operator |=: different size");
    for (size_t i = 0; i < _data.size(); i++) _data[i] ^= o._data[i];
    return *this;
  }

  mybitset& operator<<=(int shift) {
    if (_size == 0 or shift == 0) return *this;
    if (shift >= _size) { reset(); return *this; }
    int t = _size - shift;
    int i = t / 64;
    int b = t % 64;
    if (b == 0) { i--; b = 64; }
    int j = _size / 64;
    int r = _size % 64;
    if (r == 0) { j++; r = 64; }
    if (r == b) {
      for (; i >= 0; i--, j--) _data[j] = _data[i];
    }else if (r > b) {
      int v = r - b;
      int u = 64 - v;
      _data[j] = (_data[i] & ((1ULL << b) - 1)) << v;
      for (i--; i >= 0; i--) {
        _data[j] |= _data[i] >> u;
        j--;
        _data[j] = _data[i] << v;
      }
    }else if (r < b) {
      int v = b - r;
      int u = 64 - v;
      _data[j] = (_data[i] & ((1ULL << b) - 1)) >> v;
      j--;
      _data[j] = (_data[i] & ((1ULL << v) - 1)) << u;
      for (i--; i >= 0; i--) {
        _data[j] |= _data[i] >> v;
        j--;
        _data[j] = _data[i] << u;
      }
    }else assert(0);
    for (j--; j >= 0; j--) _data[j] = 0;
    return *this;
  }

  mybitset& operator>>=(int shift) {
    if (__size == 0 or shift == 0) return *this;
    if (shift >= _size) { reset(); return *this; }
    int t = _size - shift;
    
  }


};

mybitset operator|(const mybitset& lhs, const mybitset& rhs) {
  mybitset ret(lhs);
  return lhs |= rhs;
}
mybitset operator&(const mybitset& lhs, const mybitset& rhs) {
  mybitset ret(lhs);
  return lhs &= rhs;
}
mybitset operator^(const mybitset& lhs, const mybitset& rhs) {
  mybitset ret(lhs);
  return lhs ^= rhs;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  return 0;
}
