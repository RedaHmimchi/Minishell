/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 18:45:04 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/26 20:22:32 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void sigint_handler(int sig) 
{
    if (sig == SIGINT) 
    {
        // printf("\n");
        write(1, "\nminishell> ", 12);
	    // rl_replace_line("", 1);
        // rl_on_new_line();
	    rl_redisplay();
    }
}

void    sigquit_handler(int sig)
{
    if (sig == SIGQUIT)
        return;
}

void   initialize_signals()
{
    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);
}
