#include <stdio.h>
#include <libintl.h>
#include <stdlib.h>
#include <libgen.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include "config.h"


#define _(STRING) gettext(STRING)

int main(int argc, char* argv[]) {
    char *dir;

    dir = dirname(realpath(argv[0], NULL));

    bindtextdomain(GETTEXT_PACKAGE, LOCALE_PATH);
    textdomain(GETTEXT_PACKAGE);
    setlocale(LC_ALL, "");

    int min = 0, max = 100, avg;

    printf(_("Guess a number from 0 to 100\n"));

    char answer[10];
    while (min <= max) {
        avg = floor((min + max) / 2);
        printf(_("Is your number greater than %d? [yes/no]\n"), avg);
        int res = scanf("%s", answer);
        if (res == EOF) return 0;

        if (!strcasecmp(answer, _("yes"))) {
            min = avg + 1;
        } else if (!strcasecmp(answer, _("no"))) {
            max = avg - 1;
        } else {
            printf(_("Please enter only 'yes' or 'no'\n"));
        }
    }

    printf(_("Your number is %d\n"), min);

    return 0;
}
