/**
*_print_adresse - print the adresse
*@p: the address memory
*Return: printed char
*/
int _print_adresse(void *p)
{
        int c = 0;
        unsigned long int i = (unsigned long int) p;

        if (p == NULL)
        {
                write(1, "(nil)", 5);
                return (5);
        }
        c += write(1, "0x", 2);
        c += _num_char(i, 'x', 0);

        return (c);
}

