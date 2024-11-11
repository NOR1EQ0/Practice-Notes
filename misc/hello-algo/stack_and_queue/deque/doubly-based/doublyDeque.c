#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


typedef struct DoublyListDeque {
    int val;
    DoublyListDeque *next;
    DoublyListDeque *prev;
} DoublyListDeque;

DoublyListDeque* newDoublyListDeque(int num) {
    DoublyListDeque* new = (DoublyListDeque*)malloc(sizeof(DoublyListDeque));
    new->val = num;
    new->next = NULL;
    new->prev = NULL;
    return new;
}