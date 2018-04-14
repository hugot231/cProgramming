// bstring Library Functions

// a bstring is basically a header  which wraps a pointer to a char buffer.
// decleration of the tagbstring already in bstrlib.h
struct tagbstring {
       int mlen;
       int slen;
       unsigned char * data;
};

// The following related typedef is also provided:

typedef const struct tagbstring * const_bstring;
    
// this function takes a c style library '\0'  terminated char buffer and generates the same contents as the char buffer
extern bstring bfromcstr (const char * str); // function 
// example 
bstring b = bfromcstr ("Hello");
    if (!b) {
        fprintf (stderr, "Out of memory");
    } else {
        puts ((char *) b->data);
    }   

//function **********
// memory buffer of string is at least mlen characters in length.  The buffer is also at least size required to hold the string with the '\0' terminator.
extern bstring bfromcstralloc (int mlen, const char * str);
// example 
bstring b = bfromcstralloc (64, "someCstr");
if (b) b->data[63] = 'x';

//function **********
extern bstring bfromcstrrangealloc (int minl, int maxl, const char* str);

// example set the 6th character to "!"
    bstring b = bfromcstrrangealloc (0, 128, "Hello.");
    if (b) b->data[5] = '!';
    
    extern int bcstrfree (char * s);

// function to copy a bstring
extern bstring bstrcpy (const_bstring b1);
// Make a copy of the passed in bstring.  The copied bstring is returned if there is no error, otherwise NULL is returned.

int bcatStatic (bstring b, "...");

/*    Append a string literal to bstring b.  Returns 0 if successful, or BSTR_ERR if some error has occurred.  The string literal parameter is enforced as literal at compile time.
*/

extern char * bstr2cstr (const_bstring s, char z);

/*    Create a '\0' terminated char buffer which contains the contents of the
    bstring s, except that any contained '\0' characters are converted to the
    character in z.  This returned value should be freed with bcstrfree(), by
    the caller.  If an error occurs NULL is returned.
*/

extern int bstrcmp (const_bstring b0, const_bstring b1);

/*    Compare the bstrings b0 and b1 for ordering.  If there is an error,
    SHRT_MIN is returned, otherwise a value less than or greater than zero,
    indicating that the bstring pointed to by b0 is lexicographically less
    than or greater than the bstring pointed to by b1 is returned.  If the
    bstring lengths are unequal but the characters up until the length of the
    shorter are equal then a value less than, or greater than zero,
    indicating that the bstring pointed to by b0 is shorter or longer than the
    bstring pointed to by b1 is returned.  0 is returned if and only if the
    two bstrings are the same.  If the length of the bstrings are different,
    this function is O(n).  Like its standard C library counter part, the
    comparison does not proceed past any '\0' termination characters
    encountered.

    The seemingly odd error return value, merely provides slightly more
    granularity than the undefined situation given in the C library function
    strcmp.  The function otherwise behaves very much like strcmp().

    Note that the semantics of bstrcmp are not completely compatible with
    biseq because of its different treatment of the '\0' termination
    character.
    */


    extern bstring bgets (bNgetc getcPtr, void * parm, char terminator);
    typedef int (* bNgetc) (void * parm);

/*    Read a bstring from a stream.  As many bytes as is necessary are read until the terminator is consumed or no more characters are available from the stream.  If read from the stream, the terminator character will be appended to the end of the returned bstring.  The getcPtr function must have the same semantics as the fgetc C library function (i.e., returning an integer whose value is negative when there are no more characters available, otherwise the value of the next available unsigned character from the stream.)  The intention is that parm would contain the stream data context/state required (similar to the role of the FILE* I/O stream
    parameter of fgets.)  If no characters are read, or there is some other
    detectable error, NULL is returned.

    bgets will never call the getcPtr function more often than necessary to
    construct its output (including a single call, if required, to determine
    that the stream contains no more characters.)

    Abstracting the character stream function and terminator character allows
    for different stream devices and string formats other than '\n'
    terminated lines in a file if desired (consider \032 terminated email
    messages, in a UNIX mailbox for example.)

    For files, this function can be used analogously as fgets as follows:

        fp = fopen ( ... );
        if (fp) b = bgets ((bNgetc) fgetc, fp, '\n');

    (Note that only one terminator character can be used, and that '\0' is
    not assumed to terminate the stream in addition to the terminator
    character. This is consistent with the semantics of fgets.)
    
*/
