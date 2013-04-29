#include <stdio.h>
#include <stdlib.h>
#include "dlx.h"

int
main()
{
    struct node *h = init(729, 324);
    struct node **solution = (struct node **) malloc(81 * sizeof(struct node *));
    int i, j, k;

    for (j = 0; j < 81; j++) {
        solution[j] = NULL;
    }

    int solved[9][9] = {4,0,0,0,0,0,8,0,5,0,3,0,0,0,0,0,0,0,0,0,0,7,0,0,0,0,0,0,2,0,0,0,0,0,6,0,0,0,0,0,8,0,4,0,0,0,0,0,0,1,0,0,0,0,0,0,0,6,0,3,0,7,0,5,0,0,2,0,0,0,0,0,1,0,4,0,0,0,0,0,0};

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++) {
            if (solved[i][j] == 0) {
                for (k = 0; k < 9; k++) {
                    insert(h, i*81 + j*9 + k, i*9 + j);
                    insert(h, i*81 + j*9 + k, 81 + 9*i + k);
                    insert(h, i*81 + j*9 + k, 162 + 9*j + k);
                    insert(h, i*81 + j*9 + k, 243 + (3*(i/3) + j/3) * 9 + k);
                }
            }
            else {
                k = solved[i][j];
                insert(h, i*81 + j*9 + k-1, i*9 + j);
                insert(h, i*81 + j*9 + k-1, 81 + 9*i + k-1);
                insert(h, i*81 + j*9 + k-1, 162 + 9*j + k-1);
                insert(h, i*81 + j*9 + k-1, 243 + (3*(i/3) + j/3) * 9 + k-1);
            }
        }
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++)
            printf("%d", solved[i][j]);
        printf("\n");
    }

    search(h, 0, solution);

    int row, col, num;
    for (i = 0; i < 81 && solution[i] != NULL; i++) {
        row = (solution[i]->r)/81;
        col = (solution[i]->r - row* 81)/9;
        num = (solution[i]->r)%9 + 1;
        solved[row][col] = num;
    }

    for (i = 0; i < 9; i++) {
        for (j = 0; j < 9; j++)
            printf("%d", solved[i][j]);
        printf("\n");
    }
    return 0;
}
