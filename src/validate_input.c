/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:58:54 by squinn            #+#    #+#             */
/*   Updated: 2025/08/27 10:15:20 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	contains_only_numbers(int argc, char *argv[])
{
	int		i;
	char	*number;
	int		j;

	i = 1;
	while (i < argc)
	{
		number = argv[i];
		if (ft_atoi(number) != 0)
		{
			i++;
			continue ;
		}
		j = 0;
		while (number[j])
		{
			if (!ft_isdigit(number[j]))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

int	contains_only_int_type(int argc, char *argv[])
{
	int				i;
	long long int	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num < INT_MIN || num > INT_MAX)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int	contains_duplicates_helper(int *nums, int start, int last)
{
	int	i;
	int	j;

	i = start;
	while (i < last)
	{
		j = i + 1;
		while (j <= last)
		{
			if (nums[j] == nums[i])
				return (TRUE);
			j++;
		}
		i++;
	}
	return (FALSE);
}

int	contains_duplicates(int argc, char *argv[])
{
	int	*nums;
	int	i;
	int	contains_duplicates;

	nums = malloc(sizeof(int) * argc);
	i = 1;
	while (i < argc)
	{
		nums[i] = ft_atoi(argv[i]);
		i++;
	}
	contains_duplicates = contains_duplicates_helper(nums, 1, argc - 1);
	free(nums);
	return (contains_duplicates);
}

/*
 * 入力：プログラムのargc, argv
 * エラーケース：
 * - 入力が数字ではない
 * - 入力がint型の範囲を超える
 * - 入力に重複がある
 */
void	validate_input(int argc, char *argv[])
{
	if (!contains_only_numbers(argc, argv))
		handle_error();
	if (!contains_only_int_type(argc, argv))
		handle_error();
	if (contains_duplicates(argc, argv))
		handle_error();
}
