#include <stdio.h>
#include <string.h>
#include <unistd.h> 

#include "password.h"

FILE *fin = NULL;
FILE *fout = NULL;

int main(int argc, char **argv)
{
    char password[BUFSIZ];
    char ui;

    fin = stdin;
    fout = stdout;

    int opt = 0;
    int success = 1;
    const char *k = '\0';

    while((opt = getopt(argc, argv, ":i:o:")) != -1)  
    {  
        switch(opt)  
        {  
            case 'i':
                fin = fopen(optarg, "rb");
                success = success && fin;
                break;
            case 'o':  
                fout = fopen(optarg, "wb+");
                break;  
            case ':':  
                printf("option needs a value\n");  
                success = 0;
                break;  
            case '?':  
                printf("unknown option: %c\n", optopt); 
                break;  
        }  
    }

    if (success)
    {
        fprintf(stderr, "Password: ");
        get_password(password);
        fprintf(stderr, "\n");
        k = password;
        while (1)
        {
            ui = getc(fin);
            if (feof(fin))
                break;
            putc(ui ^ *k, fout);
            k = *(k + 1) ? k + 1 : password;
        }
    }

    fclose(fin);
    fclose(fout);

    return 0;
}
