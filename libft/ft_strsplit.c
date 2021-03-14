/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaultie <lgaultie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 10:55:33 by lgaultie          #+#    #+#             */
/*   Updated: 2018/11/22 18:52:31 by lgaultie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_nb_words(char *s1, char c)
{
	int		i;
	int		count_of_words;

	i = 0;
	count_of_words = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != c && (s1[i + 1] == c || s1[i + 1] == '\0'))
			count_of_words++;
		i++;
	}
	return (count_of_words);
}

static	int		ft_max_word_size(char *s1, char c)
{
	int		i;
	int		max_word_size;
	int		actual_word_size;

	i = 0;
	actual_word_size = 0;
	max_word_size = 0;
	while (s1[i] != '\0')
	{
		while (s1[i] == c && s1[i] != '\0')
			i++;
		while (s1[i] != c && s1[i] != '\0')
		{
			actual_word_size++;
			i++;
		}
		if (actual_word_size > max_word_size)
			max_word_size = actual_word_size;
		actual_word_size = 0;
		i++;
	}
	return (max_word_size);
}

static	void	*ft_fill(char *str, char **tab, char c)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (str[k] != '\0' && i < ft_nb_words(str, c) + 1)
	{
		while (str[k] == c)
			k++;
		while (str[k] != c && str[k] != '\0')
		{
			tab[i][j] = str[k];
			j++;
			k++;
		}
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab_of_tab;
	int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(tab_of_tab = (char **)malloc(sizeof(char*) \
			* ft_nb_words((char*)s, c) + 1)))
		return (0);
	while (i < ft_nb_words((char*)s, c) + 1)
	{
		if (!(tab_of_tab[i] = (char *)malloc(sizeof(char) \
			* ft_max_word_size((char*)s, c) + 1)))
			return (NULL);
		i++;
	}
	ft_fill((char*)s, tab_of_tab, c);
	tab_of_tab[i - 1] = 0;
	return (tab_of_tab);
}
