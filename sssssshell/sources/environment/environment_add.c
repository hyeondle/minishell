/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:40:37 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 00:55:40 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_env(t_env_list **env, const char *key_value_pair)
{
	t_env_list	*new_node;
	char		*pair;
	char		*equal_sign;

	new_node = (t_env_list *)malloc(sizeof(t_env_list));
	if (!new_node)
		return (-1);
	pair = (char *)malloc(sizeof(char) * ft_strlen(key_value_pair));
	new_node->pair = pair;
	equal_sign = ft_strchr(key_value_pair, '=');
	if (!equal_sign)
	{
		free(new_node);
		return (-1);
	}
	new_node->env.key = ft_strndup(key_value_pair, equal_sign - key_value_pair);
	new_node->env.value = ft_strdup(equal_sign + 1);
	new_node->next = *env;
	*env = new_node;
	return (0);
}
