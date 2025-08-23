/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:10:06 by squinn            #+#    #+#             */
/*   Updated: 2025/08/23 10:15:02 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void push(t_stack *stack, t_node *node) {
  t_node *head = stack->head;
  if (head == NULL) {
    head = node;
    return;
  }
  t_node *last = head->prev;
  node->next = head;
  node->prev = last;
  head->prev = node;
  last->next = node;
  head = node;
}
