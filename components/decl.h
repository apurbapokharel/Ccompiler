// scan.c functions
// Function prototypes for all compiler files
int scan(struct token *t);

// tree.c functions
//makes an AST node
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int inivalue);

//makes an AST leaf node
struct ASTnode *mkastleaf(int op, int intvalue);

//make an AST node with one child
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);

// expression.c functions
//a function that converts lexer token to parser token
int arithop(int tok);

//make an AST tree
struct ASTnode *binexpr(int rbp);

// interp.c functions
//a semantic analyzer
int interpretAST(struct ASTnode *n);

// stmt.c
// used to parse one or more statement
void statements(void);

// misc.c
// match tokens(t) with their respective identifiers (what)
void match(int t, char *what);
// match token with semicolon
void semi(void);

// gen.c
int genAST(struct ASTnode *n);
void genpreamble();
void genpostamble();
void genfreeregs();
void genprintint(int reg);

// cg.c
void freeall_registers(void);
void cgpreamble();
void cgpostamble();
int cgload(int value);
int cgadd(int r1, int r2);
int cgsub(int r1, int r2);
int cgmul(int r1, int r2);
int cgdiv(int r1, int r2);
void cgprintint(int r);
