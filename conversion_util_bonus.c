/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_util_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:51:51 by alkane            #+#    #+#             */
/*   Updated: 2022/01/08 06:20:16 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*base_translate(unsigned long n, unsigned int base, char *base_table)
{
	static unsigned int	len;
	static char			buf[17];
	unsigned int		index;

	len = 0;
	ft_memset(buf, '\0', 17);
	if (n / base)
		base_translate(n / base, base, base_table);
	index = n % base;
	buf[len] = base_table[index];
	len++;
	return (buf);
}

void	apply_precision(long val, int p_flag, char *converted, char *buf)
{
	char	*char_holder;

	if (val == 0 && (p_flag > -1 && p_flag < 1))
		converted = "";
	if ((int)ft_strlen(converted) < p_flag && p_flag > 0)
	{
		char_holder = ft_calloc((p_flag - ft_strlen(converted) + 1), (size_t)1);
		ft_memset(char_holder, '0', (p_flag - ft_strlen(converted)));
		ft_strlcat(buf, char_holder, p_flag);
		free(char_holder);
	}
	ft_strlcat(buf, converted, 256);
}

void	right_align_d_i(int i_d, char **buf, t_flags f, char *char_holder)
{
	char	*temp;

	temp = ft_calloc(ft_strlen(*buf) + 1, (size_t)1);
	if (f.precision == -1 && f.zero && i_d < 0)
		ft_strlcpy(temp, *buf + 1, 256);
	else
		ft_strlcpy(temp, *buf, 256);
	ft_memset(*buf, '\0', 256);
	ft_strlcat(*buf, char_holder, 256);
	ft_strlcat(*buf, temp, 256);
	if (f.precision == -1 && f.zero && i_d < 0)
	{
		ft_memmove(*buf + 1, *buf, ft_strlen(*buf));
		*(*buf) = '-';
	}
	free(temp);
}

char	*apply_width_d_i(int val, char *buf, t_flags f)
{
	char	*char_holder;
	int		extra_width;

	extra_width = f.width - ft_strlen(buf);
	if (extra_width > 0)
	{
		char_holder = ft_calloc(extra_width + 1, (size_t)1);
		if (f.zero && f.precision == -1)
			ft_memset(char_holder, '0', extra_width);
		else
			ft_memset(char_holder, ' ', extra_width);
		if (f.l_align)
			ft_strlcat(buf, char_holder, 256);
		if (!f.l_align)
			right_align_d_i(val, &buf, f, char_holder);
		free(char_holder);
	}
	return (buf);
}

char	*apply_width_u_x_bigx(char *buf, t_flags f, int *extra_width)
{
	char	*char_holder;
	char	*temp;

	*extra_width = f.width - ft_strlen(buf);
	if (*extra_width > 0)
	{
		char_holder = ft_calloc((f.width - ft_strlen(buf)) + 1, (size_t)1);
		if (f.zero && f.precision == -1)
			ft_memset(char_holder, '0', (f.width - ft_strlen(buf)));
		else
			ft_memset(char_holder, ' ', (f.width - ft_strlen(buf)));
		if (f.l_align)
			ft_strlcat(buf, char_holder, 256);
		if (!f.l_align)
		{
			temp = ft_calloc(ft_strlen(buf) + 1, (size_t)1);
			ft_strlcpy(temp, buf, 256);
			ft_memset(buf, '\0', 256);
			ft_strlcat(buf, char_holder, 256);
			ft_strlcat(buf, temp, 256);
			free(temp);
		}
		free(char_holder);
	}
	return (buf);
}
