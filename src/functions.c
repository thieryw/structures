#include <stdio.h>
#include <stdlib.h>
#include "struct.h"



void get_orders(struct order *ord , FILE *f)
{
    if(fscanf(f,"%s %s %d %d",&ord->name,&ord->standard,&ord->quantity,&ord->price) != EOF)
    {
        ord->next = malloc(sizeof(struct order)) ;
        get_orders(ord->next, f);
    }
}

struct order * get_order(struct order *ord, int i)
{
    if (i > 0 && ord->next != NULL)
    {
            return (get_order(ord->next, i - 1));
    }
    else
    {
        return(ord) ;
    }
}

void print_order(struct order *ord)
{
    printf("%s %s %d\n", ord->name, ord->standard, ord->quantity * ord->price);
}

void print_orders(struct order *ord)
{
    if (ord->next != NULL)
    {
        print_order(ord);
        print_orders(ord->next);
    }
}

struct order *get_highest_order(struct order *ord)
{
    struct order *ord_max = ord;
    struct order *temp = ord ;
    int i = 0 ;
    
    while(temp->next != NULL)
    {
        i++ ;
        temp = get_order(ord,i) ;
        if(temp->quantity * temp->price > ord_max->quantity * ord_max->price)
        {
            ord_max = temp ;
        }
    }

    return ord_max;
}