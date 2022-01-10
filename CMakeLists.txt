# CMakeList.txt : CMake project for analytics, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("analytics")

# Add source to this project's executable.
add_executable (analytics "main.cpp"  "structs/table.cpp" "structs/table.h")

# TODO: Add tests and install targets if needed.
