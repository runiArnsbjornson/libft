/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:27:45 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/04 11:17:36 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int nbr;

	nbr = nb;
	if (nb == 0)
		return (1);
	if (nb > 0 && nb < 13)
	{
		while (nbr-- > 1)
			nb = nb * nbr;
		return (nb);
	}
	else
		return (0);
}
