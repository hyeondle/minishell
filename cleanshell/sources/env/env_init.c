/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:18:08 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/30 14:55:58 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	env_init(t_setting *set, char **p_envs)
{
	t_env	*env;
	t_env	*new;
	int		i;

	if (!p_envs)
		return (1);
	env = (t_env *)malloc(sizeof(t_env));
	if (!env)
		return (1);
	env->env = ft_strdup(p_envs[0]);
	env->next = NULL;
	set->env = env;
	i = i;
	while (p_envs[0] && p_envs[i])
	{
		new = (t_env *)malloc(sizeof(t_env));
		if (!new)
			return (1);
		new->env = ft_strdup(p_envs[i]);
		new->next = NULL;
		env->next = new;
		env = new;
		i++;
	}
	return (0);
}

