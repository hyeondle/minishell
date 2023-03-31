/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:07:03 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/30 15:52:06 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//파이프 기준으로 잘랐으므로,
//순서
//1. 환경변수 처리
//2. 다시 공백기준 분리
//3. 명령어 배열과 인자배열로 구분하여 집어넣기

#include "libft/basic/libft.h"
#include "minishell.h"
#include <stddef.h>

char	*single_quote(char *str)
{
	return (ft_strtrim(str, "\'"));
}

char	*double_quote(char *str)
{
	char *temp;

	temp = (ft_strtrim(str, "\""));
	//달러기호 변경하기(환경변수)
	return temp;
}

char	*cleaning_process(char *str)
{
	char	*temp;
	int		i;

	i = 0;
	if (str[i] == '\'')
		temp = single_quote(str);
	else if (str[i] == '\"')
		temp = double_quote(str);
	else
		return (str);
	return temp;
}

char	**cleaning_token(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = cleaning_process(str[i]);
		i++;
	}
	return (str);
}
