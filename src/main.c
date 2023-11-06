#include "daily.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[]) {
    char ** words = (char **) malloc(sizeof(char *) * 7);
    int wordsSize = 7;
    for (int i = 0; i < wordsSize; ++i)
        words[i] = (char *) malloc(sizeof(char) * 6);
    words[0] = "a";
    words[1] = "ab";
    words[2] = "abc";
    words[3] = "d";
    words[4] = "cd";
    words[5] = "bcd";
    words[6] = "abcd";
//    words[0] = "a";
//    words[1] = "aa";
//    words[2] = "aaa";
//    words[3] = "aaaa";
//words[0] = "abcw";
//words[1] = "baz";
//words[2] = "foo";
//words[3] = "bar";
//words[4] = "xtfn";
//words[5] = "abcdef";
    printf("%d", maxProduct(words, wordsSize));
}
