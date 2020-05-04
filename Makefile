
FLAGS = -Wall -Werror -Wextra
NAME = mel-oual.filler
OBJECTS = get_next_line.o  parser.o place_piece.o destructor.o main.o
LIBFT = LIBFT_42/libft.a
all : $(NAME)
$(NAME) : $(OBJECTS) $(LIBFT)
	@clang $(FLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)
%.o : %.c
	@clang $(FLAGS) -g -c $< -o $@
$(LIBFT):
	@make -C LIBFT_42/
clean :
	@make clean -C LIBFT_42/
	@rm -f $(OBJECTS)
fclean : clean
	@rm -f $(NAME)
	@make fclean -C LIBFT_42/
re : fclean all
