/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucak <ayucak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 15:15:50 by ayucak            #+#    #+#             */
/*   Updated: 2023/07/25 00:38:25 by ayucak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_numlen(int num)
{
	int	i;

	if (num == 0)
		return (1);
	i = 0;
	while (num > 0 || num < 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*d;
	long	nbr;

	nbr = n;
	len = ft_numlen(nbr);
	if (n < 0)
	{
		len++;
		nbr = -nbr;
	}
	d = malloc(sizeof(char) * len + 1);
	if (!d)
		return (NULL);
	d[len] = '\0';
	while (nbr > 0)
	{
		d[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	if (n < 0)
		d[0] = '-';
	if (n == 0)
		d[0] = '0';
	return (d);
}
