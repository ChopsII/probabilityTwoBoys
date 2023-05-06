
cmake_minimum_required(VERSION 3.24)

# Fetch and include cmaked-ez
include(FetchContent)
FetchContent_Declare(
	cmaked-ez
	GIT_REPOSITORY	git@github.com:ChopsII/cmaked-ez.git
	GIT_TAG       	main
)
FetchContent_MakeAvailable(cmaked-ez)
include("${CMAKE_BINARY_DIR}/_deps/cmaked-ez-src/src/cmaked-ez.cmake")

# Your project code
project(probabilityTwoBoys)

ez_auto_configure_modules()
