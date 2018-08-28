
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "struct.h"

void get_orders(struct order *ord , FILE *f);
struct order * get_order(struct order *ord, int i);
void print_order(struct order *ord);
void print_orders(struct order *ord);
struct order *get_highest_order(struct order *ord);

#endif


