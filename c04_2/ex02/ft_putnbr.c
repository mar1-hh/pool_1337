/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:25:28 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/04 17:06:43 by msaadaou         ###   ########.fr       */
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
	long	nbl;
	int		i;

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	nbl = nb;
	i = 0;
	if (nbl < 0)
	{
		ft_putchar('-');
		nbl *= -1;
	}
	while (nbl > 0)
	{
		arr[i++] = nbl % 10 + '0';
		nbl /= 10;
	}
	i--;
	while (i >= 0)
		ft_putchar(arr[i--]);
}
