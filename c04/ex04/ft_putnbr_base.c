/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 10:19:29 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/06 12:09:26 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	wax_kayn(char *str, char c, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		if (str[i] == c)
			return (0);
		i++;
	}
	return (1);
}

int	check_the_base(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!wax_kayn(str, str[i], i))
			return (0);
		if (str[i] == '+' || str[i] == '-')
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

void	print_base(long nbrl, char *base, int num_base)
{
	int		arr[40];
	int		i;

	i = 0;
	while (nbrl > 0)
	{
		arr[i] = nbrl % num_base;
		nbrl /= num_base;
		i++;
	}
	i--;
	while (i >= 0)
	{
		write(1, &base[arr[i]], 1);
		i--;
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	long	nbrl;
	int		num_base;

	if (!check_the_base(base))
		return ;
	num_base = check_the_base(base);
	if (nbr == 0)
	{
		write(1, base, 1);
		return ;
	}
	nbrl = nbr;
	if (nbrl < 0)
	{
		write(1, "-", 1);
		nbrl *= -1;
	}
	print_base(nbrl, base, num_base);
}
