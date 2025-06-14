# ======================================================================
#  duneexamples main build file
# ======================================================================


# use cmake 3.14 or later
cmake_minimum_required (VERSION 3.20 FATAL_ERROR)
# cmake_policy(VERSION 3.19)

find_package(cetmodules REQUIRED)
project(duneexamples LANGUAGES CXX)
set(${PROJECT_NAME}_CMAKE_PROJECT_VERSION_STRING 10.08.01d00)

# cetbuildtools contains our cmake modules

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS CAUTIOUS
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic -Wno-unused-local-typedefs
)

cet_report_compiler_flags()

find_package( art REQUIRED EXPORT )
find_package( art_root_io REQUIRED EXPORT )
find_package( canvas_root_io REQUIRED EXPORT )
find_package( Boost REQUIRED EXPORT )
find_package(ROOT REQUIRED EXPORT )

# macros for artdaq_dictionary and simple_plugin
include(ArtDictionary)
include(ArtMake)
include(BuildPlugins)

add_subdirectory(duneexamples)

cet_cmake_config()
