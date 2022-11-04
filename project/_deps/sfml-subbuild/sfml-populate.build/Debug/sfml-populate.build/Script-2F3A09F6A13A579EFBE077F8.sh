#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E make_directory /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/CMakeFiles/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E touch /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/CMakeFiles/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/sfml-populate-complete
  /opt/homebrew/Cellar/cmake/3.24.2/bin/cmake -E touch /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/sfml-populate-prefix/src/sfml-populate-stamp/$CONFIGURATION$EFFECTIVE_PLATFORM_NAME/sfml-populate-done
fi

