# - Try to find libwee
# Once done this will define
#  WEE_FOUND - System has Wee
#  WEE_INCLUDE_DIRS - The Wee include directories
#  WEE_LIBRARIES - The libraries needed to use Wee


#find_package(PkgConfig)
#pkg_check_modules(PC_LIBXML QUIET libxml-2.0)
#set(LIBXML2_DEFINITIONS ${PC_LIBXML_CFLAGS_OTHER})

message("Trying to find wee.cpp")
find_path(WEE_INCLUDE_DIR wee.cpp
           )
message(${WEE_INCLUDE_DIR})

message("Trying to find libwee")
find_library(WEE_LIBRARY NAMES libwee
             )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set LIBXML2_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(WEE  DEFAULT_MSG
                                  WEE_LIBRARY WEE_INCLUDE_DIR)

mark_as_advanced(WEE_INCLUDE_DIR WEE_LIBRARY )

set(WEE_LIBRARIES ${WEE_LIBRARY} )
set(WEE_INCLUDE_DIRS ${WEE_INCLUDE_DIR} )
