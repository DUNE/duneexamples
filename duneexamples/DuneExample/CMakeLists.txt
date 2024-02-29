# dunetpc/dune/DuneCommon/CMakeLists.txt

add_subdirectory(test)

#message(STATUS "ROOTSYS=${ROOTSYS}")
#message(STATUS "ROOT_BASIC_LIB_LIST=${ROOT_BASIC_LIB_LIST}")

art_make(BASENAME_ONLY
         duneexamples_DuneExample_dict
         LIB_LIBRARIES
         art::Persistency_Provenance canvas::canvas
         ROOT::Core
         ROOT::HistPainter
         NO_PLUGINS
        ) ### MIGRATE-ACTION-RECOMMENDED (migrate-3.22.02) - deprecated: use art_make_library(), art_dictonary(), and cet_build_plugin() with explicit source lists and plugin base types

#install_fhicl()
install_source()
install_headers()
