# 求助 g++15.1 使用tbb库遇到的问题

编译环境: wsl2 + Ubuntu 24.04.3 LTS  
工具链：cmake 4.1.1 + Ninja 1.11.1 + gcc 15.1  
库版本： TBB 2021.11.0

2025/9/19 第一次尝试 在import std; 前#include\<tbb/tbb.h> 无法正常编译  
错误：conflicting imported declaration ‘template\<class _Tp> using std::__is_signed_integer = std::__is_one_of<typename std::remove_cv\<\<template-parameter-1-1> >::type, signed char, short int, int, long int, long long int, __int128>’  
错误：conflicting imported declaration ‘using std::__is_signed_integer = std::__is_one_of<typename std::remove_cv\<typename std::remove_const\<_Tp>::type>::type, signed char, short int, int, long int, long long int, __int128>’  
错误：conflicting imported declaration ‘using std::__is_signed_integer = std::__is_one_of<typename std::remove_cv< <template-parameter-1-1> >::type, signed char, short int, int, long int, long long int, __int128>’ 等。

2025/9/20 第二次尝试 看起来问题来自于头文件和import std 之间的冲突， 在模块内避免使用import std 可以正常编译通过。