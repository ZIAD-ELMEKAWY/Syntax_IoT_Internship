#include <stdlib.h>
#include <string.h>

char* addBinary(char* a, char* b) {
    int i = strlen(a) - 1;   // Pointer to end of a
    int j = strlen(b) - 1;   // Pointer to end of b
    int carry = 0;
    int k = 0;               // Length of result built so far
    
    // Allocate enough space: max(len(a), len(b)) + 1 (carry) + 1 ('\0')
    int maxLen = (i > j ? i : j) + 3;
    char* result = (char*)malloc(maxLen * sizeof(char));
    
    // Add from right to left
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        
        result[k++] = (sum % 2) + '0';  // Current bit
        carry = sum / 2;                 // Carry for next iteration
    }
    
    // Null-terminate
    result[k] = '\0';
    
    // Reverse the string (we built it LSB -> MSB)
    for (int left = 0, right = k - 1; left < right; left++, right--) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }
    
    return result;
}
