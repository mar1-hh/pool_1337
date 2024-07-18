/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:09:02 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/13 15:28:02 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(char *str, char *base, int len_base);

int	is_repeat(char *str, char c, int index)
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

int	check_the_base(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (!is_repeat(base, base[i], i))
			return (0);
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ' || 
			(base[i] >= 9 && base[i] <= 13))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	number_len(long number, char *base_to)
{
	int	counter;
	int	len_base;

	len_base = check_the_base(base_to);
	counter = 0;
	while (number > 0)
	{
		counter++;
		number /= len_base;
	}
	return (counter);
}

char	*to_any_base(long nbr, char *base_to, int flag, int len_base)
{
	int		size;
	char	*ptr_nbr;

	size = number_len(nbr, base_to);
	if (flag)
		size++;
	ptr_nbr = (char *)malloc(size + 1);
	ptr_nbr[size] = '\0';
	size--;
	while (nbr > 0)
	{
		ptr_nbr[size] = base_to[nbr % len_base];
		nbr /= len_base;
		size--;
	}
	if (flag)
		ptr_nbr[0] = '-';
	return (ptr_nbr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	number;
	int		len_base;
	char	*ptr_nbr;

	if (!check_the_base(base_from) || !check_the_base(base_to))
		return (NULL);
	len_base = check_the_base(base_from);
	number = ft_atoi_base(nbr, base_from, len_base);
	len_base = check_the_base(base_to);
	if (number == 0)
	{
		ptr_nbr = (char *)malloc(2);
		ptr_nbr[0] = *base_to;
		ptr_nbr[1] = '\0';
		return (ptr_nbr);
	}
	if (number < 0)
	{
		number *= -1;
		return (to_any_base(number, base_to, 1, len_base));
	}
	else
		return (to_any_base(number, base_to, 0, len_base));
}
