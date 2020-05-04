#include "filler.h"

void			piece_buff(t_piece *piece)
{
	char		*piece_line;
	int			i;

	i = 0;
	piece->tab = (char**)malloc(sizeof(char*) * piece->size.y);
	while (i < piece->size.y)
	{
		get_next_line(0, &piece_line);
		piece->tab[i++] = piece_line;
	}
}


int				place_first_point(t_filler filler, t_piece piece, int y, int x)
{
	int			i;
	int			j;
	int			connections;

	i = -1;
	connections = 0;
	if ((piece.size.y + y) > filler.size.y
			|| (piece.size.x + x) > filler.size.x)
		return (0);
	while (piece.size.y > ++i)
	{
		j = -1;
		while (piece.size.x > ++j)
		{
			if (ft_toupper(filler.tab[y + i][x + j])
					== ft_toupper(filler.players_info.mine)
					&& piece.tab[i][j] == '*')
				connections++;
			else if (filler.tab[y + i][x + j] != '.' && piece.tab[i][j] == '*')
				return (0);
			if (connections > 1)
				return (0);
		}
	}
	return ((connections == 1) ? 1 : 0);
}

int				**build_map(t_filler filler)
{
	int			**tab;
	int			y;
	int			x;

	y = 0;
	x = 0;
	if ((tab = (int**)malloc(sizeof(int*) * filler.size.y)))
	{
		while (y < filler.size.y)
		{
			tab[y] = (int*)malloc(sizeof(int) * filler.size.x);
			x = 0;
			while (x < filler.size.x)
			{
				if (filler.players_info.mine && ft_toupper(filler.players_info.mine)
						!= ft_toupper(filler.tab[y][x]) && filler.tab[y][x] != '.')
					tab[y][x] = 0;
				else
					tab[y][x] = -1;
				x++;
			}
			y++;
		}
	}
	return (tab);
}

void			warm_value(int **tab, t_position piece, int value, t_filler filler)
{
	if (piece.y > 0 && piece.x > 0 && tab[piece.y - 1][piece.x - 1] == -1)
		tab[piece.y - 1][piece.x - 1] = value + 1;
	if (piece.y > 0 && tab[piece.y - 1][piece.x] == -1)
		tab[piece.y - 1][piece.x] = value + 1;
	if (piece.y > 0 && (piece.x + 1) < filler.size.x && tab[piece.y - 1][piece.x + 1] == -1)
		tab[piece.y - 1][piece.x + 1] = value + 1;
	if (piece.x > 0 && tab[piece.y][piece.x - 1] == -1)
		tab[piece.y][piece.x - 1] = value + 1;
	if ((piece.x + 1) < filler.size.x && tab[piece.y][piece.x + 1] == -1)
		tab[piece.y][piece.x + 1] = value + 1;
	if (piece.x > 0 && (piece.y + 1) < filler.size.y && tab[piece.y + 1][piece.x - 1] == -1)
		tab[piece.y + 1][piece.x - 1] = value + 1;
	if ((piece.y + 1) < filler.size.y && tab[piece.y + 1][piece.x] == -1)
		tab[piece.y + 1][piece.x] = value + 1;
	if ((piece.y + 1) < filler.size.y && (piece.x + 1)
			< filler.size.x && tab[piece.y + 1][piece.x + 1] == -1)
		tab[piece.y + 1][piece.x + 1] = value + 1;
}

void			build_warm(int **map, t_filler filler)
{
	int				value;
	t_position		position;

	value = 0;
	position.y = 0;
	while (value < filler.size.y || value < filler.size.x)
	{
		position.y = 0;
		while (position.y < filler.size.y)
		{
			position.x = 0;
			while (position.x < filler.size.x)
			{
				if (map[position.y][position.x] == value)
					warm_value(map, position, value, filler);
				position.x++;
			}
			position.y++;
		}
		value++;
	}
}
