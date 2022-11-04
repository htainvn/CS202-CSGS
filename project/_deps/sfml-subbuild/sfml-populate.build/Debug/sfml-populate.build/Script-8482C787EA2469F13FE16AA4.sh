#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -Dcfgdir=/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME -P /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/sfml-populate-prefix/tmp/sfml-populate-mkdirs.cmake
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E touch /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/sfml-populate-mkdir
fi

