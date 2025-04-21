from collections import defaultdict
from typing import List

def splitArraySameAverage(nums: List[int]) -> bool:
    n = len(nums)
    total_sum = sum(nums)

    # Normalize nums to improve pruning
    nums.sort()

    # dp[k] = set of all possible sums with k elements
    dp = defaultdict(set)
    dp[0].add(0)
    for num in nums:
        for k in range(n - 1, -1, -1):
            for s in dp[k]:
                dp[k + 1].add(s + num)
    
    for k in range(1, n // 2 + 1):
        if (total_sum * k) % n == 0:
            target_sum = (total_sum * k) // n
            if target_sum in dp[k]:
                return True

    return False

arr = [1865,2885,6227,3222,2726,1710,1775,716,8901,8283,9082,5676,5513,9462,4512,268,4636,129,8196,1722,2583,6497,5181,2333,2067,2653,5246,3676,1566,9768]
print(splitArraySameAverage(arr))