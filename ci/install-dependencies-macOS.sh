#!/usr/bin/env bash
#
# Bash script to install GMT dependencies on macOS via Homebrew
#
# Environmental variables that can control the installation:
#
# - BUILD_DOCS: Build GMT documentations [false]
# - RUN_TESTS:  Run GMT tests            [false]
#
set -x -e

# set defaults to false
BUILD_DOCS="${BUILD_DOCS:-false}"
RUN_TESTS="${RUN_TESTS:-false}"

# packages for compiling GMT
packages="cmake ninja curl netcdf gdal fftw pcre2 ghostscript"

# packages for build documentations
if [ "$BUILD_DOCS" = "true" ]; then
    packages+=" graphicsmagick ffmpeg sphinx"
fi
# packages for runing GMT tests
if [ "$RUN_TESTS" = "true" ]; then
    packages+=" graphicsmagick"
fi

# Install packages
brew update
berw install ${packages}
