/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:49:02 by squinn            #+#    #+#             */
/*   Updated: 2025/08/23 08:41:56 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_node *t_link;

typedef struct s_node {
  int data;
  int sorted_index;
  t_link next;
  t_link prev;
} t_node;

typedef struct s_stack {
  t_link head;
  int size;
  int max_size;
} t_stack;

// utils.c
int *convert_words_to_integers(char **words, int size);
void selection_sort(int *nums, int size);
int get_index(int *nums, int size, int value);

#endif
