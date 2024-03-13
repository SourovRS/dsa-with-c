#include<stdio.h>
#include<stdlib.h>
typedef struct link {
    int coeff;
    int pow;
    struct link * next;
} my_ply;

void my_create_ply(my_ply **);
void my_show_ply(my_ply *);
void my_add_ply(my_ply **, my_ply *, my_ply *);

int main(void) {
    int ch;
    do {
        my_ply * ply1, * ply2, * ply3;
 
        printf("\nCreate 1st expression\n");
        my_create_ply(&ply1);
        printf("\nStored the 1st expression");
        my_show_ply(ply1);
 
        printf("\nCreate 2nd expression\n");
        my_create_ply(&ply2);
        printf("\nStored the 2nd expression");
        my_show_ply(ply2);
 
        my_add_ply(&ply3, ply1, ply2);
        my_show_ply(ply3);
 
        printf("\nAdd two more expressions? (Y = 1/N = 0): ");
        scanf("%d", &ch);
    } while (ch);
    return 0;
}

void my_create_ply(my_ply ** node) {
    int flag; //A flag to control the menu
    int coeff, pow;
    my_ply * tmp_node; //To hold the temporary last address
    tmp_node = (my_ply *) malloc(sizeof(my_ply)); //create the first node
    *node = tmp_node; //Store the head address to the reference variable
    do {
        printf("\nEnter Coeff:");
        scanf("%d", &coeff);
        tmp_node->coeff = coeff;
        printf("\nEnter Pow:");
        scanf("%d", &pow);
        tmp_node->pow = pow;

        tmp_node->next = NULL;

        printf("\nContinue adding more terms to the plynomial list?(Y = 1/N = 0): ");
        scanf("%d", &flag);

        if(flag) {
            tmp_node->next = (my_ply *) malloc(sizeof(my_ply)); //Grow the list
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    } while (flag);
}
void my_show_ply(my_ply * node) {
    printf("\nThe plynomial expression is:\n");
    while(node != NULL) {
        printf("%dx^%d", node->coeff, node->pow);
        node = node->next;
        if(node != NULL)
            printf(" + ");
    }
}

void my_add_ply(my_ply ** result, my_ply * ply1, my_ply * ply2) {
    my_ply * tmp_node; //Temporary storage for the linked list
    tmp_node = (my_ply *) malloc(sizeof(my_ply));
    tmp_node->next = NULL;
    *result = tmp_node;
    while(ply1 && ply2) {
        if (ply1->pow > ply2->pow) {
            tmp_node->pow = ply1->pow;
            tmp_node->coeff = ply1->coeff;
            ply1 = ply1->next;
        }
        else if (ply1->pow < ply2->pow) {
            tmp_node->pow = ply2->pow;
            tmp_node->coeff = ply2->coeff;
            ply2 = ply2->next;
        }
        else {
            tmp_node->pow = ply1->pow;
            tmp_node->coeff = ply1->coeff + ply2->coeff;
            ply1 = ply1->next;
            ply2 = ply2->next;
        }
        if(ply1 && ply2) {
            tmp_node->next = (my_ply *) malloc(sizeof(my_ply));
            tmp_node = tmp_node->next;
            tmp_node->next = NULL;
        }
    }
    while(ply1 || ply2) {
        tmp_node->next = (my_ply *) malloc(sizeof(my_ply));
        tmp_node = tmp_node->next;
        tmp_node->next = NULL;
 
        if(ply1) {
            tmp_node->pow = ply1->pow;
            tmp_node->coeff = ply1->coeff;
            ply1 = ply1->next;
        }
        if(ply2) {
            tmp_node->pow = ply2->pow;
            tmp_node->coeff = ply2->coeff;
            ply2 = ply2->next;
        }
    }
 
    printf("\nAddition Complete");
}