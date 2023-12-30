#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nb;
    char c;
    char str[7];
    void *p;
    short sh;
} Things;

int main (void)
{
    int i;
    Things *one_thing = malloc(sizeof(Things));
    bzero((void *) one_thing, sizeof(Things));
    one_thing->nb = 5;
    one_thing->c = 'a';
    one_thing->str[0] = '0';
    one_thing->p = &i;
    one_thing->sh = 256;
    printf("the size of the whole struct is %llu bytes\n", sizeof(Things));
    unsigned char data;
    for (int i = 0; i < sizeof(Things); i++)
    {
        if (i % 8 == 0 && i != 0)
            printf("\n");
        data = *(((unsigned char *)one_thing) + i);
        printf("%02x", data);
    }
    return (0);
}