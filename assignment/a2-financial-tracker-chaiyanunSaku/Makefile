
CC = gcc
CFLAGS = -Iinclude -Wall -Wextra  # Iinclude is to add include too

SRC_DIR = src
INCLUDE_DIR = include
RELEASE_DIR = release
DIST_DIR = dist
LOG_FILE = logs/transaction_log.txt
REPORT_DIR = report

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)  # wildcard find all .c in src/
OBJ_FILES = $(SRC_FILES:.c=.o)          # change .c to .o
EXECUTABLE = $(RELEASE_DIR)/fintrack

all: clean $(EXECUTABLE) dist  # make will do clean, compile, and zip

$(EXECUTABLE): $(OBJ_FILES)
	mkdir -p $(RELEASE_DIR)               # makedir if doesnt have already
	$(CC) $(OBJ_FILES) -o $(EXECUTABLE)  #compile
	rm -f $(OBJ_FILES)                    # delete .o

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c       # all .c to .o. 
	$(CC) $(CFLAGS) -c $< -o $@      # $< is input $@ is output

clean:
	rm -f $(SRC_DIR)/*.o
	rm -f $(EXECUTABLE)

dist:
	mkdir -p $(DIST_DIR)
	zip -r $(DIST_DIR)/fintrack.zip $(SRC_DIR) $(INCLUDE_DIR) $(LOG_FILE) $(REPORT_DIR) Makefile
