/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayucak <ayucak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:29:15 by ayucak            #+#    #+#             */
/*   Updated: 2023/07/22 18:32:22 by ayucak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	unsigned int	i;
	unsigned int	s2_len;

	s2_len = ft_strlen(s2);
	if (s2_len == 0)
		return ((char *)s1);
	if (len == 0)
		return (NULL);
	i = 0;
	while (i <= (len - s2_len) && s1[i] != '\0')
	{
		if (len < s2_len)
			return (NULL);
		if (ft_strncmp(&s1[i], s2, s2_len) == 0)
			return ((char *) &s1[i]);
		i++;
	}
	return (0);
}
