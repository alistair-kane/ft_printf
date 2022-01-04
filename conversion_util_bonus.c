/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_util_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 14:51:51 by alkane            #+#    #+#             */
/*   Updated: 2022/01/01 22:48:34 by alkane           ###   ########.fr       */
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

void    print_s(char *temp, int *ch_out, t_flags f)
{
	char *s;

	if (!temp)
		temp = "(null)";
	s = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_strlcpy(s,temp,ft_strlen(temp) + 1);
	if (f.precision >= 0 && !ft_strncmp(temp, "(null)", 6) 
		&& f.precision < (int)ft_strlen(s))
		s[0] = '\0';
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

void    print_c(char c, int *ch_out, t_flags f)
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

void	print_p(unsigned long p, int *ch_out, t_flags f)
{
	char *p_buf;
	char *converted;
	p_buf = ft_calloc(18, sizeof(char));
	if (!p)
		ft_strlcat(p_buf, "(nil)", 7);
	else
	{
		ft_strlcat(p_buf, "0x", 3);
		converted = base_translate(p, 16, "0123456789abcdef");
		ft_strlcat(p_buf, converted, ft_strlen(converted) + 3);
	}
	if (f.l_align)
		ft_putstr_fd(p_buf, 1);
	while (p_buf && f.width > (int)ft_strlen(p_buf))
	{
		write(1, " ", 1);
		(*ch_out)++;
		f.width--;
	}
	*ch_out += ft_strlen(p_buf);
	if (!f.l_align)
		ft_putstr_fd(p_buf, 1);
	free(p_buf);
}

void	print_d_i(int i_d, int *ch_out, t_flags f)
{
	long i;
	char *i_buf;
	char *converted;
	char *zeros;

	i = (long)i_d;
	i_buf = ft_calloc(18, sizeof(char));
	zeros = "";
	if (i < 0)
	{
		i *= -1;
		ft_strlcat(i_buf, "-", 2);
		// write(1, "-", 1);
		// (*ch_out)++;
	}
	converted = base_translate(i, 10, "0123456789");
	ft_strlcat(i_buf, converted, ft_strlen(converted) + 2);
	if ((int)ft_strlen(converted) < f.precision)
	{
		ft_memset(zeros, '0', (f.precision - ft_strlen(converted)));
		ft_strlcat(zeros, i_buf, f.precision);
	}
	// {
	// 	index = 0;
	// 	// write(1, "0", 1);
	// 	// (*ch_out)++;
	// 	// f.precision--;
	// }
	if (f.l_align)
		ft_putstr_fd(i_buf, 1);
	while (i_buf && f.width > (int)ft_strlen(i_buf))
	{
		write(1, " ", 1);
		(*ch_out)++;
		f.width--;
	}
	*ch_out += ft_strlen(i_buf);
	if (!f.l_align)
		ft_putstr_fd(i_buf, 1);
	free(i_buf);
}