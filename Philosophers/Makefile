MAKEFLAGS += -s

CC = cc -g 

CFLAGS = -Wall -Wextra -Werror 

#CFLAGS += -fsanitize=thread
CFLAGS += -fsanitize=address

NAME = philo

SRCS = main.c parser.c utils.c safe_hadlers.c init.c setters_getters.c sincro.c meal.c logging.c monitor.c

#LIBFT = ./libraries/libft/libft.a
#PRINTF = ./libraries/printf/ft_printf.a


GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED		= \033[38;5;196m
RESET 		= \033[0m

#BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)

all: $(NAME) 

$(NAME):  $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -lpthread -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created"
	@echo " /###### /##          /##       /##                               /##"
	@echo "|_  ##_/| ##          | ##      |__/                              | ##"
	@echo "  | ## /######        | ##       /## /##    /## /######   /#######| ##"
	@echo "  | ##|_  ##_/        | ##      | ##|  ##  /##//##__  ## /##_____/| ##"
	@echo "  | ##  | ##          | ##      | ## \  ##/##/| ########|  ###### |__"
	@echo "  | ##  | ## /##      | ##      | ##  \  ###/ | ##_____/ \____ ##"
	@echo "/######|  ####/       | ########| ##   \  #/  |  ####### /######/ /##"
	@echo "|______/ \___/        |________/|__/    \_/    \_______/|_______/ |__"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡶⢿⣿⣿⢿⣿⡿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣉⠁⢈⣉⠁⠈⠛⠃⠘⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣦⣾⣿⡇⣼⣿⣧⣰⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿ o ⣿⣿⣿ o ⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀  "
	@echo "⠀⠀⠀⠀⠀⢠⡄⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣤⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⢸⡷⠶⠦⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠴⠶⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠘⠃⠀⠀⠀⠈⢻⣿⣿⣿⣿⣿⣿⠟⢀⠀⠀⠀⠛⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣠⡀⠺⣿⣷⣦⣉⠛⠛⠛⠋⣡⣴⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⠟⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣾⣿⣿⣿⣿⣷⠄⠀⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⣿⣯⣶⣶⡀⠉⢡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠛⢻⣿⣿⣥⣤⡈⠻⠛⣻⣿⣿⡟⠛⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣏⣠⡀⢿⣿⣿⡇⠀⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠉⠉⠉⠉⠀⠈⠉⠉⠉⠉⠉⠉⠉⠀⠉⠉⠁⠀⠉⠉⠉⠉⠀⠀⠀⠀$(RESET)"

#bonus: $(BONUS_OBJS) $(OBJS)
#	ar rc $(NAME) $(BONUS_OBJS) $(OBJS)  mete no clean -> $(BONUS_OBJS)

clean:
	rm -rf $(OBJS) 
	@echo "$(YELLOW)Removing $(NAME) objects files$(RESET)" 
	#cd libraries && cd libft && make clean
	#cd libraries && cd printf && make clean

fclean: clean
	rm -rf $(NAME) 
	@echo "$(RED)Removing $(NAME) executable"
	@echo " /###### /##          /#######  /##                 /##"
	@echo "|_  ##_/| ##         | ##__  ##|__/                | ##"
	@echo "  | ## /######       | ##  \ ## /##  /######   /#######"
	@echo "  | ##|_  ##_/       | ##  | ##| ## /##__  ## /##__  ##"
	@echo "  | ##  | ##         | ##  | ##| ##| ########| ##  | ##"
	@echo "  | ##  | ## /##     | ##  | ##| ##| ##_____/| ##  | ##"
	@echo " /######  ####/      | #######/| ##|  #######|  #######"
	@echo "|______/ \___/       |_______/ |__/ \_______/ \_______/"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡶⢿⣿⣿⢿⣿⡿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣉⠁⢈⣉⠁⠈⠛⠃⠘⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣦⣾⣿⡇⣼⣿⣧⣰⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿ x ⣿⣿⣿ x ⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⢠⡄⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣤⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⢸⡷⠶⠦⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠴⠶⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠘⠃⠀⠀⠀⠈⢻⣿⣿⣿⣿⣿⣿⠟⢀⠀⠀⠀⠛⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣠⡀⠺⣿⣷⣦⣉⠛⠛⠛⠋⣡⣴⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⠟⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣾⣿⣿⣿⣿⣷⠄⠀⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⣿⣯⣶⣶⡀⠉⢡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠛⢻⣿⣿⣥⣤⡈⠻⠛⣻⣿⣿⡟⠛⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣏⣠⡀⢿⣿⣿⡇⠀⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠉⠉⠉⠉⠀⠈⠉⠉⠉⠉⠉⠉⠉⠀⠉⠉⠁⠀⠉⠉⠉⠉⠀⠀⠀⠀$(RESET)"
	#cd libraries && cd libft && make fclean
	#cd libraries && cd printf && make fclean


re: fclean all 

.phony: all bonus clean fclean re 

################################# Making librarys #########################
#$(LIBFT):
#	cd libraries && cd libft && make 
	
#$(PRINTF):
#	cd libraries && cd printf && make 

	
	
	 

