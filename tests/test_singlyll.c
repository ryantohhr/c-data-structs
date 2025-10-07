#include "singlyll.h"
#include <stdio.h>
#include <stdlib.h>

void print_with_traverse(void *item) { printf("%d ", *(int *)item); }

int main(void) {

        int i;
        int *j;

        printf("\n--- CREATING LIST ---\n");
        SinglyLinkedList *list = create_sll();

        printf("\n--- INSERTING ITEMS ---\n");
        for (i = 0; i < 5; i++) {
                insert_back(list, &i, sizeof(i));
        }
        printf("List after inserting: ");
        traverse(list, &print_with_traverse);
        printf("\n");
        printf("Length: %zu\n", list->length);

        printf("\n--- INSERTING 3 ITEMS TO THE FRONT\n");
        for (i = 0; i < 3; i++) {
                insert_front(list, &i, sizeof(i));
        }
        printf("List after inserting: ");
        traverse(list, print_with_traverse);
        printf("\n");
        printf("Length: %zu\n", list->length);

        printf("\n--- INSERTING 3 ITEMS TO THE BACK\n");
        for (i = 0; i < 3; i++) {
                insert_back(list, &i, sizeof(i));
        }
        printf("List after inserting: ");
        traverse(list, print_with_traverse);
        printf("\n");
        printf("Length: %zu\n", list->length);

        printf("\n--- REMOVING 3 ITEMS FROM THE FRONT\n");
        for (i = 0; i < 3; i++) {
                j = (int *)remove_front(list);
                printf("Removed: %d\n", *j);
                free(j);
        }
        printf("List after removing: ");
        traverse(list, print_with_traverse);
        printf("\n");
        printf("Length: %zu\n", list->length);

        printf("\n--- REMOVING 3 ITEMS FROM THE BACK\n");
        for (i = 0; i < 3; i++) {
                j = (int *)remove_back(list);
                printf("Removed: %d\n", *j);
                free(j);
        }
        printf("List after removing: ");
        traverse(list, print_with_traverse);
        printf("\n");
        printf("Length: %zu\n", list->length);

        printf("\n--- SEARCHING WITH INDEX ---\n");
        i = 3;
        printf("Item at index 3: %d\n", *(int *)search(list, NULL, &i));
        printf("Length: %zu\n", list->length);

        printf("\n--- FREEING LIST ---\n");
        free_sll(list);
}
