# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 19:33:22 by nihuynh           #+#    #+#              #
#    Updated: 2019/01/03 05:02:02 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libui.a
RUNMODE		?=	dev
SDL_SRC		:=	init_sdl.c error_sdl.c putpixel_sdl.c putcolor_sdl.c exit_sdl.c\
				render_sdl.c loop_sdl.c init_mthr_sdl.c render_mthr_sdl.c
COLOR		:=	color_add.c color_sub.c color_mult.c color_scalar.c \
				colortoi.c color_max.c
SRC			:=	$(SDL_SRC) $(COLOR)
HEADERS		:=	libui.h color.h
# directories :
SRCDIR  	:=	srcs
OBJDIR 		:=	objs
INCDIR  	:=	includes
# LIBFT
LIBFT_NAME	:=	libft.a
LIBFT_PATH	:=	../libft
LFT_LIB	:=	-L $(LIBFT_PATH) -lft
LFT_INC	:=	-I $(LIBFT_PATH)/includes
# SDL
LSDL_LIB	:=	$(shell sdl2-config --libs)
LSDL_INC	:=	$(shell sdl2-config --cflags)
# **************************************************************************** #
# make specs :
CC			:=	clang
CFLAGS		:=	-Werror -Wall -Wextra
CFLAGS		+=	-Wstrict-aliasing -pedantic -Wunreachable-code
ifeq ($(RUNMODE),dev)
    CFLAGS	+=	-g3 -O0
	# CFLAGS	+=	-Wpedantic -ggdb -fsanitize=address
else
	CFLAGS	+= -O2
endif
RM			:=	/bin/rm -f
.SILENT:
.SUFFIXES:
# **************************************************************************** #
# Automatic variable :
OBJ			:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
HEAD		:=	$(addprefix $(INCDIR)/, $(HEADERS))
LIB			:=	$(LFT_LIB) $(LSDL_LIB)
INC			:=	-I $(INCDIR) $(LFT_INC) $(LSDL_INC)
# **************************************************************************** #
OKLOGO		:=	\033[80G\033[32m[OK]\033[0m\n
GREP_ERR	:=	grep 'Error\|Warning' -C1 2> /dev/null || true
# **************************************************************************** #
# Rules :
all: $(NAME)
.PHONY: all
$(NAME): $(OBJ) $(HEAD) $(LFT_RULE)
	libtool -static -o $@ $(OBJ) && ranlib $@
	@printf "\n\033[1;34m$@\033[25G\033[32mBuilt $@ $(OKLOGO)"
$(LFT_RULE):
	make -C $(LFT_PATH)/
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(HEAD)
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -c -o $@ $< $(INC)
	@printf "\033[1;34m$(NAME)\033[25G\033[33mCompile $< $(OKLOGO)"
clean:
	$(RM) $(OBJ)
	rmdir $(OBJDIR) 2> /dev/null || true
	@printf "\033[1;34m$(NAME)\033[25G\033[31mCleaning objs $(OKLOGO)"
.PHONY: clean
fclean: clean
	$(RM) $(NAME)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mCleaning $(NAME) $(OKLOGO)"
.PHONY: fclean
re: clean all
.PHONY: re
git: clean
	git add -A && git status
	@printf "\033[1;34m$(NAME)\033[25G\033[31mGit sync $(OKLOGO)"
.PHONY: git
re: fclean all
.PHONY: re
norme:
	norminette -R CheckForbiddenSourceHeader srcs includes | $(GREP_ERR)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mNorminette $(OKLOGO)"
.PHONY: norme
