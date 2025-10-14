#include "doublyll.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

        int i;
        int *j;

        // Test create_dll
        DoublyLinkedList *list = create_dll();
        assert(list != NULL);

        // Test insert_at, search
        for (i = 0; i < 5; i++) {
                insert_at(list, i, &i, sizeof(i));
        }
        assert(list->length == 5);

        i = 20;
        insert_at(list, 0, &i, sizeof(i));
        assert(list->length == 6);
        i = 0;
        assert(*(int *)search(list, NULL, &i) == 20);

        i = 40;
        insert_at(list, list->length, &i, sizeof(i));
        assert(list->length == 7);
        i = 6;
        assert(*(int *)search(list, NULL, &i) == 40);

        i = 100;
        for (int k = 0; k < 5; k++) {
                i += 50 * k;
                insert_at(list, 2, &i, sizeof(i));
        }
        assert(list->length == 12);
        i = 6;
        assert(*(int *)search(list, NULL, &i) == 100);

        // Test remove_at
        j = (int *)remove_at(list, 0);
        assert(*j == 20);
        free(j);

        j = (int *)remove_at(list, list->length);
        assert(*j == 40);
        free(j);

        j = (int *)remove_at(list, list->length / 2);
        assert(*j == 100);
        free(j);

        free_dll(list);
        printf("\nALL TESTS PASSED!\n");

        return 0;
}
