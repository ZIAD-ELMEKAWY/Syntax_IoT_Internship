void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;      // Last valid element in nums1
    int j = n - 1;      // Last element in nums2
    int k = m + n - 1;  // Last position in the merged array
    
    // Merge from the back while both arrays have elements
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }
    
    // If nums2 still has remaining elements, copy them over.
    // (If nums1 has leftovers, they are already in the correct place.)
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
