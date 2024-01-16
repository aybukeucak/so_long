/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucak <ayucak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:23:35 by ayucak            #+#    #+#             */
/*   Updated: 2023/08/15 13:38:32 by ayucak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		leng;
	int		i;
	int		tmp;

	i = -1;
	leng = 0;
	va_start(arg, str);
	while (str[++i] != '\0')
	{
		if (str[i] == '%' && ft_check(str[i + 1]))
		{
			tmp = ft_format(&arg, str[++i]);
			if (tmp == -1)
				return (-1);
			leng += tmp - 1;
		}
		else if (str[i] != '%' && ft_putchar(str[i]) == -1)
			return (-1);
		leng++;
	}
	va_end(arg);
	return (leng);
}

int	ft_check(char str)
{
	if (str == 'c' || str == 'd' || str == 'i' || str == 'u' || str == '%'
		|| str == 's' || str == 'x' || str == 'X' || str == 'p')
		return (1);
	return (0);
}

int	ft_putchar(char x)
{
	return (write(1, &x, 1));
}

int	ft_format(va_list *args, char w)
{
	if (w == 'c')
		return (ft_putchar(va_arg((*args), int)));
	else if (w == '%')
		return (ft_putchar('%'));
	else if (w == 'd' || w == 'i')
		return (ft_int(va_arg((*args), int)));
	else if (w == 'u')
		return (ft_unsigned(va_arg((*args), unsigned int)));
	else if (w == 's')
		return (ft_string(va_arg((*args), char *)));
	else if (w == 'X' || w == 'x')
		return (ft_hex(va_arg((*args), unsigned int), w));
	else if (w == 'p')
		return (ft_point(va_arg((*args), unsigned long), 1));
	else
		return (0);
}
