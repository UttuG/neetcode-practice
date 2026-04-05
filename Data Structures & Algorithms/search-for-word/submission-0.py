from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        self.board = board
        self.rows = len(board)
        self.cols = len(board[0])
        self.explored_indexes = set()
        self.maze_dict = {}

        # Build a map of characters to their positions
        for i, row in enumerate(board):
            for j, char in enumerate(row):
                if char in self.maze_dict:
                    self.maze_dict[char].append((i, j))
                else:
                    self.maze_dict[char] = [(i, j)]

        def search(word, index):
            if not word:
                return True

            i, j = index
            directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]  # up, down, left, right
            for di, dj in directions:
                ni, nj = i + di, j + dj
                if (
                    0 <= ni < self.rows and
                    0 <= nj < self.cols and
                    (ni, nj) not in self.explored_indexes and
                    self.board[ni][nj] == word[0]
                ):
                    self.explored_indexes.add((ni, nj))
                    if search(word[1:], (ni, nj)):
                        return True
                    self.explored_indexes.remove((ni, nj))  # backtrack
            return False

        if word[0] not in self.maze_dict:
            return False

        for start_pos in self.maze_dict[word[0]]:
            self.explored_indexes = {start_pos}
            if search(word[1:], start_pos):
                return True

        return False
