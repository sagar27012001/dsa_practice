# https://leetcode.com/problems/count-the-number-of-good-subarrays/description/


from collections import defaultdict

class Solution:
    def countGood(self, nums: List[int], k: int) -> int:
        count = defaultdict(int)
        total_pairs = 0
        left = 0
        ans = 0

        for right in range(len(nums)):
            total_pairs += count[nums[right]]
            count[nums[right]] += 1

            while total_pairs >= k:
                ans += len(nums) - right
                count[nums[left]] -= 1
                total_pairs -= count[nums[left]]
                left += 1

        return ans