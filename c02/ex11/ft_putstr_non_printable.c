/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:41:36 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/18 11:31:14 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(unsigned char c)
{
	if ((c >= 0 && c < 32) || c == 127)
		return (0);
	return (1);
}

void	print_hex(unsigned char c)
{
	char	*str;

	str = "0123456789abcdef";
	write(1, &str[c / 16], 1);
	write(1, &str[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_str_is_printable((unsigned char)str[i]))
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			print_hex((unsigned char)str[i]);
		}
		i++;
	}
}
