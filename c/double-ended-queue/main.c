#include <stdio.h>
#include "./dedqueue.h"

int main (void) {
    dedqueue queue;

    int instructions_amount = 0;
    scanf("%d", &instructions_amount);

    for (int i = 0; i < instructions_amount; i++) {
        int instruction;
        scanf("%d", &instruction);

        if (instruction == 1) {
            dedqueue_init(&queue);
        }

        if (instruction == 2) {
            int value;
            scanf("%d", &value);
            dedqueue_insert_first(&queue, value);
        }

        if (instruction == 3) {
            int value;
            scanf("%d", &value);
            dedqueue_insert_last(&queue, value);
        }

        if (instruction == 4) {
            printf("%d\n", queue.head->value);
            dedqueue_delete_first(&queue);
        }

        if (instruction == 5) {
            printf("%d\n", queue.tail->value);
            dedqueue_delete_last(&queue);
        }

        if (instruction == 6) {
            printf("%d\n", dedqueue_length(&queue));
            dedqueue_free(&queue);
        }
    }

    return 0;
}