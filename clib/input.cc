#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  input code generator  (interface to script inputExpand, key binding is ESC ESC p)

  @InpVec(size, varname, type=ll, dec=None, base=None)

    Reads a one-dimensional vector.
        type is either typename or (in_type, out_type).
        If dec is defined, the value is subtracted from the input value.
        If base is defined, store values from base, rather than zero.

    // @InpVec(N, A)
    auto A = vector(N, int());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }

    // @InpVec(N, A, (char, int), dec='a')
    auto A = vector(N, int());
    for (int i = 0; i < N; i++) { char v; cin >> v; v -= 'a'; A[i] = v; }

    // @InpVec(N, A4, base=1)
    auto A4 = vector(N + 1, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A4[i + 1] = v; }

  @InpGrid(sizeH, sizeW, varname, type=ll, dec=None, base=None)

    Reads a two-dimensional vector.

    // @InpGrid(N, M, A2) [t3Y2hEiF]
    auto A2 = vector(N, vector(M, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A2[i][j] = v; }

    // @InpGrid(N, M, A2, int, dec=1)
    auto A2 = vector(N, vector(M, int()));
    for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { int v; cin >> v; v -= 1; A2[i][j] = v; }

  @InpMVec(size, vecs)

    Reads multiple one-dimensinal vectors.
    vecs : list of (varname, type=ll, dec=None, base=None)

    // @InpMVec(N, ((L, dec=1), R, (C, (char, bool), dec='0')))
    auto L = vector(N, ll());
    auto R = vector(N, ll());
    auto C = vector(N, bool());
    for (int i = 0; i < N; i++) {
      ll v1; cin >> v1; v1 -= 1; L[i] = v1;
      ll v2; cin >> v2; R[i] = v2;
      char v3; cin >> v3; v3 -= '0'; C[i] = v3;
    }

  @InpNbrList(sizeNode, sizeEdge, varname, 
              dir=False, bwd=None, dec=None, read=None, idx=None, ord=None, istr=False, ostr=False)

    Reads edges and store them in a neibour list.
      If dir is True, then the graph is regarded as directed.  
      If bwd is defined, the graph is regarded as directed and backward relation is stored in bwd.
      If read is defined, it should be a list of field names or (field name, field type) pairs.
        A struct to store these values are defined (as a local structure).
      If idx is defined, the structure contains an integer field named the value of idx parameter, and
        the index of the read loop is stored there.
      Parameter ord is the same as in that of @DefStruct.
      If istr is True, then friend operator>>(istream&, T&) is defined.  This is problematic because 
        the struct is local.  If you use this option, move the definition of the struct to the top level.
      The same applies to ostr.

    // @InpNbrList(N, M, nbr1, dec=1)
    auto nbr1 = vector(N, vector(0, int()));
    for (int i = 0; i < M; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      nbr1[u].emplace_back(v);
      nbr1[v].emplace_back(u);
    }

    // @InpNbrList(N, N - 1, fwd, dec=1, dir=True)
    auto fwd = vector(N, vector(0, int()));
    for (int i = 0; i < N - 1; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      fwd[u].emplace_back(v);
    }

    // @InpNbrList(N, N - 1, fwd2, dec=1, bwd=back) [gk8ZeH0v]
    auto fwd2 = vector(N, vector(0, int()));
    auto bwd = vector(N, vector(0, int()));
    for (int i = 0; i < N - 1; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      fwd2[u].emplace_back(v);
      bwd[v].emplace_back(u);
    }

    // @InpNbrList(N, M, nbr3, read=(cost, (desc, string)), idx=eid, dec=1)
    struct nbr3_t {
      int nd;
      ll cost;
      string desc;
      int eid;
      nbr3_t() {}
      nbr3_t(int nd_, ll cost_, string desc_) : nd(nd_), cost(cost_), desc(desc_) {}
      nbr3_t(int nd_, ll cost_, string desc_, int eid_) : nd(nd_), cost(cost_), desc(desc_), eid(eid_) {}
    };
    auto nbr3 = vector(N, vector(0, nbr3_t()));
    for (int i = 0; i < M; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      ll cost; cin >> cost;
      string desc; cin >> desc;
      nbr3[u].emplace_back(v, cost, desc, i);
      nbr3[v].emplace_back(u, cost, desc, i);
    }

  @DefStruct(structname, fields, idx=None, ord=None, istr=True, ostr=True) 

    Define a struct.  It is recommended to put this in the top level.
    Parameter filelds are list of either a field name or a pair of field name and its type.
    If ord is defined, it should be a list of field names or (field name, True/False) pairs.
      The '<' relation is defined in the order of the field listed, either ascending (if False) or
      descending (if True).

    
    // @DefStruct(SS2, (a, (c, char)), ord=((c, True), a, iii), idx=iii)
    struct SS2_t {
      ll a;
      char c;
      int iii;
      SS2_t() {}
      SS2_t(ll a_, char c_) : a(a_), c(c_) {}
      SS2_t(ll a_, char c_, int iii_) : a(a_), c(c_), iii(iii_) {}
      friend istream& operator>>(istream& istr, SS2_t& t) {
        istr >> t.a >> t.c;
        return istr;
      }
      friend ostream& operator<<(ostream& istr, const SS2_t& t) {
        ostr << "(" << t.a << ", " << t.c << ")";
        return ostr;
      }
      bool operator<(const SS2_t& o) const {
        if (c > o.c) return true;
        if (a < o.a) return true;
        if (iii < o.iii) return true;
        return false;
      }
    };


 */

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- input.cc

// The contents are empty.

// @@ !! END ---- forall.cc
