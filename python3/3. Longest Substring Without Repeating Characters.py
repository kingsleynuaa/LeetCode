#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 3. Longest Substring Without Repeating Characters
@time: 2019-08-31 17:11
@desc:
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

思路还是比较清晰的：双指针往后走
方法效率不是很高，12.11% 5.10%
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        s_len = len(s)
        result = 0
        for i in range(s_len):
            tmp_result = {}
            for j in range(i, s_len):
                if s[j] not in tmp_result:
                    tmp_result[s[j]] = 0
                else:
                    if len(tmp_result.keys()) > result:
                        result = len(tmp_result.keys())
                    break
                if j == s_len - 1:
                    if len(tmp_result.keys()) > result:
                        result = len(tmp_result.keys())

        return result

