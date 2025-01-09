
# pipex

## Description 📄

**Pipex** is a low-level Unix command-line program that simulates the functionality of piping (`|`) in a shell. The project uses `fork`, and `pipe` syscalls to manage processes and communication between them. It's a perfect project for understanding process management, inter-process communication, and system calls in Unix-based systems.

## 🛠️ Features
- 🚀 **Multiple Commands:** Supports multiple commands piped together (UNIX e.g., `cmd1 | cmd2 | cmd3`).
- ✍️ **Multiple Lines Redirection as Input (Heredoc)**: Supports heredoc syntax for providing multi-line input directly in the command line, enabling users to input blocks of text efficiently without the need for external files.
- 🔄 **Pipes Management:** Effectively handles the creation and usage of pipes for data flow.
- ⚡ **Forking and Executing:** Utilizes `fork` to spawn new processes for each command.
- 🔐 **Error Handling:** Manages errors, such as invalid commands, invalid file descriptors or incorrect pipe usage.

## ⚙️ How It Works

**Initialization:**
- Parse arguments (commands & file descriptors) passed to the program along with checking their existence and/or permissions.
- Create necessary pipes to handle inter-process communication.
   
**Process Forking:**
   - For each command, create a new child process.
   - Connect pipes for output/input redirection between processes.
   
**Execution:**
   - Use `execve` to run the commands within their respective processes.

## Usage 🖥️

Clone the repository:

```bash
git clone https://github.com/bobbyskywalker/pipex
```
Create the executable:
```bash
make
```
Run the program:
```bash
./pipex input_file "cmd1" "cmd2" "cmd3" ... "cmdn" output_file

# which should work as the bash command:
./pipex < input_file cmd1 | cmd2 | cmd3 ... | cmdn > output_file
```
You can also run pipex with heredoc:
```bash
./pipex here_doc LIMITER "cmd1" "cmd2" ... "cmdn" file

# which should work as the bash command:
cmd1 << LIMITER | cmd2 | cmd3 | ... | cmdn > output_file

```

## 📌 Notes

- **Bugs?** If you encounter any bugs, don't hesitate to submit a pull request! Contributions are always welcome. ✨

- **For 42 Students:** 📢 This repository is meant as a guide at most. **Don't cheat, learn!** <3 

- **Created in January 2025** as part of 42's Common Core at **42 Warsaw**🌍
