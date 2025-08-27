/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:48:59 by squinn            #+#    #+#             */
/*   Updated: 2025/08/27 10:23:44 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	in_ascending_order(int *nums, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (nums[i] > nums[i + 1])
		{
			return (FALSE);
		}
		i++;
	}
	return (TRUE);
}

int	main(int argc, char *argv[])
{
	int		*nums;
	t_stack	stack1;
	t_stack	stack2;

	if (argc == 1)
		exit(EXIT_SUCCESS);
	if (argv[0][1] == '\0')
		exit(EXIT_SUCCESS);
	validate_input(argc, argv);
	nums = convert_words_to_integers(argv + 1, argc - 1);
	if (in_ascending_order(nums, argc - 1))
	{
		free(nums);
		exit(EXIT_SUCCESS);
	}
	free(nums);
	initialize_stack1(&stack1, argc - 1, argv + 1);
	initialize_stack2(&stack2);
	sort(&stack1, &stack2);
	free(stack1.nodes);
}
