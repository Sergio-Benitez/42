/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring_inacabado.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenitez <sbenitez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:41:14 by sbenitez          #+#    #+#             */
/*   Updated: 2024/09/01 19:41:33 by sbenitez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void    printstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        if (str[0] == ' ' || str[0] == '\t')
            i++;
        while ((str[i] == ' ' || str[i] == '\t') && (str[i + 1] == ' ' || str[i + 1] == '\t'))
            i++;
        write(1, &str[i], 1);
        i++;
    }
}

void    rostring(char *str)
{
    int        i = 0;
    int        j = 0;
    int        k = 0;
    char    *first;
    
    while (str[i] && (str[i] == ' ' || str[i] == '\t'))
        i++;
    if (str[i])
    {
        while (str[i] && (str[i] != ' ' && str[i] != '\t'))
        {
            k++;
            i++;
        }
    }

    first = (char *)malloc((k + 1) * sizeof(char));
    while (j < k)
    {
        first[j] = str[i - k + j];
        j++;
    }
    first[j] = '\0';
    
    printstr(&str[i + 1]);
    write( 1, " ", 1);
    printstr(first);
}
int    main(int argc, char **argv)
{
    rostring(argv[1]);
    write(1, "\n", 1);
    return (0);
}