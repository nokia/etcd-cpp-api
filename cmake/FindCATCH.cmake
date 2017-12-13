# Copyright 2017 Dirk Hutter <cmail@dirk-hutter.de>

find_path(CATCH_INCLUDE_DIR catch.hpp)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(CATCH REQUIRED_VARS CATCH_INCLUDE_DIR)
