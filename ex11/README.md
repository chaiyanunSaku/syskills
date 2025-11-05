[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/6VyABIhH)
# Simple Makefile Challenge

## Instructions:

1. Clone the starting project from this repository.

2. Files:

   - `main.c`: Contains `main()` that calls a function from `helper.c` to print a message.
   - `helper.c`: Defines a function `print_help_message()` that prints “I’m here to help”.
   - `helper.h`: Declares `print_help_message()`.

3. Create a `Makefile`:

   - Running simple `make` will:
     - Generate an executable file named `makeproject` in the `release/` directory.
     - Generate a single zip file (named `makeproject.zip`) that contains `src/`, `include/`, and the `Makefile` itself. This zip file should be placed inside the `dist/` folder.
     - Remove all object files (`.o`) from any folder once `make` finishes.

4. After running `make`, the final folder structure should look like this:
          
          /
          ├── dist/                     # Zip file will be here
          │   ├── makeproject.zip
          ├── release/                  # Executable here
          │   ├── makeproject
          ├── src/                      # Source files (no .o file)
          │   ├── main.c
          │   ├── helper.c
          ├── include/                  # Header files
          │   └── helper.h
          └── Makefile                  # Your Makefile
