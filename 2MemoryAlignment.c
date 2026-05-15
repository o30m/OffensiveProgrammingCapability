#include <stdio.h>

// 1. NATURAL ALIGNMENT & PADDING
// The compiler inserts 3 bytes of padding after 'a' to align 'b' to a 4-byte boundary.
// Total size: 1 (char) + 3 (padding) + 4 (int) = 8 bytes.
struct PaddedStruct {
    char a;    
    int b;     
};

// 2. PACKED STRUCTURE
// Bypasses natural alignment rules. Forces 1-byte alignment (no padding).
// Total size: 1 (char) + 4 (int) = 5 bytes.
#pragma pack(push, 1)
struct PackedStruct {
    char a;    
    int b;     
};
#pragma pack(pop)

int main() {
    struct PaddedStruct normal;
    struct PackedStruct packed;

    // 3. SHOWING SIZES & OFFSETS
    printf("--- Natural Alignment & Padding ---\n");
    printf("Total Size: %zu bytes\n", sizeof(normal));
    printf("Offset of 'a': %zu\n", (size_t)&normal.a - (size_t)&normal);
    printf("Offset of 'b': %zu (3 bytes padding added before 'b')\n\n", (size_t)&normal.b - (size_t)&normal);

    printf("--- Packed Structure ---\n");
    printf("Total Size: %zu bytes\n", sizeof(packed));
    printf("Offset of 'a': %zu\n", (size_t)&packed.a - (size_t)&packed);
    printf("Offset of 'b': %zu (0 bytes padding)\n", (size_t)&packed.b - (size_t)&packed);

    return 0;
}
