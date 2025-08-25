/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:48:59 by squinn            #+#    #+#             */
/*   Updated: 2025/08/25 09:26:13 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char *argv[]) {
  // TODO: validate input
  // TOSO: is_sorted() check
  int num_arguments = argc - 1;
  t_stack stack1;
  t_stack stack2;
  initialize_stack1(&stack1, num_arguments, argv + 1);
  initialize_stack2(&stack2, num_arguments);
  sort(&stack1, &stack2);
  // free stack1
}
