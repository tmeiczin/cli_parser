/*
  The MIT License (MIT)

  Copyright (c) 2015 Terrence Meiczinger

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef _EXAMPLE_H_
#define _EXAMPLE_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "../cli_parser.h"

/* (command, desc, arg count, args) */
#define COMMANDS(GENERATOR) \
     GENERATOR(add,      "Adds two arguments",            number_1,number_2)  \
     GENERATOR(multiply, "Multiplies two arguments",      number_1,number_2)  \
     GENERATOR(area,     "Calculate area of a circule",   radius)

/* (argument, desc) */
#define ARGUMENTS(GENERATOR) \
    GENERATOR(number_1, "First number") \
    GENERATOR(number_2, "Second number") \
    GENERATOR(radius,   "The radius of the circle") \

/* (option, value_required, default, desc) */
#define OPTIONS(GENERATOR) \
    GENERATOR(help,           0, NULL,     "Show help") \
    GENERATOR(version,        0, NULL,     "Show version") \
    GENERATOR(units,          1, inches,   "Measurement Units (inches|mm)") \
    GENERATOR(color,          1, green,    "Color")

/* include arg structure */
CLI_PARSER_STRUCT

#ifdef __cplusplus
}
#endif

#endif // _EXAMPLE_H_
