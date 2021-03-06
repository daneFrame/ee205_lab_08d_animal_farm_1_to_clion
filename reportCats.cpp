///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author Dane Sears <dsears@hawaii.edu>
/// @date   DAY_MON_YEAR
///////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#include "config.h"
#include "reportCats.h"
#include "catDatabase.h"
#include "addCats.h"

#define DEBUG

const char* colors[] = {"NONE", "WHITE", "BLUE", "BLACK"};
//const char* colorEnum2String (enum Color collarColor1)
void printCat(int index){
    if (index < 0 || index > MAX_CATS){
        fprintf(stderr, "[%s]: Index must be between 0 and 10!\n",PROGRAM_NAME);
    }else{
        printf("cat index = %d  name = %s  gender = %d breed = %d  isFixed = %d  weight = %.2f, collar 1 = %s, collar 2 = %s, license # = %llu\n", index, catDeetsArray[index].Name, catDeetsArray[index].Gender, catDeetsArray[index].Breed, catDeetsArray[index].isFixed, catDeetsArray[index].weight, colors[catDeetsArray[index].collarColor1], colors[catDeetsArray[index].collarColor2], catDeetsArray[index].license);
    }
}

void printAllCats(){
    printf("The name(s) of the cat(s) in the database:\n");
    for (int index = 0; index < MAX_CATS; index++ )
    {
        printf("Cat %d.) is %s\n",index, catDeetsArray[index].Name);
    }
}

int findCat(const char name[]){
    for (int index = 0; index < MAX_CATS; index++)
    {
        if ( strcmp(catDeetsArray[index].Name, name) == 0){
            printf("%s is cat #%d\n",name,index);
        }else{
            fprintf(stderr, "[%s]: Cat [%s] does not exist!\n", PROGRAM_NAME, name);
            index = MAX_CATS;
        }
    }
    return 1;
}