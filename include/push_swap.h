#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_node *link;

typedef struct s_node {
  int data;
  int sorted_index;
  link next;
  link prev;
} t_node;

typedef struct s_stack {
  link head;
  int size;
  int max_size;
} t_stack;

#endif
