/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:09:25 by squinn            #+#    #+#             */
/*   Updated: 2025/08/22 20:22:37 by squinn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*
* 入力：文字列の配列、出力する配列のサイズ
* 出力：各文字列を数字に変換して、その数字を入れた整数の配列
*/
int *convert_words_to_integers(char **words, int size) {
  int *result = malloc(sizeof(int) * size);
  int i = 0;
  while (i < size) {
    int num = ft_atoi(words[i]);
    result[i] = num;
    i++;
  }
  return result;
}
