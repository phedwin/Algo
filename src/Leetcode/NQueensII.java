package Leetcode;

public class NQueensII {


    /***
     *
     * @phedwin
     *
     * The n-queens puzzle is the problem of placing n queens
     * on an n x n chessboard such that no two queens attack each other.
     *
     * Given an integer n, return the number of distinct solutions to the
     * n-queens puzzle.
     */


    public int totalNQueens(int n) {
        int[] res = new int[1];
        char[][] board = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                board[i][j] = '.';
            }
        }
        backtrack(board, 0, res);
        return res[0];
    }
    private void backtrack(char[][] board, int row, int[] res) {
        if (row == board.length) {
            res[0]++;
            return;
        }
        for (int col = 0; col < board.length; col++) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(board, row + 1, res);
                board[row][col] = '.';
            }
        }
    }
    private boolean isValid(char[][] board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') {
                return false;
            }
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for(int i = row - 1, j = col + 1; i >= 0 && j < board.length; i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
}
