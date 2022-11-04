#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -P /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/sfml-populate-prefix/tmp/sfml-populate-gitclone.cmake
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E touch /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/sfml-populate-download
fi

