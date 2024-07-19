/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 10:47:03 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/10 15:22:04 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (str[i] == '+' || str[i] == '-' || str[i] == ' ' || 
			(str[i] >= 9 && str[i] <= 13))
			return (0);
		i++;
	}
	if (i <= 1)
		return (0);
	return (i);
}

int	wax_kayn_base(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	convert_to_int(char *str, char *base, int index, int len_base)
{
	int	i;
	int	number;
	int	place;

	i = index;
	number = 0;
	while (wax_kayn_base(base, str[i]) != -1)
	{
		place = wax_kayn_base(base, str[i]);
		number = number * len_base + place;
		i++;
	}
	return (number);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	sign;
	int	len_base;
	int	number;

	if (!check_the_base(base))
		return (0);
	len_base = check_the_base(base);
	i = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	number = convert_to_int(str, base, i, len_base);
	return (number * sign);
}
