#include "queue.h"
#include <stdio.h>

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

        printf("--- CREATING QUEUE ---\n");
        Queue *queue = create_queue();

        printf("--- INSERTING ITEMS ---\n");
        for (int i = 0; i < 5; i++) {
                enqueue(queue, &i, sizeof(i));
        }

        printf("Queue after inserting: ");
        print_queue(queue);
        printf("Length: %zu nodes\n", queue->length);
        printf("Peek first item: %d\n", *(int *)peek(queue));

        printf("--- DEQUEING ITEMS ---\n");
        deque(queue);
        deque(queue);

        printf("Queue after dequeuing: ");
        print_queue(queue);
        printf("Length: %zu nodes\n", queue->length);
        printf("Peek first item: %d\n", *(int *)peek(queue));

        printf("--- FREEING QUEUE ---\n");
        free_queue(queue);

        printf("END\n");
        return 0;
}
