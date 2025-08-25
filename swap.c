/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:20:49 by squinn            #+#    #+#             */
/*   Updated: 2025/08/25 10:21:21 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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
