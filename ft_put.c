#include "ft_printf.h"

int ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int ft_putstr(char *str, int fd)
{
	int len;
	if (!str)
		return (write(fd, "(null)", 6));      /* This function prints a chain of characters*/
	len = ft_strlen(str);
	write (1, str, len);
	return (len);
}

int ft_putnbr(int nb, size_t len, int fd, int type)
{
	int i;
	i = 0;

	if (nb == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (nb < 0)
	{
		i += ft_putchar('-', 1);
		nb = -nb;
	}
	return (i + ft_putnbr(nb, len, fd, type));
}

int ft_putunbr(size_t nb, size_t len, int fd, int type)
{
	static int i;
	char base[17];
	i = 0;
	
	if (len == 16) /*caso len esteja na base 16, usado para %x ou %X*/
	{
		if (type == 1)
			ft_strcpy(base, "0123456789abcdef", 16);
		else
			
			ft_strcpy(base, "0123456789ABCDEF", 16);
	}
	else
		ft_strcpy(base, "0123456789", 10); /*Caso esteja na base 10, usado para %d, %i, e %u*/
	if (nb < len)
		i += ft_putchar(base[nb], 1);
	else
	{
		ft_putunbr(nb / len, len, fd, type);
		nb = nb % len;
		i += ft_putchar(base[nb], 1);
	}
	return (i);	
}

int	ft_putaddr(unsigned long addr, int fd)
{
	if (!addr)
		return (write(fd, "0x0", 3));
	return (write(fd, "0x", 2) + ft_putunbr(addr, 16, fd, 1));
}
