#include <stdio.h>
#include <libintl.h>
#include <stdlib.h>
#include <libgen.h>
#include <locale.h>
#include <string.h>
#include <math.h>
#include "config.h"
#include <stdbool.h>

#define _(STRING) gettext(STRING)

char* romans[] = {"N", "I", "II", "III", "IV", "V",
"VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII",
"XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX",
"XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI",
"XXVII", "XXVIII", "XXIX", "XXX", "XXXI", "XXXII",
"XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII",
"XXXIX", "XL", "XLI", "XLII", "XLIII", "XLIV", "XLV",
"XLVI", "XLVII", "XLVIII", "XLIX", "L", "LI", "LII",
"LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX",
"LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII",
"LXIX", "LXX", "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI",
"LXXVII", "LXXVIII", "LXXIX", "LXXX", "LXXXI", "LXXXII", "LXXXIII",
"LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC",
"XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"}; /**< Roman numerals from 0 to 100 */

/** Converts @p i from decimal to Roman numeral system.
 *
 * @param i number in the decimal system
 * @return number in the Roman numeral system
 */
char* fromIntToRomain(int i) {
    return romans[i];
}

/** Converts @p roman from the Roman numeral system to decimal.
 *
 * @param roman number in the Roman numeral system
 * @return number in decimal system
 */
int fromRomaintToInt(char *roman) {
    for (int i = 0; i <= 100; i++) {
        if (strcmp(roman, romans[i])) {
            return i;
        }
    }
}

int main(int argc, char* argv[]) {
    bindtextdomain(GETTEXT_PACKAGE, LOCALE_PATH);
    textdomain(GETTEXT_PACKAGE);
    setlocale(LC_ALL, "");

    if (argc > 1 && !strcmp(argv[1], "--help")) {
        printf(_("Usage: %s [OPTION...]\n\n"), argv[0]);
        printf(_(" -r         use the Roman numeral system\n"));
        printf(_(" --help     give this help list\n"));
        printf(_(" --version  print program version\n"));
        return 0;
    }

    if (argc > 1 && !strcmp(argv[1], "--version")) {
        printf(_("%s %s\n"), argv[0], PACKAGE_VERSION);
        return 0;
    }


    int opt;
    bool roman = false;

    while ((opt = getopt(argc, argv, "r")) != -1) {
        switch (opt) {
            case 'r': {
                roman = true;
                break;
            }
            default: {
                exit(1);
                break;            
            }
        }
    }


    int min = 0, max = 100, avg;

    printf(_("Guess a number from 0 to 100\n"));

    char answer[10];
    while (min <= max) {
        avg = floor((min + max) / 2);
        if (roman) {
            printf(_("Is your number greater than %s? [yes/no]\n"), fromIntToRomain(avg));
        } else {
            printf(_("Is your number greater than %d? [yes/no]\n"), avg);
        }
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

    if (roman) {
        printf(_("Your number is %s\n"), fromIntToRomain(min));
    } else {
        printf(_("Your number is %d\n"), min);
    }

    return 0;
}
