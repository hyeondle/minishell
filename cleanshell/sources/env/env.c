/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:56:41 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/30 15:19:32 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*make_new_env(char *env_str)
{
	char	*env;

	//malloc t_env
	//get size of env_str
	//malloc env_str to another one
	//put it in t_env
	//return pointer;
}

int	new_env(t_setting *set, char *env_str)
{
	t_env	*temp_env;

	temp_env = set->env;
	while (temp_env->next != NULL)
		temp_env = temp_env->next;
	temp_env->next = make_new_env(env_str);
}