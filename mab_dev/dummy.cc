#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <xgboost/c_api.h>
#include <iostream>

// always check the return value of C API functions
#define safe_xgboost(call) {  \
  int err = (call); \
  if (err != 0) { \
  throw new std::runtime_error(std::string(__FILE__) + ":" + std::to_string(__LINE__) + \
                      ": error in " + #call + ":" + XGBGetLastError());  \
  } \
}


int main(int argc, char** argv) {
  // creating the dataset & labels
  DMatrixHandle dmatrix;
  // const int ROWS = 5, COLS = 3;
  // const int data[ROWS][COLS] = {{1, 2, 3}, {2, 4, 6}, {3, -1, 9}, {4, 8, -1}, {2, 5, 1}};
  //safe_xgboost(XGDMatrixCreateFromMat(data, ROWS, COLS, -1, &dmatrix)); // missing values set to -1
  const float data[] = { 0, 0, 1, 0};
  safe_xgboost(XGDMatrixCreateFromMat(data, 1, 4, 0, &dmatrix)); // missing values set to -1

  float labels[1];
  for (int i = 0; i < 1; i++) { labels[i] = i; }
  safe_xgboost(XGDMatrixSetFloatInfo(dmatrix, "label", labels, 1));

  // create booster + set hyperparams
  BoosterHandle booster;
  const int eval_dmats_size = 2;
  DMatrixHandle eval_dmats[eval_dmats_size] = {dmatrix, dmatrix}; // train and test equal to data
  safe_xgboost(XGBoosterCreate(eval_dmats, eval_dmats_size, &booster));
  /*
  safe_xgboost(XGBoosterSetParam(booster, "booster", "gblinear"));
  safe_xgboost(XGBoosterSetParam(booster, "max_depth", "3"));
  safe_xgboost(XGBoosterSetParam(booster, "eta", "0.1")); 
  */

  // train booster
  int num_of_iterations = 5;
  const char* eval_names[eval_dmats_size] = {"train", "test"};
  const char* eval_result = NULL;
  for (int i = 0; i < num_of_iterations; ++i) {
    // Update the model performance for each iteration
    safe_xgboost(XGBoosterUpdateOneIter(booster, i, dmatrix));
   
    // Give the statistics for the learner for training & testing dataset in terms of error after each iteration
    safe_xgboost(XGBoosterEvalOneIter(booster, i, eval_dmats, eval_names, eval_dmats_size, &eval_result));
    printf("%s\n", eval_result);
  }

  // free memory
  XGDMatrixFree(dmatrix);
  XGBoosterFree(booster);
  return 0;
}
