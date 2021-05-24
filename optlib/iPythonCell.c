/*
 * Generated by ./misc/optlib2c from optlib/iPythonCell.ctags, Don't edit this manually.
 */
#include "general.h"
#include "parse.h"
#include "routines.h"
#include "field.h"
#include "xtag.h"
#include "subparser.h"


static void initializeIPythonCellParser (const langType language CTAGS_ATTR_UNUSED)
{
}

extern parserDefinition* IPythonCellParser (void)
{
	static const char *const extensions [] = {
		NULL
	};

	static const char *const aliases [] = {
		NULL
	};

	static const char *const patterns [] = {
		NULL
	};

	static kindDefinition IPythonCellKindTable [] = {
		{
		  true, 'c', "cell", "cells",
		},
	};
	static xtagDefinition IPythonCellXtagTable [] = {
		{
		  .enabled     = false,
		  .name        = "doubleSharps",
		  .description = " Include cells starting from ##",
		},
	};
	static tagRegexTable IPythonCellTagRegexTable [] = {
		{"^[ \t]*(# ?%%|# <codecell>)[ \t]*(.*[^ \t])$", "\\2",
		"c", "{exclusive}", NULL, false},
		{"^[ \t]*##[ \t]*(.*[^ \t])$", "\\1",
		"c", "{_extra=doubleSharps}{exclusive}", NULL, false},
	};

	static subparser IPythonCellSubparser = {
		.direction = SUBPARSER_BASE_RUNS_SUB,
	};
	static parserDependency IPythonCellDependencies [] = {
		[0] = { DEPTYPE_SUBPARSER, "Python", &IPythonCellSubparser },
	};

	parserDefinition* const def = parserNew ("IPythonCell");

	def->enabled       = true;
	def->extensions    = extensions;
	def->patterns      = patterns;
	def->aliases       = aliases;
	def->method        = METHOD_NOT_CRAFTED|METHOD_REGEX;
	def->kindTable     = IPythonCellKindTable;
	def->kindCount     = ARRAY_SIZE(IPythonCellKindTable);
	def->xtagTable     = IPythonCellXtagTable;
	def->xtagCount     = ARRAY_SIZE(IPythonCellXtagTable);
	def->tagRegexTable = IPythonCellTagRegexTable;
	def->tagRegexCount = ARRAY_SIZE(IPythonCellTagRegexTable);
	def->dependencies    = IPythonCellDependencies;
	def->dependencyCount = ARRAY_SIZE(IPythonCellDependencies);
	def->initialize    = initializeIPythonCellParser;

	return def;
}