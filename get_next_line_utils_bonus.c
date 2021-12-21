/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 10:54:16 by f██████           #+#    #+#             */
/*   Updated: 2021/12/21 15:54:40 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strndup(const char *s1, int j)
{
	char	*pnt;
	int		i;

	pnt = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!pnt)
		return (NULL);
	i = 0;
	while (s1[i] && i < j)
	{
		pnt[i] = s1[i];
		i++;
	}
	pnt[i] = '\0';
	return (pnt);
}

char	*ft_strnjoin(char const *s1, char const *s2, int i)
{
	int		s1_len;
	int		s3_len;
	char	*s3;
	int		k;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s3_len = ft_strlen(s1) + i;
	s3 = malloc((s3_len + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_bzero(s3, s3_len + 1);
	k = 0;
	j = 0;
	while (k < s3_len)
	{
		if (k < s1_len)
			s3[k] = s1[k];
		else
			s3[k] = s2[j++];
		k++;
	}
	return (s3);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dsts)
{
	size_t	i;

	if (!dsts)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < dsts - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

void	ft_bzero(void *s, size_t n)
{
	int	i;

	i = 0;
	while (i < (int)n)
	{
		((char *) s)[i] = 0;
		i++;
	}
}
