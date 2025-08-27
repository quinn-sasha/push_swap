/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 09:10:06 by squinn            #+#    #+#             */
/*   Updated: 2025/08/26 21:20:36 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
 * 入力：stack構造体へのポインタ、node構造体へのポインタ
 * 副作用：
 *   循環リストの先頭をnodeにする。
 *   スタックのサイズを1増やす。
 */
void	push(t_stack *stack, t_node *node)
{
	t_node	*last;

	if (stack->head == NULL)
	{
		stack->head = node;
		stack->size++;
		return ;
	}
	last = stack->head->prev;
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
t_node	*pop(t_stack *stack)
{
	t_node	*node_to_delete;

	if (stack->size == 1)
	{
		node_to_delete = stack->head;
		stack->head = NULL;
		stack->size--;
		return (node_to_delete);
	}
	stack->head->next->prev = stack->head->prev;
	stack->head->prev->next = stack->head->next;
	node_to_delete = stack->head;
	stack->head = stack->head->next;
	node_to_delete->next = node_to_delete;
	node_to_delete->prev = node_to_delete;
	stack->size--;
	return (node_to_delete);
}

void	pop_and_push(t_stack *from_stack, t_stack *to_stack)
{
	t_node	*node_to_transfer;

	node_to_transfer = pop(from_stack);
	push(to_stack, node_to_transfer);
}

void	pop_stack1_and_push_stack2(t_stack *stack1, t_stack *stack2)
{
	ft_putendl_fd("pb", STDOUT_FILENO);
	pop_and_push(stack1, stack2);
}

void	pop_stack2_and_push_stack1(t_stack *stack1, t_stack *stack2)
{
	ft_putendl_fd("pa", STDOUT_FILENO);
	pop_and_push(stack2, stack1);
}
