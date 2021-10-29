#include "container.h"

int getContainerIndex(char* src) {
    return *src & 0b00000011;
}

int getLen(char* src) {
    int length = 0;
    while(*src != '\0') {
        length++;
        src++;
    }
    return length;
}

int dupStr(char* src, char** dst) {
    int length = getLen(src);
    char *copy = (char*) calloc(length + 1, sizeof(char));
    for (int i = 0; i < length; i++) {
        copy[i] = src[i];
    }
    *dst = copy;
    return length;
}

int cmpStr(char* a, char* b) {
    while (*a == *b) {
        if (*a == '\0' || *b == '\0') {
            break;
        }
        a++;
        b++;
    }
    if (*a == '\0' && *b == '\0') {
        return 0;
    } else {
        return (*a == '\0' || *a < *b) ? 1 : -1;
    }
}

void split(char* source, int count, char** s1, char** s2) {
    int length = getLen(source);
    char *string1 = (char*) calloc(count + 1, sizeof(char));
    char *string2 = (char*) calloc(length - count + 1 > 0 ? length - count + 1 : 1, sizeof(char));
    for (int i = 0; i < length; i++) {
        if (i < count) {
            string1[i] = source[i];
        } else {
            string2[i - count] = source[i];
        }
    }
    *s1 = string1;
    *s2 = string2;
    free(source);
}

void sortedAdd(struct container* c, char* value) {
    char* dup;
    dupStr(value, &dup);
    int index = getContainerIndex(value);
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = dup;
    c->count++;
    if (c->data[index] == 0 || cmpStr(newNode->data, c->data[index]->data) == 1) {
        newNode->next = c->data[index];
        c->data[index] = newNode;
    } else {
        struct node* current = c->data[index];
        while (current->next != 0) {
            if (cmpStr(current->data, newNode->data) >= 0 && cmpStr(current->next->data, newNode->data) <= 0) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }
        newNode->next = 0;
        current->next = newNode;
    }
}

int contains(struct container* c, char* value) {
    int count = 0;
    int index = getContainerIndex(value);
    struct node* current = c->data[index];
    while (current != 0) {
        if (cmpStr(current->data, value) == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int inverseDelete(struct container* c, char* value) {
    int count = 0;
    int index = getContainerIndex(value);
    int i = 0;
    struct node* current = c->data[index];
    while (current->next != 0) {
        if (cmpStr(current->next->data, value) != 0) {
            count++;
            struct node* next = current->next;
            current->next = next->next;
            free(next->data);
            free(next);
        } else {
            current = current->next;
        }
    }
    current = c->data[index];
    while (current != 0) {
        if (cmpStr(current->data, value) != 0) {
            count++;
            c->data[index] = current->next;
            free(current->data);
            free(current);
        }
        current = current->next;
    }
    return count;
}

struct container* newContainer() {
    struct container* c = (struct container*) malloc(sizeof(struct container));
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
    for(int i = 0; i < 4; i++) {
        fprintf(stdout, "%i -> ", i);
        struct node* n = c->data[i];
        while(n != 0) {
            fprintf(stdout, "[%s]", n->data);
            n = n->next;
        }
        fprintf(stdout, "\n");
    }
}
