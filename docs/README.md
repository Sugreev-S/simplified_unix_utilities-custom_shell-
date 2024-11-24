Here’s an updated, more descriptive version of your `README.md` file without the examples:

---

# Simplified UNIX-like Utilities

This project is a simplified implementation of common UNIX-like utilities in C. It provides a custom shell that supports a set of commands often used in UNIX systems, such as `ls`, `cat`, `grep`, `wc`, `cp`, `mv`, `rm`, along with additional functionality like changing directories, printing the current directory, and basic piping of commands. The project is designed to offer a learning platform for understanding how these utilities work at a low level, implemented with minimal external dependencies.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Commands](#commands)

## Introduction

This project aims to create a basic UNIX-like shell and a set of common file manipulation utilities. It simulates the behavior of several traditional UNIX commands, allowing users to interact with the file system and execute basic operations like listing directory contents, manipulating files, and searching text. The shell supports piping commands together, enabling simple workflows that are typical in UNIX environments.

### Purpose

The goal of this project is to create a simplified shell environment where users can:
1. List files and directories.
2. View the contents of files.
3. Search for specific text patterns within files.
4. Count lines, words, and characters in files.
5. Copy, move, and remove files.
6. Change directories and print the working directory.
7. Use basic shell features like piping and echoing commands.

## Features

The project includes a set of core features designed to replicate traditional UNIX utilities with a minimalistic approach:

### **File System Commands**
- **custom_ls**: List the contents of a directory, similar to the `ls` command in UNIX.
- **custom_cat**: Display the contents of a file, akin to `cat`.
- **custom_grep**: Search for a pattern or regular expression within a file or input stream.
- **custom_wc**: Count the number of lines, words, and characters in a file.
- **custom_cp**: Copy files or directories from one location to another, similar to `cp`.
- **custom_mv**: Move or rename files or directories, functioning like `mv`.
- **custom_rm**: Remove files or directories, just like `rm`.

### **Shell Management**
- **custom_pipe**: Pipe the output of one command into another, mimicking the pipe functionality (`|`) of UNIX shells.
- **custom_cd**: Change the current working directory (`cd`).
- **custom_pwd**: Print the current working directory (`pwd`).
- **custom_echo**: Print a string to the console, similar to `echo`.
- **custom_whoami**: Display the username of the current user, just like the `whoami` command.

### **Command Shortcuts**
To streamline the user experience, commands can also be invoked with shortened names, such as:
- `c_ls` for `custom_ls`
- `c_cat` for `custom_cat`
- `c_grep` for `custom_grep`
- `c_wc` for `custom_wc`
- `c_cp` for `custom_cp`
- `c_mv` for `custom_mv`
- `c_rm` for `custom_rm`
- `c_cd` for `custom_cd`
- `c_pwd` for `custom_pwd`
- `c_echo` for `custom_echo`
- `c_whoami` for `custom_whoami`

This ensures that users can type commands faster and in a more efficient manner without needing to type the full command name.

## Installation

To get started with the project, follow these installation steps:

### Step 1: Clone the Repository

You can clone the repository from GitHub using the following command:

```bash
git clone https://github.com/yourusername/simplified_unix_utilities.git
cd simplified_unix_utilities
```

### Step 2: Build the Project

This project uses `make` to handle the compilation process. Ensure that you have `gcc` (GNU Compiler Collection) and `make` installed on your machine. If they are not installed, please install them via your package manager (e.g., `apt` on Ubuntu, `brew` on macOS).

To build the project, run the following command:

```bash
make
```

This will compile the source files and generate the `main` executable in the `bin` directory.

Also if you want to make changes in any of the src file make sure you run `make clean` to remove to previous files in bin and again use `make` to handle compilation process.

```bash
make clean
```
```bash
make
```

### Step 3: Run the Custom Shell

Once the project is built, you can run the custom shell by executing the following command:

```bash
./bin/main
```

This will launch the custom shell, and you can start using the available commands directly from the prompt.

## Usage

Once inside the custom shell, you can start typing any of the available commands listed below. The shell will process the input and perform the associated action, providing you with output or feedback where applicable.

You can exit the shell at any time by typing `exit`:

```bash
exit
```

## Commands

The following commands are available in the custom shell:

- **custom_ls**: Lists the contents of a directory.
  - Usage: `custom_ls [directory]`
  - If no directory is specified, the current directory is used by default.

- **custom_cat**: Displays the contents of a file.
  - Usage: `custom_cat <filename>`
  - This command prints the file content to the terminal.

- **custom_grep**: Searches for a pattern in a file.
  - Usage: `custom_grep <pattern> <filename>`
  - This command searches the given file for the specified pattern and prints matching lines.

- **custom_wc**: Counts the lines, words, and characters in a file.
  - Usage: `custom_wc <filename>`
  - This command provides a summary of line count, word count, and character count in the file.

- **custom_cp**: Copies a file to a new location.
  - Usage: `custom_cp <source> <destination>`
  - This command copies the specified file to the target location.

- **custom_mv**: Moves a file to a new location.
  - Usage: `custom_mv <source> <destination>`
  - This command moves the file from the source path to the destination path.

- **custom_rm**: Removes a file.
  - Usage: `custom_rm <filename>`
  - This command deletes the specified file from the system.

- **custom_pipe**: Pipes the output of one command into another.
  - Usage: `custom_pipe <command1> | <command2>`
  - This allows you to execute two commands, where the output of the first is passed as input to the second.

- **custom_cd**: Changes the current directory.
  - Usage: `custom_cd <directory>`
  - This command changes the working directory to the specified path.

- **custom_pwd**: Prints the current working directory.
  - Usage: `custom_pwd`
  - This command shows the full path of the current working directory.

- **custom_echo**: Prints a string to the console.
  - Usage: `custom_echo <string>`
  - This command prints the specified string to the terminal.

- **custom_whoami**: Displays the current user.
  - Usage: `custom_whoami`
  - This command shows the current logged-in user's name.
