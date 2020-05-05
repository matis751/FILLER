/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <mel-oual@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 01:29:41 by mel-oual          #+#    #+#             */
/*   Updated: 2020/05/05 03:33:13 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "LIBFT_42/libft.h"
# define BUFF_SIZE 1

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct	s_position
{
	int			y;
	int			x;
}				t_position;

typedef struct	s_player
{
	char		mine;
	char		other;
}				t_player;

typedef struct	s_piece
{
	char		**tab;
	t_size		size;
}				t_piece;

typedef struct	s_filler
{
	char		**tab;
	t_size		size;
	t_player	players_info;
}				t_filler;
typedef struct	s_gnl
{
	char		buff[BUFF_SIZE + 1];
	int			c;
	int			p;
}				t_gnl;

void			data_player(t_filler *filler);
int				map_size(t_filler *filler);
int				skip_line(void);
void			map_buff(t_filler *filler);
void			piece_size(t_piece *piece);

void			piece_buff(t_piece *piece);
int				place_first_point(t_filler f, t_piece p, int y, int x);
int				**build_map(t_filler filler);
void			warm_value(int **tab, t_position pos, int value, t_filler f);
void			build_warm(int **map, t_filler filler);

void			delete_piece(t_piece *piece);
void			delete_warm(int **table, t_filler filler);
void			delete_map(t_filler *filler);

int				get_next_line(const int fd, char **line);

void			print_position(int res_y, int res_x);

#endif
