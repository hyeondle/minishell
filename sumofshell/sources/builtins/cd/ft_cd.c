/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:48:05 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/15 06:37:50 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/minishell.h"

int	ft_cd(char **inputs)
{
	if (chdir(inputs[1]) != 0)
	{
		printf("cd: %s: No such file or directory", inputs[1]);
		return (1);
	}
	return (0);
}
