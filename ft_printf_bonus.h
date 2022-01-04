/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/01/01 20:49:07 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdio.h> /////alarm////////

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

int		ft_printf(const char *format, ...);
// could possibly be static 
// unsigned int	base_translate(unsigned long n, int base, char *base_table);
void	print_s(char *temp, int *ch_out, t_flags f);
void   	print_c(char c, int *ch_out, t_flags f);
void	print_p(unsigned long p, int *ch_out, t_flags f);
void	print_d_i(int i_d, int *ch_out, t_flags f);

#endif