# CLI Parser
This is a CLI parsing library to help simplify some types of command line parsing. It provides a somewhat GIT like interface where an application may have multiple commands and arguments. In addition will generate help and usage screens.

```
$ app [options] command <args>
```

Include the cli_parser.h file in your application header file. You can then define options, positional arguments, and command types.

```
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
```

In your C file, you include the CLI_PARSER macro. This will set two variables, cli_result which indicates if the parsing was successful and args which is a flat structure containing all the possible options, arguments, commands. 

```
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
```

This will auto-generate the help screen.

```
$ ./calc --help
Usage: calc [--version] [--help] [options] command <args>

Options:
  --help             Show help [default NULL]
  --version          Show version [default NULL]
  --units            Measurement Units (inches|mm) [default inches]
  --color            Color [default green]

Commands:
    add              Adds two arguments
    multiply         Multiplies two arguments
    area             Calculate area of a circule

Command Usage:
    calc [options] add  <number_1> <number_2>
    calc [options] multiply  <number_1> <number_2>
    calc [options] area  <radius>
```
