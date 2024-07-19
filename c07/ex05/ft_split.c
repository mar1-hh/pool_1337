/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 15:32:53 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/14 17:55:30 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	flag;
	int	counter;

	i = 0;
	flag = 0;
	counter = 0;
	while (str[i])
	{
		if (!is_charset(charset, str[i]))
		{
			if (!flag)
				counter++;
			flag = 1;
		}
		else
			flag = 0;
		i++;
	}
	return (counter);
}

int	word_len(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_charset(charset, str[i]))
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**matrix;
	int		size;
	int		i;
	int		j;
	int		k;

	size = count_words(str, charset);
	matrix = malloc((size + 1) * sizeof(char *));
	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (str[k] && is_charset(charset, str[k]))
			k++;
		matrix[i] = malloc((word_len(&str[k], charset) + 1) * sizeof(char *);
		j = 0;
		while (str[k] && !is_charset(charset, str[k]))
			matrix[i][j++] = str[k++];
		matrix[i][j] = '\0';
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}
