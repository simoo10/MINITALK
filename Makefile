CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar -rc
RM		= rm -f
NAME	= minitalk.a
SRC		= server.c \
			client.c \
			minitalk_utils.c \
			
TARGET= server client			
OBJ	= $(SRC:.c=.o)
all: $(TARGET)
	
$(NAME): $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

server: $(NAME)
	gcc server.c minitalk.a -o server 
client: $(NAME)
	gcc client.c minitalk.a -o client
clean:
		$(RM) $(OBJ) $(TARGET)

fclean: clean
		$(RM) $(NAME)

re:	fclean all