/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hugrene <hugrene@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:23:39 by hugrene           #+#    #+#             */
/*   Updated: 2022/07/04 13:23:42 by hugrene          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define BUFFER_SIZE	32
# define INT_MAX		2147483647
# define INT_MIN		-214783648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char		**ft_split(const char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

#endif
