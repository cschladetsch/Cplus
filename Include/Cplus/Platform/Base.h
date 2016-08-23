#pragma once

#define X_CONCAT(A, B) _X_CONCAT(A, B)
#define _X_CONCAT(A, B)  A ## B

#define X_PLATFORM Darwin

#define X_PLATFORM_INCLUDE(X) X_CONCAT(Platform/Desktop, X)

#inlcude X_PLATFORM_INCLUDE(Grahpics.h)

