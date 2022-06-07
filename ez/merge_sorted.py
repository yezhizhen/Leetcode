
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        target_loc = -1
        n1_p = m - 1
        n2_p = n - 1
        
        while n1_p >= 0 and n2_p >= 0:
            if nums1[n1_p] > nums2[n2_p]:
                nums1[target_loc] = nums1[n1_p]
                n1_p -= 1
            else:
                nums1[target_loc] = nums2[n2_p]
                n2_p -= 1
            target_loc -= 1
        
        #deal with residual
        while n2_p >= 0:
            nums1[target_loc] = nums2[n2_p]
            n2_p -= 1
            target_loc -= 1
            
        