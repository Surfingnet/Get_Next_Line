NAME = Get_Next_Line
SRC_DIR =./
INCLUDES_DIR =./
SRCS=main get_next_line
FLAGS=-Wall -Wextra -Werror
BINS = $(patsubst %,%.o,$(SRCS))
LIBS =libft

.PHONY: all clean fclean re libft

all: $(NAME)

$(LIBS):
	@make -C $(@)

$(BINS):
	gcc -I $(INCLUDES_DIR) $(FLAGS) -c $(patsubst %.o,$(SRC_DIR)%.c,$@)

$(NAME): $(BINS) $(LIBS)
	gcc $(FLAGS) -o $(NAME) $(BINS) $(LIBS)/$(patsubst %,%.a,$(LIBS))

clean:
	/bin/rm -f $(BINS)
	@make -C $(LIBS) clean

fclean: clean
	/bin/rm -f $(NAME) $(LIBS)/$(patsubst %,%.a,$(LIBS))

re: fclean all
