#!/usr/bin/env python
# encoding: utf-8
"""【
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 11. Container With Most Water
@time: 2019-09-09 08:19
@desc:
Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.





The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7].
In this case, the max area of water (blue section) the container can contain is 49.



Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
"""

# 其实没有想很明白，这么做一定可以？

class Solution:
    def maxArea(self, height: List[int]) -> int:
        n = len(height)
        i, j = 0, n - 1
        volume = 0
        while i < n - 1 and j > 0:
            if height[i] < height[j]:
                vol = height[i] * (j - i)
                i += 1
            else:
                vol = height[j] * (j - i)
                j -= 1
            if vol > volume:
                volume = vol
        return volume
