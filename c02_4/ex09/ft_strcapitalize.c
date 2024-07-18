/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 12:57:01 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/03 11:44:01 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	my_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		i++;
	}
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	my_strlowcase(str);
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			flag = 1;
		else if (str[i] >= 'a' && str[i] <= 'z')
		{
			if (flag == 0)
				str[i] = str[i] - 32;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	return (str);
}
