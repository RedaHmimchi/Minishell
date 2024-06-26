/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhmimchi <rhmimchi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 21:03:49 by rhmimchi          #+#    #+#             */
/*   Updated: 2024/06/26 08:24:01 by rhmimchi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_path(char *input, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*input == ' ' || *input == '\t')
		input++;
	while (*input != '\0' && *input != ' ' && *input != '\t')
		input++;
	while (*input == ' ' || *input == '\t')
		input++;
	while (input[i] != ' ' && input[i] != '\t' && input[i] != '\0')
		i++;
	data->path = malloc(sizeof(char) * i);
	while (j < i)
	{
		data->path[j] = input[j];
		j++;
	}
	data->path[j] = '\0';
}

void   parse_command(char *input, t_data *data)
{
	int	i;

	i = 0;
	while (*input == ' ' || *input == '\t')
		input++;
	while (input[i] != ' ' && input[i] != '\t' && input[i] != '\0')
		i++;
	data->start_path = i;
	data->cmd = malloc(sizeof(char) * i + 1);
	int j = 0;
	while (i > 0)
	{
		data->cmd[j] = input[j];
		j++;
		i--;
	}
	data->cmd[j] = '\0';
}
