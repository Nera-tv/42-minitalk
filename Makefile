#Server's souces list
LST_SRCS_S	=	server.c			\
				server_utils.c		\
				client_utils.c						

LST_OBJS_S	=	${LST_SRCS_S:.c=.o}
SRCS_S		=	$(addprefix sources_server/,${LST_SRCS_S})
OBJS_S		=	$(addprefix .objects/,${LST_OBJS_S})

#Client's souces list
LST_SRCS_C	=	client.c			\
				client_utils.c					

LST_OBJS_C	=	${LST_SRCS_C:.c=.o}
SRCS_C		=	$(addprefix sources_client/,${LST_SRCS_C})
OBJS_C		=	$(addprefix .objects/,${LST_OBJS_C})

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror -O3
NAME_S		= 	server
NAME_C		=	client
HEADER		=	includes/minitalk.h
RM			=	rm -rf
INC			=	-I includes/
LFT			=	libft/libft.a

all: ${LFT} ${NAME_S} ${NAME_C}

${LFT}:
	make re -C ./libft

#Server compiler
.objects/%.o: sources_server/%.c $(HEADER)
	mkdir -p .objects
	${CC} ${CFLAGS} -I includes/ -c $< -o $@

${NAME_S} :	$(OBJS_S)
	make -C ./libft
	${CC} ${CFLAGS} ${OBJS_S} ${LFT} -o $(NAME_S) 


#Client compiler
.objects/%.o: sources_client/%.c $(HEADER)
	mkdir -p .objects
	${CC} ${CFLAGS} -I includes/ -c $< -o $@

${NAME_C} :	$(OBJS_C)
	make -C ./libft
	${CC} ${CFLAGS} ${OBJS_C} ${LFT} -o $(NAME_C) 

clean :
	${RM} .objects

fclean :	clean
	${RM} ${NAME_S} 
	${RM} ${NAME_C} 

re :		fclean all

.PHONY :	re fclean clean all