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

// expr.c functions
//a function that converts lexer token to parser token
static int arithop(int tok);

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
void ident(void);
void fatal(char *s);
void fatals(char *s1, char *s2);
void fatald(char *s, int d);
void fatalc(char *s, int c);

// gen.c
int genAST(struct ASTnode *n, int reg);
void genpreamble();
void genpostamble();
void genfreeregs();
void genprintint(int reg);
void genglobsym(char *s);

// cg.c
void freeall_registers(void);
void cgpreamble();
void cgpostamble();
int cgloadint(int value);
int cgloadglob(char *identifier);
int cgadd(int r1, int r2);
int cgsub(int r1, int r2);
int cgmul(int r1, int r2);
int cgdiv(int r1, int r2);
void cgprintint(int r);
int cgstorglob(int r, char *identifier);
void cgglobsym(char *sym);

// sym.c
int findglob(char *s);
int addglob(char *name);

// decl.c
void var_declaration(void);