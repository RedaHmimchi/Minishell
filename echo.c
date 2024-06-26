/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 14:35:46 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/25 14:47:43 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void    ft_echo(char *cmd)
{
    int i;
    int nl;

    i = 0;
    nl = 0;
    if (cmd[5] == '-' && cmd[6] == 'n')
    {
        nl = 1;
        i = 8;
    }
    if (cmd[5] == '$')
    {
        i = 6;
        char *var = cmd + 6;
        char *value = getenv(var);
        if (value != NULL)
            printf("%s", value);
        return;
    }
    else
        i = 5;
    while (cmd[i] != '\0') 
    {
        if (cmd[i] == '\"')
            i++;
        else
        {
            printf("%c", cmd[i]);
            i++;
        }
    }
    if (nl == 0)
        printf("\n");
    return;
}
