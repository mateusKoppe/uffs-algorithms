/// https://susy.ic.unicamp.br:9999/gx605/11/enunc.html

#include <stdio.h>

typedef struct {
    char type;
    int value;
} operation;

int count_inserts (operation operations[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) 
        if (operations[i].type == 'I') count++;

    return count;
}


int count_removes (operation operations[], int size) {
    int count = 0;

    for (int i = 0; i < size; i++) 
        if (operations[i].type == 'R') count++;

    return count;
}

int is_queue (operation operations[], int size) {
    int inserts = count_inserts(operations, size);
    int values[inserts];

    int inserted_values = 0;
    for (int i = 0; i < size; i++) {
        if (operations[i].type == 'I') {
            values[inserted_values] = operations[i].value;
            inserted_values++;
        }

        if (operations[i].type == 'R') {
            if (values[0] != operations[i].value) return 0;
            inserted_values--;

            for (int j = 0; j < inserted_values; j++) values[j] = values[j+1];
        }
    }

    return 1;
}

int is_stack (operation operations[], int size) {
    int inserts = count_inserts(operations, size);
    int values[inserts];

    int inserted_values = 0;
    for (int i = 0; i < size; i++) {
        if (operations[i].type == 'I') {
            values[inserted_values] = operations[i].value;
            inserted_values++;
        }

        if (operations[i].type == 'R') {
            if (values[inserted_values - 1] != operations[i].value) return 0;
            inserted_values--;
        }
    }

    return 1;
}


int main () {
    int inputs;
    scanf("%d", &inputs);

    operation operations[inputs];

    for (int i = 0; i < inputs; i++) {
        char type;
        int value;
        scanf(" %c", &operations[i].type);
        scanf("%d", &operations[i].value);
    }

    int inserts_amount = count_inserts(operations, inputs);
    int remove_amount = count_removes(operations, inputs);

    if (remove_amount == 0) {
        printf("nem Turing sabe!\n");
        return 0;
    }

    if (is_queue(operations, inputs)) {
        printf("fila!\n");
        return 0;
    }

    if (is_stack(operations, inputs)) {
        printf("pilha!\n");
        return 0;
    }

    printf("jokerBag!\n");
    return 0;
}