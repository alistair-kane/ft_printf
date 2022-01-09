/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_diuxX_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 03:59:26 by alistair          #+#    #+#             */
/*   Updated: 2022/01/09 18:09:52 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_d_i(int i_d, int *ch_out, t_flags f)
{
	long	val;
	char	*buf;
	char	*converted;

	val = (long)i_d;
	buf = ft_calloc(256, (size_t)1);
	if (i_d < 0)
		val *= -1;
	converted = base_translate(val, 10, "0123456789");
	apply_precision((long)val, f.precision, converted, buf);
	if ((i_d < 0 || f.plus || f.space))
	{
		ft_memmove(buf + 1, buf, ft_strlen(buf));
		buf[0] = '-';
		if (f.plus && i_d >= 0)
			buf[0] = '+';
		else if (f.space && i_d >= 0)
			buf[0] = ' ';
	}
	buf = apply_width_d_i(i_d, buf, f);
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_u(unsigned int u, int *ch_out, t_flags f)
{
	unsigned long	val;
	char			*buf;
	char			*converted;
	int				extra_width;

	val = (unsigned long)u;
	buf = ft_calloc(256, (size_t)1);
	converted = base_translate(u, 10, "0123456789");
	apply_precision((long)val, f.precision, converted, buf);
	extra_width = 0;
	apply_width_u_x_bigx(buf, f, &extra_width);
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_x(unsigned int x, int *ch_out, t_flags f)
{
	char	*buf;
	char	*converted;
	int		extra_width;

	buf = ft_calloc(256, sizeof(char));
	if (!x)
		converted = "0";
	else
	{
		if (f.hash)
			ft_strlcat(buf, "0x", 3);
		converted = base_translate(x, 16, "0123456789abcdef");
	}
	apply_precision(x, f.precision, converted, buf);
	extra_width = 0;
	apply_width_u_x_bigx(buf, f, &extra_width);
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_bigx(unsigned int bigx, int *ch_out, t_flags f)
{
	char	*buf;
	char	*converted;
	int		extra_width;

	buf = ft_calloc(256, sizeof(char));
	if (!bigx)
		converted = "0";
	else
	{
		if (f.hash)
			ft_strlcat(buf, "0X", 3);
		converted = base_translate(bigx, 16, "0123456789ABCDEF");
	}
	apply_precision(bigx, f.precision, converted, buf);
	extra_width = 0;
	apply_width_u_x_bigx(buf, f, &extra_width);
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}
