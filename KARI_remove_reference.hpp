// 
//[from] /usr/include/c++/7.2.1/type_traits
//

// Reference transformations.

namespace MY{
  /// remove_reference
  template<typename _Tp>
    struct remove_reference
    { typedef _Tp   type; };

  template<typename _Tp>
    struct remove_reference<_Tp&>
    { typedef _Tp   type; };

  template<typename _Tp>
    struct remove_reference<_Tp&&>
    { typedef _Tp   type; };

#if __cplusplus > 201103L
  /// Alias template for remove_reference
  template<typename _Tp>
    using remove_reference_t = typename remove_reference<_Tp>::type;

  /// Alias template for add_lvalue_reference
  template<typename _Tp>
    using add_lvalue_reference_t = typename add_lvalue_reference<_Tp>::type;

  /// Alias template for add_rvalue_reference
  template<typename _Tp>
    using add_rvalue_reference_t = typename add_rvalue_reference<_Tp>::type;
#endif



  template<typename _Tp>
  constexpr typename std::remove_reference<_Tp>::type&
    move2(_Tp& __t) noexcept{
    return static_cast<typename std::remove_reference<_Tp>::type&>(__t);
  }

  template<typename _Tp>
  constexpr typename std::remove_reference<_Tp>::type&&
    move2(_Tp&& __t) noexcept{
    return static_cast<typename std::remove_reference<_Tp>::type&&>(__t);
  }



};
