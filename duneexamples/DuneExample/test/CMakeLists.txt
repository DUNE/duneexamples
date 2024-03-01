# dunetpc/dune/DuneCommon/test/CMakeLists.txt

include(CetTest)

cet_enable_asserts()

cet_test(test_MyClass SOURCES test_MyClass.cxx
  LIBRARIES
    duneexamples_DuneExample
    ROOT::Core
)

