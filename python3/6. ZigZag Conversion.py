#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 6. ZigZag Conversion
@time: 2019-09-05 07:49
@desc:
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:

P     I    N
A   L S  I G
Y A   H R
P     I
"""

# 参考了https://www.cnblogs.com/grandyang/p/4128268.html
# 本质是找规律
class Solution:
    def convert(self, s: str, numRows: int) -> str:
        n = len(s)
        if n <= numRows or numRows <= 1:
            return s
        delta = 2 * numRows - 2
        result = ''
        for i in range(numRows):
            for j in range(i, n, delta):
                result += s[j]
                pos = j + delta - 2 * i
                if i != 0 and i != numRows - 1 and pos < n:
                    result += s[pos]
        return result

#第二种解法，暂时没有捋明白