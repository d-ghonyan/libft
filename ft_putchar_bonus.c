/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:40:25 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:40:33 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	_ft_putchar(char c, int *count)
{
	*count += write(1, &c, 1);
}

void	ft_putchar(char c, int *count, t_flag flags)
{
	flags.width -= 1;
	if (!flags.minus)
	{
		while (flags.width > 0)
		{
			_ft_putchar(' ', count);
			flags.width--;
		}
	}
	_ft_putchar(c, count);
	if (flags.minus)
	{
		while (flags.width > 0)
		{
			_ft_putchar(' ', count);
			flags.width--;
		}
	}
}
