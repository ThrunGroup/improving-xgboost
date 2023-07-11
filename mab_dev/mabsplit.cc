/* 
    loop for samples:
    - make predictions
    - get the gradients
    - build/update histogram
    - evaluate and execute split
    - add the two new nodes (after some verfication) into expand_set
*/ 
class MABSplit:

GetBatch;
MakePredictions + GetGradients


void MabSplit(DMatrix *p_fmat) {
    // while(tre)
    // sampling logic to get batch indices
    // get the sampling batch
    // std::shared_ptr<data::IterativeDMatrix> derivedSharedPtr = std::dynamic_pointer_cast<data::IterativeDMatrix>(train);
    // data::IterativeDMatrix* rawPtr = derivedSharedPtr.get();
    // int arr[3] = {1,2,3};
    // common::Span<int> ridxs(arr, 3);

    // MetaInfo mi = rawPtr->Info().Slice(ridxs);
    // rawPtr->SetInfoDirect(std::move(mi));
    this->PredictRaw(rawPtr, &predt, true, 0, 0);
    this->PredictRaw(train.get(), &predt, true, 0, 0);


  

    // TODO:
    //    - slice the meta Info using sample indices (method already exists?)
    //    - most likely method exists in train to slice
    GetGradient(predt.predictions, train->Info(), iter, &gpair_);


}