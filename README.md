Following this [repo](https://github.com/DoctorWkt/acwj) head to tail for the duration of this project.
Practical and theoretical learning side by side.

# Phase 3
Fixed the parser's semantic analyzer. Will now make a AST according to precedence.
This is done by removing the old way of creating a AST which was basically a recursive scanning without
taking precdence into account. Pratt parser was implemented to fix this.

Thank you to DoctorWkt for making a boy's compiler dream come true.
