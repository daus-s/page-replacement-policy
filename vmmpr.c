#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INPUT 80

short pages[] = {-1,-1,-1,-1};

void reset_pages()
{
    pages[0] = -1;
    pages[1] = -1;
    pages[2] = -1;
    pages[3] = -1;
}

//return the index of the largest value of an int array
int max(short* arr)
{
    if (arr[0]>=arr[1]&&arr[0]>=arr[2]&&arr[0]>=arr[3])
    {
        return 0;
    }
    if (arr[1]>=arr[0]&&arr[1]>=arr[2]&&arr[1]>=arr[3])
    {
        return 1;
    }
    if (arr[2]>=arr[1]&&arr[2]>=arr[0]&&arr[2]>=arr[3])
    {
        return 2;
    }
    if (arr[3]>=arr[1]&&arr[3]>=arr[2]&&arr[3]>=arr[0])
    {
        return 3;
    }
    return -1;
}


int fifo(short* array)
{
    int replacements = 0;
    int count = sizeof(&array)/sizeof(short);

    for (size_t i = 0; i < count; ++i)
    {
        //check if page is already there, if it is not perform the swap
        if (pages[0]!=array[i] && pages[1]!=array[i] && pages[2]!=array[i] && pages[3]!=array[i])
        {
            //perform swap
            pages[3] = pages[2];
            pages[2] = pages[1];
            pages[1] = pages[0];
            pages[0] = array[i];

            //increment replacements
            replacements++;
        }
    }
    reset_pages();
    return replacements;
}

int lru(short* array)
{
    int replacements = 0;
    int count = sizeof(&array)/sizeof(short);

    short pages_count[4];

    for (size_t i = 0; i < count; ++i)
    {
        //check if page is already there, if it is not perform the swap
        if (pages[0]!=array[i] && pages[1]!=array[i] && pages[2]!=array[i] && pages[3]!=array[i])
        {
            //perform swap
            int itr = max(pages_count); //index to replace(itr)
            pages[itr] = array[i];
            pages_count[itr] = 0;

            //increment the counts for each time
            pages_count[0] = pages_count[0]+1;
            pages_count[1] = pages_count[1]+1;
            pages_count[2] = pages_count[2]+1;
            pages_count[3] = pages_count[3]+1;

            //increment replacements
            replacements++;
        }
    }

    reset_pages();
    return replacements;
}

// int opt(short* array)
// {
//
// }

int main(int argc, char **argv)
{
    //split the argv[1] into an array of int
    short* array;
    array = malloc(INPUT);

    int index = 0;

    char * blah = malloc(1); //because the input value is 0-9 or one char
    blah = strtok(argv[1], ",");
    while (blah) //treating the string as a bool
    {
        short x = atoi(blah);
        array[index++] = x;
        blah = strtok(NULL, ",");
    }
    int fifoR = fifo(array);
    int lruR = lru(array);
    printf("fifo algorithm produced %d page replacements, for a rate of %f%%\n", fifoR, ((float)fifoR/(float)(index)));
    printf("lru algorithm produced %d page replacements, for a rate of %f%%\n", lruR, ((float)lruR/(float)(index)));

    return 0;
}
