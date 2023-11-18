#include "daily.h"
#include <stdio.h>


int main(int argc, char const *argv[]) {

    int N, C;
    scanf("%d %d", &N, &C); // NOLINT(*-err34-c)


    char *** data = scanData(N);
    data = switchSort(data, N, C);
    printData(data, N);
    freeData(data, N);
    return 0;
}
