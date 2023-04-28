/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 04:30:19 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/28 19:22:51 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_key(char *str, int i)
{
	int		l;
	int		k;
	int		j;
	char	*key;

	k = i + 1;
	j = 0;
	while (str[k] != '$' && str[k] != '\0' && str[k] != '\"' \
			&& str[k] != ' ' && str[k] != '\'')
		k++;
	key = (char *)malloc(sizeof(char) * (k - i));
	if (!key)
		return (NULL);
	while (i < k)
	{
		key[j] = str[i + 1];
		i++;
		j++;
	}
	key[j - 1] = '\0';
	return (key);
}
