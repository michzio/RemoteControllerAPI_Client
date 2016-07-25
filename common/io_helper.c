//
// Created by Michal Ziobro on 25/07/2016.
//

#include <stdlib.h>
#include <stdio.h>
#include "io_helper.h"

/**
 * function from stackoverflow (modified)
 * link: http://stackoverflow.com/questions/314401/how-to-read-a-line-from-the-console-in-c
 */
char * read_line(void) {
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stdin);
        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

        if((*line++ = c) == '\n')
            break;
    }

    *(--line) = '\0';

    return linep;
}