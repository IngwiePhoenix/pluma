////////////////////////////////////////////////////////////
//
// Pluma - Plug-in Management Framework
// Copyright (C) 2011 Gil Costa (gsaurus@gmail.com)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
////////////////////////////////////////////////////////////

#ifndef PLUMA_PLUGIN_API_HPP
#define PLUMA_PLUGIN_API_HPP

////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <Pluma\Config.hpp>
#include <Pluma\Host.hpp>

////////////////////////////////////////////////////////////
// Macro that helps plugins generating their provider implementations
// PRE: SPECIALIZED_TYPE must inherit from BASE_TYPE
////////////////////////////////////////////////////////////
#define PLUMA_INHERIT_PROVIDER(SPECIALIZED_TYPE, BASE_TYPE)\
class SPECIALIZED_TYPE##Provider: public BASE_TYPE##Provider{\
public:\
    BASE_TYPE * create(){ return new SPECIALIZED_TYPE (); }\
};


/////////////////////////////////////////////////////////////////
// Define portable import/export macros for Plugin registration
/////////////////////////////////////////////////////////////////
#if defined(PLUMA_SYS_WINDOWS)

    #ifndef PLUMA_STATIC_PLUGIN

         // Windows platforms
        #ifdef PLUGIN_EXPORTS

            // From DLL side, we must export
            #ifdef __cplusplus
               #define PLUMA_PLUGIN_CONNECTION extern "C" __declspec(dllexport)
            #else
               #define PLUMA_PLUGIN_CONNECTION __declspec(dllexport)
            #endif

        #else

            // From client application side, we must import
            #ifdef __cplusplus
               #define PLUMA_PLUGIN_CONNECTION extern "C" __declspec(dllimport)
            #else
               #define PLUMA_PLUGIN_CONNECTION __declspec(dllimport)
            #endif

        #endif

    #else

        // No specific directive needed for static build
        #define PLUMA_PLUGIN_CONNECTION

    #endif

#else

    // Other platforms don't need to define anything
    #define PLUMA_PLUGIN_CONNECTION

#endif


#endif // PLUMA_PLUGIN_API_HPP
