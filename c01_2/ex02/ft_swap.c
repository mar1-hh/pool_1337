/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 11:10:00 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/03 18:58:01 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int **a, int **b)
{
	int		temp;

	temp = **a;
	**a = **b;
	**b = temp;
}

int main(){

	int arr[10];
	int *p1 = &a;
int *p2 = &b;
printf("%lu", sizeof(arr) / sizeof(arr[0]));
}
