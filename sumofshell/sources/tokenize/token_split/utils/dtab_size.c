/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dtab_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 08:54:59 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/08 08:55:14 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/minishell.h"

size_t	dtab_size(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
