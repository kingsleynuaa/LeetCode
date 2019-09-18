#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 9. Palindrome Number
@time: 2019-09-08 20:48
@desc:
Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.

Example 1:

Input: 121
Output: true
Example 2:

Input: -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
Example 3:

Input: 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
Follow up:

Coud you solve it without converting the integer to a string?

Accepted
666,828
Submissions
1,489,962
"""


class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        x = str(x)
        n = len(x)
        for i in range(n // 2 + 1):
            j = n - i - 1
            if i < n and j < n and x[i] == x[j]:
                continue
            else:
                break
        if i < n // 2:
            return False
        else:
            return True



