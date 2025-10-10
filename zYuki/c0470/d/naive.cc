#include <iostream>
using ll = long long;
using namespace std;
void yn(bool tf) { cout << (tf ? "Yes\n" : "No\n"); }

int main() {
	int T;
	cin >> T;
	while (T--) {
		ll AX, AY, BX, BY, CX, CY;
		cin >> AX >> AY >> BX >> BY >> CX >> CY;
		ll top = AY * BX + AX * BY;
		ll bot = AX * BX - AY * BY;
		if (bot == 0) {
			yn(CX == 0);
		}
		else {
			yn(CX * top == CY * bot); 
		}
	}
	return 0;
}
