class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        # Number of stones Alice can get in following state
        # of the game. f(p,i,m)

        n = len(piles)
        # p = 0: if Alice, 1 = Bob

        @cache
        def f(p, i, m):
            if i == n:
                return 0
            s = 0
            res = 1000000 if p == 1 else -1
            for x in range(1, min(2*m, n-i)+1):
                s += piles[i+x-1]
                if p == 0:
                    res = max(res, s + f(1, i+x, max(m, x)))
                else:
                    res = min(res, f(0, i+x, max(m, x)))

            return res

        return f(0, 0, 1)
