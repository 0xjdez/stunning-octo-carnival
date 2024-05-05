
/**
 * declaration: a function that takes two ints and
 * returns a double
*/
static double a_fn(int, int);

/**
 * declaration: a function that points to the above
 * type of function
*/
// double (*a_fn_type)(int, int);

/**
 * declaration: typedef of a pointer that points to
 * a function to takes two ints and returns a double.
 * Do this so that it can be used as a type.
*/
typedef double (*a_fn_type)(int, int);