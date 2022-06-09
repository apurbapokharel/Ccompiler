#ifndef extern_
 #define extern_ extern
#endif

// Global variables

extern_ int     Line;
extern_ int	Putback;
extern_ FILE	*Infile;
extern_ FILE *Outfile;
extern_ struct token Token;		// Last token scanned
extern_ char Text[TEXTLEN + 1];		// Last identifier scanned
