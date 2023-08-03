NAME = cub3D
DEBUG = no

CFLAGS = -Wall -Wextra -Werror
MLXFlAGS = -L $(DIR_LIB)minilibx-linux -lmlx -lXext -lX11 -lm -I $(DIR_LIB)minilibx-linux

DFLAGS = -g3 -fsanitize=leak -fsanitize=address -fsanitize=pointer-subtract -fsanitize=pointer-compare -fsanitize=undefined

ifeq ($(DEBUG), yes)
CFLAGS += $(DFLAGS)
endif

DIR_SRC =	sources/

LST_SRC =	main.c				\
			utils/init.c		\
			utils/move.c		\
			utils/draw.c		\
			utils/close.c		\
			utils/draw_map.c	\
			utils/check_arg.c
			
SOURCES	=	$(addprefix $(DIR_SRC), $(LST_SRC))

DIR_OBJ	=	objects/
OBJECTS = 	$(patsubst $(DIR_SRC)%.c, $(DIR_OBJ)%.o, $(SOURCES))

DIR_HDR = 	includes/
HEADERS =	$(DIR_HDR)cube3d.h

DIR_LIB = 	libraries/
LIBRARY = 	$(DIR_LIB)libft/libft.a

#  ==============================  RULES  ==============================  #

all: lib 
	$(MAKE) $(NAME)

lib :
	@$(MAKE) -C $(DIR_LIB)libft
	@$(MAKE) -C $(DIR_LIB)minilibx-linux

debug :
	@$(MAKE) re DEBUG=yes

clean:
	@rm -rf $(DIR_OBJ)
	@$(MAKE) -C $(DIR_LIB)libft clean

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C $(DIR_LIB)libft fclean
	@$(MAKE) -C $(DIR_LIB)minilibx-linux clean
	@printf "$(RED)$(NAME) fclean done!\n$(END)"

re: fclean
	@$(MAKE) all

run: fclean
	@$(MAKE) -C $(DIR_SRC)libft
	$(MAKE) $(NAME)

.PHONY: all clean fclean re lib debug run

#  ===========================  COMPILATION  ===========================  #

$(NAME): $(DIR_OBJ) $(OBJECTS)
	cc $(OBJECTS) $(CFLAGS) $(MLXFlAGS) $(LIBRARY) -o $(NAME)

$(DIR_OBJ)	:
	@mkdir -p $(DIR_OBJ)
	@mkdir -p $(DIR_OBJ)/utils

$(DIR_OBJ)%.o: $(DIR_SRC)%.c $(HEADERS) $(LIBRARY)
	cc $(CFLAGS) -c $< -o $@

#  =============================  OPTIONS  =============================  #

ERASE		= 	\033[2K
RERASE		= 	\r\033[2K
BLACK		=	\033[0;30m
RED			=	\033[0;31m
GREEN		=	\033[0;32m
ORANGE		=	\033[0;33m
BLUE		=	\033[0;34m
PURPLE		=	\033[0;35m
CYAN		=	\033[0;36m
GRAY_LIGHT	=	\033[0;37m
GRAY_DARK	=	\033[1;30m
RED_LIGHT	=	\033[1;31m
GREEN_LIGHT	=	\033[1;32m
YELLOW 		=	\033[1;33m
BLUE_LIGHT	=	\033[1;34m
VIOLET		=	\033[1;35m
CYAN		=	\033[1;36m
WHITE		=	\033[1;37m
END			=	\033[0m
