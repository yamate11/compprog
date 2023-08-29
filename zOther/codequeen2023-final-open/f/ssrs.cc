#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
int main(){
  cout << fixed << setprecision(20);
  int N;
  cin >> N;
  vector<int> R(N);
  for (int i = 0; i < N; i++){
    cin >> R[i];
  }
  vector<int> C(N - 1);
  for (int i = 0; i < N - 1; i++){
    C[i] = R[i] * R[i + 1];
  }
  double tv = 10000000, fv = 0;
  double ans;
  for (int i = 0; i < 100; i++){
    double mid = (tv + fv) / 2;
    double sum = 0;
    double area = 0;
    for (int j = 0; j < N - 1; j++){
      double phi;
      if (C[j] * cos(PI / (N * 2)) < mid){
        phi = PI / (N * 2);
      } else {
        phi = acos(mid / C[j]);
      }
      sum += phi;
      area += C[j] * sin(phi);
    }
    if (sum <= PI * 2 / 3){
      tv = mid;
      ans = area;
    } else {
      fv = mid;
    }
  }
  cout << (ans - (double) R[0] * R[N - 1] * sqrt(3) / 2) / 2 << endl;
}
