#include "doublyll.h"
#include <stdio.h>
#include <stdlib.h>

void print_with_traverse(void *item) { printf("%d ", *(int *)item); }

int main(void) {

        int i;
        int *j;

        printf("\n--- CREATING LIST ---\n");
        DoublyLinkedList *list = create_dll();

        printf("\n--- INSERTING ITEMS ---\n");
        for (i = 0; i < 5; i++) {
                insert_at(list, i, &i, sizeof(i));
        }
        printf("List after inserting: ");
        traverse(list, print_with_traverse);
        printf("\n");

        printf("\n--- INSERTING AT THE FRONT ---\n");
        i = 20;
        insert_at(list, 0, &i, sizeof(i));
        printf("List after inserting: ");
        traverse(list, print_with_traverse);
        printf("\n");

        printf("\n--- INSERTING AT THE BACK ---\n");
        i = 40;
        insert_at(list, list->length, &i, sizeof(i));
        printf("List after inserting: ");
        traverse(list, print_with_traverse);
        printf("\n");

        printf("\n--- REMOVING FROM THE FRONT ---\n");
        j = (int *)remove_at(list, 0);
        printf("Removed: %d\n", *j);
        free(j);
        printf("List after removing: ");
        traverse(list, print_with_traverse);
        printf("\n");

        printf("\n--- REMOVING FROM THE BACK ---\n");
        j = (int *)remove_at(list, list->length);
        printf("Removed: %d\n", *j);
        free(j);
        printf("List after removing: ");
        traverse(list, print_with_traverse);
        printf("\n");

        printf("\n--- SEARCHING WITH INDEX ---\n");
        i = 3;
        printf("Item at index 3: %d\n", *(int *)search(list, NULL, &i));
        printf("Length: %zu\n", list->length);

        printf("\n--- SEARCHING WITH ITEM ---\n");
        i = 2;
        j = (int *)search(list, (void *)&i, NULL);
        printf("Index of item '2': %d\n", *j);
        free(j);
        printf("Length: %zu\n", list->length);

        printf("\n--- INSERTING WITHIN LIST ---\n");
        i = 100;
        for (int k = 0; k < 5; k++) {
                i += 50 * k;
                insert_at(list, 2, &i, sizeof(i));
        }
        printf("List after inserting: ");
        traverse(list, print_with_traverse);
        printf("\n");

        printf("\n--- REMOVING WITHIN LIST ---\n");
        j = (int *)remove_at(list, list->length / 2);
        printf("Removed: %d\n", *j);
        free(j);
        printf("List after removing: ");
        traverse(list, print_with_traverse);
        printf("\n");

        printf("\n--- FREEING LIST ---\n");
        free_dll(list);

        return 0;
}
