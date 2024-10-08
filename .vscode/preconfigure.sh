make -Bink 2> /dev/null | sed 's/| /\'$'\n''/g; s/iquote/I/g' > .vscode/dryout.log
