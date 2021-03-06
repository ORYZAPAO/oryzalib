// ======================================================================
//
// bitset Sample
//
// 多ビット表現
//
// ======================================================================
#include<iostream>
#include<boost/format.hpp>

#include<bitset>

using namespace std;

int main(){

  //------------------------------
  // 初窺値の指定なしの場合は、All Zero
  //------------------------------
  bitset<10> bsA; // 10bit長
  cout << "10bit --> " << bsA << endl;
  cout << endl;

  //------------------------------
  // 初期値を指定 
  // (Memo) bitset<N> の　N個より少なくてもOK
  //------------------------------
  bitset<8> bsB("10101111"); // 8bit長の値(0xAF)
  cout << " 8bit --> " << bsB << endl;
  cout << endl;

  //------------------------------
  // 初期値を string形式のビット列で指定
  //
  // bitset<N> bs(string(s),i,j> 
  //   string形式のビット列sから
  //   左 i番目から j文字取り出し
  //------------------------------
  
  // bitset<10> bs0{"10110111011110",2,0}; // Compile Error
  //                                          string形式のビット列で指定

  //                                               string形式のビット列から
  bitset<10> bs0{string("10110111011110"),2,0}; //   左 2番目から 0文字取り出し(無効)
  bitset<10> bs1{string("10110111011110"),2,1}; //               2番目から 1 ビット列を取り出して、LSB側から埋める
  bitset<10> bs2{string("10110111011110"),2,2}; //               2番目から 2
  bitset<10> bs3{string("10110111011110"),2,3}; //               2番目から 3
  bitset<10> bs4{string("10110111011110"),2,4}; //               2番目から 4
  bitset<10> bs5{string("10110111011110"),2,5}; //               2番目から 5
  bitset<10> bs6{string("10110111011110"),2,6}; //               2番目から 6
  bitset<10> bs7{string("10110111011110"),2,7}; //               2番目から 7

  // 0123456789... 位置は左から0開始
  //  1234567 ... 取り出すビット数
  //  |---->
  //10110111011110
  //
  //   0000000000
  //   0000000001
  //   0000000011
  //   0000000110
  //   0000001101
  //   0000011011
  //   0000110111
  //   0001101110
  cout << bs0 << endl;
  cout << bs1 << endl;
  cout << bs2 << endl;
  cout << bs3 << endl;
  cout << bs4 << endl;
  cout << bs5 << endl;
  cout << bs6 << endl;
  cout << bs7 << endl;

}

