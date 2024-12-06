# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 09:32:42 by dleclerc          #+#    #+#              #
#    Updated: 2024/12/05 10:32:32 by dleclerc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-Silent-------------#
ifndef VERBOSE
.SILENT:
endif

#-Color--------------#
DEFAULT	=	\033[0;39m
GRAY	=	\033[0;90m
RED		=	\033[0;91m
GREEN	=	\033[0;92m
YELLOW	=	\033[0;93m
BLUE	=	\033[0;94m
MAGENTA	=	\033[0;95m
CYAN	=	\033[0;96m
WHITE 	=	\033[0;97m
#-Variable-----------------------------#
PRINTF		=	printf
CFLAGS		=	-Wall -Wextra -Werror -g
RM			=	rm -f
CC			=	cc
NAME		=	push_swap
NAME_B		=	checker
#----------------------------#
OBJ_DIR		=	obj
OBJB_DIR	=	objb
#----------------------------#
SRC_DIR		=	source
SRC_DIRB	=	source_bonus
#----------------------------#
HEADER		=	libft/libft.h
#-Source-------------------------------#
SRC			= 	push_swap.c
#--------------------------------------#	
SRCB		=	checker_bonus.c
#-Object----------------------------------------------#
OBJ			=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
OBJB		=	$(addprefix $(OBJB_DIR)/, $(SRCB:.c=.o))
#-Progress-vars----------------------------------------------------------------------------------------------------------#
SRC_COUNT_TOT := $(shell expr $(shell echo -n $(SRC) | wc -w) - $(shell ls -l $(OBJ_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRC_COUNT_TOT) -le 0; echo $$?),0)
	SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
endif
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))
#------------------------------------------------------------------------------------------------------------------------#
SRCB_COUNT_TOT := $(shell expr $(shell echo -n $(SRCB) | wc -w) - $(shell ls -l $(OBJB_DIR) 2>&1 | grep ".o" | wc -l) + 1)
ifeq ($(shell test $(SRCB_COUNT_TOT) -le 0; echo $$?),0)
	SRCB_COUNT_TOT := $(shell echo -n $(SRCB) | wc -w)
endif
SRCB_COUNT := 0
SRCB_PCT = $(shell expr 100 \* $(SRCB_COUNT) / $(SRCB_COUNT_TOT))
#-Rule-------------------------------------------------------------------------------------------------------------------#
all				:	$(NAME)

$(NAME)			:	$(OBJ)
#					$(RM) bonus
#					$(RM) -r $(OBJB_DIR)
					$(PRINTF) "\n\n"
					make -C libft --silent
					$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)
					$(PRINTF) "$(GRAY)\n$(NAME) says : $(CYAN)$(NAME)$(GREEN) is up to date!\n$(DEFAULT)"

$(OBJ_DIR)/%.o	:	$(SRC_DIR)/%.c | $(OBJ_DIR)
					$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
					$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says :$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
					$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@
				
$(OBJB_DIR)/%.o: 	$(SRC_DIRB)/%.c | $(OBJB_DIR)
					$(eval SRCB_COUNT = $(shell expr $(SRCB_COUNT) + 1))
					$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says :$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRCB_COUNT) $(SRCB_COUNT_TOT) $(SRCB_PCT)
					$(CC) $(CFLAGS) -I$(HEADER) -c $< -o $@


bonus			:	$(OBJB)
#					$(RM) -r $(OBJ_DIR)
					touch bonus
					$(PRINTF) "\n\n"
					make -C libft --silent
					$(CC) $(CFLAGS) $(OBJB) libft/libft.a -o $(NAME_B)
					$(PRINTF) "$(GRAY)\n$(NAME) says : $(CYAN)$(NAME_B)$(GREEN) is up to date!\n$(DEFAULT)"

$(OBJ_DIR)		:
					mkdir -p $(OBJ_DIR)

$(OBJB_DIR)		:
					mkdir -p $(OBJB_DIR)
					
clean			:
					$(RM) -r $(OBJ_DIR)
					$(RM) -r $(OBJB_DIR)
					$(PRINTF) "$(GRAY)$(NAME) says : $(YELLOW)_*#*__$(CYAN)Cleaning up object$(YELLOW)__*#*_"
					sleep 0.8
					$(PRINTF) "\r\r$(GRAY)$(NAME) says : $(YELLOW)_*#*_🧹_*#*_🧹_*#*_*#*_*#*_*#*_"
					sleep 0.4
					$(PRINTF) "\r\r$(GRAY)$(NAME) says : $(YELLOW)_________*#*_🧹_*#*_🧹_*#*_*#*_"
					sleep 0.4
					$(PRINTF) "\r\r$(GRAY)$(NAME) says : $(YELLOW)_________________*#*_🧹_*#*_🧹_"
					sleep 0.4
					$(PRINTF) "\r\r$(GRAY)$(NAME) says : $(YELLOW)____________clean_🧹___________\n\n$(DEFAULT)"
					sleep 0.4
					make clean -C libft --silent

fclean			:	clean
					$(RM) $(NAME)
					$(RM) bonus
					$(PRINTF) "$(GRAY)$(NAME) says : $(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.4
					make do_clean=0 fclean -C libft --silent

re				:	fclean all

.PHONY			:	all clean fclean re
