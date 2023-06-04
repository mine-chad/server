/*
 * Copyright (C) 2023 mine-chad
 * This file is part of the Mine-chad project.
 *
 * Mine-chad is free software: you can redistribute it and/or modify it under
 * the terms of the MIT License.
 *
 * Mine-chad is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the MIT License for more details.
 *
 * You should have received a copy of the MIT License along with Mine-chad. If
 * not, see <https://mit-license.org/> or contact the Massachusetts Institute
 * of Technology (MIT) at <tlo-inquiries@mit.edu>.
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <ctype.h>

#include "info.h"

void term_handler(int signum) {
    if(signum == SIGTERM || signum == SIGINT) {
        char yesno;
        printf("Are you really sure that you want to quit? [Y(es)/n(o)]: ");

        while(1) {
            /* Get the first character and convert it to lowercase */
            yesno = tolower(getchar());

            if(yesno = tolower(yesno) == 'y') {
                printf("Quiting...\n");
                exit(EXIT_SUCCESS);
            }
            else if (yesno == 'n')
                break;
            else {
                printf("Invalid choice! Please retry [Y(es)/n(o)]: ");

                /* Clear the input buffer */
                char c;
                while(c = getchar() != '\n' && c != EOF)
                    continue;

                /* Retry choice */
                continue;
            }
        }
    }

    /* Clear the input buffer */
    char c;
    while(c = getchar() != '\n' && c != EOF)
        continue;

    return;
}
