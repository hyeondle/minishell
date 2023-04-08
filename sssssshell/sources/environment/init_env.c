/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 00:35:56 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 09:24:24 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	init_env(char **envp, t_setting **set)
{
	t_env_list	*head;
	int			i;

	head = NULL;
	i = 0;
	while (envp[i])
	{
		add_env(&head, envp[i]);
		i++;
	}
	(*set)->env_list = head;
}
