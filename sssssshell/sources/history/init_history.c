/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_history.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 03:53:58 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/16 06:24:49 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
//여기서 기존 히스토리를 읽어올 때, 연결리스트로 구현 하기
//마지막 종료시에 l_history와 s_history연결해서
//.minishell_history에 저장해야함
void	init_history(t_setting **setting)
{
	t_history	*history;
	t_history	*temp;
	char		*str;
	int			fd;
	int			i;

	i = 0;
	fd = open(HISTORY_FILE, O_RDONLY);
	if (fd == -1)
		return ;
	str = get_next_line(fd);
	if (!str)
		return ;
	history = (t_history *)malloc(sizeof(t_history));
	if (!history)
		return ;
	history->next = NULL;
	while (str)
	{
		history->history = ft_strdup(str);
		add_history(str);
		i++;
		str = get_next_line(fd);
		if (str)
		
	}
	close(fd);
}