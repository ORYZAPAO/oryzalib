#include<iostream>

usidng namespace std;

int main(){

  /// http://cpprefjp.github.io/lang/cpp11/lambda_expressions.html から引用
  /// 
  /// 構文
  /// 
  /// [キャプチャリスト](パラメータリスト) mutable 例外仕様 属性 -> 戻り値の型 { 関数の本体 }
  /// 
  /// このうち、以下は省略可能である：
  /// 
  ///     パラメータ、mutable、例外仕様、属性、戻り値の型のいずれも明示的に指定しない場合は、パラメータリストの丸カッコを省略できる
  ///     コピーキャプチャした変数を書き換える必要がない場合、mutableを省略できる
  ///     例外仕様を指定しない場合、それを省略できる
  ///     属性を指定しない場合、それを省略できる
  ///     戻り値の型を推論に任せる場合、->記号および戻り値の型を省略できる
  /// 
  /// もっとも短いラムダ式は、以下のようになる：
  /// 
  ///   []{}
  /// 
  /// このラムダ式は、なにもキャプチャせず、パラメータを受け取らず、なにも処理せず、
  /// 戻り値の型がvoidである関数オブジェクトを定義する。
  /// 
  /// ラムダ式の記述に関する制限として、「ラムダ式は、評価されないオペランドに現れてはならない」というものがある。
  /// そのため、decltype、sizeof、noexcept、alignasのオペランドにはラムダ式を指定できない。

  /// キャプチャ
  /// 
  /// ラムダ式には、ラムダ式の外にある自動変数を、ラムダ式内で参照できるようにする「キャプチャ(capture)」という機能がある。
  /// キャプチャは、ラムダ導入子(lambda-introducer)と呼ばれる、ラムダ式の先頭にある[ ]ブロックのなかで指定する。
  /// 
  /// キャプチャには、コピーキャプチャと参照キャプチャがあり、デフォルトでどの方式でキャプチャし、個別の変数をどの方式でキャプチャするかを指定できる。
  /// キャプチャ記法 	説明
  /// [&] 	デフォルトで環境にある変数を参照して、ラムダ式のなかで使用する
  /// [=] 	デフォルトで環境にある変数をコピーして、ラムダ式のなかで使用する
  /// [&x] 	変数xを参照して、ラムダ式のなかで使用する
  /// [x] 	変数xをコピーして、ラムダ式のなかで使用する
  /// [&, x] 	デフォルトで参照キャプチャ、変数xのみコピーして、ラムダ式のなかで使用する
  /// [=, &x] 	デフォルトでコピーキャプチャ、変数xのみ参照して、ラムダ式のなかで使用する
  /// [this] 	*thisのメンバを参照して、ラムダ式のなかで使用する
  /// [this, x] 	*thisのメンバを参照し、変数xのみコピーして、ラムダ式のなかで使用する
}
