NAME = pipex
NAME_B = pipex

LIBRARIES	=	-L./libft -lft
LIBFT		=	./libft/libft.a

HEADER = ./includes/pipex.h 
SRCS_UTILS = ./srcs/check_arg.c ./srcs/get_env.c ./srcs/errorer.c
SRCS = ./srcs/pipex.c ${SRCS_UTILS}

HEADER_B = ./includes_bonus/pipex_bonus.h
SRCS_UTILS_B = ./srcs_bonus/check_arg_b.c ./srcs_bonus/get_env_b.c \
		./srcs_bonus/errorer.c
SRCS_B = ./srcs_bonus/pipex_b.c ${SRCS_UTILS_B}

CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf

OBJ = ${SRCS:.c=.o}
OBJ_B = ${SRCS_B:.c=.o}

all : ${NAME}

${NAME} : Makefile ${OBJ} ${HEADER}
	@make -C ./libft
	@echo "\033[32m'libft' was compiled\n"
	@${CC} ${CFLAGS} ${LIBRARIES} ${OBJ} -I./includes/pipex.h -o ${NAME}
	@echo "\033[32mPipex compiled"

bonus : Makefile ${OBJ_B} ${HEADER_B}
	@make -C ./libft
	@echo "\033[32m'libft' was compiled\n"
	@${CC} ${CFLAGS} ${LIBRARIES} ${OBJ_B} -I./includes_bonus/pipex_bonus.h -o ${NAME_B}
	@echo "\033[32mBonus Update"

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean :
	@${RM} ${OBJ} ${OBJ_B}
	@echo "\033[32mClean"

fclean : clean
	@make fclean -C ./libft
	@echo "\033[32m'libft' was fclean\n"
	@${RM} ${NAME}
	@echo "\033[32mPipex fclean"

re: fclean all

.PHONY: all clean fclean re bonus