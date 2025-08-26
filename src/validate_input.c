/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:58:54 by squinn            #+#    #+#             */
/*   Updated: 2025/08/26 18:55:32 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void handle_error(void) {
  ft_putendl_fd("Error", STDERR_FILENO);
  exit(EXIT_FAILURE);
}

int contains_only_numbers(int argc, char *argv[]) {
  int i = 1;
  while (i < argc) {
    char *number = argv[i];
    int j = 0;
    while (number[j]) {
      if (!ft_isdigit(number[j]))
        return FALSE;
      j++;
    }
    i++;
  }
  return TRUE;
}

int contains_only_int_type(int argc, char *argv[]) {
  int i = 1;
  while (i < argc) {
    long long int num = ft_atoi(argv[i]);
    if (num < INT_MIN || num > INT_MAX)
      return FALSE;
    i++;
  }
  return TRUE;
}

int contains_duplicates(int argc, char *argv[]) {
  int nums[argc];
  int i = 1;
  while (i < argc) {
    nums[i] = ft_atoi(argv[i]);
    i++;
  }
  i = 1;
  while (i < argc - 1) {
    int j = i + 1;
    while (j < argc) {
      if (nums[j] == nums[i])
        return TRUE;
      j++;
    }
    i++;
  }
  return FALSE;
}

/*
* 入力：プログラムのargc, argv
* エラーケース：
* - 入力が数字ではない
* - 入力がint型の範囲を超える
* - 入力に重複がある
*/
void validate_input(int argc, char *argv[]) {
  if (!contains_only_numbers(argc, argv))
    handle_error();
  if (!contains_only_int_type(argc, argv))
    handle_error();
  if (contains_duplicates(argc, argv))
    handle_error();
}
