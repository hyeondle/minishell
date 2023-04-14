/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_env_envp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:11:24 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/15 00:55:49 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	check_key_to_remove(char *env, char *key)
{
	char	*equal_sign;
	char	*env_key;

	equal_sign = ft_strchr(env, '=');
	if (!equal_sign)
		return (1);
	env_key = ft_strndup(env, equal_sign - env);
	if (ft_strcmp(env_key, key) == 0)
	{
		free(env_key);
		return (1);
	}
	else
	{
		free(env_key);
		return (0);
	}
	return (0);
}

int	remove_env_envp(t_setting **set, const char *key)
{
	char	**new_envp;
	int		size;
	int		i;
	int		j;
	char	**temp;

	size = 0;
	i = 0;
	j = 0;
	while ((*set)->envp[size])
		size++;
	new_envp = (char **)malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		if (check_key_to_remove((*set)->envp[i], (char *)key) == 1)
		{
			i++;
			continue;
		}
		new_envp[j] = ft_strdup((*set)->envp[i]);
		i++;
		j++;
	}
	new_envp[j] = NULL;
	i = 0;
	temp = (*set)->envp;
	(*set)->envp = new_envp;
	while (temp && temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
	return (0);
}