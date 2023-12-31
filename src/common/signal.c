/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoonslee <yoonslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 10:44:29 by yoonslee          #+#    #+#             */
/*   Updated: 2023/08/21 17:42:35 by yoonslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/minishell.h"

/// @brief handles ctrl + c
/// @param icotl acts like printing '\n' for using enter
static void	handle_sig(int signo)
{
	if (signo == SIGINT)
	{
		g_info.sig_status = 1;
		ioctl(STDIN_FILENO, TIOCSTI, "\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

/// @brief leaving the minishell with ctrl + d
void	ctrl_d_cmd(char *line, t_data *ms)
{
	if (line == NULL)
	{
		restore_terminal(ms);
		ft_putstr_fd("exit\n", 0, 1);
		clear_hashmap((ms->env)->vars);
		exit(EXIT_SUCCESS);
	}
}

void	restore_terminal(t_data *ms)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &(ms->old_tio));
}

/// @param SIGNINT ctrl + c
/// @param SIGQUIT ctrl + '\'
/// @param ctrl + D will send by default NULL(EOF)
/// @param signal() ignores SIGQUIT signal (usually by pressing ctrl+)
void	set_signal_action(t_data *ms)
{
	tcgetattr(STDIN_FILENO, &(ms->old_tio));
	ms->new_tio = ms->old_tio;
	ms->new_tio.c_lflag &= ~ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &(ms->new_tio));
	ms->sa.sa_handler = &handle_sig;
	sigemptyset(&(ms->sa.sa_mask));
	ms->sa.sa_flags = 0;
	sigaction(SIGINT, &(ms->sa), NULL);
	signal(SIGQUIT, SIG_IGN);
}
