// Function prototypes for all compiler files
int scan(struct token *t);

//makes an AST node
struct ASTnode *mkastnode(int op, struct ASTnode *left, struct ASTnode *right, int inivalue);

//makes an AST leaf node
struct ASTnode *mkastleaf(int op, int intvalue);

//make an AST node with one child
struct ASTnode *mkastunary(int op, struct ASTnode *left, int intvalue);

//a function that converts lexer token to parser token
int arithop(int tok);

//make an AST tree
struct ASTnode *binexpr(int rbp);

//a semantic analyzer
int interpretAST(struct ASTnode *n);

