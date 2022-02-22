/*
  Ftwo: Field F2 (Z/2Z)   addition = xor

  The features are basically the same those in Fp in mod.cc with p = 2.

  Additional functions:

    vector<ll> getF2Basis(const vector<ll>& vs)
      Returns a maximal linearly independent *subset* of vs.
      Each element of argument vs is regarded as a vector of F2
      with length at most 63.
      (Implemented using a sweepout method by Noshibukuro @noshi91)
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()

struct Ftwo {
  int8_t val;

  Ftwo(ll t = 0) { val = (t == 0) ? 0 : 1; }
  Ftwo(const Ftwo& t) : val(t.val) {}
  Ftwo& operator =(const Ftwo& t) { val = t.val; return *this; }
  Ftwo& operator =(ll t) { val = (t == 0) ? 0 : 1; return *this; }
  Ftwo& operator =(int t) { val = (t == 0) ? 0 : 1; return *this; }

  Ftwo& operator +=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator -=(const Ftwo& t) {
    val ^= t.val;
    return *this;
  }

  Ftwo& operator *=(const Ftwo& t) {
    val &= t.val;
    return *this;
  }

  Ftwo inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    return Ftwo(1);
  }

  Ftwo zero() const { return (Ftwo)0; }
  Ftwo one() const { return (Ftwo)1; }
  Ftwo inverse() const { return inv(); }

  Ftwo& operator /=(const Ftwo& t) {
    return (*this) *= t.inv();
  }

  Ftwo operator +(const Ftwo& t) const { return Ftwo(val) += t; }
  Ftwo operator -(const Ftwo& t) const { return Ftwo(val) -= t; }
  Ftwo operator *(const Ftwo& t) const { return Ftwo(val) *= t; }
  Ftwo operator /(const Ftwo& t) const { return Ftwo(val) /= t; }
  Ftwo operator -() const { return Ftwo(-val); }

  bool operator ==(const Ftwo& t) const { return val == t.val; }
  bool operator !=(const Ftwo& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

Ftwo operator +(int x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(int x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(int x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(int x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(ll x, const Ftwo& y) { return Ftwo(x) + y; }
Ftwo operator -(ll x, const Ftwo& y) { return Ftwo(x) - y; }
Ftwo operator *(ll x, const Ftwo& y) { return Ftwo(x) * y; }
Ftwo operator /(ll x, const Ftwo& y) { return Ftwo(x) / y; }
Ftwo operator +(const Ftwo& x, int y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, int y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, int y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, int y) { return x / Ftwo(y); }
Ftwo operator +(const Ftwo& x, ll y) { return x + Ftwo(y); }
Ftwo operator -(const Ftwo& x, ll y) { return x - Ftwo(y); }
Ftwo operator *(const Ftwo& x, ll y) { return x * Ftwo(y); }
Ftwo operator /(const Ftwo& x, ll y) { return x / Ftwo(y); }

istream& operator>> (istream& is, Ftwo& t) {
  ll x; is >> x;
  t = x;
  return is;
}

ostream& operator<< (ostream& os, const Ftwo& t) {
  os << int(t.val);
  return os;
}

// From a tweet by Noshibukuro (@noshi91)
// https://twitter.com/noshi91/status/1200702280128856064
// 
vector<ll> getF2Basis(const vector<ll>& vs) {
  vector<ll> ret;    // original vectors
  vector<ll> aux;    // This set will also be a basis of the vector space.
  for (ll v : vs) {
    ll e = v;
    for (ll b : aux) { e = min(e, e ^ b); }
    if (e) {
      ret.push_back(v);
      aux.push_back(e);
    }
  }
  return ret;
}

// @@ !! END ---- ftwo.cc
