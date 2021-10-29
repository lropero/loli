#include "container.h"

int dupStr(char* src, char** dst) {

    // COMPLETAR

    return 0;
}

int cmpStr(char* a, char* b) {

    // COMPLETAR

    return 0;
}

void split(char* source, int count, char** s1, char** s2) {

    // COMPLETAR

}

void sortedAdd(struct container* c, char* value) {

    // COMPLETAR

}

int contains(struct container* c, char* value) {

    // COMPLETAR

    return 0;
}

int inverseDelete(struct container* c, char* value) {

    // COMPLETAR

    return 0;
}

struct container* newContainer() {
    struct container* c = (struct container*)malloc(sizeof(struct container));
    c->data[0] = 0;
    c->data[1] = 0;
    c->data[2] = 0;
    c->data[3] = 0;
    c->count = 0;
    return c;
}

void deleteContainer(struct container* c) {
    for(int i=0; i<4; i++) {
        struct node* n = c->data[i];
        while(n != 0) {
            struct node* t = n;
            n = n->next;
            free(t->data);
            free(t);
        }
    }
    free(c);
}

void printContainer(struct container* c) {
    for(int i=0; i<4; i++) {
        fprintf(stdout,"%i -> ",i);
        struct node* n = c->data[i];
        while(n != 0) {
            fprintf(stdout,"[%s]",n->data);
            n = n->next;
        }
        fprintf(stdout,"\n");
    }
}
