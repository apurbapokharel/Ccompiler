#include "components/defs.h"
#include "components/data.h"
#include "components/decl.h"

// Parse a primary factor and return an AST node representing it
static struct ASTnode *primary(void){
	struct ASTnode *n;
	switch (Token.token) {
		case T_INTLIT:
			n = mkastleaf(A_INTLIT, Token.intvalue);
			scan(&Token);
			return n;
		default:
			fprintf(stderr, "syntax error on line %d\n", Line);
			exit(1);
	}
}

// Convert a lexer enum into parser operation/enum
int arithop(int tok){
	switch (tok) {
		case T_PLUS:
			return (A_ADD);
		case T_MINUS:
			return (A_SUBTRACT);
		case T_STAR:
			return (A_MULTIPLY);
		case T_SLASH:
			return (A_DIVIDE);
		default:
			fprintf(stderr, "unknown token in arithhop() on line %d\n", Line);
			exit(1);
	}
}

// Operator precedence for each token
static int OpPrec[] = { 0, 10, 10, 20, 20, 0 };

// Check that we have a binary operator and
// return its precedence.
static int op_precedence(int tokentype) {
  int prec = OpPrec[tokentype];
  if (prec == 0) {
    fprintf(stderr, "syntax error on line %d, token %d\n", Line, tokentype);
    exit(1);
  }
  return (prec);
}

// Return an AST tree whose root is a binary operator.
// Parameter ptp is the previous token's precedence.
struct ASTnode *binexpr(int ptp) {
  struct ASTnode *left, *right;
  int tokentype;
  // Get the integer literal on the left.
  // Fetch the next token at the same time.
  left = primary();
  // If no tokens left, return just the left node
  tokentype = Token.token;
  if (tokentype == T_EOF)
    return (left);
  // While the precedence of this token is
  // more than that of the previous token precedence
  while (op_precedence(tokentype) > ptp) {
    // Fetch in the next integer literal
    scan(&Token);
    // Recursively call binexpr() with the
    // precedence of our token to build a sub-tree
    right = binexpr(OpPrec[tokentype]);
    // Join that sub-tree with ours. Convert the token
    // into an AST operation at the same time.
    left = mkastnode(arithop(tokentype), left, right, 0);
    // Update the details of the current token.
    // If no tokens left, return just the left node
    tokentype = Token.token;
	if (tokentype == T_EOF){
		return (left);
	}
  }
  // Return the tree we have when the precedence
  // is the same or lower
  return (left);
}

