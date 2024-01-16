/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsever <gsever@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 14:10:41 by ayucak            #+#    #+#             */
/*   Updated: 2023/12/26 02:56:37 by gsever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup_gnl(const char *s1)
{
	char	*new;
	size_t	i;

	new = malloc(sizeof(char) * (ft_strlen_gnl(s1) + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*new;
	size_t	first;
	size_t	total;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	first = ft_strlen_gnl(s1) + 1;
	total = ft_strlen_gnl(s2) + first;
	new = (char *)malloc(total * sizeof(char));
	if (!new)
		return (NULL);
	i = -1;
	while (s1[++i])
		new[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		new[i] = s2[j];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	i;
	size_t	j;

	s_len = ft_strlen_gnl(s);
	if (!s || len <= 0)
		return (NULL);
	if (len > s_len)
		len = s_len;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = start;
	j = 0;
	while (i < s_len && j < len)
	{
		new[j] = s[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash)
		return (NULL);
	if (create_line == 1)
	{
		line = ft_strdup_gnl(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	else if (create_line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = NULL;
		}
		return (NULL);
	}
	return (NULL);
}
