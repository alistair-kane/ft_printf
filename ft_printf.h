/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/01/08 08:36:56 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

char	*base_translate(unsigned long n, unsigned int base, char *base_table);

void	print_p(unsigned long p, int *ch_out);
void	print_d_i(int i_d, int *ch_out);
void	print_u(unsigned int u, int *ch_out);
void	print_x(unsigned long x, int *ch_out);
void	print_bigx(unsigned long X, int *ch_out);

#endif