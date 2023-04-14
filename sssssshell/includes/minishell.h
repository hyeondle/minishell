/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 23:53:34 by hyeondle          #+#    #+#             */
/*   Updated: 2023/04/14 14:56:05 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
readline.h	=	readline
history.h	=	re_clear_history, rl_on_new_line, rl_replace_line, re_redisplay, add_history
stdio.h		=	printf, strerror, perror
stdlib.h	=	malloc, free
sys/stat.h	=	getcwd, chdir, stat, lstat, fstat, unlink, execve
dirent.h	=	opendir, readdir, closedir
unistd.h	=	write, access, dup, dup2, pipe
signal.h	=	fork, wait, waitpid, wait3, wiat4, signal, sigaction, sigemptyset, sigaddset, kill, exit
sys/ioctl.h	=	isatty, ttyname, ttyslot, ioctl
stdlib.h	=	getenv
termios.h	=	tcsetattr, tcgetattr
termcap		=	tgetnet, tgetflag, tgetnum, tgetstr, tgoto, tputs
fcntl.h		=	open, read, close
*/


#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/mylibft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <dirent.h>
# include <unistd.h>
# include <signal.h>
# include <sys/ioctl.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>

# define	HISTORY_FILE	".minishell_history"
# ifndef	HISTORY_SIZE
#  define	HISTORY_SIZE	1024
# endif

/*		typedef			*/

typedef enum e_quote
{
	NONE,
	SINGLE,
	DOUBLE
}	t_quote;

typedef struct s_env
{
	char	*key;
	char	*value;
}			t_env;

typedef struct s_env_list
{
	t_env				env;
	char				*pair;
	struct s_env_list	*next;
}						t_env_list;

typedef struct s_setting
{
	char		**envp;
	t_env_list	*env_list;
}				t_setting;

/*			actors				*/
void	operation(char *input, t_setting **set);

/*			environment			*/
void	init_env(char **envp, t_setting **set);
int		add_env(t_env_list **env, const char *key_value_pair);
int		remove_env(t_env_list **env, const char *key);
char	*get_env_value(t_env_list *env, const char *key);
char	*get_env_key(char *str, int i);
int		update_env(t_env_list *env, const char *key, const char *new_value);
void	free_env(t_env_list	*env);
//		env_to_str		//
char	*find_key_and_get_env_value(char *str, int i, t_setting **set);
char	*get_env_to_str(t_setting **set, char *str);
//	temp
char	*split_and_join(char *p_str, int i, char *value);
int		get_third_size(char *str);

/*			input				*/
char	*get_input(void);
int		input_check(char *input);
char	*check_input_add(char *additional);

/*			execute				*/
int	execute(char **inputs, t_setting **set);

/*			tokenize			*/
//			shell split			//
char	**shell_split(char const *s);
char	*put_word(char *str, size_t s);
char	**do_split(char **tab, char *temp);
//			shell split utils	//
size_t	quote_leng(const char *s, size_t k);
size_t	tab_size(char *s);
t_quote	check_quote(char temp);
size_t	new_strlen_m(char *str, size_t k);
//			token split			//
char	**split_by_token(char **str);
char	**split_by_case(char **str, int i, int k);
//			case				//
char	**go_split(char **str, int i, int k);
char	**token_split_case_alone(char **str, int i, int k);
char	**token_split_case_no_back(char **str, int i, int k);
char	**token_split_case_no_front(char **str, int i, int k);
//			token split utils	//
int		split_case_index_check(char **str, int i, int k);
int		token_check(char c);
int		check_delimeter(char *str);
int		check_delimeter_type_i(char	*str);
size_t	dtab_size(char **str);
char	*deli_char(char c);

/*								*/
/*			builtins			*/
/*								*/
//		echo
int		ft_echo(char **inputs);


#endif