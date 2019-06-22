#!/usr/bin/env python
# encoding: utf-8
"""
@author: AC4Fun
@contact: kingsleynuaa AT gmail DOT com
@file: 2. Add Two Numbers
@time: 2019-08-31 10:09
@desc:
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.

此题可以很好的熟悉链表的一些基础操作
有空可以复习一下C语言对链表的操作
"""


# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        carry = 0
        p = None
        head = None
        l1_p = l1
        l2_p = l2
        while l1_p or l2_p:
            if l1_p and l2_p:
                val = l1_p.val + l2_p.val + carry
                l1_p = l1_p.next
                l2_p = l2_p.next
            elif l1_p:
                val = l1_p.val + carry
                l1_p = l1_p.next
            else:
                val = l2_p.val + carry
                l2_p = l2_p.next
            carry = val // 10
            val = val - carry * 10
            if not head:
                p = ListNode(val)
                head = p
            else:
                p.next = ListNode(val)
                p = p.next
        if carry == 1:
            p.next = ListNode(carry)

        return head
