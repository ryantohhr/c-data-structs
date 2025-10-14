#include "singlyll.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

        int i;
        int *j;

        // Test create_sll
        SinglyLinkedList *list = create_sll();
        assert(list != NULL);

        // Test insert_back
        for (i = 0; i < 5; i++) {
                insert_back(list, &i, sizeof(i));
        }
        assert(list->length == 5);

        // Test insert_front
        for (i = 0; i < 3; i++) {
                insert_front(list, &i, sizeof(i));
        }
        assert(list->length == 8);

        // Test insert_back
        for (i = 0; i < 3; i++) {
                insert_back(list, &i, sizeof(i));
        }
        assert(list->length == 11);

        // Test remove_front
        for (i = 0; i < 3; i++) {
                j = (int *)remove_front(list);
                assert(*j == 2 - i);
                free(j);
        }
        assert(list->length == 8);

        // Test remove_back
        for (i = 0; i < 3; i++) {
                j = (int *)remove_back(list);
                assert(*j == 2 - i);
                free(j);
        }

        // Test search
        i = 3;
        assert(*(int *)search(list, NULL, &i) == 3);

        i = 2;
        j = (int *)search(list, (void *)&i, NULL);
        assert(*j == 2);
        free(j);

        free_sll(list);
        printf("\nALL TESTS PASSED!\n");

        return 0;
}
