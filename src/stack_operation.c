/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:10:06 by squinn            #+#    #+#             */
/*   Updated: 2025/08/25 08:43:57 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void rotate_left(t_stack *stack) {
  stack->head = stack->head->next;
}

void rotate_right(t_stack *stack) {
  stack->head = stack->head->prev;
}

void rotate_stack1_left(t_stack *stack1) {
  ft_putendl_fd("Rotate stack1 left", STDOUT_FILENO);
  rotate_left(stack1);
}

void rotate_stack1_right(t_stack *stack1) {
  ft_putendl_fd("Rotate stack1 right", STDOUT_FILENO);
  rotate_right(stack1);
}

void rotate_stack2_left(t_stack *stack2) {
  ft_putendl_fd("Rotate stack2 left", STDOUT_FILENO);
  rotate_left(stack2);
}

void rotate_stack2_right(t_stack *stack2) {
  ft_putendl_fd("Rotate stack2 right", STDOUT_FILENO);
  rotate_right(stack2);
}

// Assume stack has more than 2 elements
void swap(t_stack *stack) {
  int temp_data = stack->head->data;
  int temp_index = stack->head->sorted_index;
  stack->head->data = stack->head->next->data;
  stack->head->sorted_index = stack->head->next->sorted_index;
  stack->head->next->data = temp_data;
  stack->head->next->sorted_index = temp_index;
}

void swap_stack1(t_stack *stack1) {
  ft_putendl_fd("Swap top 2 elments of stack1", STDOUT_FILENO);
  swap(stack1);
}

/*
* 入力：stack構造体へのポインタ、node構造体へのポインタ
* 副作用：
*   循環リストの先頭をnodeにする。
*   スタックのサイズを1増やす。
*/
void push(t_stack *stack, t_node *node) {
  if (stack->head == NULL) {
    stack->head = node;
    stack->size++;
    return;
  }
  t_node *last = stack->head->prev;
  node->next = stack->head;
  node->prev = last;
  stack->head->prev = node;
  last->next = node;
  stack->head = node;
  stack->size++;
}

/*
* 注意：スタックが空かどうかは、呼び出し側が確認する
* 出力：リストから削除したスタックの先頭
* 副作用：
* - スタックの先頭が、繋ぎかえられてリストから削除される
* - スタックのサイズが1減る
*/
t_node *pop(t_stack *stack) {
  if (stack->size == 0)
    return;
  stack->head->next->prev = stack->head->prev;
  stack->head->prev->next = stack->head->next;
  t_node *node_to_delete = stack->head;
  stack->head = stack->head->next;
  node_to_delete->next = node_to_delete;
  node_to_delete->prev = node_to_delete;
  stack->size--;
  return node_to_delete;
}

void pop_and_push(t_stack *from_stack, t_stack *to_stack) {
  t_node *node_to_transfer = pop(from_stack);
  push(to_stack, node_to_transfer);
}

void pop_stack1_and_push_stack2(t_stack *stack1, t_stack *stack2) {
  ft_putendl_fd("Pop stack1 and push stack2", STDOUT_FILENO);
  pop_and_push(stack1, stack2);
}

void pop_stack2_and_push_stack1(t_stack *stack1, t_stack *stack2) {
  ft_putendl_fd("Pop stack2 and push stack1", STDOUT_FILENO);
  pop_and_push(stack2, stack1);
}
