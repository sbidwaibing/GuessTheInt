#!/bin/bash

set -e

echo "Running basic build tests..."

./run.sh sanitize

echo "If no sanitizer errors appear → build is correct"