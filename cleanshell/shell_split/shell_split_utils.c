/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:28:26 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/07 17:23:18 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	quote_leng(const char *s, size_t k)
{
	size_t	k_p;

	k_p = k + 1;
	if (s[k] == '\'')
	{
		while (s[k_p] != '\'' && s[k_p] != '\0')
			k_p++;
	}
	else if (s[k] == '\"')
	{
		while (s[k_p] != '\"' && s[k_p] != '\0')
			k_p++;
	}
	else
		return 0;
	return (k_p);
}

size_t	tab_size(char *s)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (s[k] == ' ')
		if (s[k + 1] != ' ')
			k++;
	while (s[k])
	{
		if (s[k] == ' ')
		{
			while (s[k + 1] == ' ' && s[k + 1] != '\0')
				k++;
			if (s[k + 1] != '\0' && s[k + 1] != ' ')
				i++;
		}
		else if (s[k] == '\'' || s[k] == '\"')
		{
			k = quote_leng(s, k);
			i++;
		}
		k++;
	}
	return (i + 1);
}

e_quote	check_quote(char temp)
{
	if (temp == '\'')
		return SINGLE;
	else if (temp == '\"')
		return DOUBLE;
	else
		return NONE;
}

size_t	new_strlen_m(char *str, size_t k)
{
	size_t	i;

	i = k;
	while (str[i] != '\0' && str[i] != ' ')
	{
		if (str[i] == '\'')
		{
			i++;
			while (str[i] != '\'' && str[i] != '\0')
				i++;
			i++;
		}
		else if (str[i] == '\"')
		{
			i++;
			while (str[i] != '\"' && str[i] != '\0')
				i++;
			i++;
		}
		else
			i++;
	}
	return (i - k + 1);
}
