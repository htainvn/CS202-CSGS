#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild
  make -f /Users/hoangtheanh/Documents/GitHub/CS202-CSGS/project/_deps/sfml-subbuild/CMakeScripts/ReRunCMake.make
fi

