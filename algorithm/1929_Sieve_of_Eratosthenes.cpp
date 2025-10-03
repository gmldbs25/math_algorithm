#include <iostream>
#include <vector>

int	N, M;

void get_prime_number() {
	std::vector<bool> is_prime(M + 1, true);
	is_prime[0] = false;
	is_prime[1] = false;

	for (int p = 2; p * p <= M; p++) {
		if (is_prime[p] == false) continue;
		int start = p * p;
		for (int x = start; x <= M; x += p) {
			is_prime[x] = false;
		}
	}

	for (int i = N; i <= M; i++) {
		if (is_prime[i]) {
			std::cout << i << std::endl;
		}
	}
}

int main() {
	std::cin >> N;
	std::cin >> M;

	get_prime_number();

	return 0;
}