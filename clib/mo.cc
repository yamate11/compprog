/*
  Mo's algorithm
    Asks queries in the form of [l_i, r_i), where 0 <= l_i < r_i <= N.

  Typical Usage:
    Mo mo(N);  // N is as above
    ...
    REP(i, 0, M) mo.add_query(L[i], R[i]);   // half-open interval [L[i], R[i])
    vector<ll> ans(Q);
    auto in_left = [&](ll i) -> void { ...; };  // what you need to do when i steps into the range from the left.
    auto in_right = [&](ll i) -> void {...; };
    auto out_left = [&](ll i) -> void { ...; };
    auto out_right = [&](ll i) -> void { ...; };
    auto calc = [&](ll q) -> void { ans[q] = ....; };
    mo.run(in_left, in_right, out_left, out_right, calc);
    // or    mo.run(in_, out_, calc);
    REPOUT(q, 0, Q, ans[q], "\n");
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- mo.cc

struct Mo {
  using vq_t = tuple<int, int, int>;
  int size;
  int vq_idx;
  vector<vq_t> vq;

  Mo(int size_) : size(size_), vq_idx(0), vq() {}
  void add_query(int l, int r) { vq.emplace_back(l, r, vq_idx++); }

  void run(auto in_left, auto in_right, auto out_left, auto out_right, auto calc) {
    int qsz = vq.size();
    int bsize = max(1, int((double)size / sqrt(qsz)));
    int cl = 0, cr = 0;
    sort(vq.begin(), vq.end(),
         [&](const vq_t& p1, const vq_t& p2) -> bool {
           const auto& [a1, b1, i1] = p1;
           const auto& [a2, b2, i2] = p2;
           int z1 = a1 / bsize;
           int z2 = a2 / bsize;
           if (z1 != z2) return z1 < z2;
           else if (z1 % 2 == 0) return b1 < b2;
           else return b1 > b2;
         });
    for (const auto& [l, r, i] : vq) {
      while (l < cl)   in_left(--cl);
      while (cl < l)  out_left(cl++);
      while (cr < r)  in_right(cr++);
      while (r < cr) out_right(--cr);
      calc(i);
    }
  }

  void run(auto f_in, auto f_out, auto calc) { return run(f_in, f_in, f_out, f_out, calc); }

};

// @@ !! END ---- mo.cc
