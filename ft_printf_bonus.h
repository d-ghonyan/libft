/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 17:46:43 by dghonyan          #+#    #+#             */
/*   Updated: 2022/03/27 17:47:42 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H

# define FT_PRINTF_BONUS_H

# include "libft.h"

typedef struct s_flag
{
	int	plus;
	int	octo;
	int	space;
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	precision_width;
}	t_flag;

void	to_hex_lower(unsigned int n, int *count, t_flag flags);
void	ft_putnbr(int n, int *count, t_flag flags);
void	ft_putstr(char const *s, int *count, t_flag flags);
void	to_hex_upper(unsigned int n, int *count, t_flag flags);
void	ft_putnbr_u(unsigned int n, char c, int *count, t_flag flags);
void	ft_putchar(char c, int *count, t_flag flags);
void	print_ptr(uintptr_t ptr, int *count, t_flag flags);
void	eh(t_flag *flags, int *i, char const *s);
char	*ft_strchr(const char *s, int c);
int		len(int num);
int		len_ptr(uintptr_t num);
int		len_u(unsigned int num);
int		len_hex(unsigned int num);

#endif
