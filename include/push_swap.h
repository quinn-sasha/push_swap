/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:49:02 by squinn            #+#    #+#             */
/*   Updated: 2025/08/23 18:51:54 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "../libft/libft.h"

# define SMALLER_CHUNK_SIZE 20
# define BIGGER_CHUNK_SIZE 50

typedef struct s_node {
  int data;
  int sorted_index;
  struct s_node *next;
  struct s_node *prev;
} t_node;

typedef struct s_stack {
  int max_size;
  int size;
  t_node *head;
  t_node *nodes;
} t_stack;

// utils.c
int *convert_words_to_integers(char **words, int size);
void selection_sort(int *nums, int size);
int get_index(int *nums, int size, int value);
// stack_operation.c
void rotate_left(t_stack *stack);
void rotate_right(t_stack *stack);
void rotate_stack1_left(t_stack *stack1);
void rotate_stack1_right(t_stack *stack1);
void swap(t_stack *stack);
void swap_stack1(t_stack *stack1);
void push(t_stack *stack, t_node *node);
t_node *pop(t_stack *stack);
void pop_and_push(t_stack *from_stack, t_stack *to_stack);
void pop_stack1_and_push_stack2(t_stack *stack1, t_stack *stack2);
void pop_stack2_and_push_stack1(t_stack *stack1, t_stack *stack2);

void initialize_nodes(t_node *nodes, int size, char **input_nums);
void initialize_stack1(t_stack *stack, int max_size, char **input_nums);
void initialize_stack2(t_stack *stack, int max_size);

#endif
