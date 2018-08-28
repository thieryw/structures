
#ifndef STRUCT_H
#define STRUCT_H

struct order
{
    char name[40] ;
    char standard[40] ;
    int quantity ;
    int price ;
    struct order *next ;
} ;

#endif

