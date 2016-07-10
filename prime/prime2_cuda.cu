#include <iostream>
//include <boost/format.hpp>
#include<stdio.h>
#include<array>
#include<memory>

///#include "make_unique.hpp" /// for c++11
using namespace std;


//const int MAX_INT = 1000000;
const int MAX_INT = 100;


//const int MAX_INT = 1000000;
const unsigned int MAX_INT = 1024;

// Prime 素数を判定
//
__device__ bool isPrime(unsigned int val) {
  unsigned int  half_val = (val >> 1); /// val / 2 
  bool         ret_code = false;

  unsigned int i;
  for (i = half_val; i>1; i--) {
    if ((val % i) == 0) break;
  }
  if (i == 1) ret_code = true;
  else       ret_code = false;

  return ret_code;
}


//
//
__global__ void Kernel_Prime(
  const unsigned int *in,
  unsigned int *rst ) {
  //// Coding Now///
  unsigned int offset = *(in + threadIdx.x) ;

  // 判定
  if( isPrime(*(in+offset)) ){ 
    *(rst+offset) = *(in+offset);
  }else{
    *(rst+offset) = 0;
  }
  
}




//
//
int main(){
  ///unique_ptr<unsigned int[]>  inputVal(new unsigned int[MAX_INT]);  /// 入力データ
  unsigned int  *inVal_h;
  unsigned int  *inVal_d;
  unsigned int  *rstVal_d;    /// 素数判定結果
  unsigned int  *rstVal_h;    /// 素数判定結果6
  
  cudaError_t cudaStatus;
  /// 入力値バッファ(Device)
  cudaMalloc((void**)&inVal_d, MAX_INT * sizeof(unsigned int));
  
  /// 判定結果の保存バッファ(Device)
  cudaMalloc((void**)&rstVal_d, MAX_INT * sizeof(unsigned int));


  /// 入力値を用意(Host)
  inVal_h = new unsigned int[MAX_INT];
  for (unsigned int i = 0; i<MAX_INT; i++) {
    inVal_h[i] = i;
  }
  cudaMemcpy(inVal_d, inVal_h,
             MAX_INT * sizeof(unsigned int),
             cudaMemcpyHostToDevice); /* メモリ転送(Host→Device) */



  ////////////////////////////////////////
  printf("start\n");
  Kernel_Prime<<<1,MAX_INT>>>(inVal_d, rstVal_d);
    
                              // 素数判定
    
  //for (int j = 1; j<MAX_INT; j++) {
  ///result[j]  = isPrime(j);
  //}
  
  // Check for any errors launching the kernel
  cudaStatus = cudaGetLastError();
  if (cudaStatus != cudaSuccess) {
    fprintf(stderr, "addKernel launch failed: %s\n", cudaGetErrorString(cudaStatus));
    ///goto Error;
  }
  
  ////////////////////////////////////////

  /// 結果を取得 
  rstVal_h = new unsigned int[MAX_INT];
  cudaMemcpy(rstVal_h, /*inVal_d*/rstVal_d,
             MAX_INT * sizeof(unsigned int),
             cudaMemcpyDeviceToHost);  /* メモリ転送(Device→Host) */


  // 結果を表示
  for (int j = 1; j<MAX_INT; j++) {
    if (rstVal_h[j] != 0) printf("%d ", j);
    ///printf("%d ", rstVal_h[j]);
  }
  

  // MemoryFree
  delete[] inVal_h;
  delete[] rstVal_h;
  cudaFree(inVal_d);
  cudaFree(rstVal_d);


  return 0;
}
