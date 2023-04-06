/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_main.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:27:34 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/06 14:57:23 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*put_word(char *str, size_t s)
{
	size_t	i;
	size_t	size;
	char	*word;

	i = 0;
	size = new_strlen_m(str, s);
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return NULL;
	while (i < size)
	{
		word[i] = str[s + i];
		i++;
	}
	if (word[i - 1] == ' ')
		word[i - 1] = '\0';
	word[i] = '\0';
	return (word);
}

char	**do_split(char **tab, char *temp)
{
	size_t	i;
	size_t	k;
	char	**ttab;
	char	*ttemp;

	i = 0;
	k = 0;
	ttab = tab;
	ttemp = temp;
	while (ttemp[k] != 0)
	{
		while (ttemp[k] && ttemp[k] == ' ')
			k++;
		if (ttemp[k] != 0)
		{
			ttab[i] = put_word(ttemp, k);
			k = k + new_strlen_m(ttemp, k) - 1;
			i++;
		}
	}
	ttab[i] = NULL;
	return (ttab);
}
