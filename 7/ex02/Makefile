# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/27 06:51:47 by teando            #+#    #+#              #
#    Updated: 2025/09/03 14:25:59 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= a.out

SRC			:= main.cpp
ARG			:= 

CXX			:= c++
CXXFLAG		:= -Wall -Wextra -Werror -std=c++98 -pedantic
OPT			:= -O2
RM			:= rm -rf
ROOT_DIR	:= .
SRC_DIR		:= $(ROOT_DIR)
INC_DIR		:= $(ROOT_DIR)
OBJ_DIR		:= $(ROOT_DIR)/obj
DEFINE		:=
IDFLAG		:= -I$(INC_DIR)
OBJ			:= $(patsubst %.cpp, $(OBJ_DIR)/%.o, $(SRC))

# 42 Rules
all: $(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ============ ORIGINAL RULES ============
# build and run
run: $(NAME)
	./$(NAME) $(ARG)

1:	$(NAME)
	./$(NAME) $(ARG) 2&>/dev/null

# fast build
f:
	$(MAKE) $(NAME) -j $(shell nproc)

r: fclean
	$(MAKE) $(NAME) -j $(shell nproc)

# Debug build
debug: OPT		:= -g -O1 -fno-omit-frame-pointer -fsanitize=address
debug: DEFINE	:= 
debug: fclean
	$(MAKE) $(NAME) -j $(shell nproc)

test: r check fclean

# ============= BUILDS RULES =============

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAG) $(OPT) $(IDFLAG) $(DEFINE) -o $@ $^

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAG) $(OPT) $(IDFLAG) $(DEFINE) -MMD -MP -c $< -o $@

# ================= TEST =================

valgrind: $(NAME)
	@{ \
		TMP=$$(mktemp); \
		valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARG) >$$TMP 2>&1; \
		RET=$$?; \
		if [ $$RET -ne 0 ]; then \
		cat $$TMP; \
		echo "\033[31m[KO] Memory leaks detected!\033[0m"; \
		rm $$TMP; \
		exit $$RET; \
		else \
		cat $$TMP; \
		echo "\033[32m[OK] No memory leaks detected.\033[0m"; \
		rm $$TMP; \
		fi; \
	}

forbidden:
	@grep -R --include='*.cpp' --include='*.h*' --include='*.tpp' -nE '\b(malloc|calloc|free|printf|fprintf|sprintf|snprintf|dprintf|using namespace|friend)\b' $(SRC_DIR) \
	&& { \
		echo "\033[31m[KO] Forbidden patterns found.\033[0m" >&2; \
		exit 1; \
	} \
	|| { \
		echo "\033[32m[OK] No forbidden patterns found.\033[0m" >&2; \
		exit 0; \
	}

check: forbidden valgrind

# ================= MISC =================
nm:
	@nm $(OBJ) | grep ' U ' | awk '{print $$2}' | sort | uniq

nmbin:
	@nm $(NAME) | grep ' U ' | awk '{print $$2}' | sort | uniq

printsrc:
	@echo $(SRC) | tr ' ' '\n' | sort

printobj:
	@echo $(OBJ) | tr ' ' '\n' | sort

.PHONY: all clean fclean re run 1 f r debug test valgrind forbidden check nm nmbin printsrc printobj
