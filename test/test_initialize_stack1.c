#include "../include/push_swap.h"

int main(int argc, char *argv[]) {
  t_stack stack1;
  initialize_stack1(&stack1, argc - 1, argv + 1);
  printf("Original input:\n");
  for (int i = 1; i < argc; i++) {
    printf(" %s ", argv[i]);
  }
  printf("\n");
  t_node *node = stack1.head;
  for (int i = 1; i < argc; i++) {
    printf("data: %d, index: %d\n", node->data, node->sorted_index);
    node = node->next;
  }
  printf("done\n");
}
