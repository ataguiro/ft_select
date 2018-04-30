# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ataguiro <ataguiro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/15 14:57:28 by ataguiro          #+#    #+#              #
#    Updated: 2017/01/28 15:55:20 by ataguiro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ===== Editable =====
NAME	:=	ft_select
INDEX	:=	1
# ====================

# ===== Standard =====
CC		:=	gcc
CFLAGS	:=	
SRCDIR	:=	src/
OBJDIR	:=	obj/
INCDIR	:=	include/
LIBDIR	:=	libft/
SRC		:=	$(SRCDIR)code/codes_basic.c \
			$(SRCDIR)code/codes_whitespace.c \
			$(SRCDIR)sin/sin_env.c \
			$(SRCDIR)sin/sin_select.c \
			$(SRCDIR)input.c \
			$(SRCDIR)key.c \
			$(SRCDIR)design.c \
			$(SRCDIR)modes.c \
			$(SRCDIR)ft_select.c \
			$(SRCDIR)key_get.c \
			$(SRCDIR)move.c \
			$(SRCDIR)print.c \
			$(SRCDIR)sig_handler.c
OBJ		:=	$(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
INC		:=	-I./$(INCDIR) -I./$(LIBDIR)$(INCDIR)
LIBPATH	:=	-L./$(LIBDIR) -lft
CACHEF	:=	.cache_exists
# ====================

# ====== Colors ======
CLEAR		= "\033[2K"
UP			= "\033[A"
EOC			= "\033[0;0m"
BLACK		= "\033[0;30m"
RED			= "\033[0;31m"
BRED			= "\033[1;31m"
GREEN		= "\033[0;32m"
BGREEN		= "\033[1;32m"
YELLOW		= "\033[0;33m"
BLUE		= "\033[0;34m"
PURPLE		= "\033[0;35m"
CYAN		= "\033[0;36m"
WHITE		= "\033[0;37m"
# ====================

.PHONY: all libft norme clean fclean re
.SILENT:

all: $(NAME)

$(NAME): libft $(OBJ)
	$(CC) $(CFLAGS) -ltermcap $(OBJ) -o $@ $(LIBPATH) $(LIB) $(INC)
	echo

$(OBJDIR)%.o: $(SRCDIR)%.c $(CACHEF)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	printf "\r"
	printf $(BGREEN)"[ compiling $(NAME)... ] "
	printf "$(shell echo 'scale=2;$(INDEX)/13 * 100' | bc)%%"$(EOC)
	$(eval INDEX=$(shell echo $$(($(INDEX)+1))))

$(CACHEF):
	test -d $(OBJDIR) || mkdir $(OBJDIR)
	test -d $(OBJDIR)code || mkdir $(OBJDIR)code
	test -d $(OBJDIR)sin || mkdir $(OBJDIR)sin
	test -d $(CACHEF) || touch $(CACHEF)

%.c:
	printf $(RED)"Missing file : $@\n"$(EOC)

libft:
	make -C $(LIBDIR)

norme:
	norminette $(SRCDIR) $(INCDIR) | grep -v Norme -B1 || true
	norminette $(LIBFT)$(SRCDIR) $(LIBFT)$(INCDIR) | grep -v Norme -B1 || true

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJDIR) $(CACHEF)
	printf $(YELLOW)"All objects removed\n"$(EOC)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -f $(NAME)
	printf $(RED)"$(NAME) removed\n"$(EOC)

re: fclean all
