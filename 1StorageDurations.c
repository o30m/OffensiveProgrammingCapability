#include <stdio.h>
#include <stdlib.h>

// 1. STATIC: Lifetime matches program lifetime
int global_static = 10; 

void demo() {
    // 2. AUTOMATIC: Lifetime matches block execution
    int auto_var = 20; 

    // 3. THREAD-LOCAL: Lifetime matches thread lifetime (Windows GCC compliant)
    static __thread int tl_var = 30;

    // 4. ALLOCATED: Lifetime managed manually via heap
    int *allocated_var = (int*)malloc(sizeof(int));
    if (allocated_var) {
        *allocated_var = 40;
        printf("Auto: %d | Static: %d | TL: %d | Allocated: %d\n", 
                auto_var, global_static, tl_var, *allocated_var);
        free(allocated_var); 
    }
}

int main() {
    demo();
    return 0;
}
