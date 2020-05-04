#include "filler.h"

int				search_score(t_piece piece, int y, int x, int **map)
{
	int			i;
	int			j;
	int			score;

	i = 0;
	score = 0;
	while (i < piece.size.y)
	{
		j = 0;
		while (j < piece.size.x)
		{
			if (piece.tab[i][j] == '*')
				score += map[y + i][x + j];
			j++;
		}
		i++;
	}
	return (score);
}

void	place_piece(t_filler filler, t_piece piece, int **map)
{
	int			y;
	int			x;
	int			res_x;
	int			res_y;
	int			score;

	y = -1;
	res_x = 0;
	res_y = 0;
	score = INT_MAX;
	while (++y < filler.size.y)
	{
		x = -1;
		while (++x < filler.size.x)
			if (place_first_point(filler, piece, y, x))
				if (search_score(piece, y, x, map) < score)
				{
					res_x = x;
					res_y = y;
					score = search_score(piece, y, x, map);
				}
	}
	print_position(res_y, res_x);
}

void			print_position(int res_y, int res_x)
{
	ft_putnbr(res_y);
	ft_putchar(' ');
	ft_putnbr(res_x);
	ft_putchar('\n');
}




int main()
{
  t_filler filler;
  t_piece piece;
  int **map;

  ft_bzero(&filler, sizeof(filler));
  ft_bzero(&piece, sizeof(piece));
  data_player(&filler);
  while(map_size(&filler))
  {
    skip_line();
    map_buff(&filler);
    piece_size(&piece);
    piece_buff(&piece);
    map = build_map(filler);
    build_warm(map, filler);
	place_piece(filler, piece, map);
	delete_piece(&piece);
	delete_warm(map, filler);
	ft_memdel((void**)&map);
	delete_map(&filler);
  }
  
}
