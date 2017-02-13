/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utf8_convert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdebladi <jdebladi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 12:46:48 by jdebladi          #+#    #+#             */
/*   Updated: 2017/02/13 12:47:25 by jdebladi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

int		numberbits(unsigned int bits)
{
	int				ret;
	unsigned int	mask;

	ret = 0;
	mask = 1;
	if (bits < 2)
		return (1);
	while (bits >= mask)
	{
		++ret;
		mask <<= 1;
		if (mask == 0)
			return (8 * sizeof(bits));
	}
	return (ret);
}

void	push_char(char *buf, size_t *index, char eob)
{
	if (*index == 0 || buf == NULL || index == NULL)
		return ;
	--*index;
	buf[*index] = eob;
}

void	push_uchar(char *buf, size_t *index, unsigned char eohex)
{
	push_char(buf, index, (char)eohex);
}

char	*utf8_convert(char *buf, size_t buf_size, int code)
{
	const int			usablebits[4] = {7, 5, 4, 3};
	const unsigned char	mask_1oct[4] = {0x7F, 0x1F, 0x0F, 0x07};
	const unsigned char prefix_1oct[4] = {0x00, 0xC0, 0xE0, 0xF0};
	const int			max_hex = sizeof(mask_1oct) / sizeof(mask_1oct[0]);
	const size_t		max_size = max_hex + 1;
	size_t				index = buf_size;
	unsigned int		bits = code;
	int					nb_bits = numberbits(bits);
	int					bits_left = nb_bits;
	int					bits_writen = 0;

	if (buf == NULL || buf_size < max_size)
		return (NULL);
	if (code < 0 || nb_bits > 21)
		return (NULL);
	push_char(buf, &index, '\0');
	while (bits_left > usablebits[bits_writen])
	{
		const unsigned int	mask_hex = 0x0000003F;
		const unsigned char	prefix_hex = 0x80;
		unsigned int		bits_hex = bits & mask_hex;
		unsigned char		eohex = (unsigned char)(bits_hex) | prefix_hex;
		push_uchar(buf, &index, eohex);

		++bits_writen;
		bits >>= 6;
		bits_left -= 6;
		if ((unsigned long)bits_writen > max_size)
			return (NULL);
	}
	unsigned int		bits_1oct = bits & mask_1oct[bits_writen];
	unsigned char		first_oct = (unsigned char)bits_1oct | prefix_1oct[bits_writen];
	push_uchar(buf, &index, first_oct);
	return (buf + index);
}
