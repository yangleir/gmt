#!/usr/bin/env bash
#
# Bash script to install GMT dependencies on Ubuntu.
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
packages="build-essential cmake ninja-build libcurl4-gnutls-dev libnetcdf-dev \
          libgdal-dev libfftw3-dev libpcre3-dev liblapack-dev libglib2.0-dev \
          ghostscript curl"
# packages for build documentations
if [ "$BUILD_DOCS" = "true" ]; then
    packages+=" python3-pip python3-setuptools python3-wheel graphicsmagick ffmpeg"
fi
# packages for runing GMT tests
if [ "$RUN_TESTS" = "true" ]; then
    packages+=" graphicsmagick gdal-bin"
fi

echo $packages
# Install packages
sudo apt-get update
sudo apt-get install -y --no-install-recommends --no-install-suggests $packages
