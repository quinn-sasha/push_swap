/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:48:59 by squinn            #+#    #+#             */
/*   Updated: 2025/08/23 10:38:30 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
* nodeのメンバである data, sorted_index, next, prev を初期化する
* 副作用：int *numsを動的に割り当てて、解放する
*/
void initialize_nodes(t_node *nodes, int size, char **input_nums) {
  int *nums = convert_words_to_integers(input_nums, size);
  int i = 0;
  while (i < size) {
    nodes[i].data = nums[i];
    nodes[i].next = &nodes[i];
    nodes[i].prev = &nodes[i];
    i++;
  }
  int sorted_nums[size];
  ft_memcpy(sorted_nums, nums, sizeof(int) * size);
  selection_sort(sorted_nums, size);
  i = 0;
  while (i < size) {
    int index = get_index(sorted_nums, size, nodes[i].data);
    nodes[i].sorted_index = index;
    i++;
  }
}

/*
* 入力：初期化されていないスタック, スタックの要素数、プログラムへの引数
* 出力：なし
* 副作用：
  * stack構造体のメンバである head, size, max_sizeを初期化する
  * t_node *nodesを動的に割り当てて、解放する
*/
void initialize_stack1(t_stack *stack, int max_size, char **input_nums) {
  stack->max_size = max_size;
  stack->size = 0;
  stack->head = NULL;
  stack->nodes = malloc(sizeof(t_node) * max_size);
  initialize_nodes(stack->nodes, max_size, input_nums);
  int i = max_size - 1;
  while (i >= 0) {
    push(stack, &stack->nodes[i]);
    i--;
  }
}

void initialize_stack2(t_stack *stack, int max_size) {
  stack->max_size = max_size;
  stack->size = 0;
  stack->head = NULL;
  stack->nodes = NULL;
}

int main(int argc, char *argv[]) {
  // TODO: validate input
  t_stack stack1;
  t_stack stack2;
  initialize_stack1(&stack1, argc - 1, argv + 1);
  initialize_stack2(&stack2, argc - 1);
  // free stack1
}
