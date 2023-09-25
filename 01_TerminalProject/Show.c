#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define DX 3

int main(int argc, char *argv[]) {
    WINDOW *win;
    FILE *fd;
    char *line;
    int c, n = 0;
    size_t len = 0;
    ssize_t read;

    if (argc < 2) {
        printf("Usage:  ./Show filename\n");
        exit(1);
    }
    
    fd = fopen(argv[1], "r");

    initscr();
    noecho();
    cbreak();
    mvprintw(0, 0, "Filename: %s", argv[1]);
    refresh();
    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok(win, TRUE);
    box(win, 0, 0);

    int i;

    for (i=0; i < LINES-2*DX - 3; i++) {
        if (read = getline(&line, &len, fd) != -1) {
            mvwprintw(win, i+1, 0, "%4d: %s\n", i+n+1, line);
        }
    }
    box(win, 0, 0); 
    wrefresh(win);

    while((c = wgetch(win)) != 27) {
        switch(c) {
        case ' ':
            if (read = getline(&line, &len, fd) != -1) {
                mvwprintw(win, i+1, 0, "%4d: %s\n", i+n+1, line);
                n += 1;
            }
            break;
        }
        
        box(win, 0, 0); 
        wrefresh(win);        
    };

    endwin();
    fclose(fd);
}
