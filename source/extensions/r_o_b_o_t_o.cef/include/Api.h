// Copyright (c) 2022, NVIDIA CORPORATION. All rights reserved.
//
// NVIDIA CORPORATION and its licensors retain all intellectual property
// and proprietary rights in and to this software, related documentation
// and any modifications thereto. Any use, reproduction, disclosure or
// distribution of this software and related documentation without an express
// license agreement from NVIDIA CORPORATION is strictly prohibited.
//
#pragma once

#ifdef _WIN32
// When we build DLL, we need the __declspec(dllexport) keyword to export class
// member functions from a DLL. __declspec(dllexport) adds the export directive
// to the object file, so you do not need to use a .def file.
#    define ROBOTO_CEF_EXPORT __declspec(dllexport)
// When we build a third-party library that uses public symbols defined by this
// DLL, the symbols must be imported. We need to use __declspec(dllimport) on
// the declarations of the public symbols.
#    define ROBOTO_CEF_IMPORT __declspec(dllimport)
#    define ROBOTO_CEF_CLASS_EXPORT
#else
// It works similarly in Linux. The symbols must be visible in DSO because we
// build with the compiler option -fvisibility=hidden.
#    define ROBOTO_CEF_EXPORT __attribute__((visibility("default")))
// But to use them we don't need to use any dirrective.
#    define ROBOTO_CEF_IMPORT
// typeinfo of the class should be visible in DSO as well.
#    define ROBOTO_CEF_CLASS_EXPORT __attribute__((visibility("default")))
#endif

#if defined(ROBOTO_CEF_STATIC)
#    define ROBOTO_CEF_API
#    define ROBOTO_CEF_CLASS_API
#else
#    if defined(ROBOTO_CEF_EXPORTS)
#        define ROBOTO_CEF_API ROBOTO_CEF_EXPORT
#        define ROBOTO_CEF_CLASS_API ROBOTO_CEF_CLASS_EXPORT
#    else
#        define ROBOTO_CEF_API ROBOTO_CEF_IMPORT
#        define ROBOTO_CEF_CLASS_API
#    endif
#endif

#define ROBOTO_CEF_NS roboto::cef
#define ROBOTO_CEF_NAMESPACE_USING_DIRECTIVE using namespace ROBOTO_CEF_NS;
#define ROBOTO_CEF_NAMESPACE_OPEN_SCOPE                                                                                \
    namespace roboto                                                                                                   \
    {                                                                                                                  \
    namespace cef                                                                                                      \
    {
#define ROBOTO_CEF_NAMESPACE_CLOSE_SCOPE                                                                               \
    }                                                                                                                  \
    }
