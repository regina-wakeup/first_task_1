#pragma once

#ifdef WIN32
  #define ip_sort_EXPORT __declspec(dllexport)
#else
  #define ip_sort_EXPORT
#endif

ip_sort_EXPORT void ip_sort();
