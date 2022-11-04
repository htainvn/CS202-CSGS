#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-build
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E echo_append
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E touch /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/sfml-populate-build
fi

