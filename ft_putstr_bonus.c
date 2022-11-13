/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:41:09 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:10 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	_ft_putstr(char const *s, int *count, int prec)
{
	if (!s)
	{
		write(1, "(null)", 6);
		*count += 6;
		return ;
	}
	if (prec >= 0 && prec < (int)ft_strlen(s))
		*count += write(1, s, prec);
	else
		*count += write(1, s, ft_strlen(s));
}

static void	hello(int cond, int a, int *count)
{
	if (cond)
	{
		while (a > 0)
		{
			*count += write (1, " ", 1);
			a--;
		}
	}
}

void	ft_putstr(char const *s, int *count, t_flag flags)
{
	int	a;
	int	prec;

	prec = -1;
	if (flags.precision
		&& flags.precision_width < (int)ft_strlen(s))
	{
		prec = flags.precision_width;
		if (prec == 0)
			a = flags.width;
		else
			a = flags.width - ((int)ft_strlen(s) - prec);
	}
	else
		a = flags.width - ft_strlen(s);
	hello(!flags.minus, a, count);
	_ft_putstr(s, count, prec);
	hello(flags.minus, a, count);
}
