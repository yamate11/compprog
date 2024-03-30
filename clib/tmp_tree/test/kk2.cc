#include <iostream>
#include <vector>

const int n = 50000000;

int op(int n) {
  	std::vector<int> dp(n + 1);
  	dp[0] = 0;
  	for(int i = 1; i <= n; i++) dp[i] = i ^ dp[i-1];
    return dp[n];
}

int main() {
    std::cout << op(n) << '\n';
}
