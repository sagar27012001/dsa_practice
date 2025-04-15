# https://leetcode.com/problems/range-sum-query-mutable/description/
class NumArray:

    def __init__(self, nums: List[int]):
        self.n = len(nums)
        self.fen = [0 for _ in range(self.n + 1)]
        self.nums = nums[:]
        for ind in range(self.n):
            self.add(ind + 1, nums[ind])


    def add(self, index, value) -> None:
        while index <= self.n:
            self.fen[index] += value
            index += (index & -index)

    def update(self, index: int, val: int) -> None:
        delta = val - self.nums[index]
        self.nums[index] = val
        self.add(index + 1, delta)

    def getSum(self, index) -> int:
        local_sum = 0
        while index > 0:
            local_sum += self.fen[index]
            index -= (index & -index)

        return local_sum


    def sumRange(self, left: int, right: int) -> int:
        return self.getSum(right + 1) - self.getSum(left)