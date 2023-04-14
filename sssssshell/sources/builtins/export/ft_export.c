/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:47:04 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/15 06:38:04 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_export(t_setting **set, char **inputs)
{
	int		i;

	i = 1;
	while (inputs[i])
	{
		add_env(&((*set)->env_list), inputs[i], set);
		i++;
	}
	return (0);
}
