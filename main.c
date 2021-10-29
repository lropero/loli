#include <stdio.h>
#include <stdlib.h>

#include "container.h"

int main() {
    // dupStr
    char* dup;
    int size = dupStr("hola", &dup);
    printf("dupStr(\"hola\", &dup) -> size = %i, dup = \"%s\"\n", size, dup);
    free(dup);

    // cmpStr
    printf("cmpStr(\"abc\", \"abc\") -> %i\n", cmpStr("abc", "abc"));
    printf("cmpStr(\"abcd\", \"abc\") -> %i\n", cmpStr("abcd", "abc"));
    printf("cmpStr(\"abc\", \"abcd\") -> %i\n", cmpStr("abc", "abcd"));

    // split
    dupStr("Hola Carola", &dup);
    char* s1;
    char* s2;
    printf("split(\"%s\", 5, &s1, &s2) -> ", dup);
    split(dup, 5, &s1, &s2);
    printf("s1=\"%s\", s2=\"%s\"\n", s1, s2);
    free(s1);
    free(s2);

   // sortedAdd
    struct container* c = newContainer();
    printContainer(c);
    sortedAdd(c, "perro");
    sortedAdd(c, "perro");
    sortedAdd(c, "gato");
    sortedAdd(c, "elefante");
    sortedAdd(c, "burro");
    sortedAdd(c, "pato");
    sortedAdd(c, "paloma");
    printContainer(c);

    // contains
    printf("contains(c, \"perro\") -> %i\n", contains(c, "perro"));
    printf("contains(c, \"carola\") -> %i\n", contains(c, "carola"));

    // inverseDelete
    inverseDelete(c, "perro");
    printContainer(c);
}
