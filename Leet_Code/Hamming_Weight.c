int hammingWeight(int n) {
    unsigned int num = n;   // Cast to unsigned: safe bit manipulation
    int count = 0;
    
    while (num) {
        num &= num - 1;     // Magic: clears the lowest set bit
        count++;
    }
    
    return count;
}
