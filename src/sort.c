/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:13:19 by squinn            #+#    #+#             */
/*   Updated: 2025/08/23 16:15:39 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void sort_three_elements(t_stack *stack1) {
  int max_index = stack1->max_size;
  if (stack1->head->data == max_index)
    rotate_stack1_left(stack1);
  else if (stack1->head->next->data == max_index)
    rotate_stack1_right(stack1);
  if (stack1->head->data > stack1->head->next->data)
    swap_stack1(stack1);
}

/*
* 副作用：
* - スタック内のリストが繋ぎかえられる
* - スタック要素が4個以上なら、stack1のサイズが3になるまでstack2に移す
*/
void sort_less_than_five_elements(t_stack *stack1, t_stack *stack2) {
  if (stack1->size == 3) {
    // sort three elements
    return;
  }
  // move elements until the size of stack1 becomes 3
  // sort three elements
  // put elements back to stack1
}

// Checked swap 1 was unordered
void sort(t_stack *stack1, t_stack *stack2) {
  if (stack1->size == 1)
    return;
  if (stack1->size == 2) {
    swap_stack1(stack1);
    return;
  }
  if (stack1->size <= 5) {
    // sort less than 5 elements
    return;
  }
  int chunk_size;
  if (stack1->size <= 100)
    chunk_size = SMALLER_CHUNK_SIZE;
  else
    chunk_size = BIGGER_CHUNK_SIZE;
  // transfer nodes to stack2
  // put back then to stack1
}
