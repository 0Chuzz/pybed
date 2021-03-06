#!/usr/bin/env python2

from distutils.core import setup, Extension

module1 = Extension('bedbindings',
                    sources = ['src/pybed.c'],
                    libraries=["bed", "util"],
                    include_dirs=["bed-2.5/libbed","bed-2.5/libutil"],
                    library_dirs=["bed-2.5/lib"])

setup (name = 'pybed',
       version = '1.0',
       description = 'bindings for bed library',
       py_modules = ["bed"],
       ext_modules = [module1])
