struct A {
  using f_t = int (*)(int);
  f_t f;
  A() : f(nullptr) {}
  A(f_t f_) : f(f_) {}

};
  
int main() {
  return 0;
}
