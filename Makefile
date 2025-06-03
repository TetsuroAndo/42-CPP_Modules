# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teando <teando@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/31 11:03:53 by teando            #+#    #+#              #
#    Updated: 2025/06/03 11:36:51 by teando           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Commands
MAKE	:= make -C
FCLEAN	:= make fclean -C
RUN		:= make run -C

# Modules
MODULES := 0 1 2 3 4 5 6 7 8 9

help:
	@echo "Usage:"
	@echo "  make all         - Build all modules"
	@echo "  make <module>    - Build a specific module (e.g., make 2)"
	@echo "  make run-<m>     - Run a specific module (e.g., make run-2)"
	@echo "  make fclean-<m>  - Clean a specific module (e.g., make fclean-2)"
	@echo "  make fclean      - Clean all modules"
	@echo "  make re-<m>      - Rebuild a specific module (e.g., make re-2)"
	@echo "  make list        - List all available exercises"
	@echo "  make help        - Show this help message"

all:
	@echo "Processing All"
	@for module in $(MODULES); do \
		if [ -d "$$module" ]; then \
			echo "Building $$module"; \
			for ex in $$module/ex*; do \
				if [ -f "$$ex/Makefile" ]; then \
					$(MAKE) "$$ex"; \
				fi; \
			done; \
		else \
			echo "Directory $$module does not exist"; \
		fi; \
	done

# Rules for specific modules
$(MODULES):
	@echo "Processing module $@"
	@if [ -d "$@" ]; then \
		for ex in $@/ex*; do \
			if [ -f "$$ex/Makefile" ]; then \
				echo "Building $$ex"; \
				$(MAKE) "$$ex"; \
			fi; \
		done; \
	else \
		echo "Module $@ does not exist"; \
	fi

# Run a specific module
run-%:
	@module=$$(echo $* | cut -d'/' -f1); \
	if [ -d "$$module" ]; then \
		echo "Running $$module"; \
		for ex in $$module/ex*; do \
			if [ -f "$$ex/Makefile" ]; then \
				echo "========== "$$ex" start ========="; \
				$(RUN) "$$ex"; \
				echo "=========== "$$ex" end =========="; \
			fi; \
		done; \
	else \
		echo "Directory $$module does not exist"; \
	fi

fclean-%:
	@module=$$(echo $* | cut -d'/' -f1); \
	if [ -d "$$module" ]; then \
		echo "Cleaning $$module"; \
		for ex in $$module/ex*; do \
			if [ -f "$$ex/Makefile" ]; then \
				$(FCLEAN) "$$ex"; \
			fi; \
		done; \
	else \
		echo "Directory $$module does not exist"; \
	fi

fclean:
	@echo "Cleaning all modules";
	@for module in $(MODULES); do \
		if [ -d "$$module" ]; then \
			echo "Cleaning $$module"; \
			for ex in $$module/ex*; do \
				if [ -f "$$ex/Makefile" ]; then \
					$(FCLEAN) "$$ex"; \
				fi; \
			done; \
		else \
			echo "Directory $$module does not exist"; \
		fi; \
	done

re-%:
	@module=$$(echo $* | cut -d'/' -f1); \
	if [ -d "$$module" ]; then \
		echo "Rebuilding $$module"; \
		for ex in $$module/ex*; do \
			if [ -f "$$ex/Makefile" ]; then \
				echo "Rebuilding $$ex"; \
				$(FCLEAN) "$$ex"; \
				$(RUN) "$$ex"; \
			fi; \
		done; \
	else \
		echo "Directory $$module does not exist"; \
	fi

# List all available exercises
list:
	@echo "Available exercises:"
	@for module in $(MODULES); do \
		if [ -d "$$module" ]; then \
			echo "\nModule $$module:"; \
			for ex in $$module/ex*; do \
				if [ -f "$$ex/Makefile" ]; then \
					echo "  $$(basename $$ex)"; \
				fi; \
			done; \
		fi; \
	done

.PHONY: help all $(MODULES) run-% fclean-% fclean re-% list
