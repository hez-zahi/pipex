SRC_FILE =  ft_split.c ft_strjoin.c ft_strncmp.c ft_strlen.c ft_patht.c pipex.c creat_linkdlist.c creat_pipe.c child_process.c
SRC_FILE_BONUS = ft_split.c ft_strjoin.c ft_strncmp.c ft_strlen.c ft_patht.c creat_linkdlist.c creat_pipe.c child_process.c \
						creat_pipe_heredoc.c get_next_line.c get_next_line_utils.c pipex_bounus.c
NAME = pipex
NAME_BONUS = pipex_bonus
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_FILE_BONUS = $(SRC_FILE_BONUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = pipex.h pipex_bonus.h
cc = gcc

all : $(NAME)

%.o:%.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ_FILE) 
	@$(cc) $(CFLAGS) $(OBJ_FILE) -o $(NAME)

bonus : $(OBJ_FILE_BONUS)
	@$(cc) $(CFLAGS) $(OBJ_FILE_BONUS) -o $(NAME_BONUS)

clean :
	rm -f $(OBJ_FILE) $(OBJ_FILE_BONUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
