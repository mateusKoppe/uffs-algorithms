#include <stdio.h>
#include <stdlib.h>

void main() {
    char studants[40][50];
    int studants_amount;
    scanf("%d ",&studants_amount);
    for (int i = 0; i < studants_amount; i++) {
        scanf("%[^\n] ", &studants[i]);
    }

    char outputs[100];
    int prints;
    scanf("%d ",&prints);

    for (int i = 0; i < prints; i++) {
        int studant_index;
        scanf("%d ",&studant_index);
        char name_option;
        scanf("%c ",&name_option);
        if (name_option == 'p') {
            printf("%c\n", studants[studant_index][0]);
        } else {
            for (int j = 0; j < 40; j++) {
                if (studants[studant_index][j] == ' ') {
                    printf("%c\n", studants[studant_index][j+1]);
                    break;
                }
            }
        }
    }
}