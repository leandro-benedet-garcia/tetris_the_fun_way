#ifndef MATH_CONSTANTS_HPP
#define MATH_CONSTANTS_HPP

/// \def __precision
/// Can be either a float or double depending on the arguments used to compile
/// the engine
#ifdef arg_double_precision
#define __precision double
#else
#define __precision float
#endif

#endif
