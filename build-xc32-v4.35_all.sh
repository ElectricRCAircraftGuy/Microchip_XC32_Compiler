#!/usr/bin/env bash

# See: https://stackoverflow.com/a/60157372/4561887
FULL_PATH_TO_SCRIPT="$(realpath "${BASH_SOURCE[-1]}")"
SCRIPT_DIRECTORY="$(dirname "$FULL_PATH_TO_SCRIPT")"

"$SCRIPT_DIRECTORY/build-xc32-v4.35m.sh"
ret_code="$?"
if [ $ret_code -ne 0 ]; then
    echo "Error: Failed to build XC32m!"
    exit "$ret_code"
fi

"$SCRIPT_DIRECTORY/build-xc32-v4.35c.sh"
ret_code="$?"
if [ $ret_code -ne 0 ]; then
    echo "Error: Failed to build XC32c!"
    exit "$ret_code"
fi

echo "Done! Built successfully."
