# dunetpc/dune/DuneCommon/test/CMakeLists.txt

include(CetTest)

cet_enable_asserts()

cet_transitive_paths(FHICL_DIR BINARY IN_TREE)
cet_test_env_prepend(FHICL_FILE_PATH "." ${TRANSITIVE_PATHS_WITH_FHICL_DIR})
cet_transitive_paths(LIBRARY_DIR BINARY IN_TREE)
cet_test_env_prepend(CET_PLUGIN_PATH ${TRANSITIVE_PATHS_WITH_LIBRARY_DIR})

cet_test(test_MyClass SOURCES test_MyClass.cxx
  LIBRARIES
    duneexamples_DuneExample
    ROOT::Core
)

