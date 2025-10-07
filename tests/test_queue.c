#include "queue.h"
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

        printf("\n--- CREATING QUEUE ---\n");
        Queue *queue = create_queue();

        printf("\n--- INSERTING ITEMS ---\n");
        for (int i = 0; i < 5; i++) {
                enqueue(queue, &i, sizeof(i));
        }

        printf("Queue after inserting: ");
        print_queue(queue);
        printf("Length: %zu nodes\n", queue->length);
        printf("Peek first item: %d\n", *(int *)peek(queue));

        printf("\n--- DEQUEING ITEMS ---\n");
        for (i = 0; i < 2; i++) {
                j = (int *)deque(queue);
                printf("Dequeued: %d\n", *j);
                free(j);
        }

        printf("Queue after dequeuing: ");
        print_queue(queue);
        printf("Length: %zu nodes\n", queue->length);
        printf("Peek first item: %d\n", *(int *)peek(queue));

        printf("\n--- FREEING QUEUE ---\n");
        free_queue(queue);

        printf("END\n");
        return 0;
}
