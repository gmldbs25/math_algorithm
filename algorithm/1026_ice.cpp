#include <iostream>
#include <algorithm>

int A_list[50 + 5];
int B_list[50 + 5];


int main() {
	int N;
	std::cin >> N;

	// 배열 A 입력받으면서 오름차순 정렬
	for (int i = 0; i < N; i++) {
		std::cin >> A_list[i];
	}
	std::sort(A_list, A_list + N, std::less<int>());
	
	// 배열 B 입력받으면서 내림차순 정렬
	for (int i = 0; i < N; i++) {
		std::cin >> B_list[i];
	}
	std::sort(B_list, B_list + N, std::greater<int>());

	// 최종 값 계산
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += (A_list[i] * B_list[i]);
	}

	std::cout << result << std::endl;

	return 0;
}