# Spell Checker
 A program that’s designed to spell-check a file after loading a dictionary of words from disk into memory.

` Usage: speller [dictionary] text`

where *dictionary* is assumed to be a file containing a list of lowercase words, one per line, and text is a file to be spell-checked. As the brackets suggest, provision of dictionary is optional; if this argument is omitted, speller will use dictionaries/large by default. In other words, running:

`./speller text`

will be equivalent to running

`./speller dictionaries/large text`

where *text* is the file you wish to spell-check. `dictionaries/small` is a smaller dictionary. To use it, execute:

`./speller dictionaries/small text`

where _text_ is the file you wish to spell-check