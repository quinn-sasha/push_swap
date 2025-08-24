/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 12:13:19 by squinn            #+#    #+#             */
/*   Updated: 2025/08/25 08:47:12 by squinn           ###   ########.fr       */
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
    sort_three_elements(stack1);
    return;
  }
  int min_index = 0;
  while (stack1->size > 3) {
    while (stack1->head->sorted_index != min_index) {
        rotate_stack1_left(stack1);
    }
    pop_stack1_and_push_stack2(stack1, stack2);
    min_index++;
  }
  sort_three_elements(stack1);
  pop_stack2_and_push_stack1(stack1, stack2);
  pop_stack2_and_push_stack1(stack1, stack2);
}

/*
* stack1からstack2に全ての要素を移す。
* 小さい数から移動させたいので、min_index + chunk_sizeに収まるものから動かす。
*/
void transfer_all_items_to_stack2(t_stack *stack1, t_stack *stack2, int chunk_size) {
  int min_index = 0;
  while (stack1->size > 0) {
    if (stack1->head->sorted_index <= min_index) {
      pop_stack1_and_push_stack2(stack1, stack2);
      min_index++;
      continue;
    }
    if (stack1->head->sorted_index <= min_index + chunk_size) {
      pop_stack1_and_push_stack2(stack1, stack1);
      rotate_stack2_left(stack2);
      min_index++;
      continue;
    }
    rotate_stack1_left(stack1);
  }
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
    sort_less_than_five_elements(stack1, stack2);
    return;
  }
  int chunk_size;
  if (stack1->size <= 100)
    chunk_size = SMALLER_CHUNK_SIZE;
  else
    chunk_size = BIGGER_CHUNK_SIZE;
  // transfer nodes to stack2
  transfer_all_items_to_stack2(stack1, stack2, chunk_size);
  // put back then to stack1
}
