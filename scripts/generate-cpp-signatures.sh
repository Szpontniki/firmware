#!/bin/sh

set -e

cd "$(dirname "$0")/.."

bear --output compile_commands_mock.json -- make production

mv compile_commands_mock.json scripts
