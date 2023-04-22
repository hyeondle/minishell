/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:03:12 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/22 20:02:56 by hyeondle         ###   ########.fr       */
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
		printf("%d : %s%c\n", i, tokenized_str[i], '$');
		i++;
	}
	while (tokenized_str[i])
	{
		tokenized_str[i] = get_env_to_str(set, tokenized_str[i]);
		i++;
	}
	i = 0;
	execute(tokenized_str, set);
	// while (tokenized_str[i])
	// {
	// 	printf("%d : %s%c\n", i, tokenized_str[i], '$');
	// 	i++;
	// }
}

//여기서 delimeter기준으로 쪼개진 배열들을 나눈 뒤, 다시 환경변수 처리할 것
//2차원 배열로 만들어서 argv[0][0~n] = 첫 명령어
//argv[1][0~n] = 두번째 명령어. 파이프를 통해 전달하기