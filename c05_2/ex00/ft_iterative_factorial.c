/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msaadaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 15:36:21 by msaadaou          #+#    #+#             */
/*   Updated: 2024/07/07 15:46:01 by msaadaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	gojo;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	i = 2;
	gojo = 1;
	while (i <= nb)
	{
		gojo *= i;
		i++;
	}
	return (gojo);
}
