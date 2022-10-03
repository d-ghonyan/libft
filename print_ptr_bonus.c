/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 20:41:17 by dghonyan          #+#    #+#             */
/*   Updated: 2022/04/03 20:41:18 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static void	to_hex_lower_p(uintptr_t n, int *count, t_flag flags)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (n > 15)
		to_hex_lower_p(n / 16, count, flags);
	*count += write(1, hex + (n % 16), 1);
}

void	print_ptr(uintptr_t ptr, int *count, t_flag flags)
{
	int	a;

	a = flags.width - (len_ptr(ptr) + 2);
	if (!flags.minus)
	{
		while (a > 0)
		{
			*count += write(1, " ", 1);
			a--;
		}
	}
	*count += write(1, "0x", 2);
	to_hex_lower_p(ptr, count, flags);
	if (flags.minus)
	{
		while (a > 0)
		{
			*count += write(1, " ", 1);
			a--;
		}
	}
}

static void	too_many_lines(t_flag *flags, char const *s, int *i, int a)
{
	flags->octo += s[*i] == '#';
	flags->plus += s[*i] == '+';
	flags->space += s[*i] == ' ';
	flags->minus += s[*i] == '-';
	flags->zero += s[*i] == '0';
	if (s[*i] && (s[*i] >= '1' && s[*i] <= '9'))
	{
		flags->width = 0;
		a = 0;
		while (s[*i] && (s[*i] >= '0' && s[*i] <= '9'))
		{
			a = 1;
			flags->width = flags->width * 10 + s[*i] - 48;
			*i += 1;
		}
		*i -= a;
	}
}

void	eh(t_flag *flags, int *i, char const *s)
{
	int	a;

	while (s[*i] && (ft_strchr("# +.0-", s[*i])
			|| (s[*i] >= '1' && s[*i] <= '9')))
	{
		too_many_lines(flags, s, i, a);
		a = 0;
		if (s[*i] == '.')
		{
			flags->precision += 1;
			*i += 1;
			flags->precision_width = 0;
			a = 1;
			while (s[*i] && (s[*i] >= '0' && s[*i] <= '9'))
			{
				flags->precision_width = flags->precision_width
					* 10 + s[*i] - 48;
				*i += 1;
			}
			*i -= a;
		}
		*i += 1;
	}
}
