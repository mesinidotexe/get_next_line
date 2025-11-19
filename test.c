#include "stdlib.h"
#include "unistd.h"

size_t	line_chr(const char *s, int nl)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

int main()
{
	char test[] = "";
	if (line_chr(test, '\n'))
		write(1, "tem linha\n", 11);
	return 0;
}
