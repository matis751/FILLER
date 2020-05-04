#include "LIBFT_42/libft.h"
#include <stdio.h>
#include "limits.h"
#define  BUFF_SIZE 1

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

/*PARSER*/
void			data_player(t_filler *filler);
int				map_size(t_filler *filler);
int				skip_line(void);
void		    map_buff(t_filler *filler);
void			piece_size(t_piece *piece);
/*PLACE_PIECE*/
void            piece_buff(t_piece *piece);
int				place_first_point(t_filler filler, t_piece piece, int y, int x);
int				**build_map(t_filler filler);
void			warm_value(int **tab, t_position piece, int value, t_filler filler);
void			build_warm(int **map, t_filler filler);

/*DESTRUCTOR*/
void			delete_piece(t_piece *piece);
void			delete_warm(int **table, t_filler filler);
void			delete_map(t_filler *filler);

/*GET_NEXT_LINE*/
int		get_next_line(const int fd, char **line);

/*MAIN*/
void			print_position(int res_y, int res_x);
