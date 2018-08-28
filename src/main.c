#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "struct.h"


int main(void)
{
    struct order ord;
    struct order *high_ord;
    FILE *f;

    if ((f = fopen("res/file.txt", "r")) == NULL)
    {
        printf("Error on file opening !\n");
    }
    else
    {
        get_orders(&ord, f);
    }
    print_orders(&ord);
    high_ord = get_highest_order(&ord);
    printf("\n\n");
    print_order(high_ord);
}
