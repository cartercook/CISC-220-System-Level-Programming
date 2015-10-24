#by 13cjcc and 12twgf
\?^[[:blank:]]*//?d		#delete empty lines containing a double slash
\?//.*?s///g			#replace any one-line comment with nothing (for unempty lines with comments)
\?^[[:blank:]]*/\*.*\*/?d	#delete lines containing blanks followed by a single-line block comment
\?/\*.*\*/?s///g		#replace all one-line block comments with nothing (for unempty lines containing block comments)
