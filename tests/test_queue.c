#include "queue.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

void print_queue(Queue *queue) {
        if (!queue) {
                printf("invalid queue\n");
                return;
        }
        Node *curr = queue->head;
        while (curr) {
                printf("%i ", *(int *)curr->data);
                if (!curr->next)
                        printf("\n");
                curr = curr->next;
        }
}

int main(void) {

        int i;
        int *j;

        Queue *queue = create_queue();
        assert(queue != NULL);

        for (int i = 0; i < 5; i++) {
                enqueue(queue, &i, sizeof(i));
        }
        assert(queue->length == 5);
        assert(*(int *)peek(queue) == 0);

        for (i = 0; i < 2; i++) {
                j = (int *)dequeue(queue);
                assert(*j == i);
                free(j);
                j = NULL;
        }
        assert(j == NULL);
        assert(queue->length == 3);

        free_queue(queue);

        return 0;
}
