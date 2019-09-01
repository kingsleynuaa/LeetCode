#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@file: 78.子集.py
@time: 2019-06-22 11:38
@desc:
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: nums = [1,2,3]
输出:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

"""


# 解法一 二进制的方式
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        """
        用二进制位来标记一个数是否存在于某个子集中, 然后挨个去check是否应该将指定位的数加入该子集
        外层循环为2^n 内层循环为n, 时间复杂度O(n*2^n)
        :param nums:
        :return:
        """
        nums_cnt = len(nums)
        result = []
        bit_num = 1 << nums_cnt
        for i in range(bit_num):
            sub_list = []
            for j in range(nums_cnt):
                if 1 << j & i != 0:
                    sub_list.append(nums[j])
            result.append(sub_list)
        return result


# 解法二 循环枚举
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        """发现了平时没有注意过的一个隐藏bug, result会不断增长,陷入死循环
        逐个枚举，空集的幂集只有空集，每增加一个元素，让之前幂集中的每个集合，追加这个元素，就是新增的子集。"""
        # import copy
        # nums_cnt = len(nums)
        # result = [[]]
        # for e in nums:
        #     # size = len(result)
        #     # for i in range(size):
        #     #     print(size,result[i],)
        #
        #     for f in result:
        #         print(e, f, )
        #         new_sub_list = copy.deepcopy(f)
        #         new_sub_list.append(e)
        #         result.append(new_sub_list)
        # return result
        result = [[]]
        for e in nums:
            size = len(result)
            for i in range(size):
                new_sub_list = list(result[i])
                new_sub_list.append(e)
                result.append(new_sub_list)
        return result


# 解法三 递归枚举
class Solution:
    def subsets(self, nums):
        result = [[]]
        self.reversion_set(nums, 0, result)
        return result

    def reversion_set(self, nums, i, res):
        if i >= len(nums):
            return
        size = len(res)
        for j in range(size):
            sub_list = list(res[j])
            sub_list.append(nums[i])
            res.append(sub_list)
        self.reversion_set(nums, i + 1, res)

# 其他还有二叉树的思想和回溯思想 tobecontinue
# https://leetcode-cn.com/problems/subsets/solution/er-jin-zhi-wei-zhu-ge-mei-ju-dfssan-chong-si-lu-9c/
