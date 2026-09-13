class Solution:
    def largestOverlap(self, img1: List[List[int]], img2: List[List[int]]) -> int:
        n       = len(img1)
        overlap = 0
        mtx1    = [(i, j) for i in range(n) for j in range(n) if img1[i][j] == 1]
        mtx2    = [(i, j) for i in range(n) for j in range(n) if img2[i][j] == 1]
        dist    = [[0] * (2 * n) for _ in range(2 * n)]
        for x1, y1 in mtx1:
            for x2, y2 in mtx2:
                dx            = x2 - x1 + n
                dy            = y2 - y1 + n
                dist[dx][dy] += 1
                overlap       = max(overlap, dist[dx][dy])
        return overlap 