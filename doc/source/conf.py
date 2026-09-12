# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
# import os
# import sys
# sys.path.insert(0, os.path.abspath('.'))


# -- Project information -----------------------------------------------------

project = 'otilib-pyoti'
copyright = 'Mauricio Aristizabal (2016-Current), St. Mary\'s University (2025-Current), UT San Antonio (2022-2025) and Universidad EAFIT (2016-2020)'
author = 'Mauricio Aristizabal'

# The full version, including alpha/beta/rc tags
release = '0.1'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [
	'nbsphinx',
	'sphinx.ext.mathjax', # For math equation display.
	'sphinx.ext.autodoc',
	'sphinx.ext.viewcode',
	'sphinx.ext.napoleon',
	'breathe',
	'exhale',
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store', '**.ipynb_checkpoints']

source_suffix = [".rst"]

# -- Breathe / Exhale (C API docs from Doxygen XML) --------------------------

breathe_projects = {
	"OTIlib": "./doxyoutput/xml"
}
breathe_default_project = "OTIlib"

exhale_args = {
	"containmentFolder":     "./capi_generated",
	"rootFileName":          "capi_root.rst",
	"rootFileTitle":         "C API Reference",
	"doxygenStripFromPath":  "../../include",
	"createTreeView":        True,
	"exhaleExecutesDoxygen": True,
	"exhaleUseDoxyfile":     True,
}

# include/oti headers are plain C (extern "C" guards, no classes/templates/namespaces).
primary_domain = 'c'
highlight_language = 'c'

# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
# html_theme = 'alabaster'
html_theme = 'pydata_sphinx_theme'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']