#!/bin/bash

set -e

echo "Installing required dependencies..."

if [[ "$OSTYPE" == "linux-gnu"* ]]; then
    sudo apt-get update
    sudo apt-get install -y git g++ libgtest-dev
else
    echo "Unsupported OS: $OSTYPE"
    exit 1
fi

echo -e "\n\033[32mSuccessfully installed dependencies!\033[0m"