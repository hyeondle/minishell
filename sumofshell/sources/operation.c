/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 02:03:12 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/28 20:14:49 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	operation(char *input, t_setting **set)
{
	char	**tokenized_str;
	char	**joined_str;
	int		i;

	i = 0;
	// tokenized_str = shell_split(input);
	// tokenized_str = split_by_token(tokenized_str);
	// while (tokenized_str[i])
	// {
	// 	tokenized_str[i] = convertion(set, tokenized_str[i]);
	// 	i++;
	// }
	// i = 0;
	// while (tokenized_str[i])
	// {
	// 	tokenized_str[i] = del_quotes(set, tokenized_str[i]);
	// 	i++;
	// }
	input = convertion(set, input);
	tokenized_str = shell_split(input);
	tokenized_str = split_by_token(tokenized_str);
	// i = 0;
	// while (tokenized_str[i])
	// {
	// 	tokenized_str[i] = convertion(set, tokenized_str[i]);
	// 	i++;
	// }
	i = 0;
	while (tokenized_str[i])
	{
		tokenized_str[i] = del_quotes(set, tokenized_str[i]);
		i++;
	}
	execute(tokenized_str, set);
	// while (tokenized_str[i])
	// {
	// 	printf("%d : %s%c\n", i, tokenized_str[i], '$');
	// 	i++;
	// }
}

// split_by_token이후에 >>나 <<를 묶어주도록 고려
// 예시 -> <, <보면 <<로 묶고 다음 배열 삭제, 인덱싱 당기기

//여기서 delimeter기준으로 쪼개진 배열들을 나눈 뒤, 다시 환경변수 처리할 것
//2차원 배열로 만들어서 argv[0][0~n] = 첫 명령어
//argv[1][0~n] = 두번째 명령어. 파이프를 통해 전달하기