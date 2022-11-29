/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mouarsas <mouarsas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 20:12:12 by mouarsas          #+#    #+#             */
/*   Updated: 2022/11/09 21:32:05 by mouarsas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include "readline/readline.h"
# include "readline/history.h"
# include <curses.h>
# include <limits.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# define BUFF_SIZE 1024

typedef struct s_list
{
	char			*str;
	struct s_list	*first;
	struct s_list	*next;
}				t_list;

typedef struct s_my
{
	char	c;
	int		i;
	int		x;
	int		j;
	int		start;
	int		per;
	int		per2;
	int		per3;
	char	*tmp;
	char	*tmp2;
	char	*tmp3;
	char	*tmp4;
	char	*new;
}				t_my;

typedef struct s_pi
{
	char	*new;
	int		p;
	int		**pipe;
}				t_pi;

typedef struct s_cd
{
	int		i;
	char	*old_cur;
	int		*st;
	char	path[255];
}				t_cd;

typedef struct s_norme
{
	char	**env;
	t_pi	pi;
}				t_norme;

typedef struct s_norme2
{
	char	*str;
	char	**tab;
	int		status;
	char	**andand;
	char	**oror;
}				t_norme2;

typedef struct s_norme3
{
	char	**str;
	int		p0;
	int		status;
	char	**andand;
	char	**oror;
}				t_norme3;

typedef struct s_env_list
{
	char				*name;
	char				*environ;
	struct s_env_list	*next;
}				t_env_list;

typedef struct s_status
{
	t_pi	pi;
	int		status;
}				t_status;

typedef struct s_some_norme
{
	char	c;
	char	count;
	int		b;
	char	*str;
}				t_some_norme;

typedef struct s_global
{
	int	status;
	int	old_status;
}				t_global;

t_global	g_isexecuting;

/////////////////////////////////////////////////

int				ft_pwd(t_pi pi);
int				ft_echo(char **av, t_pi pi, int i);
int				ft_get_sig(int sig);
int				ft_newline(char *s);
void			environment(t_list *env);
void			ft_env(char **av, t_list *list, t_pi pi);
void			free_and_exit(int status);
t_list			*ft_my_exit(char **av, t_list *list, t_pi *pi, t_norme2 *norme);
t_list			*ft_cd(char **av, t_list *list, t_pi pi, int *st);
char			*get_key_env(char *str);
char			*get_value_env(char *str);
t_list			*ft_unset(char **av, t_list *list);
t_list			*get_node_env(char *s, t_list *list);
t_list			*ft_export(char **av, t_list *list, t_pi pi);
t_list			*cd_norm(t_list *list, t_pi pi, int *st);
char			*env_value(char *s, t_list *list);
t_list			*change_dir(char **av, t_cd ci, t_list *list, t_pi pi);
void			change_dir_norm(t_cd ci, t_list *list, t_pi pi);
t_list			*help_hamza_mustafa_cd(t_pi pi, char *old_cur, \
				int *st, t_list *list);
void			handle(int sig);
char			*boyka_help_us_echo(int len, char *str, int i);

t_list			*and_and(t_list *list, char *str, t_norme3 norme);
void			anathor_help_for_mini1(char *str, t_norme3 *norme3,
					t_norme2 *norme);
void			another_mini_help_for_mini2(t_status *status, char *commande);
int				check_if_and_and(char **str, int i);
int				check_count_and(char *str, int countand);
int				print_number_of_and(char s, int count);
int				print_and_of_number(char s, int count);
int				print_fu_redirect_error(void);
int				some_name(int *i, int *j, char *str, char c);
int				some_norme_again(char *str, int j, char c, int count);
int				some_name_norme(t_some_norme norme, int *j, int *i);
char			*replace_home(char *line, t_env_list *env);
int				help_replace_home2(char **line, int i, t_env_list *env);
int				help_replace_home(char **line, int i);
char			*check_if_exist(char *command, char **env);
char			*help_to_concate(char *first, char **str, int j);
char			*concate(char *path, char *str);
char			**mini_filter_h(char **str, char **command);
void			join_with_anything2(char **line, char *str, int a, int i);
int				help_to_take_file(int j, char **file);
int				help_type_one(char *file, int *error);
int				parse_to_two(char *file, int out, int type, int ***pipe);
void			free_of_trait0(t_pi *pi, int i, char **str, int *status);
void			free_of_trait0v2(t_pi *pi, int i);
int				check_if_is_num(char *file);
int				print_error_num(char *file, int *error, int *staus);
char			*serach_env2(t_list *list);
t_list			*or_or(t_list *list, char *str, t_norme3	*norme);
char			**split_and_and(char *line, char c);
void			help_split_and_and(char *line, char **command, int i, char s);
int				count_and_and(char *line, char s);
char			*check(char *str);
int				trait_the_pi(char *str, t_pi *pi, int p0);
void			close_pi(t_pi *pi);
void			wait_null(int p2, int i, int *status);
t_list			*ft_trait0v2(t_list *list, char *line);
void			help_the_systeme(t_norme norme);
int				error_type_three(char *file, int *error);
int				if_three(char *file2, int out, int type, int ***pipe);
int				if_two(int out, int type, int ***pipe);
int				if_four(char *file2, int out, int type, int ***pipe);
int				print_bad_file(char *file2, int ***pipe);
int				print_syntax_error(int ***pipe);
void			free_2d(char **str);
void			free_my_pi(t_pi	*pi);
int				check_line(char *line);
char			**split_command(char *line, char s);
void			help_bonus(char *line, char **command, char s, int i);
int				count_command(char *line, char s);
char			*replace_with_env(char *line, t_env_list *env, int b);
char			*help_replace_env(int *a, char *line, int i, t_env_list *env);
void			join_with_something(char **line, char *str, int a, int i);
char			*check_env(char *str, t_env_list *env);
char			*move_slash(char *line);
char			*help_slash(char *line, int a);
int				count_slash(char *line);
char			*move_quote(char *line, int i);
char			*get_name(char *environ);
char			*get_environ(char *environ);
int				leno(char *s);
int				jump_quote(char *s, int end);
char			**ls(char *path);
int				n_str(char *path);
void			remplir(char **str, char *path);
t_list			*ft_trait(char *commande, t_list *list,
					char **argv, t_status *status);
char			**pipe_line(char *line);
int				error_pipe(char **str, char *line);
char			**ft_strsplito(char *s);
int				search_no_espace(char *str);
int				complete_the_pipe(char **str);
void			help_to_finish_the_pipe(char **line);
int				leno_pipe(char *str, char c);
int				check_redirections(char **str);
int				check_one_by_one(char *line);
int				check_if_h_file(char *line);
int				redirect(t_pi *pi, char **line, int *status);
char			*take_file(char **file, int *j);
void			join_with_anything(char **line, int a, int i);
int				type_pipe(char *line, int i);
int				help_redirect(char *file);
int				redirect_with_fd(char *line, int *i);
int				**alloc_for_int(void);
int				help_to_parse(char **line, int j, int ***pipe, int *status);
int				print_p_d(char *file, int *pipe);
int				print_n_x(char *file, int *pipe);
int				print_i_d(char *file, int *pipe);
int				type_one(char *file, int ***pipe, int out);
int				type_two(char *file, int ***pipe, int out);
int				type_three(char *file, int ***pipe, int out);
int				type_four(char *file, int ***pipe, int out);
int				trait_the_type(char *file, int out, int type, int ***pipe);
int				check_number_or_word(char *file);
int				trait_the_and(char *file, int out, int type, int ***pipe);
t_list			*ft_trait1(t_norme2 *norme, t_list *list, t_pi *pi,
					char **tab);
int				mylen2(char *str, char *argv);
int				mylen(char *str);
char			**my_magic(t_list *list);
char			*ft_filter_quote(char *cont);
int				ft_number_words(char *cont);
char			**ft_deux(char *cont, char **argv);
void			ft_fresh(char **tab);
int				search_commande(t_list *list, char *commande,
					char **argv, t_pi pi);
void			free_mylist(t_list *list);
void			affichage_myenv(t_list *list, t_pi pi);
t_list			*ft_trait0(t_list *list, char *line, t_norme3 *norme3, int i);
t_list			*new_list(char *tmp);
t_list			*stock_list(char **env);
t_list			*ft_myshell(char **argv, int com, t_list *list,
					t_status *status);
t_env_list		*create_env(char **environ);
t_env_list		*create_next(char *environ);
t_list			*help_mini_or_or(t_list *list, char **new);
int				help_to_redirect_with_fd(char *str, int *i, int j);
void			ft_mini_help_ft_trait(char **argv, t_list *list, \
				t_status *status, char *commande);
void			ok_x_path(char **argv, t_list *list, t_pi pi, int *status);
t_list			*help_to_norme_ft_trait0(t_list *list, char *line, \
				t_norme3 *norme3, char ***str);
t_list			*last_help_for_ft_trait0(t_list *list, t_norme2 *norme, \
				t_status status);

#endif