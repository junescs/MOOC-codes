//coding practice from CS50_2018 on edX
//help synthesizing a song "happy birthday" by identify the notes in a format the programme can read

#include <cs50.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    //Store the numerator and denominator
    int X = atoi(&fraction[0]);
    int Y = atoi(&fraction[2]);

    return ((X * 8) / Y);
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    //semitone
    int n = 0;
    int oct;

    //Check length of note and decide the places of accidental and octave
    if (strlen(note) == 3)
    {
        char accidental = note[1];
        oct = atoi(&note[2]);

        if (accidental == '#')
        {
            n += 1;
        }

        else if (accidental == 'b')
        {
            n -= 1;
        }
    }

    else
    {
        oct = atoi(&note[1]);
    }

    char note_name = note[0];

    //Check if it match the standard of music note
    if (note_name < 'A' || note_name > 'G')
    {
        return 1;
    }
    if (oct < 0 || oct > 8)
    {
        return 1;
    }

    //interval check of each note name with "A"4
    if (note_name == 'A')
    {
        n += 0;
    }
    else if (note_name == 'B')
    {
        n += 2;
    }
    else if (note_name == 'C')
    {
        n -= 9;
    }
    else if (note_name == 'D')
    {
        n -= 7;
    }
    else if (note_name == 'E')
    {
        n -= 5;
    }
    else if (note_name == 'F')
    {
        n -= 4;
    }
    else if (note_name == 'G')
    {
        n -= 2;
    }

    //interval of tones
    n += ((oct - 4) * 12);

    //A4 = 440Hz
    float freq = round(pow(2, n / 12.) * 440);

    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    //Check to see whether a blank line
    //"Strcmp" used to compare strings
    //s[0] == "\0" won't work
    if (strcmp(s, "") == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }

}
