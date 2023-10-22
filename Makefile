DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread -g #-fsanitize=address -g

SOURCE = philosophers.c utils.c utils_for_write.c \
		 init.c segurity.c\
		 thread.c sacar_tiempos.c

%.o: %.c
				@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(GREEN)$< $(DEF_COLOR)"
				@${CC} ${CFLAGS} -c $< -o $@


OBJS = ${SOURCE:.c=.o}

all: ${NAME}
	
${NAME}: ${OBJS}
				@$(CC) $(CFLAGS) $(SOURCE) -o $(NAME)
				@echo "\n$(GREEN) Created $(NAME) ✓$(DEF_COLOR)\n" 
				@echo "    _       _       _" | lolcat
				@echo " __(.)<  __(.)>  __(.)=    Cuak!"  | lolcat
				@echo " \___)   \___)   \___)"  | lolcat

clean:
				@${RM} ${OBJS}
				@echo "\n${GRAY} ◎ $(RED)All objects cleaned successfully ${GRAY}◎$(DEF_COLOR)\n"

fclean:
				@${RM} ${NAME}
				@${RM} ${OBJS} 
				@echo "\n${GRAY} ◎ $(RED)All objects and executable cleaned successfully${GRAY} ◎$(DEF_COLOR)\n"

re: fclean all 

#thread: CFLAGS += -fsanitize=thread
#thread: CFLAGS += -g3
#thread: CFLAGS += -pthread
#thread: re


.PHONY: all clean fclean re 
