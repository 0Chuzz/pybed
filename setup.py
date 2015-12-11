#!/usr/bin/python2

from distutils.core import setup, Extension

module1 = Extension('bed',
                    sources = ['src/pybed.c'],
                    libraries=["bed", "util"],
                    include_dirs=["bed-2.5/libbed","bed-2.5/libutil"],
                    library_dirs=["bed-2.5/lib"])

setup (name = 'PackageName',
       version = '1.0',
       description = 'This is a demo package',
       ext_modules = [module1])
