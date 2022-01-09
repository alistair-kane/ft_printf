/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_pdiuxX.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 07:33:32 by alistair          #+#    #+#             */
/*   Updated: 2022/01/09 18:03:22 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_p(unsigned long p, int *ch_out)
{
	char	*buf;
	char	*converted;

	buf = ft_calloc(256, sizeof(char));
	if (!p)
		ft_strlcat(buf, "0x0", 5);
	else
	{
		ft_strlcat(buf, "0x", 3);
		converted = base_translate(p, 16, "0123456789abcdef");
		ft_strlcat(buf, converted, ft_strlen(converted) + 3);
	}
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_d_i(int i_d, int *ch_out)
{
	long	val;
	char	*buf;
	char	*converted;

	val = (long)i_d;
	buf = ft_calloc(256, (size_t)1);
	if (i_d < 0)
		val *= -1;
	converted = base_translate(val, 10, "0123456789");
	ft_strlcpy(buf, converted, ft_strlen(converted) + 1);
	if (i_d < 0)
	{
		ft_memmove(buf + 1, buf, ft_strlen(buf));
		buf[0] = '-';
	}
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_u(unsigned int u, int *ch_out)
{
	char			*buf;
	char			*converted;

	buf = ft_calloc(256, (size_t)1);
	converted = base_translate(u, 10, "0123456789");
	ft_strlcpy(buf, converted, ft_strlen(converted) + 1);
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_x(unsigned int x, int *ch_out)
{
	char	*buf;
	char	*converted;

	buf = ft_calloc(256, sizeof(char));
	if (!x)
		converted = "0";
	else
		converted = base_translate(x, 16, "0123456789abcdef");
	ft_strlcpy(buf, converted, ft_strlen(converted) + 1);
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}

void	print_bigx(unsigned int bigx, int *ch_out)
{
	char	*buf;
	char	*converted;

	buf = ft_calloc(256, sizeof(char));
	if (!bigx)
		converted = "0";
	else
		converted = base_translate(bigx, 16, "0123456789ABCDEF");
	ft_strlcpy(buf, converted, ft_strlen(converted) + 1);
	*ch_out += ft_strlen(buf);
	ft_putstr_fd(buf, 1);
	free(buf);
}
