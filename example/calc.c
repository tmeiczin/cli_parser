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

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "calc.h"


/****************************/
/***** APPLICATION CODE *****/
/****************************/

/* start of application */
int main(int argc, char *argv[]) {

    /* include parser macro */
    CLI_PARSER
    /* cli_result and args are now defined */

    /* check the result of the parser */
    if (cli_result) {
        exit(1);
    }

    /* print arguments */
    printf("[Commands]\n");
    printf("  add:       %s\n", args.add ? "true" : "false");
    printf("  multiply:  %s\n", args.multiply ? "true" : "false");
    printf("  area:      %s\n", args.area ? "true" : "false");
    printf("\n[Arguments]\n");
    printf("  number_1:  %s\n", args.number_1);
    printf("  number_2:  %s\n", args.number_2);
    printf("  radius:    %s\n", args.radius);
    printf("\n[Options]\n");
    printf("  --help:     %s\n", args.help ? "true" : "false");
    printf("  --version:  %s\n", args.version ? "true" : "false");
    printf("  --units:    %s\n", args.units);
    printf("  --color:    %s\n", args.color);

    if (args.version) {
        printf("version 1.00.00\n");
        exit(0);
    }

    /* execute commands */
    if (args.add) {
        int a = atoi(args.number_1);
        int b = atoi(args.number_2);
        printf("\nAdd: ");
        printf("%d + %d = %d\n", a, b, a + b);
    }
    else if (args.area) {
        int radius = atoi(args.radius);
        float area = 3.14 * radius * radius;
        printf("\nArea: ");
        printf("The area is %2.2f square %s\n", area, args.units);
    }
    else if (args.multiply) {
        int a = atoi(args.number_1);
        int b = atoi(args.number_2);
        printf("\nAdd: ");
        printf("%d * %d = %d\n", a, b, a * b);
    }

    return 0;
}
