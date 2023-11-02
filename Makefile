DEF_COLOR =		\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m

NAME = philo

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread  -fsanitize=address -g #-fsanitize=thread -g
		

SOURCE = philosophers.c  utils_for_write.c \
		 init.c \
		 thread.c sacar_tiempos.c \
		 ft_sleep.c \
		 diner/no_gluttony.c \
		 action/philo_alone.c \
		 action/take_and_eat.c \
		 action/die.c \
		 utils/segurity.c\
		 utils/ft_fully.c \
		 utils/utils.c \
		 utils/ft_create_thread.c \

%.o: %.c
				@echo "${BLUE} ◎ $(YELLOW)Compiling   ${RED}→   $(GREEN)$< $(DEF_COLOR)"
				@${CC} ${CFLAGS} -c $< -o $@


OBJS = ${SOURCE:.c=.o}

all: ${NAME}
	
${NAME}: ${OBJS}
				@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
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

thread: CFLAGS += -fsanitize=thread
thread: CFLAGS += -g3
thread: CFLAGS += -pthread
thread: re

asan: CFLAGS += -fsanitize=address
asan: CFLAGS += -g3
asan: re


.PHONY: all clean fclean re 
