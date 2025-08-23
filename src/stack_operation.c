/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:10:06 by squinn            #+#    #+#             */
/*   Updated: 2025/08/23 11:08:07 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
