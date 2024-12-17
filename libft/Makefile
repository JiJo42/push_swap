# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dleclerc <dleclerc@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/08 09:56:45 by dleclerc          #+#    #+#              #
#    Updated: 2024/12/17 15:16:51 by dleclerc         ###   ########.fr        #
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
#-//---------------------------#
NAME		=	libft.a
#-//---------------------------#
SRC_DIR			=	source
BUILD_DIR		=	object
#-//---------------------------#
HEADER		=	source/gnl_dir/get_next_line.h	\
				source/printf_dir/ft_printf.h	\
				source/printf_fd_dir/ft_printffd.h
#-//---------------------------#
do_clean 	:= 	1



#-Source----------------------------------------------#
#-Char-#
SRC			+=	source/char/ft_isalpha.c	\
				source/char/ft_isdigit.c	\
				source/char/ft_isalnum.c	\
				source/char/ft_isascii.c	\
				source/char/ft_isprint.c	\
				source/char/ft_tolower.c	\
				source/char/ft_toupper.c
#-Memory-#
SRC			+=	source/memory/ft_memset.c	\
				source/memory/ft_memcpy.c	\
				source/memory/ft_memmove.c	\
				source/memory/ft_memchr.c	\
				source/memory/ft_memcmp.c	\
				source/memory/ft_calloc.c	\
				source/memory/ft_bzero.c
#-Sting-#
SRC			+=	source/string/ft_strlen.c	\
				source/string/ft_strlcat.c	\
				source/string/ft_strnstr.c	\
				source/string/ft_strdup.c	\
				source/string/ft_strchr.c	\
				source/string/ft_strrchr.c	\
				source/string/ft_strmapi.c	\
				source/string/ft_strncmp.c	\
				source/string/ft_strlcpy.c	\
				source/string/ft_strtrim.c	\
				source/string/ft_striteri.c	\
				source/string/ft_substr.c	\
				source/string/ft_strjoin.c	\
				source/string/ft_itoa.c		\
				source/string/ft_split.c
#-Number-#
SRC			+=	source/number/ft_atoi.c	\
				source/number/ft_atol.c	\
				source/number/ft_insertion_sort.c
#-Write_fd-#
SRC			+=	source/write_fd/ft_putchar_fd.c	\
				source/write_fd/ft_putstr_fd.c	\
				source/write_fd/ft_putendl_fd.c	\
				source/write_fd/ft_putnbr_fd.c	\
				source/write_fd/ft_printf_fd.c
#				#-Printf_fd_utils-#
SRC			+=	source/write_fd/printf_fd/ft_putchar_pffd.c	\
				source/write_fd/printf_fd/ft_putstr_pffd.c	\
				source/write_fd/printf_fd/ft_putnbrs_pffd.c	\
				source/write_fd/printf_fd/ft_puthex_pffd.c	\
				source/write_fd/printf_fd/ft_putadress_pffd.c
#-List-#
SRC			+=	source/list/ft_lstsize.c	\
				source/list/ft_lstnew.c	\
				source/list/ft_lstlast.c	\
				source/list/ft_lstadd_back.c\
				source/list/ft_lstdelone.c	\
				source/list/ft_lstclear.c	\
				source/list/ft_lstiter.c	\
				source/list/ft_lstmap.c		\
				source/list/ft_lstadd_front.c
#-Printf-#
SRC			+=	source/printf/ft_printf.c		\
				source/printf/ft_putchar_pf.c	\
				source/printf/ft_putstr_pf.c	\
				source/printf/ft_putnbrs_pf.c	\
				source/printf/ft_puthex_pf.c	\
				source/printf/ft_putadress_pf.c
#-Get_next_line-#
SRC			+=	source/get_next_line/get_next_line.c	\
				source/get_next_line/gnl_fix_for_pipex.c\
				source/get_next_line/get_next_line_utils.c
#-Object----------------------------------------------#
OBJ			=	${SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o}
DIRS		=	$(sort $(shell dirname $(OBJ)))



#-Progress-vars-----------------------------------------------------#
SRC_COUNT_TOT := $(shell echo -n $(SRC) | wc -w)
SRC_COUNT := 0
SRC_PCT = $(shell expr 100 \* $(SRC_COUNT) / $(SRC_COUNT_TOT))



#-Rule-------------------------------------------------------------------------------------------------------------------#
all				:	$(NAME)

$(NAME)			:	$(OBJ)
					$(PRINTF) "\n"
					ar -rc $(NAME) $(OBJ)
					$(PRINTF) "$(GRAY)\n$(NAME) says: \t\t$(CYAN)$(NAME)$(GREEN) is up to date!\n$(DEFAULT)"

$(BUILD_DIR)/%.o	:	$(SRC_DIR)/%.c | $(DIRS)
						$(eval SRC_COUNT = $(shell expr $(SRC_COUNT) + 1))
						$(PRINTF) "\r%100s\r$(GRAY)$(NAME) says: \t\t$(CYAN)[ %d/%d (%d%%) ] $(BLUE)$<$(DEFAULT)" "" $(SRC_COUNT) $(SRC_COUNT_TOT) $(SRC_PCT)
						$(CC) $(CFLAGS) -c $< -o $@

$(DIRS)		:
					mkdir -p $@

				
					
#-Rule-Cleaning---------------------------------------------------------------------------------------------------------#
clean			:
					$(RM) -r $(BUILD_DIR)
					$(PRINTF) "$(GRAY)$(NAME) says: \t\t$(YELLOW)_*#*__$(CYAN)Cleaning up object$(YELLOW)__*#*_"
					sleep 0.6
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)_*#*_🧹_*#*_🧹_*#*_*#*_*#*_*#*_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)_________*#*_🧹_*#*_🧹_*#*_*#*_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)_________________*#*_🧹_*#*_🧹_"
					sleep 0.3
					$(PRINTF) "\r\r$(GRAY)$(NAME) says: \t\t$(YELLOW)____________clean_🧹___________\n\n$(DEFAULT)"
					sleep 0.3

fclean			:	
					if [ $(do_clean) -eq 1 ]; then  make clean --silent; fi
					$(RM) $(NAME)
					$(RM) bonus
					$(PRINTF) "$(GRAY)$(NAME) says: \t\t$(MAGENTA)🌀 Sending $(CYAN)$(NAME)$(MAGENTA) to the void 🌀\n\n$(DEFAULT)"
					sleep 0.3

re				:	fclean all



#-PHONY----------------------------------------------------------------------#
.PHONY			:	all clean fclean re