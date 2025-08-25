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

/*
* 入力：整数の配列、配列の要素数、数字
* 出力：配列の中の数字の位置. もし存在しなければ -1.
*/
int get_index(int *nums, int size, int value) {
  int i = 0;
  while (i < size) {
    if (nums[i] == value)
      return i;
    i++;
  }
  return NOT_FOUND;
}

/*
* 入力：スタック構造体
* 出力：スタックが持つ最も大きい要素の、リスト先頭からの位置
* 注意：size - 1に等しい sorted_index を持つ要素が必ずあるという前提で動く
*/
int get_max_index_position(t_stack *stack) {
  int max_index = stack->size - 1;
  t_node *node = stack->head;
  int position = 0;
  while (node->sorted_index != max_index) {
    node = node->next;
    position++;
  }
  return position;
}

int get_max_index(t_stack *stack) {
  int max_index = INT_MIN;
  t_node *node = stack->head;
  int i = 0;
  while (i < stack->size) {
    if (node->sorted_index > max_index)
      max_index = node->sorted_index;
    node = node->next;
    i++;
  }
  return NOT_FOUND;
}
