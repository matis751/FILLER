/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <mel-oual@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:30:59 by mel-oual          #+#    #+#             */
/*   Updated: 2020/05/05 02:07:28 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			data_player(t_filler *filler)
{
	char		*line;

	if (get_next_line(0, &line) == 1)
	{
		filler->players_info.mine = (line[10] == '1') ? 'o' : 'x';
		filler->players_info.other = (line[10] == '2') ? 'o' : 'x';
	}
	if (line)
	{
		free(line);
	}
}

int				map_size(t_filler *filler)
{
	char		*plateau_line;
	int			i;

	i = 8;
	if (get_next_line(0, &plateau_line) == 1)
	{
		filler->size.y = ft_atoi(plateau_line + 8);
		while (plateau_line[i] != ' ')
			i++;
		filler->size.x = ft_atoi(plateau_line + i + 1);
		if (plateau_line)
			free(plateau_line);
		return (1);
	}
	if (plateau_line)
		free(plateau_line);
	return (0);
}

int				skip_line(void)
{
	char		*str;

	if (get_next_line(0, &str) == 1)
	{
		free(str);
		return (1);
	}
	return (0);
}

void			map_buff(t_filler *filler)
{
	int			i;
	char		*line;

	i = 0;
	filler->tab = (char**)malloc(sizeof(char*) * filler->size.y);
	while (filler->size.y > i && get_next_line(0, &line) == 1)
	{
		filler->tab[i] = ft_strdup(line + 4);
		free(line);
		i++;
	}
}

void			piece_size(t_piece *piece)
{
	char		*piece_size_line;
	int			i;

	i = 6;
	if (get_next_line(0, &piece_size_line) == 1)
	{
		piece->size.y = ft_atoi(piece_size_line + 6);
		while (piece_size_line[i] != ' ')
			i++;
		piece->size.x = ft_atoi(piece_size_line + i);
	}
	if (piece_size_line)
	{
		free(piece_size_line);
	}
}
