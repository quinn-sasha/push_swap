/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:48:59 by squinn            #+#    #+#             */
/*   Updated: 2025/08/26 19:10:19 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int main(int argc, char *argv[]) {
  if (argc == 1)
    exit(EXIT_SUCCESS);
  if (argv[0][1] == '\0')
    exit(EXIT_SUCCESS);
  validate_input(argc, argv);
  t_stack stack1;
  t_stack stack2;
  initialize_stack1(&stack1, argc - 1, argv + 1);
  initialize_stack2(&stack2);
  sort(&stack1, &stack2);
  free(stack1.nodes);
}
