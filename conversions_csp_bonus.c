/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions_csp_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 03:53:40 by alistair          #+#    #+#             */
/*   Updated: 2022/01/08 05:31:17 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	print_c(char c, int *ch_out, t_flags f)
{
	if (f.l_align)
		write(1, &c, 1);
	while (f.width > 1)
	{
		write(1, " ", 1);
		(*ch_out)++;
		f.width--;
	}
	if (!f.l_align)
		write(1, &c, 1);
	(*ch_out)++;
}

void	print_s(char *temp, int *ch_out, t_flags f)
{
	char	*s;

	if (!temp)
		temp = "(null)";
	s = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_strlcpy(s, temp, ft_strlen(temp) + 1);
	if (f.precision >= 0 && f.precision < (int)ft_strlen(s))
		s[f.precision] = '\0';
	if (f.l_align)
		ft_putstr_fd(s, 1);
	while (s && f.width > (int)ft_strlen(s))
	{
		write(1, " ", 1);
		(*ch_out)++;
		f.width--;
	}
	*ch_out += ft_strlen(s);
	if (!f.l_align)
		ft_putstr_fd(s, 1);
	free(s);
}

void	print_p(unsigned long p, int *ch_out, t_flags f)
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
	if (f.l_align)
		ft_putstr_fd(buf, 1);
	while (buf && f.width > (int)ft_strlen(buf))
	{
		write(1, " ", 1);
		(*ch_out)++;
		f.width--;
	}
	*ch_out += ft_strlen(buf);
	if (!f.l_align)
		ft_putstr_fd(buf, 1);
	free(buf);
}
