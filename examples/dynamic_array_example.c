#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <kanlib/dynamic_array.h>

size_t square(size_t x) {
    return x * x;
}

void da_add(dynamic_array* da) {
    for ( size_t i=1; i<=10; ++i ) {
        dynamic_array_add(da, (int*) i);
    }
}

void da_square(dynamic_array* da) {
    for ( size_t i=0; i<dynamic_array_size(da); ++i ) {
        intptr_t curr = (intptr_t) dynamic_array_get(da, i);
        dynamic_array_set(da, i, (int*) square(curr));
    }
}

void da_print(dynamic_array* da) {
    for ( size_t i=0; i<dynamic_array_size(da); ++i ) {
        printf("%ld ", (intptr_t) dynamic_array_get(da, i));
    }
    printf("\n");
}

int main(int argc, char const *argv[]) {
    
    dynamic_array d_array;
    dynamic_array* da = &d_array;

    dynamic_array_init(da);
    da_add(da);

    printf("%s ", "Before taking square of elements:");
    da_print(da);

    da_square(da);
    
    printf("%s ", "After taking square of elements:");
    da_print(da);    

    dynamic_array_free(da);

    return 0;
}
