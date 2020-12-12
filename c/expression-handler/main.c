#include <stdio.h>


char expression_handler (char operator, char* values) {
    if (operator == 'E') {
        if (values[0] == 'v' && values[1] == 'v') {
            return 'v';
        }
        return 'f';
    }

    if (operator == 'O') {
        if (values[0] == 'v' || values[1] == 'v') {
            return 'v';
        }
        return 'f';
    }

    if (operator == 'O') {
        if (values[0] == 'v' || values[1] == 'v') {
            return 'v';
        }
        return 'f';
    }

    if (operator == 'X') {
        if ((values[0] == 'v' && values[1] == 'f') || (values[0] == 'f' && values[1] == 'v')) {
            return 'v';
        }
        return 'f';
    }

    if (operator == 'N') {
        if (!values[0] == 'v') {
            return 'v';
        }
        return 'f';
    }

    return 'f';
}

int get_operator_params(char operator) {
    if (operator == 'E' | operator == 'O' || operator == 'X') return 2;
    if (operator == 'N') return 1;
    return 0;
}

char get_operator_value(char* items, int operator_index) {
    char operator = items[operator_index];
    int params = get_operator_params(operator);

    char values[2];
    int first_param = operator_index - params;
    for (int i = first_param; i < operator_index; i++) {
        values[i - first_param] = items[i];
    }

    return expression_handler(operator, values);
}

int find_first_operator(char* items, int size) {
    for (int i = 0; i < size; i++) {
        char token = items[i];
        if (token == 'E' | token == 'O' | token == 'N' | token == 'X') return i;
    }

    return -1;
}

char run_expression (char* items, int size) {
    int operator_index = find_first_operator(items, size);

    if (operator_index == -1) return items[0];
   
    char operator = items[operator_index];
    int params = get_operator_params(operator);
    int new_size = size - params;
    char new_items[size - params];
    int new_operator_index = operator_index - params;

    for (int i = 0; i < new_operator_index; i++) new_items[i] = items[i];

    new_items[new_operator_index] = get_operator_value(items, operator_index);

    for (int i = new_operator_index + 1; i < new_size; i++) new_items[i] = items[i + params];

    return run_expression(new_items, new_size);
}

int count_values (char* items, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        char token = items[i];
        if (token == 'v' || token == 'f') count++;
    }
    return count;
}

int count_operators (char* items, int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        char token = items[i];
        if (token == 'N' || token == 'E' || token == 'O' || token == 'X') count++;
    }
    return count;
}

int main () {
    int inputs = 0;
    scanf("%d", &inputs);
    char items[inputs];

    for (int i = 0; i < inputs; i++) {
        char option;
        scanf(" %c", &option);
        items[i] = option;
    }

    printf("values: %d\n", count_values(items, inputs));
    printf("operators: %d\n", count_operators(items, inputs));
    printf("result: %c\n", run_expression(items, inputs));

    return 0;
}