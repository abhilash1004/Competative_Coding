"# Competative_Coding" 

Some setup command to run in VS Code:

/opt/homebrew/bin/g++-16 -fdiagnostics-color=always /Users/abhilashperla/Abhi/DSA/Competative_Coding/first.cpp -o /Users/abhilashperla/Abhi/DSA/Competative_Coding/first && /Users/abhilashperla/Abhi/DSA/Competative_Coding/first < inputf.in > outputf.out

		or

g++-16 -std=c++17 -O2 first.cpp -o first && first < inputf.in > outputf.out


Created a build system for sublime with name CP.sublime-build.


It's shell cmd: "g++-16 -std=c++17 -O2 \"$file\" -o \"$file_base_name\" && ./$file_base_name < inputf.in > outputf.out && rm -f \"$file_base_name\""

The file location is: '/Users/abhilashperla/Library/Application Support/Sublime Text/Packages/User/CP.sublime-build'

