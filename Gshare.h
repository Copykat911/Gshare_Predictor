
//  ╔═╗┌─┐┬ ┬┌─┐┬─┐┌─┐ ┬ ┬
//  ║ ╦└─┐├─┤├─┤├┬┘├┤  ├─┤
//  ╚═╝└─┘┴ ┴┴ ┴┴└─└─┘o┴ ┴

//  ╦┌┐┌┌─┐┬  ┬ ┬┌┬┐┌─┐┌─┐
//  ║││││  │  │ │ ││├┤ └─┐
//  ╩┘└┘└─┘┴─┘└─┘─┴┘└─┘└─┘
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

//  ╔═╗┬─┐┌─┐┌┬┐┌─┐┌┬┐┬ ┬┌─┐┌─┐┌─┐
//  ╠═╝├┬┘│ │ │ │ │ │ └┬┘├─┘├┤ └─┐
//  ╩  ┴└─└─┘ ┴ └─┘ ┴  ┴ ┴  └─┘└─┘
void 
    hex_to_int(),
    find_M_index(),
    compare_outcome(),
    print_table(int *),
    create_reverse_array(),
    open_file(char **argv),
    init_table(int *M_TABLE),
    simulation_properties(char **argv);

//  ╦  ╦┌─┐┬─┐┬┌─┐┌┐ ┬  ┌─┐┌─┐
//  ╚╗╔╝├─┤├┬┘│├─┤├┴┐│  ├┤ └─┐
//   ╚╝ ┴ ┴┴└─┴┴ ┴└─┘┴─┘└─┘└─┘
int
    M,
    N,
    GHB,
    hit,
    miss,
    N_EXT,
    M_index,
    prediction,
    isolated_M,
    size_of_table,
    total_instructions;

bool
    active = true;

FILE
    *fp;

char *
    fname;

char
    outcome[1],
    outcome_char,
    store_file_address[30];

float
    misoutcome_ratio;

unsigned int
    integer_Address;

unsigned char
    reversed_file_address[30];


