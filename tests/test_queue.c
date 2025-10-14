#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {

        int i;
        int *j;

        // Test create_queue
        Queue *queue = create_queue();
        assert(queue != NULL);

        // Test enqueue
        for (int i = 0; i < 5; i++) {
                enqueue(queue, &i, sizeof(i));
        }
        assert(queue->length == 5);

        // Test peek
        assert(*(int *)peek(queue) == 0);

        // Test dequeue
        for (i = 0; i < 2; i++) {
                j = (int *)dequeue(queue);
                assert(*j == i);
                free(j);
                j = NULL;
        }
        assert(queue->length == 3);

        free_queue(queue);
        printf("\nALL TESTS PASSED!\n");

        return 0;
}
