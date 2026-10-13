#!/bin/sh

set -e

cd "$(dirname "$0")"

./generate-cpp.sh
./generate-platformio.sh

mv compile_commands_mock.json ../../src/mock/compile_commands.json
mv compile_commands_hardware.json ../../src/hardware/compile_commands.json
