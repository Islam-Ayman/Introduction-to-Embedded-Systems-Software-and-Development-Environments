/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief source code for assignment 1 of the course. contains all function implementations.
 *
 *
 * @author Islam Ayman
 * @date 20-May-2022
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  /* Other Variable Declarations Go Here */
  
  /* Other Variable Declarations Go Here */
  unsigned char minimum = 0;
  unsigned char maximum = 0;
  float mean = 0;
  unsigned char median = 0;

  /* Statistics and Printing Functions Go Here */
  printf("Array before sorting: \n");
  print_array(&test, SIZE);
  median = find_median(&test, SIZE);
  mean = find_mean(&test, SIZE);
  maximum = find_maximum(&test, SIZE);
  minimum = find_minimum(&test, SIZE);
  print_statistics(minimum, maximum, mean, median);
  sort_array(&test, SIZE);
  printf("Array after sorting: \n");
  print_array(&test, SIZE);
}

void print_statistics (unsigned char minimum, unsigned char maximum, float mean, unsigned char median){
  printf("The minimum is %d \n", minimum);
  printf("The maximum is %d \n", maximum);
  printf("The mean is %f \n", mean);
  printf("The median is %d \n", median);
}


void print_array (unsigned char *array, unsigned int arr_size){
  for (int i=0; i<arr_size; i++){
    printf("%d,", *(array + i));
  }
  printf("\n");
}

unsigned char find_median (unsigned char *array, unsigned int arr_size){
  unsigned char median = 0;
  median = *(array + (arr_size / 2) -1);
  return median;
}

float find_mean (unsigned char *array, unsigned int arr_size){
  unsigned int accumulator = 0; // variable to store the accumulator value throughout the mean finding process
  float mean = 0;
  for (int i=0; i<arr_size; i++){
    accumulator = accumulator + array[i] /* *(array + i) */;
  }
  printf("acc = %d \n", accumulator);
  mean = accumulator / ((float) arr_size); //must type cast one of the two integers to float for accurate calculation.
  return mean;
}

unsigned char find_maximum (unsigned char *array, unsigned int arr_size){
  unsigned char maximum = *array; //initialize the max with first element
  // loop on whole array starting from the second element and check if there is a bigger value 
  for (int i=1; i<arr_size; i++){ 
    if (*(array + i) > maximum){
      maximum = *(array + i);
    }
    else {

         } 
  }
  return maximum;
}

unsigned char find_minimum (unsigned char *array, unsigned int arr_size){
  unsigned char minimum = *array; //initialize the min with first element
  // loop on whole array starting from the second element and check if there is a smaller value 
  for (int i=1; i<arr_size; i++){ 
    if (*(array + i) < minimum){
      minimum = *(array + i);
    }
    else {

         } 
  }
  return minimum;
}

void sort_array (unsigned char *array, unsigned int arr_size){
  for (int i=0;i<arr_size-1;i++){
      for(int j=0;j<(arr_size-1-i);j++){
          if (array[j]<array[j+1]){
              int temp=array[j];
              array[j]=array[j+1];
              array[j+1]=temp;
          }
          else{

              }
      }
  }
  }
 


