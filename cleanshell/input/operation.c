/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:13:16 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/29 14:41:07 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	operation(char *input)
{
	char	**tokenized_str;

	tokenized_str = shell_split(input);
	tokenized_str = split_by_token(tokenized_str);
	//각 오퍼레이션에 넣는데, 삼차원 배열로 만들어서 첫항은 명령어 둘째항은 인자 넣기.
	//tokenized_str = cleaning_token(tokenized_str);//수정합시다
	int i = 0;
	while (tokenized_str[i])
	{
		printf("%d : %s%c\n", i, tokenized_str[i], '$');
		i++;
	}
}