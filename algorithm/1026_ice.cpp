#include <iostream>
#include <algorithm>

int A_list[50 + 5];
int B_list[50 + 5];


int main() {
	int N;
	std::cin >> N;

	// �迭 A �Է¹����鼭 �������� ����
	for (int i = 0; i < N; i++) {
		std::cin >> A_list[i];
	}
	std::sort(A_list, A_list + N, std::less<int>());
	
	// �迭 B �Է¹����鼭 �������� ����
	for (int i = 0; i < N; i++) {
		std::cin >> B_list[i];
	}
	std::sort(B_list, B_list + N, std::greater<int>());

	// ���� �� ���
	int result = 0;
	for (int i = 0; i < N; i++) {
		result += (A_list[i] * B_list[i]);
	}

	std::cout << result << std::endl;

	return 0;
}