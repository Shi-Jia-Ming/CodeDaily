#include "daily.h"
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]) {

    int fileNum;
    scanf("%d", &fileNum);

    ArrayNode * head = getFile(fileNum);

    int searchNum;

    scanf("%d", &searchNum);

    double * res = getRate(head, searchNum);
    int i;
    for (i = 0; i < searchNum - 1; ++i) {
        printf("%.1f%c\n", res[i], '%');
    }
    printf("%.1f%c", res[i], '%');
    free(res);

    freeAll(head);

    return 0;
}
