int reverseBits(int n) {
    unsigned int num = n;   // Cast to unsigned: avoids sign-extension bugs on right shift
    unsigned int rev = 0;
    
    for (int i = 0; i < 32; i++) {
        rev <<= 1;          // 1. Make room in rev for the next bit
        rev |= (num & 1);   // 2. Take the LSB of num, put it into rev's LSB
        num >>= 1;          // 3. Drop the LSB we just processed
    }
    
    return (int)rev;
}
