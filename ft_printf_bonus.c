/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkane <alkane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:23:00 by alkane            #+#    #+#             */
/*   Updated: 2022/01/09 18:02:16 by alkane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static unsigned int	find_type(const char *format)
{
	unsigned int	i;

	i = 0;
	while (i <= (ft_strlen(format)))
	{
		if (format[i] == 'c' || format[i] == 's' || format[i] == 'p'
			|| format[i] == 'd' || format[i] == 'i' || format[i] == 'u'
			|| format[i] == 'x' || format[i] == 'X' || format[i] == '%'
			|| format[i] == '\0')
			return (i);
		i++;
	}
	return (0);
}

static unsigned int	initial_parse(char *format, t_flags *flag_struct)
{
	unsigned int	i;

	i = 0;
	flag_struct->l_align = 0;
	flag_struct->plus = 0;
	flag_struct->space = 0;
	flag_struct->hash = 0;
	flag_struct->zero = 0;
	while (format[i] == '-' || format[i] == '+' || format[i] == ' '
		|| format[i] == '#' || format[i] == '0')
	{
		if (format[i] == '-')
			flag_struct->l_align = 1;
		if (format[i] == '+')
			flag_struct->plus = 1;
		if (format[i] == ' ')
			flag_struct->space = 1;
		if (format[i] == '#')
			flag_struct->hash = 1;
		if (!flag_struct->l_align && format[i] == '0')
			flag_struct->zero = 1;
		i++;
	}
	return (i);
}

static unsigned int	flag_processor(char *format, t_flags *flag_struct)
{
	unsigned int	i;
	unsigned int	end;

	i = initial_parse(format, flag_struct);
	end = find_type(format);
	flag_struct->width = -1;
	if (i < end && format[i] != '.')
		flag_struct->width = ft_atoi(&format[i]);
	flag_struct->precision = -1;
	while (i < end)
	{
		if (format[i] == '.')
			flag_struct->precision = ft_atoi(&format[i + 1]);
		i++;
	}
	return (end + 1);
}

static void	print_specifer(char specifer, va_list args, int *ch_out, t_flags f)
{
	if (specifer == '%')
	{
		write(1, "%", 1);
		(*ch_out)++;
	}
	if (specifer == 'c')
		print_c(va_arg(args, int), ch_out, f);
	if (specifer == 's')
		print_s(va_arg(args, char *), ch_out, f);
	if (specifer == 'p')
		print_p(va_arg(args, unsigned long), ch_out, f);
	if (specifer == 'd' || specifer == 'i')
		print_d_i(va_arg(args, int), ch_out, f);
	if (specifer == 'u')
		print_u(va_arg(args, unsigned int), ch_out, f);
	if (specifer == 'x')
		print_x(va_arg(args, unsigned int), ch_out, f);
	if (specifer == 'X')
		print_bigx(va_arg(args, unsigned int), ch_out, f);
}

int	ft_printf(const char *format, ...)
{
	int				ch_written;
	int				i;
	unsigned int	flag_end;
	va_list			args;
	t_flags			flags;

	ch_written = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			flag_end = flag_processor((char *)&format[i + 1], &flags);
			i += flag_end;
			print_specifer(format[i], args, &ch_written, flags);
		}
		else
		{
			write(1, &format[i], 1);
			ch_written++;
		}
	}
	return (ch_written);
}
