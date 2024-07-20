/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 13:39:38 by msaadaou          #+#    #+#             */
/*   Updated: 2024/06/27 17:14:09 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	arr[10];
	long	number;
	int		i;

	number = nb;
	i = 0;
	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (number < 0)
	{
		ft_putchar('-');
		number *= -1;
	}
	while (number > 0)
	{
		arr[i ++] = number % 10 + '0';
		number /= 10;
	}
	i --;
	while (i >= 0)
		ft_putchar(arr[i --]);
}
