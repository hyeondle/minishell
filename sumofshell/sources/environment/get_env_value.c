/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:58:56 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/12 12:00:28 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*get_env_value(t_env_list *env, const char *key)
{
	t_env_list	*current;

	current = env;
	if (!key)
		return (NULL);
	while (current)
	{
		if (ft_strcmp(current->env.key, key) == 0)
		{
			return (current->env.value);
		}
		current = current->next;
	}
	return (NULL);
}
