/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_env_envp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:56:15 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/14 20:07:43 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	add_env_envp(t_setting **set, const char *str)
{
	char	**new_envp;
	int		size;
	int		i;
	char	**temp;

//다시 만 들 어
	// size = 0;
	// i = 0;
	// while ((*set)->envp[size] && (*set)->envp[size][0] != '\0')
	// 	size++;
	// new_envp = (char **)malloc(sizeof(char *) * (size + 2));
	// while (i < size)
	// {
	// 	new_envp[i] = ft_strdup((*set)->envp[i]);
	// 	i++;
	// }
	// new_envp[i] = ft_strdup(str);
	// new_envp[i + 1] = NULL;
	// i = 0;
	// temp = (*set)->envp;
	// (*set)->envp = new_envp;
	// while (temp && temp[i])
	// {
	// 	free(temp[i]);
	// 	i++;
	// }
	// free(temp);
	return(0);
}