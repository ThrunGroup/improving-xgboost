#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <xgboost/c_api.h>
#include <iostream>

int main(int argc, char** argv) {
  int silent = 0;

  BoosterHandle booster;

  // do something with booster

  //free the memory
  //XGBoosterFree(booster);

  DMatrixHandle DMatrixHandle_param;

  std::cout << "hello world" << std::endl;

  // do something with DMatrixHandle_param

  // free the memory
  //XGDMatrixFree(DMatrixHandle_param);

  return 0;
}