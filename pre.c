#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LEN 50

typedef struct {
    char name[MAX_NAME_LEN];
    float gpa;
} Student;

int main() {
    Student students[100];
    int count = 0;

    while (scanf("%s %f", students[count].name, &students[count].gpa) != EOF) {
        count++;
    }

    printf("Students with GPA above 3.0:\n");
    for (int i = 0; i < count; i++) {
        if (students[i].gpa > 3.0) {
            printf("%s\n", students[i].name);
        }
    }

    return 0;
}
