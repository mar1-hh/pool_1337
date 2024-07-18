/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 10:13:18 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/13 10:25:07 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_atoi_base(char *str, char *base, int len_base)
{
	int	i;
	int	sign;
	int	number;

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
