/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_hex_lower.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:41:26 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:27 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	_to_hex_lower(unsigned int n, int *count, t_flag flags)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		_to_hex_lower(n / 16, count, flags);
	*count += write (1, hex + (n % 16), 1);
}

static void	hello(int cond, int a, int *count, int ah)
{
	char	c;

	c = ' ';
	if (ah)
		c = '0';
	if (cond)
	{
		while (a > 0)
		{
			*count += write (1, &c, 1);
			a--;
		}
	}
}

void	to_hex_lower(unsigned int n, int *count, t_flag flags)
{
	int	a;
	int	tf;
	int	prec;

	if (flags.precision && flags.precision_width <= 0 && !n)
		return ;
	prec = flags.precision_width - len_hex(n);
	tf = 0;
	if (prec > 0)
		tf = prec;
	a = flags.width - (len_hex(n) + (2 * flags.octo) + tf);
	hello(!flags.minus, a, count, flags.zero);
	if (flags.octo && n)
		*count += write(1, "0x", 2);
	while (prec > 0)
	{
		*count += write (1, "0", 1);
		prec--;
	}
	_to_hex_lower(n, count, flags);
	hello(flags.minus, a, count, flags.zero);
}
