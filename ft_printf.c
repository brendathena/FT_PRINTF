#include "ft_printf.h"

/* This function will verify which function was used and use the right function to the return the amount of printed characters */

int ft_printf_arg(const char *fmt, int i, va_list ap)
{
	if (fmt[i + 1] == 37) /* 37 = % */
		return (ft_putchar(fmt[i + 1], 1));
	else if (fmt[i + 1] == 99) /* 99 = c */
		return (ft_putchar(va_arg(ap, int), 1));
	else if (fmt[i + 1] == 115) /* 115 = s */
		return (ft_putstr(va_arg(ap, char *), 1));
	else if (fmt[i + 1] == 100 || fmt[i + 1] == 105) /* 100 = d || 105 = i*/
		return (ft_putnbr(va_arg(ap, int), 10, 1, 1));
	else if (fmt[i + 1] == 117) /* 117 = u */
		return (ft_putunbr(va_arg(ap, unsigned int), 10, 1, 1));
	else if (fmt[i + 1] == 120) /* 120 = x */
		return (ft_putunbr(va_arg(ap, unsigned int), 16, 1, 1));
	else if (fmt[i + 1] == 88) /* 88 = X */
		return (ft_putunbr(va_arg(ap, unsigned int), 16, 1, 0));
	else if (fmt[i + 1] == 112) /* 112 = p */
		return (ft_putaddr(va_arg(ap, unsigned long), 1));
	return (1);
}

int ft_printf(const char *fmt, ...)
{
	va_list ap;
	int i;
	int ret;
	i = 0;
	ret = 0;
	va_start(ap, fmt);
	
	while (fmt[i])
	{
		if (fmt[i] == 37 && ft_strchr("cspdiuxX%", fmt[i + 1]))
		{
			/*Checks if % exists and if it's part of a printf flag (strchr).*/
			ret += ft_printf_arg(fmt, i, ap);
			i++;
		}
		else
			ret += ft_putchar(fmt[i], 1);
			/*ret controls how many characters were printed, if no % were found,
			putchar will print the character and add it to ret.*/
		i++;
	}
	va_end(ap);
	return (ret);
}
