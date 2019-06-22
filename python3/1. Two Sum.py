#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 1. Two Sum
@time: 2019-08-31 09:28
@desc:
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

第一轮刷题先寻找感觉, 能找到非直接能想到的办法即可，不追求极致。
本题实际是查找问题，主要是使用hash表加速查找

"""


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        remainder_dict = {target - v: k for k, v in enumerate(nums)}
        for k, v in enumerate(nums):
            if v in remainder_dict.keys() and k != remainder_dict[v]:
                return [k, remainder_dict[v]]
