/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:20:08 by squinn            #+#    #+#             */
/*   Updated: 2025/08/25 10:20:20 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void rotate_stack2(t_stack *stack2, int direction) {
  if (direction == LEFT)
    rotate_stack2_left(stack2);
  else
    rotate_stack2_right(stack2);
}

