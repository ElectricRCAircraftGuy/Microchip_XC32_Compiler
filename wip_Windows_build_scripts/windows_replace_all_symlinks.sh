#!/usr/bin/env bash

# See: https://stackoverflow.com/a/60157372/4561887
FULL_PATH_TO_SCRIPT="$(realpath "${BASH_SOURCE[-1]}")"
SCRIPT_DIRECTORY="$(dirname "$FULL_PATH_TO_SCRIPT")"

# (a little harsh; I was frustrated)
############# Hello, I see you are using Windows. Windows is stupid. I'm going
#to pause for 2 seconds to let you think about that.

# Now I'm replacing all symbolic links with copies of the files they point to,
# since again, Windows is stupid and needs this.

# Directory to start in
start_dir="$SCRIPT_DIRECTORY"

# Find all symbolic links in the directory and its subdirectories
find "$start_dir" -type l -print0 | while IFS= read -r -d '' symlink; do
    # Get the target of the symlink
    target="$(readlink -f "$symlink")"

    # Check if the target exists
    if [ -e "$target" ]; then
        echo "Replacing symlink \"$symlink\" with the contents of \"$target\"."

        # Remove the symlink
        rm "$symlink"

        # Copy the target to the symlink location
        cp -r "$target" "$symlink"
    else
        echo "Warning: target does not exist for $symlink"
    fi
done
