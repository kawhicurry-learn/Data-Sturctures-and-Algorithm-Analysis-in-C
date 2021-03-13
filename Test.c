#include <stdio.h>
int main( ) {
    int i;
    while (scanf("%d", &i) != EOF) {
        if (i % 2 != 0) {
            i = (1 + i) / 2 * i;
        } else {
            i = i / 2 * (1 + i);
        }
        printf("%d\n\n", i);
    }
    return 0;
}
// test for git