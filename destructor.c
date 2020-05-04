#include "filler.h"


void			delete_piece(t_piece *piece)
{
	int			i;

	i = 0;
	while (i < piece->size.y)
	{
		free(piece->tab[i]);
		i++;
	}
	ft_memdel((void **)&piece->tab);
}

void			delete_warm(int **table, t_filler filler)
{
	int			i;

	i = 0;
	while (i < filler.size.y)
	{
		if (table[i])
			free(table[i]);
		i++;
	}
}

void			delete_map(t_filler *filler)
{
	int			i;

	i = 0;
	while (i < filler->size.y)
	{
		if (filler->tab[i])
			free(filler->tab[i]);
		i++;
	}
	ft_memdel((void**)&filler->tab);
}
