#!/bin/sh

set -e

cd "$(dirname "$0")/.."

platformio run --target compiledb && mv compile_commands.json compile_commands_hardware.json

mv compile_commands_hardware.json scripts
