#include "libft.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	char		line[70000];
	static int	buffer_read;
	static int 	buffer_pos;
	int			i;

	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break ;
		}
		if (buffer[buffer_pos] == '\n')
        {
            line[i++] = '\n';
            buffer_pos++;
			break ;
        }
		line[i] = buffer[buffer_pos++];
		i++;
	}
    line[i] = 0;
	if (i == 0)
		return (NULL);
	return (ft_strdup(line));
}
