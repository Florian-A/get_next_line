/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: f██████ <f██████@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:44:03 by f██████           #+#    #+#             */
/*   Updated: 2021/12/21 15:54:35 by f██████          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

size_t	ft_strlen(const char *s);
char	*ft_strndup(const char *s1, int j);
char	*ft_strnjoin(char const *s1, char const *s2, int i);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsts);
void	ft_bzero(void *s, size_t n);
char	*get_next_line(int fd);
int		ft_strchr_i(const char *s, int c);

#endif