SRC_FILE =  ft_split.c ft_strjoin.c ft_strncmp.c ft_strlen.c ft_patht.c pipex.c
SRC_FILE_BOUNUS = ft_split.c ft_strjoin.c ft_strncmp.c ft_strlen.c ft_patht.c creat_linkdlist.c creat_pipe.c child_process.c creat_pipe_heredoc.c get_next_line.c get_next_line_utils.c pipex_bounus.c
NAME = pipex.a
OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_FILE_BOUNUS = $(SRC_FILE_BOUNUS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
HEADER = pipex.h
cc = gcc

all : $(NAME)

$(NAME) : $(OBJ_FILE) 
	ar rc $(NAME) $(OBJ_FILE)

bounus : $(OBJ_FILE_BOUNUS)
	ar rc $(NAME) $(OBJ_FILE_BOUNUS)

%.o:%.c $(HEADER)
	$(cc) $(CFLAGS) -c $< -o $@
clean :
	rm -f $(OBJ_FILE) $(OBJ_FILE_BOUNUS)

fclean : clean
	rm -f $(NAME)

re : fclean all
