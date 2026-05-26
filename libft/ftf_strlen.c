size_t strlen(const char *s)
{
	sizet_t	i;

	while(*s)
	{
		i++;
		s++;
	}
	return (i);
}