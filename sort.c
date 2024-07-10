#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

int compare(const void *a, const void *b) {
    return strcmp((char *)a, (char *)b);
}

int main() {
    char names[100][MAX_NAME_LEN];
    int count = 0;

    while (scanf("%s", names[count]) != EOF) {
        count++;
    }

    qsort(names, count, MAX_NAME_LEN, compare);

    printf("Sorted student names:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", names[i]);
    }

    return 0;
}
