/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:48:59 by squinn            #+#    #+#             */
/*   Updated: 2025/08/22 17:01:22 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
*
*
*/
void initialize_nodes(t_node *nodes) {

}

/*
* 入力：初期化されていないスタック, 整数の配列、整数のサイズ
* 出力：なし
* 副作用：stack構造体のメンバである head, size, max_sizeを初期化する
*/
void initialize_stack(t_stack *stack, int *nums, int max_size) {
  stack->max_size = max_size;
  stack->size = 0;
  stack->head = NULL;
  t_node *nodes = malloc(sizeof(t_node) * max_size);
  initialize_nodes(nodes);
  int i = 0;
  while (i < max_size) {
    // node = nodes[i]
    // push(stack, node)
    i++;
  }
}

int main(int argc, char *argv[]) {
  // TODO: validate input
  t_stack stack1;
  t_stack stack2;
  int *nums = convert_argv_to_integers(argv + 1, argc - 1);
  initialize_stack(&stack1, nums, argc - 1);
}
