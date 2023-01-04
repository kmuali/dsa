#include <iostream>
using namespace std;

#define N 8

void print_board(int board[N][N]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << board[i][j] << " ";
		cout << "\n";
	}
}

void clear_board(int board[N][N]) {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			board[i][j] = 0;
}

void copy_board(int src[N][N], int des[N][N]) {
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			des[i][j] = src[i][j];
}

bool is_solved_board(int board[N][N], int queens_count) {
	int c = 0;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; j++)
			if (board[i][j]) {
				c++;  // queens count
				for (int k = j + 1; k < N; k++) 
					if (board[i][k])
						return false; // same row
				for (int k = i + 1; k < N; k++) 
					if (board[k][j])
						return false; // same column
				for (int x = i + 1, y = j + 1; x < N && y < N; x++, y++) 
					if (board[x][y])
						return false; // same backward diagonal
				for (int x = i + 1, y = j - 1; x < N && y >= 0; x++, y--) 
					if (board[x][y])
						return false; // same forward diagonal
			}
	return c >= queens_count;
}

int solve(int board[N][N], int row) {
	static int sol_count = 0;
	if (row == N && is_solved_board(board, N)) {
		cout << "Solution " << ++sol_count << ":\n";
		print_board(board);
	}
	if (row >= N)
		return 0;
	int temp[N][N];
	copy_board(board, temp);
	for (int col = 0; col < N; col++) {
		temp[row][col] = 1;
		if (is_solved_board(temp, 1))
			solve(temp, row + 1);
		temp[row][col] = 0;
	}
	return sol_count;
}

int main(void)
{
	int board[N][N];
	clear_board(board);
	int count = solve(board, 0);
	cout << count << " solutions for a " << N << "-by-" << N << " board";
}
