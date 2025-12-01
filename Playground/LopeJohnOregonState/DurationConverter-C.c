/*
Example Usage
./DurationConverter 3600 sec hour

This program converts a duration from one time unit to another.
It accepts three command-line arguments:
1. Numeric value to convert
2. Source unit (second, minute, hour, day)
3. Target unit (second, minute, hour, day)
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VALID_TYPE_NUM 4    // Number of valid time units
#define ERROR_MSG_LEN 3     // Number of possible error messages

// List of valid time unit strings
static char *ValidTypes[] = {"second","minute","hour","day"};

// Corresponding number of seconds for each valid time unit
static int  SecondsTypes[] = {1, 60, 3600, 86400};

/*
TypeValidation Helper

Checks if the provided time unit string matches any valid type.

type: string representing the time unit

Returns: true if valid, false if invalid
*/
bool TypeValidation_Helper(char *type){
    for (int i = 0; i < VALID_TYPE_NUM; i++){
        if (strcmp(type, ValidTypes[i]) == 0)
            return true; // input type matches one of the valid types
    }
    return false; // input type does not match one of the valid types
}

/* 
CheckforErrors

Checks if any error messages were set during input validation.

error_msgs_len: length of the error message array
error_msgs: array of pointers to error messages

Returns: true if any errors exists, false otherwise
*/
bool CheckforErrors(int error_msgs_len ,char *error_msgs[]){
    for (int i = 0; i < error_msgs_len; i++){
        if (error_msgs[i] != NULL)
            return true; // there is an error
    }
    return false; // no errors
}

/*
ConvertToSeconds

Converts a value froma. specified time unit to seconds.

value: numeric value to convert
type: time unit of the value

Returns: value converted to seconds
*/
int ConvertToSeconds(int value, char *type){
    int conversionValue = 0;
    for (int i = 0; i < VALID_TYPE_NUM; i++){
        if (strcmp(type, ValidTypes[i]) == 0){
            conversionValue = SecondsTypes[i];
            break;
        }
    }
    return value * conversionValue;
}
/*
Duration Converter

Converts a numeric value from a source time unit to a target time unit.
Validates input and prints error messages if invald.

val: numeric value to convert
source: source time uint
target: target time unit

Returns: true if conversion succeeds, false if any errors occur.
*/
bool DurationConverter(int val, char *source, char *target){
    int error_msgs_len = ERROR_MSG_LEN;
    char *error_msgs[ERROR_MSG_LEN] = {NULL, NULL, NULL};
    /*Check if value is less than 0*/
    if (val < 0){
        error_msgs[0] = "Value is less than";
    }

    /*Check if incorrect source type*/
    if (!TypeValidation_Helper(source)){
        error_msgs[1] = "Incorrect source type";
    }

    /*Check if incorrect target type*/
    if (!TypeValidation_Helper(target)){
        error_msgs[2] = "Incorrect target type";
    }

    /*If there is an error present*/
    if (CheckforErrors(error_msgs_len, error_msgs)){
        for (int i = 0; i < error_msgs_len; i++){
            if (error_msgs[i] != NULL) // print error messages
                printf("%s\n", error_msgs[i]);
        }
        return false; // exit program
    }

    /*Convert Value*/
    int convertedVal = ConvertToSeconds(val, source) / ConvertToSeconds(1, target);
    printf("%d\n", convertedVal);
    return true;
}

/*
main

Entry point of the program.
Parses command-line arguments and calls the converter.
*/
int main(int argc, char *argv[]){
    /*Input Validation*/
    if (argc < 4){
        char *error_msg = "Please enter 3 arguments";
        printf("%s\n", error_msg);
        return 1;
    }

    /*TypeCast and return function*/
    int input_val = atoi(argv[1]);
    if(DurationConverter(input_val, argv[2], argv[3]))
        return 0;
    else
        return 1;
}