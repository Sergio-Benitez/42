/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 17:50:48 by sbenitez          #+#    #+#             */
/*   Updated: 2024/04/19 18:54:42 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>
int	main(void)
{
// FT_ISALPHA

	int	a;
	int b;
	
	a = 'a';
	b = '8';

	printf("\n- ft_isalpha: Muestra 1 si el parámetro es alfabético y 0 si no lo es.\n\n\t%c = %d\n\t%c = %d\n\n", (char)a, ft_isalpha(a), (char)b, ft_isalpha(b));

// FT_ISDIGIT

	printf("\n- ft_isdigit: Muestra 1 si el parámetro es numérico y 0 si no lo es.\n\n\t%c = %d\n\t%c = %d\n\n", (char)a, ft_isdigit(a), b, (char)ft_isdigit(b));

// FT_ISALNUM

	int	c;
	
	c = '?';
	printf("\n- ft_isalnum: Muestra 1 si el parámetro es alfanumérico y 0 si no lo es.\n\n\t%c = %d\n\t%c = %d\n\t%c = %d\n\n", (char)a, ft_isalnum(a), (char)b, ft_isalnum(b), (char)c, ft_isalnum(c));

// FT_ISASCII

	int	d;
	
	d = 0xFC;
	printf("\n- ft_isascii: Muestra 1 si el parámetro es ASCII y 0 si no lo es.\n\n\t%c = %d\n\t%c = %d\n\n", (char)c, ft_isascii(c), (char)d, ft_isascii(d));

// FT_ISPRINT

	printf("\n- ft_isprint: Muestra 1 si el parámetro es imprimible y 0 si no lo es.\n\n\t%c = %d\n\t%c = %d\n\n", (char)c, ft_isascii(c), (char)d, ft_isascii(d));

// FT_STRLEN

	const char	str1[] = "Panderetas turbodinosáuricas"; 

	printf("\n- ft_strlen: Muestra la longitud de un string.\n\n\tEl string '%s' tiene una longitud de %zu.\n\n", str1, ft_strlen(str1));

// FT_MEMSET

	int f;
	size_t len;
	
	f = '6';
	len = 5;

	printf("\n- ft_memset: Escribe len (%zu) bytes del valor %c en el string '%s'.\n\n\t", len, (char)f, str1);
	ft_memset((void *)str1, f, len);
	printf("%s\n\n", str1);
	
// FT_BZERO
	
	printf("\n- ft_bzero: Escribe n (%zu) ceros en el string '%s'.\n\n\t", len, str1);
	ft_bzero((void *)str1, len);
	printf("El string '%s' no se muestra debido a que empieza por nulo.\n\n", str1);
	
// FT_MEMCPY

	char	src[] = "Source";
	char	dst[] = "Destination";
	
	printf("\n- ft_memcpy: Copia n (%zu) bytes desde el área de memoria src ('%s') al área de memoria dst ('%s')\n\n\t", len, src, dst);
	ft_memcpy((void *)dst, (const void *)src, len);
	printf("%s\n\n", dst);
	
// FT_MEMMOVE

	char	dst2[] = "Malacatones";
	
	printf("\n- ft_memmove: Copia len (%zu) bytes desde la cadena src ('%s') a la cadena dst ('%s')\n\n\t", len, src, dst2);
	ft_memmove((void *)dst2, (const void*)src, len);
	printf("%s\n\n", dst2);

// FT_STRLCPY

	char	dst3[] = "Asfaltadora cuántica";
	printf("\n- ft_strlcpy: Copia un string src ('%s') en un dstsize ('%zu') máximo en un string dst ('%s') y garantiza su terminación en nulo.\n\n\t", src, len, dst3);
	ft_strlcpy((char *)dst3, (const char *)src, len);
	printf("%s\n\n", dst3);

// FT_STRLCAT

	char	dst4[] = "Khe";
	printf("\n- ft_strlcat: Concatena src ('%s') al final de dst ('%s'), limitado por dstsize ('%zu'), y asegura que dst esté correctamente terminado con un carácter nulo.\n\n\t", src, dst4, len);
	ft_strlcat((char *)dst4, (const char *)src, len);
	printf("%s\n\n", dst4);

// FT_TOUPPER

	int g;

	g = 'e';
	printf("\n- ft_toupper: Convierte el argumento en mayúscula si es una letra minúscula\n\n\t%c = %c\n", (char)g, (char)ft_toupper(g));
	
// FT_TOLOWER

	int	h;

	h = 'U';
	printf("\n- ft_tolower: Convierte el argumento en minúscula si es una letra mayúscula\n\n\t%c = %c\n", (char)h, (char)ft_tolower(h));

// FT_STRCHR
	printf("testing strchr\n");
	char	src2[] = "Source";
	int j;
	j = 'r';
	char	*result = strchr((const char *)src2, 't' + 256);
	printf("%s\n", result);
	/*printf("\n- ft_strchr: Localiza la primera aparición de c ('%c') en el string apuntado por s ('%s')\n\n\t", j, src2);
	if (result != NULL)
		printf("El caracter '%c' se encontró en la posición: %ld\n", j, result - src2);
	else
		printf("El caracter '%c' no se encontró en la cadena.\n", j);*/

	
		
// FT_STRRCHR

	char	*result2 = ft_strrchr((const char*)src2, j);
	
	printf("\n- ft_strrchr: Localiza la última aparición de c ('%c') en el string apuntado por s ('%s')\n\n\t", j, src2);
	if (result2 != NULL)
		printf("El caracter '%c' se encontró en la posición: %ld\n", j, result2 - src2);
	else
		printf("El caracter '%c' no se encontró en la cadena.\n", j);

// FT_STRNCMP

	const char *str4 = "Hello";
    const char *str5 = "Hell";

    int result3 = ft_strncmp(str4, str5, len);

	printf("\n- ft_strncmp: Compara dos strings ('%s' y '%s') no más de 'n' (%zu) caracteres.\n\n\t", str4, str5, len);
    if (result3 == 0)
        printf("Las primeras 4 letras de '%s' y '%s' son iguales.\n", str4, str5);
    else if (result3 < 0)
        printf("Las primeras 4 letras de '%s' son menores que las de '%s'.\n", str4, str5);
    else
        printf("Las primeras 4 letras de '%s' son mayores que las de '%s'.\n", str4, str5);
		
// FT_MEMCHR

	int	i = 'c';
	char	str6[] = "Cocoloco";
	char	*ptr = ft_memchr((const void *)str6, i, len);

	printf("\n- ft_memchr: Localiza la primera ocurrencia de 'c' (%c) en los primeros 'n' (%zu) bytes del string 's' ('%s')\n\n\t", (char)i, len, str6);
	if (ptr != NULL)
        printf("El caracter '%c' se encontró en la posición: %ld\n", i, ptr - str6);
    else
        printf("El caracter '%c' no se encontró en la cadena.\n", i);

// FT_MEMCMP

	int result4 = ft_memcmp((const void*)str4, (const void*)str5, len);
	
	printf("\n- ft_memcmp: Compara los primeros 'n' (%zu) bytes de dos regiones de memoria apuntadas por 's1' ('%s') y 's2' )'%s'.\n\n\t", len, str4, str5);
	if (result4 == 0)
        printf("Los primeros %zu bytes de '%s' y '%s' son iguales.\n", len, str4, str5);
    else if (result4 < 0)
        printf("Los primeros %zu bytes de '%s' son menores que los de '%s'.\n", len, str4, str5);
    else
        printf("Los primeros %zu bytes de '%s' son mayores que los de '%s'.\n", len, str4, str5);

// FT_STRNSTR

	char	needle[] = "esta";
	char	haystack[] = "Búscame esta, crack";
	char	*result5 = ft_strnstr((const char *)haystack, (const char *)needle, ft_strlen(haystack));
	
	printf("\n- ft_strnstr: La función strnstr busca la primera ocurrencia de la cadena 'needle' ('%s') dentro de la cadena 'haystack' ('%s'), con un límite de búsqueda dado por 'len' (%zu).\n\n\t", needle, haystack, ft_strlen(haystack));
	if (result5 != NULL)
        printf("La cadena '%s' fue encontrada en la posición: %ld\n", needle, result5 - haystack);
    else
        printf("La cadena '%s' no fue encontrada en '%s'.\n", needle, haystack);

// FT_ATOI

	const char *str7 = "   -8173";
	
	printf("\n- ft_atoi: Convierte una cadena de caracteres 'str' ('%s') que representa un número en formato de texto en un valor entero de tipo int.\n\n\tEl resultado de convertir la cadena '%s' a entero es: %d\n", str7, str7, ft_atoi(str7));

// FT_CALLOC
// FT_STRDUP
// FT_SUBSTR

// FT_STRJOIN

	const char	*str8[] = "Eficiencia ";
	const char	*str9[] = "demostrada.";
	printf(("\n- ft_strjoin: Reserva espacio con malloc y devuelve un string formado por la concatenación de s1 ('%s') y s2 ('%s).\n\n\t%s", str8, str9, ft_strjoin(str8, str9)));
	
	return (0);
}