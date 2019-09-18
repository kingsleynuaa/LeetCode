#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 7. Reverse Integer
@time: 2019-09-08 18:09
@desc:
Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range:
[−231,  231 − 1].
For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
"""

# 这种方法估计不是出题者的本意？
class Solution:
    def reverse(self, x: int) -> int:
        flag = False
        if x < 0:
            flag = True
            x = -x
        x = str(x)[::-1]
        if flag == True:
            x = 0 - int(x)
        else:
            x = int(x)
        if x < -pow(2, 31) or x > pow(2, 31) - 1:
            return 0
        else:
            return x

#这种才是本意？
class Solution:
    def reverse(self, x: int) -> int:
        result = 0
        if x < 0:
            x = -x
            x = str(x)[::-1]
            mi = pow(2, 31)
            for e in x:
                if mi - result * 10 > int(e):
                    result = result * 10 + int(e)
                else:
                    return 0
            return -result
        else:
            x = str(x)[::-1]
            ma = pow(2, 31) - 1
            for e in x:
                if ma - result * 10 > int(e):
                    result = result * 10 + int(e)
                else:
                    return 0
            return result

