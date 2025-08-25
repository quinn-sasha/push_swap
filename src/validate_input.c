/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/25 14:58:54 by squinn            #+#    #+#             */
/*   Updated: 2025/08/25 15:43:18 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void handle_error(void) {
  ft_putendl_fd("Error", STDERR_FILENO);
  exit(EXIT_FAILURE);
}

/*
* 入力：プログラムのargc, argv, 正しさが検証されたargv
* 出力：valid_argvの文字列数
* 副作用：valid_argvが持つ、新たに割当られた文字列の配列(initialize_stack1()で解放される)
*/
int validate_input(int argc, char *argv[], char *valid_argv[]) {
  int i = 1;
  char *joined_strings = NULL;
  while (i < argc) {
    char *temp = joined_strings;
    joined_strings = ft_strjoin(joined_strings, argv[i]);
    free(temp);
    i++;
  }
  if (joined_strings == NULL)

}
