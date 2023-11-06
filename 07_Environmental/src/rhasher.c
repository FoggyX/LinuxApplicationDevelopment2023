#include <rhash.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include "config.h"

#ifdef READLINE

#include <readline/readline.h>
#include <readline/history.h>

#endif

int main(int argc, char* argv[]) {
	char *line;
	size_t len = 0;

	rhash_library_init();
#ifdef READLINE
	while ((line = readline(NULL))) {
#else
	while (getline(&line, &len, stdin) != -1) {
#endif
		char *hash_str = strtok(line, " ");
		char *what = strtok(NULL, " \n");
		if (what == NULL) {
			fprintf(stderr, "Enter hash type and data\n");
			continue;
		}

		int encoding = isupper(hash_str[0]) ? RHPR_HEX : RHPR_BASE64;
		
		int hash;
        if (!strcasecmp(hash_str, "md5")) {
        	hash = RHASH_MD5;
        } else if (!strcasecmp(hash_str, "sha1")) {
        	hash = RHASH_SHA1;
        } else if (!strcasecmp(hash_str, "tth")) {
        	hash = RHASH_TTH;
        } else {
        	fprintf(stderr, "Unknown hash type\n");
        	continue;
        }

        char digest[64];
        char output[256];
        int res;

        if (what[0] == '"') {
        	res = rhash_msg(hash, what + 1, strlen(what) - 1, digest);
        } else {
        	res = rhash_file(hash, what, digest);
        }
        if (res < 0) {
        	fprintf(stderr, "LibRHash error: %s: %s\n", what, strerror(errno));
        	continue;
        }

        rhash_print_bytes(output, digest, rhash_get_digest_size(hash), encoding);
        printf("%s\n", output);
    }

    return 0;
}
