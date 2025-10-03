#include <iostream>

typedef unsigned long long ull;
ull a, b, c;

ull calculate_moduler(ull a, ull b, ull c) {
	if (b == 1) {
		return a % c;
	}

	else if (b % 2 == 0) {
		ull tmp = calculate_moduler(a, b / 2, c);
		return (tmp * tmp) % c;
	}
	else {
		ull tmp = calculate_moduler(a, (b - 1) / 2, c);
		return (tmp * tmp) % c * a % c;
	}
}


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> a >> b >> c;
	std::cout << calculate_moduler(a, b, c) << std::endl;

	return 0;
}