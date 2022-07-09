# Definition of what each .c and .h file does

Since, the number of files is increasing I am going to maintain this file dictionary from phase 6.

## Header files

1. data.h

This file deals with declaring the necessary global datas for our compiler.
ifndef and extern are used to achieve this.

2. decl.h

This file deals with declaring the functions that will be implemented in their respective c files.

3. defs.h

This files holds the definition for globally used struct and enumns.
Has token and AST node's struct defined within it.

## C files

1. scan.c

The code for the lexical scanner. Scanner scans each token at a time or per call to the function, 
skips whitespaces.

2. tree.c

The file contains the functions to define AST parent and lead nodes.

3. expr.c

The file contains the code generates the AST.

4. interp.c

Depreciated file that computed final result from AST tree upto phase 3. It used c's maths operators
rather than using assembly for performing mathematical operation.

5. gen.c and cg.c

Home to the assembly code for allocation and deallocation of registers. Performing mathematical 
operation using registers and assembly for x86 CPU architecture.

6. stmt.c

This file will scan a single statement at a time. 
print 2+3; is an example of statement upto phase 5.

7. misc.c

This is a Miscellaneous file that contains the helper functions used by stmt.c.
Currently houses code to match/check semicolons.

8. decl.c

This contains the code used for parsing  declaration statements.

9. sym.c

This contains the code used for storing, fetching and or checking variable name from the 
globally declared array of variable struct.

