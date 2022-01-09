/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 17:04:29 by alkane            #+#    #+#             */
/*   Updated: 2022/01/09 18:06:37 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char *format, ...);
char	*base_translate(unsigned long n, unsigned int base, char *base_table);
void	print_p(unsigned long p, int *ch_out);
void	print_d_i(int i_d, int *ch_out);
void	print_u(unsigned int u, int *ch_out);
void	print_x(unsigned int x, int *ch_out);
void	print_bigx(unsigned int bigx, int *ch_out);

#endif