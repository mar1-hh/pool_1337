/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 09:48:29 by msaadaou          #+#    #+#             */
/*   Updated: 2024/06/27 13:31:03 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(int num)
{
	ft_putchar(num / 10 + '0');
	ft_putchar(num % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			if (! (a == 0 && b == 1))
				write(1, ", ", 2);
			print_num(a);
			ft_putchar(' ');
			print_num(b);
			b ++;
		}
		a ++;
	}
}
