/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: squinn <squinn@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:09:25 by squinn            #+#    #+#             */
/*   Updated: 2025/08/23 08:24:14by squinn           ###   ########.fr       */
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

/*
* 入力：整数の配列、配列の要素数
* 副作用：numsがソートされる
*/
void selection_sort(int *nums, int size) {
  int i = 0;
  while (i < size - 1) {
    int min_value_index = i;
    int j = i + 1;
    while (j < size) {
      if (nums[j] < nums[min_value_index])
        min_value_index = j;
      j++;
    }
    int temp = nums[i];
    nums[i] = nums[min_value_index];
    nums[min_value_index] = temp;
    i++;
  }
}


int get_index(int *nums, int size, int value) {
  int i = 0;
  while (i < size) {
    if (nums[i] == value)
      return i;
    i++;
  }
  return NOT_FOUND;
}
