#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-src
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -P /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/sfml-populate-prefix/tmp/sfml-populate-gitupdate.cmake
fi

