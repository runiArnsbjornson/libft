/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 18:26:47 by jdebladi          #+#    #+#             */
/*   Updated: 2016/11/02 18:32:11 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int nbr;

	if (nb == 0)
		return (1);
	if (nb > 0 && nb < 13)
	{
		nbr = ft_recursive_factorial(nb - 1);
		nb = nb * nbr;
		return (nb);
	}
	else
		return (0);
}
