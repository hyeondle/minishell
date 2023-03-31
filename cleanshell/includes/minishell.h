/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:05:16 by Linsio            #+#    #+#             */
/*   Updated: 2023/03/30 15:01:02 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/mylibft.h"

# define	HISTORY_FILE	".minishell_history"
# ifndef	HISTORY_SIZE
#  define	HISTORY_SIZE	1024
# endif

typedef enum t_quote
{
	NONE,
	SINGLE,
	DOUBLE
} e_quote;

typedef struct s_env
{
	char			*env;
	struct s_env	*next;
}	t_env;


typedef struct s_setting
{
	t_env			*env;
	t_env			*s_env;
	/* data */
}           t_setting;


/*			input				*/
//	operation.c
void	operation(char *input);

//	get_input.c
char	*get_input(void);

//	split_by_token.c
char	**split_by_token(char **str);

//	split_by_token_cases.c
char	**token_split_case_no_front(char **str, int i, int k);
char	**token_split_case_no_back(char **str, int i, int k);
char	**token_split_case_alone(char **str, int i, int k);
char	**go_split(char **str, int i, int k);

//	split_by_token_utils.c
char	*deli_char(char c);
size_t	dtab_size(char **str);
int		check_delimeter_type_i(char	*str);
int		check_delimeter(char *str);
int		token_check(char c);

/*			shell_split			*/
//	shell_split.c
char	**shell_split(char const *s);

//	shell_split_main.c
char	**do_split(char **tab, char *temp);
char	*put_word(char *str, size_t s);

//	shell_split_utils.c
size_t	tab_size(char *s);
e_quote	check_quote(char temp);
size_t	new_strlen_m(char *str, size_t k);
size_t	quote_leng(const char *s, size_t k);

/*								*/
/*			builtins			*/
/*								*/

/*			env					*/
int	env_init(t_setting *set, char **p_envs);


#endif