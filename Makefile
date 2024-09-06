STD = -std=c99
COMPILER = gcc
LIB = build/lib/cset99.a
I = -Iinclude
OPTIONS = -Wall -Wpedantic -Wno-unused-result -O0 -g
OPTIMIZED = -Wall -Wpedantic -Wno-unused-result -Ofast -g
OBJ = build/obj
BUILDER = ar rv

FILES = structs/safearray.c structs/set.c
VALIDATION = auxiliar/valset.c

safe:
	gcc -Iinclude -Iauxiliar $(FILES) $(VALIDATION) tests/test_safearray.c -o build/test_safearray.exe
	gcc -Iinclude -Iauxiliar $(FILES) $(VALIDATION) tests/test_set.c -o build/test_set.exe


compile:
	for file in $(FILES) ; do \
		$(COMPILER) $(STD) -c $$file $(I) -o $(OBJ)/$$file.o ; \
	done

library:
	for file in $(FILES); do \
		$(BUILDER) $(LIB) $(OBJ)/$$file.o ; \
	done

build: compile library