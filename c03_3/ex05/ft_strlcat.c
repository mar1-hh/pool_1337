/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 19:46:16 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/11 12:53:08 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	j;
	unsigned int	len_dst;
	unsigned int	len_src;
	unsigned int	res;

	len_dst = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (size < len_dst)
		return (len_src + size);
	res = len_dst + len_src;
	j = 0;
	while (src[j] && (j + len_dst) < size - 1)
	{
		dest[len_dst + j] = src[j];
		j++;
	}
	dest[len_dst + j] = '\0';
	return (res);
}
