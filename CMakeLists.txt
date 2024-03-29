# ======================================================================
#  duneexamples main build file
# ======================================================================


# use cmake 3.14 or later
cmake_minimum_required (VERSION 3.19 FATAL_ERROR)

project(duneexamples LANGUAGES CXX)
set(${PROJECT_NAME}_CMAKE_PROJECT_VERSION_STRING 09.85.00d00)

# cetbuildtools contains our cmake modules
find_package(cetbuildtools REQUIRED)

include(CetCMakeEnv)
cet_cmake_env()

cet_set_compiler_flags(DIAGS CAUTIOUS
  WERROR
  NO_UNDEFINED
  EXTRA_FLAGS -pedantic -Wno-unused-local-typedefs
)

cet_report_compiler_flags()

find_ups_product( art )
find_ups_product( art_root_io )
find_ups_product( canvas_root_io )
find_ups_boost( )
find_ups_root()
find_ups_product( cetbuildtools )

# macros for artdaq_dictionary and simple_plugin
include(ArtDictionary)
include(ArtMake)
include(BuildPlugins)

add_subdirectory(duneexamples)
add_subdirectory(ups)

include(UseCPack)
