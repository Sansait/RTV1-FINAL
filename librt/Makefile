# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 19:33:22 by nihuynh           #+#    #+#              #
#    Updated: 2019/01/03 05:01:31 by nihuynh          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	librt.a
VEC			:=	vec3_add.c vec3_cross.c vec3_mag.c vec3_scalar.c vec3_cos.c \
				vec3_dot.c vec3_normalize.c vec3_sub.c vec3_new.c vec3_print.c \
				vec3_cpy.c vec3_find.c ray_new.c vec3_reflect.c print_matrix.c \
				vec3_matrix_mult.c vec3_matrix_apply.c
INTER		:=	inter_cylinder.c inter_plane.c inter_sphere.c inter_cone.c \
				inter_set.c inter_find.c inter_setlight.c
COLOR		:=	color_cpy.c
MATRIX		:=	mat3_rot.c
NORMAL		:=	normal_cone.c normal_sphere.c normal_cylinder.c normal_plane.c
SRC			:=	$(VEC) $(INTER) $(COLOR) $(NORMAL) $(MATRIX)
# directories :
SRCDIR  	:=	srcs
OBJDIR 		:=	objs
INCDIR  	:=	includes
# LIBFT
LIBFT_NAME	:=	libft.a
LIBFT_PATH	:=	../libft
LFT_LIB	:=	-L $(LIBFT_PATH) -lft
LFT_INC	:=	-I $(LIBFT_PATH)/includes
# **************************************************************************** #
# make specs :
CC			:=	clang
CFLAGS		:=	-Werror -Wall -Wextra
CFLAGS		+=	-Wstrict-aliasing -pedantic -Wunreachable-code
RM			:=	/bin/rm -f
# **************************************************************************** #
# Automatic variable :
OBJ			:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEP			:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.d))
LIB			:=	$(LFT_LIB)
INC			:=	-I $(INCDIR) $(LFT_INC)
# **************************************************************************** #
OKLOGO		:=	\033[80G\033[32m[OK]\033[0m\n
GREP_ERR	:=	grep 'Error\|Warning' -C1 2> /dev/null || true
# **************************************************************************** #
# Target rules :
all: $(NAME)
.PHONY: all
$(NAME): $(OBJ) $(LFT_RULE)
	@libtool -static -o $@ $(OBJ) && ranlib $@
	@printf "\n\033[1;34m$@\033[25G\033[32mBuilt $@ $(OKLOGO)"
-include $(DEP)
$(LFT_RULE):
	@make -C $(LFT_PATH)/
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir $(OBJDIR) 2> /dev/null || true
	@$(CC) $(CFLAGS) -MMD -c -o $@ $< $(INC)
	@printf "\033[1;34m$(NAME)\033[25G\033[33mCompile $< $(OKLOGO)"
clean:
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(RM) test.out
	@rmdir $(OBJDIR) 2> /dev/null || true
	@printf "\033[1;34m$(NAME)\033[25G\033[31mCleaning objs $(OKLOGO)"
.PHONY: clean
fclean: clean
	@$(RM) $(NAME)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mCleaning $(NAME) $(OKLOGO)"
.PHONY: fclean
re: clean all
.PHONY: re
git: fclean
	@git add -A
	@printf "\033[1;34m$(NAME)\033[25G\033[31mGit sync $(OKLOGO)"
	@git status
.PHONY: git
norme:
	@norminette -R CheckForbiddenSourceHeader srcs includes | $(GREP_ERR)
	@printf "\033[1;34m$(NAME)\033[25G\033[31mNorminette $(OKLOGO)"
.PHONY: norme