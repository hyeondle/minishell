/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_key_and_get_env_value.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 05:02:54 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/09 05:09:50 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

char	*find_key_and_get_env_value(char *str, int i, t_setting **set)
{
	char	*key;
	char	*value;

	key = get_env_key(str, i);
	value = get_env_value((*set)->env_list, key);
	if (!value)
		value = "";
	free(key);
	return (value);
}