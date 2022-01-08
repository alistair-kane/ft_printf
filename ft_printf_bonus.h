/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/01/08 08:44:34 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct s_flags
{
	int	l_align;
	int	plus;
	int	space;
	int	zero;
	int	hash;
	int	width;
	int	precision;
}	t_flags;

char	*base_translate(unsigned long n, unsigned int base, char *base_table);
void	apply_precision(long val, int p_flag, char *converted, char *buf);
void	right_align_d_i(int i_d, char **buf, t_flags f, char *char_holder);
char	*apply_width_d_i(int i_d, char *buf, t_flags f);
char	*apply_width_u_x_bigx(char *buf, t_flags f, int *extra_width);

void	print_c(char c, int *ch_out, t_flags f);
void	print_s(char *temp, int *ch_out, t_flags f);
void	print_p(unsigned long p, int *ch_out, t_flags f);
void	print_d_i(int i_d, int *ch_out, t_flags f);
void	print_u(unsigned int u, int *ch_out, t_flags f);
void	print_x(unsigned long x, int *ch_out, t_flags f);
void	print_bigx(unsigned long X, int *ch_out, t_flags f);

#endif