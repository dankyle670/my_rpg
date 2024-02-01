##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile <3
##

NAME		=	my_rpg

FILES		=	init/initstruct_b.c							\
				init/initstruct_t.c							\
				init/initstruct_battle.c					\
				init/init_pause_menu.c						\
				destroy_all.c								\
				create_generic_fonctions/sprite_menu.c		\
				create_generic_fonctions/sprites_obj.c		\
				create_generic_fonctions/create_button.c	\
				create_generic_fonctions/create_sprite.c	\
				create_generic_fonctions/create_sound.c		\
				create_generic_fonctions/create_text.c		\
				menu/menu.c									\
				menu/options.c								\
				menu/check_button.c							\
				menu/loading_menu.c							\
				menu/pause_menu.c							\
				colisions/obj_colisions.c					\
				colisions/map_colisions.c					\
				colisions/map_colisions2.c					\
				colisions/make_colisions.c					\
				colisions/demake_colision.c					\
				game_root/cursor.c							\
				game_root/display_particule.c				\
				game_root/game_root.c						\
				game_root/manage_input.c					\
				game_root/manage_input2.c					\
				game_root/event.c							\
				game_root/display_perso.c					\
				game_root/quests.c							\
				game_root/pokemons.c						\
				game_root/display_battle.c

CC			=	gcc

CFLAGS		+=	-Wall -Wextra -I include/ -g

SRCS_PREFIX	=	src/

MAIN		=	$(addprefix $(SRCS_PREFIX), main.c)

SRCS		=	$(addprefix $(SRCS_PREFIX), $(FILES))

OBJ			=	$(MAIN:.c=.o) $(SRCS:.c=.o)

OBJ_T		=	$(SRCS:.c=.o) $(TESTS:.c=.o)

LIB			=	-L./lib/my -lmy

GLIB		=	-lcsfml-graphics -lcsfml-system \
-lcsfml-window -lcsfml-audio -g

all:	makelib $(NAME)

# sed 0 by 1 -> bold
RED		=	\033[0;31m
GREEN		=	\033[0;32m
NC		=	\033[0m
GREY		=	\033[90m
BLUE		=	\033[0;94m
PURPLE		=	\033[0;95m
BG_COLOR	=	\033[46m
BLACK		=	\033[40m
IRED		=	\033[0;91m

ifndef VERBOSE
	MAKEFLAGS += --no-print-directory
endif

$(NAME):	$(OBJ)
	@echo -e '${NC}${GREY}Libs: $(LIB)$(LDFLAGS)${NC}'
	@echo -e '${GREY}Flags: $(CFLAGS)${NC}'
	@$(CC) -o $(NAME) $(OBJ) $(LIB) $(GLIB) $(LDFLAGS) 2>>build_log.txt\
		&& echo -e '${BLUE}Create${NC}: \e[;1m./$(NAME)\e[0m'\
		|| echo -e '${RED}[ FAILED ]${NC}: __Create__${GREY} ./$(NAME)${NC}'
	@echo -e "\e[42;1m----------------READY TO WORK!----------------\e[0m"

%.o:		%.c
	@-$(CC) -o $@ -c $< $(CFLAGS) $(LIB) $(GLIB) 2>>build_log.txt\
		&& echo -e '${GREEN} [ OK ]${NC} Build $<'\
		|| echo -e '${RED}[ FAILED ]${NC} __Build__ $<'\
		&& echo -ne '${PURPLE}' && grep  $< build_log.txt |\
		grep warning |cut -d':' -f2- |cut -d'[' -f-1\
		&& echo -ne '${PURPLE}' && grep  $< build_log.txt |\
		grep error |cut -d':' -f2-\
		||:

need:		$(OBJ)
	@make && echo "mkdir test ; cd test ; ls -a ; ls | cat | ./mysh

debug:	clean
	$(eval CFLAGS += -D DEBUG)
	@$(MAKE)

clean:
	@rm -rf $(OBJ)
	@rm -rf vgcore.*
	@rm -f gmon.out
	@rm -rf a.out
	@find . -name *.gc* -delete
	@rm -f build_log.txt
	@echo -e '${BLUE}Clean${NC} : OK'

makelib:
	@make -C lib/my

fclean:		clean
	@rm -rf build_log.txt 2>/dev/null
	@rm -rf $(NAME)
	@cd lib/my/ && make fclean && cd ../../
	@cd lib/ && rm -f libmy.a
	@cd lib/my/ && rm -f libmy.a
	@echo -e '${BLUE}Fclean${NC}: ./$(NAME) removed'

re:	fclean	makelib all

.PHONY: fclean clean all re

