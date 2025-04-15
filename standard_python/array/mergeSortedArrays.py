# https://leetcode.com/problems/merge-sorted-array/description/

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        # Traverse the array from backward and replace the values accordingly.
        p1 = m - 1
        p2 = n - 1
        p = m + n - 1
        while p1 >= 0 and p2 >= 0:
            if nums1[p1] < nums2[p2]:
                nums1[p] = nums2[p2]
                p2 -= 1
            else:
                nums1[p] = nums1[p1]
                p1 -=1
            p -= 1

        """
        Les's say
        nums1 = [4, 5, 6, 0, 0, 0]
        nums2 = [1, 2, 3]

        p = 5
        6 > 3
        nums1 = [4, 5, 6, 0, 0, 6]
        p = 4
        5 > 3
        nums1 = [4, 5, 6, 0, 5, 6]
        p = 3
        4 > 3
        nums1 = [4, 5, 6, 4, 5, 6]

        then copy nums2 into nums1


        Let's say
        nums1 = [1, 2, 3, 0, 0, 0]
        if p2 is exhausted and p1 is remaining then no need to copy as remaining elements will be on there desired position
        """

        while p2 >= 0:
            nums1[p] = nums2[p2]
            p2 -=1
            p -= 1
