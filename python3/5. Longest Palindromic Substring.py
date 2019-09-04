#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 5. Longest Palindromic Substring
@time: 2019-09-01 22:51
@desc:
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"
Accepted
638,260
Submissions
2,294,694

"""


# 思路还是以某个字母为中心向左右搜索，实际上偶数长度串的情况可以认为是向右移动重复串
# 参考https://www.cnblogs.com/grandyang/p/4464476.html
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        start = 0
        end = 0
        max_len = 0
        for i in range(n):
            left = i
            right = i
            while right < n - 1 and s[right + 1] == s[right]:
                right += 1
            while left > 0 and right < n - 1 and s[right + 1] == s[left - 1]:
                right += 1
                left -= 1
            if right - left + 1 > max_len:
                max_len = right - left + 1
                start = left
                end = right
        return s[start:end + 1]


# 动态规划的算法，实际就是摸清楚递推关系
# 维护一个二维数组 dp，其中 dp[i][j] 表示字符串区间 [i, j] 是否为回文串，当 i = j 时，只有一个字符，肯定是回文串，如果 i = j + 1，说明是相邻字符，此时需要判断 s[i] 是否等于 s[j]，如果i和j不相邻，即 i - j >= 2 时，除了判断 s[i] 和 s[j] 相等之外，dp[i + 1][j - 1] 若为真，就是回文串，通过以上分析，可以写出递推式如下：
#
# dp[i, j] = 1                                      if i == j
#          = s[i] == s[j]                            if j = i + 1
#          = s[i] == s[j] && dp[i + 1][j - 1]    if j > i + 1
# DP 的算法注意搞清楚ij的填充过程，(没有搞懂)

class Solution:
    def longestPalindrome(self, s: str) -> str:
        import numpy as np
        n = len(s)
        max_len = 0
        start = 0
        end = 0
        dp = np.zeros((n, n), dtype=np.int)
        for i in range(n):
            dp[i][i] = 1
            for j in range(0, i):
                if i == j + 1 and s[i] == s[j]:
                    dp[j][i] = 1
                if s[i] == s[j] and dp[j + 1][i - 1]:
                    dp[j][i] = 1
                if dp[j][i] == 1 and i - j + 1 > max_len:
                    max_len = i - j + 1
                    start = j
                    end = i
        return s[start:end + 1]


# 额外还有算法，这次先不考虑了
# https://www.cnblogs.com/grandyang/p/4475985.html



