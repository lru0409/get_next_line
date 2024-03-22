/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolee <rolee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:59:14 by rolee             #+#    #+#             */
/*   Updated: 2024/03/22 17:08:32 by rolee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	idx;

	if (str == NULL)
		return (0);
	idx = 0;
	while (str[idx] != 0)
		idx++;
	return (idx);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		idx;

	new_str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	new_str[0] = 0;
	idx = 0;
	while (*s1)
	{
		new_str[idx++] = *s1;
		s1++;
	}
	while (*s2)
	{
		new_str[idx++] = *s2;
		s2++;
	}
	new_str[idx] = 0;
	return (new_str);
}

char	*ft_strdup(const char *str)
{
	char	*dest;
	int		str_len;
	int		idx;

	str_len = ft_strlen(str);
	dest = (char *)malloc(sizeof(char) * (str_len + 1));
	if (!dest)
		return (NULL);
	idx = 0;
	while (idx < str_len)
	{
		dest[idx] = str[idx];
		idx++;
	}
	dest[idx] = 0;
	return (dest);
}

char	*ft_strchr(const char *str, int chr)
{
	int		idx;

	if (!str)
		return (0);
	idx = 0;
	while (str[idx])
	{
		if (str[idx] == (char)chr)
			return (&((char *)str)[idx]);
		idx++;
	}
	if ((char)chr == 0)
		return (&((char *)str)[idx]);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	alloc_size;
	unsigned int	idx;

	if (start >= ft_strlen(s))
	{
		substr = ft_strdup("");
		return (substr);
	}
	alloc_size = 0;
	while (alloc_size < len && s[start + alloc_size])
		alloc_size++;
	substr = (char *)malloc(alloc_size + 1);
	if (!substr)
		return (NULL);
	idx = 0;
	while (idx < len && s[start + idx])
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = 0;
	return (substr);
}
