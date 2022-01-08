/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alistair <alistair@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 12:23:00 by alkane            #+#    #+#             */
/*   Updated: 2022/01/08 08:44:11 by alistair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static void	print_c(char c, int *ch_out)
{
	write(1, &c, 1);
	(*ch_out)++;
}

static void	print_s(char *temp, int *ch_out)
{
	char	*s;

	if (!temp)
		temp = "(null)";
	s = ft_calloc(ft_strlen(temp) + 1, sizeof(char));
	ft_strlcpy(s, temp, ft_strlen(temp) + 1);
	*ch_out += ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
}

static void	print_specifer(char specifer, va_list args, int *ch_out)
{
	if (specifer == '%')
	{
		write(1, "%", 1);
		(*ch_out)++;
	}
	if (specifer == 'c')
		print_c(va_arg(args, int), ch_out);
	if (specifer == 's')
		print_s(va_arg(args, char *), ch_out);
	if (specifer == 'p')
		print_p(va_arg(args, unsigned long), ch_out);
	if (specifer == 'd' || specifer == 'i')
		print_d_i(va_arg(args, int), ch_out);
	if (specifer == 'u')
		print_u(va_arg(args, unsigned int), ch_out);
	if (specifer == 'x')
		print_x(va_arg(args, unsigned long), ch_out);
	if (specifer == 'X')
		print_bigx(va_arg(args, unsigned long), ch_out);
}

int	ft_printf(const char *format, ...)
{
	int				ch_written;
	int				i;
	va_list			args;

	ch_written = 0;
	i = -1;
	va_start(args, format);
	while (format[++i])
	{
		if (format[i] == '%')
		{
			i += 1;
			print_specifer(format[i], args, &ch_written);
		}
		else
		{
			write(1, &format[i], 1);
			ch_written++;
		}
	}
	return (ch_written);
}

// int main(void)
// {
// 	// ft_printf("%01.1d", 0);
// 	ft_printf("%u", 42);
// 	return(0);
// }

// conversion specifiers:
// c,s,p,d,i,u,x,X %
// %[flag][min width][.precision][length modifier][conversion specifier]

// flags:
// "-" Left-justify within field width; Right justification is the default
// "0" Left-pads the number with (0) instead of spaces if padding specified
//		**ignored if - is present

// "." Precision specifier,
//                        c,p egal
//                          s maximum number of chars printed
//                  d,i,u,x,X number of digits written

// "#" Value is preceeded with 0x or 0X for values different than zero
//                        x,X

// " " when no sign is written, insert blank space before the value
//		**ignored when + is present

// "+" Forces to preceed the result with a plus or minus sign (+ or -) even 
//		for positive numbers, by default, only negative numbers are preceded 
//		with a - sign