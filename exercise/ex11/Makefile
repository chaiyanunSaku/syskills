
# compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra

# dir
SRC_DIR = src
RELEASE_DIR = release
DIST_DIR = dist
INCLUDE_DIR = include

# end files
TARGET = $(RELEASE_DIR)/makeproject
ZIPFILE = $(DIST_DIR)/makeproject.zip

# object files
OBJS = main.o helper.o

# default rule
all: clean $(TARGET) zip cleanobj

# link the executable from object files
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)


# compile each
main.o: $(SRC_DIR)/main.c $(INCLUDE_DIR)/helper.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/main.c -o main.o

helper.o: $(SRC_DIR)/helper.c $(INCLUDE_DIR)/helper.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRC_DIR)/helper.c -o helper.o


# create zip that contains src/, /include, and Makefile
zip:
	mkdir -p $(DIST_DIR)
	zip -r $(ZIPFILE) $(SRC_DIR) $(INCLUDE_DIR) Makefile

# janitor rules
clean:
	rm -f $(OBJS) $(TARGET)

cleanobj:
	rm -f $(OBJS)

.PHONY: all clean cleanobj zip