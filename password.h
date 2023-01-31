#include <termios.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

void get_password(char *password)
{
    static struct termios old_terminal;
    static struct termios new_terminal;

    //get settings of the actual terminal
    tcgetattr(STDIN_FILENO, &old_terminal);

    // do not echo the characters
    new_terminal = old_terminal;
    new_terminal.c_lflag &= ~(ECHO);

    // set this as the new terminal options
    tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);

    // get the password
    // the user can add chars and delete if he puts it wrong
    // the input process is done when he hits the enter
    // the \n is stored, we replace it with \0
    if (fgets(password, BUFSIZ, stdin) == NULL)
        password[0] = '\0';
    else
        password[strlen(password)-1] = '\0';

    // go back to the old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}
