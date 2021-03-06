# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nihuynh <nihuynh@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/27 19:33:22 by nihuynh           #+#    #+#              #
#    Updated: 2019/01/16 10:05:11 by sklepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	rtv1
RUNMODE		?=	dev
#RUNMODE		?=	release
SCENE		:=	playground
SRC			:=	error.c main.c parser.c read.c render.c parse_toolbox.c \
				setter.c light.c
WIP			:=	light.c inter.c
# directories :
SRCDIR  	:=	srcs
OBJDIR 		:=	objs
INCDIR  	:=	includes
# LIBFT
LFT_NAME	:=	libft.a
LFT_PATH	:=	./libft
LFT_LIB		:=	-L $(LFT_PATH) -lft
LFT_INC		:=	-I $(LFT_PATH)/includes
LFT_RULE	:=	$(LFT_PATH)/$(LFT_NAME)
# LIBRT
LRT_NAME	:=	librt.a
LRT_PATH	:=	./librt
LRT_LIB	:=	-L $(LRT_PATH) -lrt
LRT_INC	:=	-I $(LRT_PATH)/includes
LRT_RULE	:=	$(LRT_PATH)/$(LRT_NAME)
# LIBUI
LUI_NAME	:=	libui.a
LUI_PATH	:=	./libui
LUI_LIB		:=	-L $(LUI_PATH) -lui
LUI_INC		:=	-I $(LUI_PATH)/includes
LUI_RULE	:=	$(LUI_PATH)/$(LUI_NAME)
# SDL
LSDL_LIB	:=	$(shell sdl2-config --libs)
LSDL_INC	:=	$(shell sdl2-config --cflags)
# **************************************************************************** #
# Automatic variable :
# If the first argument is "run"...
ifeq (run,$(firstword $(MAKECMDGOALS)))
  RUN_ARGS := $(wordlist 2,$(words $(MAKECMDGOALS)),$(MAKECMDGOALS))
  $(eval $(RUN_ARGS):;@:)
endif
RUN_SCENE	:=	$(or $(RUN_ARGS),$(SCENE))
SCENES		:= 	$(addprefix $(addprefix scenes/, $(RUN_SCENE)), .rt)
OBJ			:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.o))
DEP			:=	$(addprefix $(OBJDIR)/, $(SRC:.c=.d))
LIB			:=	$(LFT_LIB) $(LRT_LIB) $(LSDL_LIB) $(LUI_LIB)
INC			:=	-I $(INCDIR) $(LFT_INC) $(LSDL_INC) $(LRT_INC) $(LUI_INC)
# **************************************************************************** #
# make specs :
CC			:=	clang
CFLAGS		:=	-Werror -Wall -Wextra -g -I$(INCDIR)
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
OKLOGO		:=	\033[80G\033[32m[OK]\033[0m\n
GREP_ERR	:=	grep 'Error\|Warning' -C1 2> /dev/null || true
PHELP		:=	"\033[36m%-26s\033[0m %s\n"
# **************************************************************************** #
# Target rules :
.DEFAULT_GOAL := all
all: lib $(NAME) ## Built the project (Default goal).
.PHONY: all
$(NAME): $(OBJ) $(LFT_RULE) $(LRT_RULE) $(LUI_RULE)
	$(CC) $(CFLAGS) $(OBJ) -o $@ $(INC) $(LIB)
	printf "\n\033[1;34m$(NAME)\033[25G\033[32mBuilt $@ $(OKLOGO)"
-include $(DEP)
$(LFT_RULE):
	$(MAKE) -C $(LFT_PATH)/ RUNMODE=$(RUNMODE)
$(LRT_RULE):
	$(MAKE) -C $(LRT_PATH)/ RUNMODE=$(RUNMODE)
$(LUI_RULE):
	$(MAKE) -C $(LUI_PATH)/ RUNMODE=$(RUNMODE)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir $(OBJDIR) 2> /dev/null || true
	$(CC) $(CFLAGS) -MMD -c -o $@ $< $(INC)
	printf "\033[1;34m$(NAME)\033[25G\033[33mCompile $< $(OKLOGO)"
lib: ## Built the libraries.
	$(MAKE) -j32 -sC $(LFT_PATH) RUNMODE=$(RUNMODE)
	$(MAKE) -j32 -sC $(LRT_PATH) RUNMODE=$(RUNMODE)
	$(MAKE) -j32 -sC $(LUI_PATH) RUNMODE=$(RUNMODE)
.PHONY: lib
clean:  ## Clean of the project directory (.o & .d).
	$(RM) $(OBJ)
	$(RM) $(DEP)
	$(RM) -r $(OBJDIR) 2> /dev/null || true
	printf "\033[1;34m$(NAME)\033[25G\033[31mCleaning objs $(OKLOGO)"
.PHONY: clean
lclean: ## Clean of the library.
	$(MAKE) -C $(LFT_PATH)/ fclean
	$(MAKE) -C $(LRT_PATH)/ fclean
	$(MAKE) -C $(LUI_PATH)/ fclean
.PHONY: lclean
dclean: ## Clean of the documentation.
	$(RM) -r docs/html 2> /dev/null || true
	$(RM) -r docs/latex 2> /dev/null || true
.PHONY: dclean
fclean: clean lclean dclean ## Full clean of the directory & the libs.
	$(RM) $(NAME)
	printf "\033[1;34m$(NAME)\033[25G\033[31mCleaning $(NAME) $(OKLOGO)"
.PHONY: fclean
re: fclean all ## Rebuilt the project.
.PHONY: re
git: fclean ## Clean the project directory & add file to git.
	git add -A
	printf "\033[1;34m$(NAME)\033[25G\033[31mGit sync $(OKLOGO)"
	git status
.PHONY: git
run: all ## Run scenes from the scenes folder.
	printf "\033[1;34m$(NAME)\033[25G\033[31mRunning $(SCENES) $(OKLOGO)"
	./$(NAME) $(SCENES)
.PHONY: run
usage: ## Print out on how to use this Makefile.
	printf "\n$(NAME)\n  Usage:\n\tmake <target>\n\n  Targets:\n"
	fgrep -h " ## " $(MAKEFILE_LIST) \
	| fgrep -v fgrep | awk 'BEGIN {FS = ":.*?## "}; {printf $(PHELP), $$1, $$2}'
	printf "\n  Scenes:\n"
	for file in `LS scenes | grep .rt | sort -u | cut -d . -f 1`; \
		do printf "make run $$file \n"; done
.PHONY: usage
doc: ## Generate a documentation using doxygen.
	doxygen Doxyfile
	open docs/html/index.html
.PHONY: doc
ls: ## List all the repo to see if the clean is done.
	\ls -R . $(LFT_PATH) $(LRT_PATH) $(LUI_PATH) \
	| grep -Fv .c | grep -Fv .h | grep -Fv $(LUI_PATH) \
	| grep -Fv $(LRT_PATH) | grep -Fv $(LFT_PATH) \
	| grep -Fv srcs | grep -Fv includes | grep -Fv .rt \
	| grep -Fv README.md | grep -Fv .pdf | grep -Fv .png \
	| grep -Fv Makefile | grep -Fv Doxyfile | grep -Fv changelog.md \
	| grep -Fv scenes | grep -Fv auteur | awk 'NF!=0'
.PHONY: ls
norme: ## Check the norme of the project and the libraries.
	norminette -R CheckForbiddenSourceHeader srcs includes | $(GREP_ERR)
	$(MAKE) -C $(LFT_PATH) norme
	$(MAKE) -C $(LRT_PATH) norme
	$(MAKE) -C $(LUI_PATH) norme
	printf "\033[1;34m$(NAME)\033[25G\033[31mNorminette $(OKLOGO)"
.PHONY: norme
