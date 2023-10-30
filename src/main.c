#include "daily.h"
#include <stdio.h>


int main(int argc, char const *argv[]) {

    initQueue();
    push(1);
    push(2);
    push(3);
    printf("%d\t", pop());
    printf("%d\t", pop());
    printf("%d\t", pop());
    freeQueue();
    return 0;
}
