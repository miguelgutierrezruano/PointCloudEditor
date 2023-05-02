
// Distributed under MIT License
// @miguelgutierrezruano
// 2023

#pragma once

// For Visual Studio

#if defined PointCloudLib

#define API __declspec(dllexport)

#else

#define API __declspec(dllimport)

#endif
