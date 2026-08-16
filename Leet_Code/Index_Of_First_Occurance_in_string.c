int strStr(char* haystack, char* needle) {
    int hLen = 0, nLen = 0;
    
    // 1. Calculate lengths of both strings
    while (haystack[hLen] != '\0') hLen++;
    while (needle[nLen] != '\0') nLen++;
    
    // 2. Empty needle is conventionally found at index 0
    if (nLen == 0) return 0;
    
    // 3. Only check start positions where needle could fully fit
    for (int i = 0; i <= hLen - nLen; i++) {
        int j = 0;
        
        // 4. Compare needle against haystack starting at position i
        while (j < nLen && haystack[i + j] == needle[j]) {
            j++;
        }
        
        // 5. If we matched all of needle, return the start index
        if (j == nLen) {
            return i;
        }
    }
    
    // 6. No match found
    return -1;
}
