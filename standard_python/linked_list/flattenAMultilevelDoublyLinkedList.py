# https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/description/

"""
# Definition for a Node.
class Node:
    def __init__(self, val, prev, next, child):
        self.val = val
        self.prev = prev
        self.next = next
        self.child = child
"""

class Solution:
    def flatten(self, head: 'Optional[Node]') -> 'Optional[Node]':
        if not head:
            return head
        flatten_list = Node(0)
        home = flatten_list

        def dfs(node):
            nonlocal flatten_list
            start = node
            while start:

                next_node = Node(start.val)
                flatten_list.next = next_node
                flatten_list.next.prev = flatten_list
                flatten_list = flatten_list.next
                if start.child:
                    dfs(start.child)
                start = start.next

        dfs(head)
        home.next.prev = None
        return home.next