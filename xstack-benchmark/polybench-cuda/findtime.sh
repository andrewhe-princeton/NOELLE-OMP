#!/bin/bash

search_dir="."

# Function to recursively search for files
search_files() {
    local dir="$1"

    # Loop through all files and directories in the current directory
    for file in "$dir"/*; do
        if [ -d "$file" ]; then
            # If the current item is a directory, recursively call the function
            search_files "$file"
        elif [ -f "$file" ]; then
            # If the current item is a file, check if it is either clang.cpu.time or manual.clang.cpu.time
            if [ "$(basename "$file")" = "clang.cpu.time" ]; then
                echo "Original:clang.cpu.time $(cat "$file") in $dir"
            elif [ "$(basename "$file")" = "manual.clang.cpu.time" ]; then
                echo "Manual:manual.clang.cpu.time $(cat "$file") in $dir"
            fi
        fi
    done
}

# Call the function with the search directory
search_files "$search_dir"