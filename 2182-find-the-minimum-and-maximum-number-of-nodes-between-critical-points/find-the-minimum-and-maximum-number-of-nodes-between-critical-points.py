# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def nodesBetweenCriticalPoints(self, head: Optional[ListNode]) -> List[int]:
        if head is None:
            return [-1,-1]
        elif head.next is None:
            return [-1,-1]
        elif head.next.next is None:
            return [-1,-1]
        else:
            mindist = sys.maxsize
            maxdist = 0
            last = 0

            cur = head.next
            prev = head
            index = 1
            while cur.next:
                print(index, cur.val)
                if prev.val <cur.val and cur.val>cur.next.val:
                    if last:
                        mindist = min(mindist, index-last)
                        maxdist = max(maxdist, index-last+maxdist)
                    last = index
                elif prev.val>cur.val and cur.val<cur.next.val:
                    if last:
                        mindist = min(mindist, index-last)
                        maxdist = max(maxdist, index-last+maxdist)
                    last = index

                prev = cur
                cur = cur.next
                index = index+1

            if maxdist == 0:
                maxdist = -1
            if mindist == sys.maxsize:
                mindist = -1
            return [mindist, maxdist]                    