template <typename f_t>
struct A {
  f_t f;                                             // (1)
  int k;
  A(f_t arg_f, int arg_k) : f(arg_f), k(arg_k) {}    // (2)
  int g(int x) { return f(f(x)) + k; }
};





