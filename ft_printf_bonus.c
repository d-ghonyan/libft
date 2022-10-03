/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:45:09 by dghonyan          #+#    #+#             */
/*   Updated: 2022/03/27 17:46:32 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static int	thingie_(t_flag flags)
{
	return (flags.octo == 0
		&& flags.plus == 0
		&& flags.space == 0
		&& flags.minus == 0
		&& flags.precision == 0
		&& flags.width == 0);
}

static void	thingie(t_flag *flags)
{
	flags->octo = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->minus = 0;
	flags->zero = 0;
	flags->precision = 0;
	flags->precision_width = -1;
	flags->width = -1;
}

static void	norm(char s, va_list args, int *c, t_flag flags)
{
	if (s == 'd' || s == 'i')
		ft_putnbr(va_arg(args, int), c, flags);
	else if (s == 'c')
		ft_putchar(va_arg(args, int), c, flags);
	else if (s == 'x' || s == 'X' || s == 'u')
		ft_putnbr_u(va_arg(args, unsigned int), s, c, flags);
	else if (s == 's')
		ft_putstr(va_arg(args, char *), c, flags);
	else if (s == 'p')
		print_ptr(va_arg(args, uintptr_t), c, flags);
	else if (s == '%')
		*c += write(1, "%", 1);
	else if (thingie_(flags))
	{
		*c += write(1, "%", 1);
		*c += write(1, &s, 1);
	}
}

static void	another_thingie(t_flag flags, char c, int *count)
{
	if (!ft_strchr("cspiduxX%", c))
	{
		write(1, "%", 1);
		if (flags.octo)
			write(1, "#", 1);
		if (flags.plus)
			write(1, "+", 1);
		if (flags.space)
			write(1, " ", 1);
		if (flags.precision)
			write(1, ".", 1);
		if (flags.width)
			ft_putnbr(flags.width, count, flags);
		if (flags.minus)
			write(1, "-", 1);
		if (flags.zero)
			write(1, "0", 1);
	}
}

int	ft_printf(char const *s, ...)
{
	va_list	args;
	int		i;
	int		c;
	t_flag	flags;

	i = 0;
	c = 0;
	va_start(args, s);
	while (s[i])
	{
		thingie(&flags);
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			eh(&flags, &i, s);
			another_thingie(flags, s[i], &c);
			norm(s[i], args, &c, flags);
		}
		else
			c += write (1, s + i, 1);
		i++;
	}
	va_end(args);
	return (c);
}
