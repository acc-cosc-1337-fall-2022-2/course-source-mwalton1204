//add include statements
#include "func.h"

//Function to get GC Content
double get_gc_content(const string& dna)
{
    double gc_content = 0;

    for(int i = 0; i < dna.length(); i++)
    {
        if(dna[i] == 'C' || dna[i] == 'G')
        {
            gc_content++;
        }
    }

    return gc_content / dna.length();
}

//Function to get DNA Complement
string get_dna_complement(string dna)
{
    string complement;

    for(int i = 0; i < dna.length(); i++)
    {
        if(dna[i] == 'A'){complement += 'T';}
        else if(dna[i] == 'T'){complement += 'A';}
        else if(dna[i] == 'C'){complement += 'G';}
        else if(dna[i] == 'G'){complement += 'C';}
    }

    complement = get_reverse_string(complement);
    return complement;
}

//Function to reverse strings
string get_reverse_string(string dna)
{
    string reverse;

    for(int i = dna.length() - 1; i >= 0; i--)
    {
        reverse += dna[i];
    }

    return reverse;
}