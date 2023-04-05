/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:16 by Linsio            #+#    #+#             */
/*   Updated: 2023/04/05 13:02:53 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	operation(char *input, t_setting **set)
{
	char	**tokenized_str;
	int		i;

	i = 0;
	tokenized_str = shell_split(input);
	tokenized_str = split_by_token(tokenized_str);
	while (tokenized_str[i])
	{
		tokenized_str[i] = get_env_to_str(set, tokenized_str[i]);
		i++;
	}
	//각 오퍼레이션에 넣는데, 삼차원 배열로 만들어서 첫항은 명령어 둘째항은 인자 넣기.
	//tokenized_str = cleaning_token(tokenized_str);//수정합시다
	i = 0;
	while (tokenized_str[i])
	{
		printf("%d : %s%c\n", i, tokenized_str[i], '$');
		i++;
	}
}