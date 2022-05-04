#include "components/defs.h"
#include "components/data.h"
#include "components/decl.h"

// Array of operators
static char *ASTop[] = {"+", "-", "*", "/"};

// Semantic analyze AST tree and get value
int interpretAST(struct ASTnode *n){
	int leftVal, rightVal;

	if(n->left)
		leftVal = interpretAST(n->left);
	if(n->right)
		rightVal = interpretAST(n->right);

	if (n->op == A_INTLIT)
		printf("int %d\n", n->intvalue);
	else
		printf("%d %s %d\n", leftVal, ASTop[n->op], rightVal);

	switch (n->op) {
		case A_ADD:
			return leftVal + rightVal;
		case A_SUBTRACT:
			return leftVal - rightVal;
		case A_MULTIPLY:
			return leftVal * rightVal;
		case A_DIVIDE:
			return leftVal / rightVal;
		case A_INTLIT:
			return (n->intvalue);
		default:
			fprintf(stderr, "Unknown AST operator %d\n", n->op);
			exit(1);

	}
}
