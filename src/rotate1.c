/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 10:18:25 by squinn            #+#    #+#             */
/*   Updated: 2025/08/25 10:19:43 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rotate_left(t_stack *stack)
{
	stack->head = stack->head->next;
}

void	rotate_right(t_stack *stack)
{
	stack->head = stack->head->prev;
}
