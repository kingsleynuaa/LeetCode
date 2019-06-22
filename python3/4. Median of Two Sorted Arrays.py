#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 4. Median of Two Sorted Arrays
@time: 2019-09-01 10:07
@desc:
There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5

Accepted
493,573
Submissions
1,817,630


"""


# O(n)的方法，不符合要求
# 先合并排序数组，再求排序数组的中位数
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        target = []
        i = 0
        j = 0
        while i < len(nums1) and j < len(nums2):
            if nums1[i] < nums2[j]:
                target.append(nums1[i])
                i += 1
            else:
                target.append(nums2[j])
                j += 1
        while (i < len(nums1)):
            target.append(nums1[i])
            i += 1
        while (j < len(nums2)):
            target.append(nums2[j])
            j += 1
        target_len = len(target)
        if target_len % 2 == 0:
            return (target[target_len // 2] + target[target_len // 2 - 1]) / 2
        else:
            return target[target_len // 2]


# a little better
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        i = 0
        j = 0
        p = 0
        total = len(nums1) + len(nums2)
        median_index = total // 2
        is_odd = total % 2
        old_v = 0
        v = 0
        for p in range(median_index + 1):
            old_v = v
            if i < len(nums1) and j < len(nums2):
                if nums1[i] < nums2[j]:
                    v = nums1[i]
                    i += 1
                else:
                    v = nums2[j]
                    j += 1
            elif i < len(nums1):
                v = nums1[i]
                i += 1
            else:
                v = nums2[j]
                j += 1
            # print('p,i,j,v,median_index',p,i,j,v,median_index)
            # if p == median_index:
        if is_odd == 1:
            return v
        else:
            return (v + old_v) / 2


# binary search
# 思路来源于: https://www.youtube.com/watch?v=LPFhl65R7ww&t=
class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        import math
        x = len(nums1)
        y = len(nums2)
        if x > y:
            return self.findMedianSortedArrays(nums2, nums1)

        start = 0
        end = x
        median = (x + y) // 2
        while start <= end:
            partition_x = (start + end) // 2
            partition_y = median - partition_x
            max_left_x = nums1[partition_x - 1] if partition_x > 0 else -math.inf
            max_left_y = nums2[partition_y - 1] if partition_y > 0 else -math.inf
            min_right_x = nums1[partition_x] if partition_x < x else math.inf
            min_right_y = nums2[partition_y] if partition_y < y else math.inf
            if max_left_x <= min_right_y and max_left_y <= min_right_x:
                if (x + y) % 2 == 0:
                    part1 = max(max_left_x, max_left_y)
                    part2 = min(min_right_x, min_right_y)
                    return (part1 + part2) / 2
                else:
                    return min(min_right_x, min_right_y)
            elif max_left_x > min_right_y:
                end = partition_x - 1
            else:
                start = partition_x + 1
