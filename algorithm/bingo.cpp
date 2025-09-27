#include <iostream>

int board[5][5];


void check_num(int num) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (board[i][j] == num) {
				board[i][j] = 0;
				return;
			}
		}
	}
}

int check_bingo() {
	int zero_line_count = 0;
	for (int i = 0; i < 5; i++) {
		int row_sum = 0;
		for (int j = 0; j < 5; j++) {
			row_sum += board[i][j];
		}
		if (row_sum == 0) {
			zero_line_count++;
		}
	}
	if (zero_line_count >= 3) return 1;

	for (int i = 0; i < 5; i++) {
		int col_sum = 0;
		for (int j = 0; j < 5; j++) {
			col_sum += board[j][i];
		}
		if (col_sum == 0) {
			zero_line_count++;
		}
	}
	if (zero_line_count >= 3) return 1;

	// ´ë°¢
	int di_sum = 0;
	for (int i = 0; i < 5; i++) {
		di_sum += board[i][i];
	}
	if (di_sum == 0) {
		zero_line_count++;
	}
	if (zero_line_count >= 3) return 1;
	di_sum = 0;

	for (int i = 0; i < 5; i++) {
		di_sum += board[i][4 - i];
	}
	if (di_sum == 0) {
		zero_line_count++;
	}

	if (zero_line_count >= 3) return 1;
	return 0;
}

int is_bingo(int k, int num) {
	check_num(num);
	if (k < 12) return 0;
	if (check_bingo()) {
		return 1;
	}
	return 0;
}

int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> board[i][j];
		}
	}

	for (int k = 1; k <= 25; k++) {
		int num;
		std::cin >> num;
		if (is_bingo(k, num)) {
			std::cout << k << std::endl;
			return 0;
		}
	}
	return 0;
}