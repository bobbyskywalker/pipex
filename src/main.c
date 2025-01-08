#include "../inc/pipex.h"
#include <fcntl.h>
#include <unistd.h>

bool    check_here_doc(char *arg)
{
    if (!ft_strncmp("here_doc", arg, 8))
        return (true);
    return (false);
}

void    handle_here_doc(char *limiter)
{
    char    *line;
    int     fd_tmp;

    fd_tmp = open("tmp_file", O_RDWR | O_CREAT | O_TRUNC, 0777);
    while (1)
	{
		line = get_next_line(0);
		if (!line || !ft_strncmp(line, limiter, ft_strlen(line) - 1))
			break ;
		write(fd_tmp, line, ft_strlen(line));
		free(line);
	}
	close(fd_tmp);
}

int main(int argc, char **argv, char **envp)
{
    int fd_in;
    int fd_out;
    int i;
    bool is_here_doc;

    is_here_doc = check_here_doc(argv[1]);
    if (argc < 5)
    {
        errno = EINVAL;
        perror("valid exec: ./pipex infile cmd cmd outfile");
        return (1);
    }
    if (is_here_doc)
    {
        handle_here_doc(argv[2]);
        fd_in = open("tmp_file", O_RDONLY, 0777);
    }
    else
        fd_in = open(argv[1], O_RDONLY, 0777);
    fd_out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_in == -1 || fd_out == -1)
    {
        errno = EBADF;
        close(fd_in);
        close(fd_out);
        perror("pipex");
        exit(EXIT_FAILURE);
    }
    dup2(fd_in, STDIN_FILENO);
    close(fd_in);
    if (!is_here_doc)
        i = 2;
    else
        i = 3;
    while (i < argc - 2)
        exec_process(argv[i++], envp);
    if (is_here_doc)
        unlink("tmp_file");
    dup2(fd_out, STDOUT_FILENO);
    exec_command(argv[argc - 2], envp);
    return (0);
}
