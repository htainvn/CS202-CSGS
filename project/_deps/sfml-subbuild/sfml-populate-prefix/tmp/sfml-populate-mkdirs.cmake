# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-src"
  "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-build"
  "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-subbuild/sfml-populate-prefix"
  "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-subbuild/sfml-populate-prefix/tmp"
  "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
  "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-subbuild/sfml-populate-prefix/src"
  "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "C:/Users/Administrator/Desktop/Deadline/CS202-CSGS/Project/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/${subDir}")
endforeach()
