
This program can parse most DnD spell books, but it parses via line by line, so if a name is really long and takes up more than one line the text input file will have to be editted such that it would work.
This is technically still a work in progress, here is a list of current issues:



* Special characters like bullets aren't output in list form, they are output like a paragraph.

* Little actual security and failsafes for the program, so no encapsulation, and basically spagetti

* Different books introduce new format problems, such as different apostrophes, or commas in the first input to butane.txt

compile with: g++ spells.cpp spell_data.cpp -o spells

Requirements:

*Need linux, preferably Ubuntu.(linux has tools that make smoothing out columns and turning a book pdf into a text file very easy)

*Download Mutool from the terminal use:

           sudo apt install mupdf

           sudo apt install mupdf-tools

This works for Debian based systems only!

*run "mutool poster -x 2 -y 0 input.pdf output.pdf"



*run: pdftotext -layout -nopgbrk -f (first page) -l (last page) -eol unix output.pdf in.txt



~note we run the commands like this to save time, and is basically necessary because there is currently no upper guard on the program



*run program with ./spells



*you will be prompted for the filename (it is in.txt on the line above), book name, and output file name.



*output file name can be fed to the app to automatically update your spellbook!