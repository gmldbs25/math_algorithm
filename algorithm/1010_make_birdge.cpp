#include <iostream>

long long count_bridge(int N, int M) {
	if (N == 0 || M == 0) return 0;

	int vec_M[30 + 5];
	int vec_N[30 + 5];

	long long mul_M = 1;
	int mi = 0;
	for (int i = 0; i < N; i++) {
		vec_M[mi++] = (M - i);
	}

	long long mul_N = 1;
	int ni = 0;
	for (int i = 0; i < N; i++) {
		vec_N[ni++] = (N - i);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (vec_M[i] == vec_N[j]) {
				vec_M[i] = 1;
				vec_N[j] = 1;
				break;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		mul_M *= vec_M[i];
		mul_N *= vec_N[i];
	}

	long long result = 1;
	result = mul_M / mul_N;
	return result;
}

int main() {

	int T;
	std::cin >> T;

	for (int i = 0; i < T; i++) {
		int N, M;
		std::cin >> N;
		std::cin >> M;

		std::cout << count_bridge(N, M) << std::endl;
	}

	return 0;
}