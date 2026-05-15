#include <stdio.h>
#include <stdint.h>

// 1. TYPE PUNNING VIA UNION (Standard Compliant)
// Reading a different member than the one last written is explicitly allowed in C.
union TypePunner {
    float f;
    uint32_t i;
};

int main() {
    float float_val = 1.0f; // Binary: 0x3F800000

    // 2. STRICT ALIASING VIOLATION (Undefined Behavior)
    // You cannot point an integer pointer to a float memory address.
    // The compiler assumes 'float_val' and '*bad_ptr' never share the same memory.
    uint32_t *bad_ptr = (uint32_t *)&float_val; 
    
    printf("--- Strict Aliasing Rule ---\n");
    printf("Pointer Cast: 0x%X (May misoptimize or crash)\n\n", *bad_ptr);

    // 3. SAFE TYPE PUNNING VIA UNION (Defined Behavior)
    union TypePunner pun;
    pun.f = float_val; 

    printf("--- Type Punning via Union ---\n");
    printf("Union Cast:   0x%X (Safe and predictable)\n", pun.i);

    return 0;
}
