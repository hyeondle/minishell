/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 18:44:20 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/09 05:18:20 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*env_to_str(t_setting **set, char *str, int *i)
{
	char	*value;
	char	*t_str;
	char	*storage;
	int		k;
	
	value = find_key_and_get_env_value(str, *i, set);
	if (!value)
		value = "";
	storage = str;
	t_str = split_and_join(str, *i, value);
	free(storage);
	return (t_str);
}

static t_quote quote_check(t_quote quote, char c)
{
	if (c == '\"' && quote == NONE)
		return (DOUBLE);
	else if (c == '\"' && quote == DOUBLE)
		return (NONE);
	else if (c == '\'' && quote != DOUBLE)
		return (SINGLE);
	else
		return (NONE);
	return (NONE);
}

char	*get_env_to_str(t_setting **set, char *str)
{
	int		i;
	char	*j_str;
	t_quote	quote;

	i = 0;
	quote = NONE;
	while (str[i])
	{
		quote = quote_check(quote, str[i++]);
		if (quote == SINGLE)
		{
			while (str[i] != '\'' && str[i] != '\0')
				i++;
			if (str[i] == '\'')
				quote = NONE; 
		}
		if (str[i] == '$' && quote != SINGLE)
			j_str = env_to_str(set, str, &i);
		i++;
	}
	return (j_str);
}