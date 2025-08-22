/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:49:02 by squinn            #+#    #+#             */
/*   Updated: 2025/08/22 16:24:57 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include "../libft/libft.h"

typedef struct s_node *link;

typedef struct s_node {
  int data;
  int sorted_index;
  link next;
  link prev;
} t_node;

typedef struct s_stack {
  link head;
  int size;
  int max_size;
} t_stack;

#endif
